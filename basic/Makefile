GSTREAMER =-pthread -I/usr/include/gstreamer-1.0 -I/usr/include/glib-2.0 -I/usr/lib/aarch64-linux-gnu/glib-2.0/include -lgstreamer-1.0 -lgobject-2.0 -lglib-2.0

all:
	g++ -o create_GstElement.app  create_GstElement.cpp $(GSTREAMER) 
	g++ -o dynamicPipeline.app  basic-tutorial-3.c  $(GSTREAMER) 

clean:
	rm *.app

