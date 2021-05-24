#include <cstudio>
#include <gst/gst.h>

/* Structure to contain all our information, so we can pass it around */
typedef struct _CustomData {
	GstElement *playbin;  /* our one and only element */

	gint n_video;         /* Number of embedded video streams    */
	gint n_audio;         /* Number of embedded audio streams    */
	gint n_text;          /* Number of embedded subtitle streams */

	gint current_video;   /* currently playing video stream */
	gint current_audio;   /* currently playing audio stream */
	gint current_text;    /* Currently playing subtitle stream */

	GMainLoop *main_loop;  /* GLib's main loop */
} CustomData;

/* playbin flags */
typedef enum {
	GST_PLAY_FLAG_VIDEO = (1<<0), 
	GST_PLAY_FLAG_AUDIO = (1<<1),
	GST_PLAY_FLAG_TEXT  = (1<<2)
} GstPlayFlags;

/* Forward definition for the message and keyboard processing functions */
static gboolean handle_message(GstBus *bus, GstMessage *msg, CustomData *data);
static gboolean handle_keyboard(GIOChannel *source, GIOCondition cond, CustomData *data);

int main(int argc, char *argv[])
{
	CustomData data;
	GstBus *bus;
	GstStateChangeReturn ret;
	gint flags;
	GIOChannel *io_stdin;

	/* Initialize GStreamer */
	gst_init(&argc, &argv);

	/* Create the elements */
	data.playbin = gst_element_factory_make("playbin", "playbin");
	if(!data.playbin){
		g_printerr("Not all elements could be created.\n");
		return (-1);
	}

	/* Set the URI to play */
	g_object_set(data.playbin, "uri", "file:///home/sabioguru/gstreamer-boilerplate/sintel_trailer-480p.webmsintel_trailer-480p.ogv", NULL);
	/* Set the subtitle URI to play and some font description */
	g_object_set(data.playbin, "suburi", "file:///home/sabioguru/gstramer-boilerplate/sintel_trailer_gr.srt", NULL);
	g_object_set(data.playbin, "subtitle-font-desc", "Sans, 18", NULL);

	/* Set flags to show Audio, Video and Subtitles */
	g_object_get(data.playbin, "flags", &flags, NULL);
	flags |= GST_PLAY_FLAG_VIDEO | GST_PLAY_FLAG_AUDIO | GST_PLAY_FLAG_TEXT;
	g_object_set(data.playbin, "flags", flags, NULL);

	/* Add a bus watch, so we get notified when a message arrives */
	bus = gst_element_get_bus(data.playbin);
	gst_bus_add_watch(bus, (GstBusFunc)handle_message, &data);

	/* Add a keyboard watch so we get notified of keystrokes */
#ifdef G_OS_WIN32
	io_stdin = g_io_channel_win32_new_fd(fileno(stdin));
#else
	io_stdin = g_io_channel_unix_new(fileno(stdin));
#endif
	g_io_add_watch(io_std

}

