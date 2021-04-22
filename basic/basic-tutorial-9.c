#include <string.h>
#include <gst/gst.h>
#include <gst/pbutils/pbutils.h>

/* Structure to contain all our information, so we can pass it around */
typedef struct __CustomData {
	GstDiscoverer *discoverer;
	GMainLoop *loop;
} CustomData;

int main(int argc, char **argv)
{
	CustomData data;
	GError *err = NULL;
	gchar *uri = "../sintel_trailer-480p.webm";

	if(argc > 1){
		uri = argv[1];
	}

	/* Initialize custom data structure */
	memset(&data, 0x00, sizeof(data));

	/* Initialize GStreamer */
	gst_init(&argc, &argv);
	g_print("Discovering '%s'\n", uri);

	/* Instantiate the Discoverer */
	data.discoverer = gst_discoverer_new(5*GST_SECOND, &err);
	if(!data.discoverer){
		g_print("Error creating discoverer instance: %s\n", err->message);
		g_clear_error(&err);
		return (-1);
	}
}

