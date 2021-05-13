GSTREAMER:=$(shell pkg-config --libs --cflags gstreamer-1.0)
GTKFLAGS:=$(shell pkg-config --libs --cflags gtk+-3.0)
GSTVIDEO:=$(shell pkg-config --libs --cflags gstreamer-video-1.0)
RIFF_MEDIA_LIB = -lgstriff-1.0
GSTAUDIO:=$(shell pkg-config --libs --cflags gstreamer-audio-1.0)
PBUTILS:=$(shell pkg-config --libs --cflags gstreamer-pbutils-1.0)

all:
	g++ -o create_GstElement.app  create_GstElement.cpp $(GSTREAMER) 
	g++ -o dynamicPipeline.app  basic-tutorial-3.c  $(GSTREAMER) 
	g++ -o timeManagement.app  basic-tutorial-4.c  $(GSTREAMER) 
	g++ -o mediaPlayerGui.app  basic-tutorial-5.c  $(GSTREAMER) $(GTKFLAGS) -Wdeprecated-declarations $(GSTVIDEO) 
	gcc -o padCapability.app  basic-tutorial-6.c  $(GSTREAMER)
	g++ -o simpleThreaded.app  basic-tutorial-7.c  $(GSTREAMER)
	g++ -o shortCuttingPipeline.app  basic-tutorial-8.c  $(GSTREAMER) $(GSTAUDIO) 
	g++ -o discover.app  basic-tutorial-9.c  $(GSTREAMER) $(PBUTILS) 
	g++ -o streaming.app basic-tutorial-12.c $(GSTREAMER)

clean:
	rm *.app

