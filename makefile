.SUFFIXES:

CXX := g++
CXXFLAGS := -Wall -O2 -std=c++17
INCLUDES := -I./tdx -I./dll
LIBS := -static -shared -s -mwindows -Wl,--kill-at
TARGET := macd_area.dll

SRCDIR := dll
SRCOBJS := $(patsubst %.cpp, %.o, $(wildcard $(SRCDIR)/*.cpp))
OBJS := $(SRCOBJS) $(TESTOBJS)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) $^ -o $@

$(OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< -c -o $@

clean:
	-@rm -f $(TARGET)
	-@rm -f $(OBJS)