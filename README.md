x86-to-C interface programming project

Members:
1) Austria, Rafael Antonio
2) Go, Michael Joseph

To find out if the dot product of both codes are correct or not, the code has a checker if the ASM dot product and the C dot product yield the same result. If they are it will print out “Dot product C and ASM results are equal”, otherwise it will print out “Dot product C and ASM results are not equal”.

Vector size 2^20 (debug):

![image](https://github.com/ReddMA/x86-to-C-interface-programming-project/assets/98443988/2b4c8a59-4b9e-4ef9-a5d4-cf792550656c)

Vector size 2^20 (release):

![image](https://github.com/ReddMA/x86-to-C-interface-programming-project/assets/98443988/0068a9f9-dc54-4d41-a425-e33a0a87c936)


Vector size 2^24 (debug):

![image](https://github.com/ReddMA/x86-to-C-interface-programming-project/assets/98443988/7895c1b5-cdc1-4a62-9e59-47986a193694)

Vector size 2^24 (release):

![image](https://github.com/ReddMA/x86-to-C-interface-programming-project/assets/98443988/fba7fa95-269e-4dc7-a0a7-c14ab6836f25)

Vector size 2^28 (debug):

![image](https://github.com/ReddMA/x86-to-C-interface-programming-project/assets/98443988/3dd0978b-731f-427e-9c92-15c2b9c2a3c5)

Vector size 2^28 (release):

![image](https://github.com/ReddMA/x86-to-C-interface-programming-project/assets/98443988/028bb542-d123-4776-9bc4-aab2255c2de9)

The Assembly code demonstrates its performance by computing the dot product calculation in roughly half the time the C code did in the given test cases for the vector size, showing that writing code in Assembly can make dot product calculations quicker than using C.

