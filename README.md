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
$Z_$ : Euclidean Distance

# Execution Time and Analysis: C vs x86_64 Assembly


# Correctness Check
[insert screenshot of C version here]
[insert screenshot of x86 version here]
