#include <iostream>

using namespace std;

int LinearSum(int A[], int n)
{
	if (n <= 0)
		return 0;
	return (LinearSum(A, n - 1) + A[n - 1]);
}

int main()
{
	int A[] = { 11,22,33,44,55 };
	int n = sizeof(A) / sizeof(A[0]);
	cout << LinearSum(A, n) << endl;
	
	return 0;
}
