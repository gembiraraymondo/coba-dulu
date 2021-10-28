#include<iostream>
using namespace std;

//deklarasi single Linked List
struct Data{
	string nama;
	int umur, tb;
	
	Data *next;
};

Data *head, *tail, *cur;

void createData(string nama, int umur, int tb){
	head = new Data();
	head->nama = nama;
	head->umur = umur;
	head->tb = tb;	
	head->next= NULL;
	tail = head;
}

void printData(){
	cur = head;
	while( cur != NULL){
		cout << "Nama		: " << cur->nama<<endl;
		cout << "Umur		: " << cur->umur<<endl;
		cout << "Tinggi Badan	: " << cur->tb<<endl;		
		cur = cur->next;		
		cout << endl <<endl;
	}
}

int main(){
	
	createData("Inez", 20, 150);
	printData();
	createData("Laiz", 20, 180);
	printData();
	createData("Agus", 21, 150);
	printData();
}
