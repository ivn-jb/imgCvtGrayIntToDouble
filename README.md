# imgCvtGrayIntToDouble

**Execution Times:**
|             |ASM      |C        |
|-------------|---------|---------|
| 10*10       |0 ms     |0 ms     |
| 100*100     |0 ms     |0 ms     |
| 1000*1000   |4.57 ms  |2.27 ms  |
| 10000*10000 |438.23 ms|203.03 ms|

**Analysis:**
Apparently, the results show that the C program is almost 2x faster than the assembly code. According to research, modern C compilers has become very efficient at compiling code that it takes high expertise for humans to write a more efficient code in Assembly. The code written in Assembly follows the lectures of the LBYARCH course. Some parts of the code could have made the program execute longer, such as loops and division codes, while modern C compilers used technologies that are not in the scope of the course. It is said that a human coder should be very talented to assess which code key parts to optimize using assembly to increase code performance. But for most coding patterns, modern compilers are made to automatically compile code that are very optimized.

It is also said that it is more important to use the right algorithm. From there, a coder should read the generated assembly code and adjust accordingly. In coding, one should assess the trade-offs and factors in using C and Assembly, whether flexibility and fast development is better or performance should be boosted. 


**Correctness check:**

<img width="468" height="975" alt="image" src="https://github.com/user-attachments/assets/37aaf109-16f9-44d8-8efb-7b12f0475744" />
<img width="457" height="907" alt="image" src="https://github.com/user-attachments/assets/20b3227c-528e-4d71-9b2d-190eaa35f109" />

**Sources:**
- https://www.dspguide.com/ch28/5.htm
- https://blogs.sw.siemens.com/embedded-software/2013/02/18/why-c-is-faster-than-assembly/

