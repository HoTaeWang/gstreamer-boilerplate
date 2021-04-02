GSTREAMER =-pthread -I/usr/include/gstreamer-1.0 -I/usr/include/glib-2.0 -I/usr/lib/aarch64-linux-gnu/glib-2.0/include -lgstreamer-1.0 -lgobject-2.0 -lglib-2.0

all:
	g++ -o playbackBin.app  playback-tutorial-1.c $(GSTREAMER) 

clean:
	rm *.app

