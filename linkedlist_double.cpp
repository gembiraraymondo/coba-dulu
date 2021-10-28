#include <iostream>

using namespace std;

struct Data{
	string nama;
	int no_urut;
	
	Data *next, *prev;
};

Data *head, *tail, *cur, *newNode, *del, *temp;

void createData(string nama, int no_urut){
	head = new Data();
	head -> nama = nama;
	head -> no_urut = no_urut;
	head -> next = NULL;
	tail = head;
}

void addFirstData(string nama, int no_urut){
	if(head == NULL){
		cout << "Belum ada Double Linked List" ;
	}
	else{
		newNode = new Data();
		newNode -> nama = nama;
		newNode -> no_urut = no_urut;
		newNode -> prev = NULL;
		newNode -> next = head;
		head -> prev = newNode;
		head = newNode;
	}
}

void addMidData(string nama, int no_urut, int posisi){
	if(head == NULL){
		cout << "Belum ada Double Linked List" ;
	}
	else{
		int count = 2;
		newNode = new Data();
		newNode -> nama = nama;
		newNode -> no_urut = no_urut;                      //masukkan data ke node
		newNode -> next = NULL;
		newNode -> prev = NULL;          
			
		temp = head;
		while(temp){
			if(count == posisi){ //berhenti di posisi sebelum node yang akan ditambahkan
				newNode -> next = temp -> next; //newNode->next mengarah seperti arah temp->next
				temp -> next -> prev = newNode; //node setelah temp prevnya mengarah ke node newNode
				newNode -> prev = temp; //newNode->prev mengarah ke temp
				temp -> next = newNode; //temp->next mengarah ke newNode
				break; //menghentikan while-do
			}
			temp = temp -> next; //pindah ke node selanjutnya
			count++;
		}
	}
}

void addLastData(string nama, int no_urut){
	if(head == NULL){
		cout << "Belum ada Double Linked List" ;
	}
	else{
		newNode = new Data();
		newNode -> nama = nama;
		newNode -> no_urut = no_urut;
		newNode -> prev = tail;
		newNode -> next = NULL;
		tail -> next = newNode;
		tail = newNode;
	}
}

void deleteFirstData(){
	if(head == NULL){
		cout << "Belum ada Double Linked List" ;
	}
	else if (head -> next == NULL){
		del = head;
		head = NULL;
		tail = NULL;
		delete del;
	}
	else{
		del = head;
		head = del -> next;
		head -> prev = NULL;
		delete del;
	}
	cout << endl;
}

void deleteMidData(int posisi){
	int count = 1;
	temp = head;
	while(temp){
		if(count == posisi - 1){ //berhenti di posisi sebelum node yang akan didel
			del = temp -> next; //del menjadi node setelah temp
			del -> next -> prev = temp; //node setelah del prevnya mengarah ke temp
			temp -> next = del -> next; //temp->next mengarah sama seperti del->next
			del -> next = del -> prev = NULL; //del->next dan del->prev NULL
			delete del; //delete del
			break;
		}
		count++;                        
	}
}

void deleteLastData(){
	if(head == NULL){
		cout << "Belum ada Double Linked List" ;
	}
	else if (head -> next == NULL){
		del = head;
		head = NULL;
		tail = NULL;
		delete del;
	}
	else{
		del = tail;
		tail = del -> prev;
		tail -> next = NULL;
		delete del;
	}
	cout << endl;
}

void showData(){
	cur = head;
	while(cur != NULL){
		cout << "\tNama		: " << cur->nama << endl;
		cout << "\tNomor Urut	: " << cur->no_urut << endl;
		cur = cur -> next;
		
		cout << endl;
	}
}

void printData(){
	cur = temp;
	while(cur != NULL){
		cout << "\tNama		: " << cur->nama << endl;
		cout << "\tNomor Urut	: " << cur->no_urut << endl;
		cur = cur -> next;
		
		cout << endl;
	}
}

int main()
{
	createData("Abdul", 1);
	showData();
	
	cout << "\t--Setelah data ditambah di awal--" << endl;
	addFirstData("Adam", 2);
	showData();
	
	cout << "\t--Setelah data ditambah ditengah--" << endl;
	addMidData("Amelia", 4, 2);
	printData();
	
	cout << "\t--Setelah data ditambah di akhir--" << endl;
	addLastData("Agit", 3);
	showData();
	
	cout << "\t--Setelah data awal dihapus--" << endl;
	deleteFirstData();
	showData();
	
	cout << "\t--Setelah data ditengah dihapus--" << endl;
	deleteMidData(2);
	printData();
	
	cout << "\t--Setelah data akhir dihapus--" << endl;
	deleteLastData();
	showData();
	
	
	return 0;
}