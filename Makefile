profiler_example: profiler.h profiler.cpp

profiler_example: profiler.cpp example.cpp
	$(CXX) -Wall -g -std=c++11 -o profiler_example profiler.cpp example.cpp

clean:
	rm -f profiler_example
