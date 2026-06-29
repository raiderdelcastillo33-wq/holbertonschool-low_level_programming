# Green Efficiency Analysis

This project shows that software efficiency is not only a question of speed. It is also connected to CPU usage, energy consumption, and the environmental impact of computation. During the benchmarking tasks, I measured several programs and compared how different approaches use execution time.

In the baseline loop test, the program executed 100,000,000 iterations three times. The measured execution times were 0.111880 seconds, 0.106923 seconds, and 0.103800 seconds. The average execution time was approximately 0.107534 seconds. This result gives a simple reference point: even a basic loop can consume measurable CPU time when the number of iterations is large.

The strongest result came from the comparison between the naive algorithm and the single-pass algorithm. The naive implementation had an average execution time of 2.019215 seconds. The single-pass implementation had an average execution time of only 0.000079 seconds. According to the measured results, the naive implementation was approximately 25,668 times slower than the single-pass implementation. This difference is very important because both programs are solving a related problem, but the algorithmic approach changes the amount of work performed by the CPU.

From a green efficiency perspective, this means that choosing a better algorithm can reduce waste. A slower algorithm keeps the processor active for longer. If this happens once, the difference may look small. However, if the same inefficient code runs thousands or millions of times, or if it runs on many servers, the accumulated cost becomes much larger. Less CPU time usually means less energy used, less heat produced, and less pressure on hardware resources.

The instrumentation task also helped me understand where time is spent inside a program. The total measured time was 0.000699 seconds. The build phase took 0.000365 seconds, the process phase took 0.000190 seconds, and the reduce phase took 0.000138 seconds. These values show that measuring only the total time is useful, but separating the program into phases gives better information. It helps identify which part of the program deserves optimization first.

My conclusion is that green software engineering starts with measurement. Without metrics, it is easy to guess incorrectly. In this project, the data showed that algorithmic complexity has a direct effect on execution time. Writing efficient code is not only about making programs faster for users. It can also reduce unnecessary CPU work and support more responsible computing.

This also shows why optimization should be guided by evidence. The best target is not always the largest function or the most complex-looking code, but the part that measurements prove to be expensive.
