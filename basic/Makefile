GSTREAMER =-pthread -I/usr/include/gstreamer-1.0 -I/usr/include/glib-2.0 -I/usr/lib/aarch64-linux-gnu/glib-2.0/include -lgstreamer-1.0 -lgobject-2.0 -lglib-2.0
GTKFLAGS = -pthread -I/usr/include/gtk-3.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 -I/usr/lib/aarch64-linux-gnu/dbus-1.0/include -I/usr/include/gtk-3.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libpng16 -I/usr/include/glib-2.0 -I/usr/lib/aarch64-linux-gnu/glib-2.0/include -lgtk-3 -lgdk-3 -lpangocairo-1.0 -lpango-1.0 -latk-1.0 -lcairo-gobject -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0
GSTVIDEO =-pthread -I/usr/include/gstreamer-1.0 -I/usr/include/orc-0.4 -I/usr/include/gstreamer-1.0 -I/usr/include/glib-2.0 -I/usr/lib/aarch64-linux-gnu/glib-2.0/include -lgstvideo-1.0 -lgstbase-1.0 -lgstreamer-1.0 -lgobject-2.0 -lglib-2.0

all:
	g++ -o create_GstElement.app  create_GstElement.cpp $(GSTREAMER) 
	g++ -o dynamicPipeline.app  basic-tutorial-3.c  $(GSTREAMER) 
	g++ -o timeManagement.app  basic-tutorial-4.c  $(GSTREAMER) 
	g++ -o mediaPlayerGui.app  basic-tutorial-5.c  $(GSTREAMER) $(GTKFLAGS) -Wdeprecated-declarations $(GSTVIDEO) 
	gcc -o padCapability.app  basic-tutorial-6.c  $(GSTREAMER)
	g++ -o simpleThreaded.app  basic-tutorial-7.c  $(GSTREAMER)
	g++ -o shortCuttingPipeline.app  basic-tutorial-8.c  $(GSTREAMER)

clean:
	rm *.app

