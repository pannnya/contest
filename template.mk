.SUFFIXES : .cpp
.cpp : $@
	g++ -std=c++11 -o $@ $<
