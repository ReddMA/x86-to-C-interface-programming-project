x86-to-C interface programming project

Members:
1) Austria, Rafael Antonio
2) Go, Michael Joseph

To find out if the dot product of both codes are correct or not, the code has a checker if the ASM dot product and the C dot product yield the same result. If they are it will print out “Dot product C and ASM results are equal”, otherwise it will print out “Dot product C and ASM results are not equal”.

Vector size 2^20:

![image](https://github.com/ReddMA/x86-to-C-interface-programming-project/assets/98443988/2b4c8a59-4b9e-4ef9-a5d4-cf792550656c)

Vector size 2^24:

![image](https://github.com/ReddMA/x86-to-C-interface-programming-project/assets/98443988/7895c1b5-cdc1-4a62-9e59-47986a193694)


For vector size 2^30, we ran in 2 instances due to the machine slowing down in a concerning manner. First was ran with a cpu of an i5 10th gen cpu, second run with a cpu of an i9 9th gen.

Vector size 2^30 by i5 10th gen:
 ![image](https://github.com/ReddMA/x86-to-C-interface-programming-project/assets/98443988/14a6d4d0-b105-417c-b893-098f52c78bd3)

Vector size 2^30 by i9 9th gen:
 ![image](https://github.com/ReddMA/x86-to-C-interface-programming-project/assets/98443988/2909cca2-a94f-45c0-a94a-9f3a60ab3b70)

The Assembly code demonstrates its performance by computing the dot product calculation in roughly half the time the C code did in the given test cases for the vector size, showing that writing code in Assembly can make dot product calculations quicker than using C.

