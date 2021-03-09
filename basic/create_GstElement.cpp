#include <gst/gst.h>

int main(int argc, char **argv)
{
	GstElement *pElement = NULL;

	// init gstreamer
	gst_init(&argc, &argv);
	

	// create element
	pElement = gst_element_factory_make("fakesrc", "source");
	if(!pElement){
		g_print("Failed to create element of type 'fakesrc'\n");
		return(-1);
	}

	gst_object_unref(GST_OBJECT(pElement));
	return 0;
}

