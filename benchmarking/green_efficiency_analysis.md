# Green Efficiency Analysis

## Measurement Methodology

I measured the execution time of the provided benchmarking programs and used the recorded outputs as evidence for this report. For the baseline loop, the program executed 100,000,000 iterations three times. The measured times were 0.111880 seconds, 0.106923 seconds, and 0.103800 seconds, giving an average of approximately 0.107534 seconds. For the algorithm comparison, I compared a naive implementation with a single-pass implementation. For the instrumentation task, I measured the total program time and separated the execution into build, process, and reduce phases.

## Observed Performance Differences

The largest performance difference appeared in the algorithm comparison. The naive algorithm had an average execution time of 2.019215 seconds, while the single-pass algorithm had an average execution time of 0.000079 seconds. The recorded output showed that the naive implementation was approximately 25,668 times slower than the single-pass implementation. This is a very large difference for programs solving a related problem. It shows that the algorithmic approach can matter much more than small code changes.

The instrumentation program also showed useful timing information. Its total measured time was 0.000699 seconds. The build phase took 0.000365 seconds, the process phase took 0.000190 seconds, and the reduce phase took 0.000138 seconds. This helped show where the program spent most of its measured time.

## Relation Between Runtime and Energy Consumption

Runtime is connected to energy consumption because a program that keeps the CPU active for longer usually requires more computational work. The measurements do not directly report electrical power, but they do show CPU execution time. Based on the recorded results, the naive algorithm used much more runtime than the single-pass algorithm. If inefficient code runs many times or on many machines, the extra CPU time can become a larger energy cost. Improving algorithms can therefore reduce unnecessary computation and support more efficient software.

## Limitations of the Experiment

This experiment has clear limitations. I measured execution time, not real power usage in watts. The results were also collected on one machine, so they may vary on another computer or under different system load. Small programs can also be affected by background processes and timer precision. Because of this, the results should be interpreted as evidence about relative runtime, not as a complete energy profile.

## Practical Engineering Takeaway

The main lesson is that measurement should guide optimization. Without recorded outputs, it is easy to guess incorrectly about what matters. In this project, the data showed that a better algorithm can reduce runtime dramatically. For practical engineering, the best first step is to measure, identify the expensive part, and then optimize the code that evidence shows is actually costly.
