#include<iostream>

using namespace std;

//deklarasi double Linked List
struct Data {
	string nama;
	int umur, tb;
	
	Data *prev;
	Data *next;
};

Data *head, *tail, *cur, *newNode;

//Create Double Linked List
void createData(string nama, int umur, int tb){
	head=new Data();
	head->nama = nama;
	head->umur = umur;
	head->tb = tb;
	head->prev=NULL;
	head->next= NULL;
	tail = head;
}

//Add First
void addFirst(string nama, int umur, int tb){
	if( head == NULL){
		cout << "Duoble Linked List belum dibuat!!";
	}
	else{
		newNode=new Data();
		newNode->nama = nama;
		newNode->umur = umur;
		newNode->tb = tb;
		newNode->prev=NULL;
		newNode->next= head;
		head->prev = newNode;
		head = newNode;
	}
}

//Add Last
void addLast(string nama, int umur, int tb){
	if( head == NULL){
		cout << "Double Linked List belum dibuat!!";
	}
	else{
		newNode=new Data();
		newNode->nama = nama;
		newNode->umur = umur;
		newNode->tb = tb;
		newNode->prev= tail;
		newNode->next= NULL;
		tail->next = newNode;
		tail = newNode;
	}
}

void printData(){
	if(head == NULL){
		cout << "Double Linked List belum dibuat !!";
	}
	else{
		cur = head;
		while( cur != NULL){
		cout << "Nama		: " << cur->nama<<endl;
		cout << "Umur		: " << cur->umur<<endl;
		cout << "Tinggi Badan	: " << cur->tb<<endl;		
		cur = cur->next;		
		cout << endl <<endl;
		}
		cout << "-----------------------------------------"<<endl;
	}
}

int main (){
	createData("Inez", 20, 150);
	printData();
	addFirst("Ika", 21, 160);
	printData();
	addLast("Mondo", 21, 166);
	printData();
}

