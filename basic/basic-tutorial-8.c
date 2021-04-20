#include <gst/gst.h>
#include <gst/audio/audio.h>
#include <string.h>

#define CHUNK_SIZE 1024		/* Amount of bytes we are sending in each buffer */
#define SAMPLE_RATE 44100	/* Samples per second we are sending  		 */

/* Structure to contain all our information, so we can pass it to callbacks */
typedef struct _CustomData {
	GstElement *pipeline, *app_source, *tee, *audio_queue, *audio_convert1, *audio_resample, *audio_sink;
	GstElement *video_queue, *audio_convert2, *visual, *video_convert, *video_sink;
	GstElement *app_queue, *app_sink;

	guint64 num_samples;	/* Number of samples generated so far (for timestamp generation) */
	gfloat a, b, c, d;	/* For waveform generation */

	guint sourceid;		/* To control the GSource */

	GMainLoop *main_loop;	/* GLib's Main Loop */
} CustomData;


/* This method is called by the idel GSource in the mainloop, to feed CHUNK_SIZE bytes into appsrc.
 * The idle handler is added to the mainloop when appsrc requests us to start sending data (need-data signal)
 * and is removed when appsrc has enough data (enough-data signal)
 */
static gboolean push_data(CustomData *data)
{
	GstBuffer *buffer;
	GstFlowReturn ret;
	int i;
	GstMapInfo map;
	gint16 *raw;
	gint num_samples = CHUNK_SIZE /2; /* Because each sample is 16 bits */
	gfloat freq;

	/* Create a new empty buffer */
	buffer = gst_buffer_new_and_alloc(CHUNK_SIZE);

	/* Set its timestamp and duration */
	GST_BUFFER_TIMESTAMP(buffer) = gst_util_uint64_scale(data->num_samples, GST_SECOND, SAMPLE_RATE);
	GST_BUFFER_TIMESTAMP(buffer) = gst_util_uint64_scale(num_samples, GST_SECOND, SAMPLE_RATE);

	/* Generate some psychodelic waveforms */
	gst_buffer_map(buffer, &map, GST_MAP_WRITE);
	raw = (gint16 *)map_data;
	data->c += data->d;
	data->d -= data->c / 1000;
	freq = 1100 + 1000 * data->d;
	for(i=0; i< num_samples; i++){
		data->a += data->b;
		data->b -= data->a / freq;
		raw[i] = (gint16)(500 * data->a);
	}
	gst_buffer_unmap(buffer, &map);
	data->num_samples += num_samples;

	/* Push the buffer into the appsrc */
	g_signal_emit_by_name(data->app_source, "push-buffer", buffer, &ret);
	
	/* Free the buffer now that we are done with it */
	gst_buffer_unref(buffer);

	if(GST_FLOW_OK != ret){
		/* We got some error, stop ending data */
		return FALSE;
	}

	return TRUE;
}

/* This signal callback triggers when appsrc needs data. Here, we add an idle handler
 * to the mainloop to start pushing data into the appsrc  */
static void start_feed(GstElement *source, guint size, CustomData *data)
{
	if(data->sourceid == 0){
		g_print("Start feeding \n");
		g_source_remove(data->sourceid);
		data->sourceid = 0;
	}
}


/* This callback triggers when appsrc has enough data and we can stop sending.
 * We remove the idle handler from the mainloop  */
static void stop_feed(GstElement *source, CustomData *data)
{
	if(data->sourceid != 0){
		g_print("Stop feeding\n");
		g_source_remove(data->sourceid);
		data->sourceid = 0;
	}
}

/* The appsink has received a buffer */

