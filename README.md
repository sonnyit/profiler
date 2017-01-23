# Profiler

Easy to used profiler c++.

## Usage

### Define task
Just add:

```c++
PROFILER_TASK(task_name);
```

where u want to profile.

### Retrive info

1. get the times this task be called.

```c++
PROFILER_GET(task_name).count
```

2. get total time this `task_name` has taken.

```c++
PROFILER_GET(task_name).time_pass
```

3. get time the last called to this task taken

```c++
PROFILER_GET(task_name).last_time_pass
```

# Example

```c++
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
  cout << "- func1: \n\tnum_calls: " << PROFILER_GET(func1).count << "\n\ttotal_time_passed: " << PROFILER_GET(func1).time_pass << " microsecond" << "\n\tlast_execution_time: " << PROFILER_GET(func1).last_time_pass << "              microsecond\n";
  cout << "- func2: \n\tnum_calls: " << PROFILER_GET(func2).count << "\n\ttotal_time_passed: " << PROFILER_GET(func2).time_pass << " microsecond" << "\n\tlast_execution_time: " << PROFILER_GET(func2).last_time_pass << "              microsecond\n";
}
```

Output:

```
fun1 output: -39.66
fun2 output: -349.98
fun1 output: -142.56

- func1: 
	num_calls: 2
	total_time_passed: 13690 microsecond
	last_execution_time: 6241 microsecond
- func2: 
	num_calls: 1
	total_time_passed: 39903 microsecond
	last_execution_time: 39903 microsecond
```
