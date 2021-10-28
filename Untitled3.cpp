#include <stdio.h>
 
// Return sum of elements in A[0..N-1]
int findSum(int A[], int n)
{
    if (n <= 0)
        return 0;
    return (findSum(A, n - 1) + A[n - 1]);
}
 
int main()
{
    int A[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(A) / sizeof(A[0]);
    printf("%dn", findSum(A, n));
    return 0;
}
