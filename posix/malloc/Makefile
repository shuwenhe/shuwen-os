HELL = /bin/bash

AllDirs := $(shell ls -R | grep '^\./.*:$$' | awk '{gsub(":","");print}') . 
Sources := $(foreach n,$(AllDirs) , $(wildcard $(n)/*.c)) 
Objs := $(patsubst %.c,%.o, $(Sources)) 
Deps := $(patsubst %.c,%.d, $(Sources)) 
StaticLib := libyy.a 
DynamicLib := libyy.so 
Bin := main

AllLibs : $(Bin)

CC = gcc 
CXX = g++ 
RM = rm -f 
#CXXFLAGS = -g -O2 -fPIC -Wall 
CXXFLAGS = -g -Wall 
CPPFLAGS = $(foreach n,$(AllDirs) , -I$(n)) 
LDFLAGS = -lstdc++ 

$(StaticLib) : $(Objs) 
	        ar rcs $@ $^ 

$(DynamicLib) : $(Objs) 
	        $(CXX) -shared -o $@ $^ $(LDFLAGS) 

$(Bin) : $(Objs) 
	        $(CXX) $(Objs) -o $@ 

%.d : %.cpp 
	        $(CXX) -MT"$(<:.cpp=.o) $@" -MM $(CXXFLAGS) $(CPPFLAGS) $< > $@ 

sinclude $(Deps) 

clean:  
	        $(RM) $(Objs) $(Deps) $(Bin)

.PHONY : clean  
