CXXFLAGS_CUSTOM = -Wall -g -O3 -std=c++14
CXXFLAGS_ROOT = $(shell root-config --cflags)
CXXFLAGS = $(CXXFLAGS_CUSTOM) $(CXXFLAGS_ROOT)
LDFLAGS_CUSTOM =
LDFLAGS_ROOT = $(shell root-config --libs)
LDFLAGS = $(LDFLAGS_ROOT) $(LDFLAGS_CUSTOM)

all: write read

event.cxx: event.h event_linkdef.h
	rootcling -f $@ event.h event_linkdef.h

libEvent.so: event.cxx
	g++ -shared -fPIC -o$@ $(CXXFLAGS) event.cxx $(LDFLAGS)

write: write.cc libEvent.so
	g++ $(CXXFLAGS) -o $@ $< $(LDFLAGS)

read: read.cc libEvent.so
	g++ $(CXXFLAGS) -o $@ $< $(LDFLAGS)


clean:
	rm -f read write libEvent.so event.cxx event_rdict.pcm