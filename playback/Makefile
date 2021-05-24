GSTREAMER:=$(shell pkg-config --libs --cflags gstreamer-1.0)

all:
	g++ -o playbackBin.app  playback-tutorial-1.c $(GSTREAMER) 

clean:
	rm *.app

