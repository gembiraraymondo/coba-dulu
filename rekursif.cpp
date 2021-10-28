// PROGRAM MENCETAK 0-6 REKURSIF
#include<iostream>
using namespace std;
int rekursif(int i) 
{	
	if(i <= 6) {		
		cout << "Angka " << i << endl;		
		i++;		
		return(rekursif(i));}
}
int main() 
{	
	rekursif(0);	
	return 0;
}
