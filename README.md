# x86-to-C-Interface

Group Members:  
Agbayani, Nauj Krylle E.  
Hugo, Kurt Justine J.  

NOTE: uncomment size declaration at the beginning to choose between n = 2^20, 2^24, 2^26

# Specifications
This kernel calculates the distance of between coordinate points of two vectors using the formula:  
$Z[i] = \sqrt{(X_2[i] - X_1[i])^2 + (Y_2[i] - Y_1[i])^2}$  

The kernel takes 6 inputs:  
$N$: the length of the vectors, an integer  
$X_1$: X-coordinate of the first vector, single precision float  
$X_2$: X-coordinate of the second vector, single precision float  
$Y_1$: Y-coordinate of the first vector, single precision float  
$Y_2$: Y-coordinate of the second vector, single precision float  
$Z$ : Euclidean Distance

# Execution Time and Analysis: C vs x86_64 Assembly
This first image shows the execution time for around 16777216 entries, randomly generated. The execution time for C is 653.80 ms, while assembly language is executed at 80.30 ms.
![Screenshot 2024-12-02 232513](https://github.com/user-attachments/assets/a3fcc044-e05d-48b2-aaf0-a12de05af7ef)

The second image also shows the large gap in the execution time for assembly and C, with each having 243.67 ms and 2003.33 ms, respectively.
![Screenshot 2024-12-02 232719](https://github.com/user-attachments/assets/b8a4efd5-94d3-4539-8d82-9c7090e24d5f)

This just goes to show that algorithms, instruction written in assembly are more quickly executed since the instruction is more forward, without the convoluted underlayings of premade functions in other languages, which are made for the sake of ease of use, and encompassing failsafe methods when it comes to memory allocation, arithmetic logic, etc.

# Correctness Check
Upon printing the values, the function for C and Assembly both display the same results. The values on the left are from the C algorithm (stored in zC), while the values on the right are the ones made through Assembly (zAsm)
![Screenshot 2024-12-02 233829](https://github.com/user-attachments/assets/1f9ac569-c5ff-4718-a0d3-030cda3c7606)

