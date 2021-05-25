GSTREAMER:=$(shell pkg-config --libs --cflags gstreamer-1.0)
GSTAUDIO:=$(shell pkg-config --libs --cflags gstreamer-audio-1.0)

all:
	g++ -o playbackBin.app  playback-tutorial-1.c $(GSTREAMER) 
	g++ -o selectSubtitle.app  playback-tutorial-2.c $(GSTREAMER) 
	g++ -o connectConfigAppSrc.app  playback-tutorial-3.c $(GSTREAMER) $(GSTAUDIO)

clean:
	rm *.app

