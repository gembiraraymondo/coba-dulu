#include <bits/stdc++.h>
using namespace std;
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void annonymousFunc(int p[],int n) {
	int i, j, temp ;
 	for( i=0; i < n ; i++ ) {
		for( j=0 ;j <n-1; j++) 
			if( p[j] > p[j+1] ) {
				temp = p[j] ;
				p[j] = p[j+1] ;
				p[j+1] = temp ;
			}
	}
}
 
/* Function to print an array */
void printArray(int p[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << p[i] << " ";
    cout << endl;
}
 
// Driver program to test above functions
int main()
{
    int p[] = {64, 25, 12, 22, 11};
    int n = sizeof(p)/sizeof(p[0]);
    annonymousFunc(p, n);
    cout << "Sorted array: \n";
    printArray(p, n);
    return 0;
}



