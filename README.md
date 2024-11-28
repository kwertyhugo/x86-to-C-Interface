# x86-to-C-Interface

Group Members:  
Agbayani, Nauj Krylle E.  
Hugo, Kurt Justine J.  

# Specifications
This kernel calculates the distance of between coordinate points of two vectors using the formula:  
$Z[i] = \sqrt{(X_2[i] - X_1[i])^2 + (Y_2[i] - Y_1[i])^2}$  

The kernel takes 5 inputs:  
$N$: the length of the vectors, an integer  
$X_1$: X-coordinate of the first vector, double precision float  
$X_2$: X-coordinate of the second vector, double precision float  
$Y_1$: Y-coordinate of the first vector, double precision float  
$Y_2$: Y-coordinate of the second vector, double precision float  

And gives 1 output:  
$Z$ : Euclidean Distance

# Execution Time and Analysis: C vs x86_64 Assembly


# Correctness Check
[insert screenshot of C version here]
[insert screenshot of x86 version here]
