#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
#include "profiler.h"

using namespace std;

void func1() {
  PROFILER_TASK(func1);

  float f = 0;
  for (int i = 0; i < 100000; ++i) {
    f += cosf(static_cast<float>(rand()));
  }
  cout << "fun1 output: " << fixed << setprecision(2) << f << endl;
}

void func2() {
  PROFILER_TASK(func2);

  float f = 0;
  for (int i = 0; i < 500000; ++i) {
    f += cosf(static_cast<float>(rand()));
  }
  cout << "fun2 output: " << fixed << setprecision(2) << f << endl;

  func1();
}

int main() {
  srand(time(NULL));
  func1();
  func2();

  cout << "\n";
  cout << "- func1: \n\tnum_calls: " << PROFILER_GET(func1).count << "\n\ttotal_time_passed: " << PROFILER_GET(func1).time_pass << " microsecond" << "\n\tlast_execution_time: " << PROFILER_GET(func1).last_time_pass << " microsecond\n";
  cout << "- func2: \n\tnum_calls: " << PROFILER_GET(func2).count << "\n\ttotal_time_passed: " << PROFILER_GET(func2).time_pass << " microsecond" << "\n\tlast_execution_time: " << PROFILER_GET(func2).last_time_pass << " microsecond\n";
}
