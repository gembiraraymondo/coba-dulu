#include<iostream>
using namespace std;

//Deklarasi Single Linked List
struct Data{
	string nama;
	int tahun, harga;
	
	//Menggunakan 1 pointer 'next'
	Data *next;
};

//Inisialisasi Single linked list
Data *head, *tail, *cur, *newNode, *hapus, *t;

//Pembuatan Elemen Single Linked List
void createData(string nama, int tahun, int harga){
	head = new Data();
	head->nama = nama;
	head->tahun = tahun;
	head->harga = harga;	
	head->next= NULL;
	tail = head;
}

//Penambahan Node Awal Pada List
void tambahAwal(string nama, int tahun, int harga){
	newNode = new Data();
	newNode->nama = nama;
	newNode->tahun = tahun;
	newNode->harga = harga;	
	newNode->next= head;
	head = newNode;
}

//Penambahan Node Tengah Pada List
void tambahTengah(string nama, int tahun, int harga, int p){
	if(head == NULL){
		cout << "Belum ada Single Linked List !!" ;
	}
	else{
		int j = 2;
		newNode = new Data(); //Pembuatan Node Baru
		newNode -> nama = nama;
		newNode -> tahun = tahun;    
		newNode -> harga = harga;                   
		newNode -> next = NULL;    			
		t = head;
		
		while(t){
			if(j == p){ //Pemberhentian Posisi Sebelum Penambahan Node
				newNode -> next = t ->next; //newNode->next mengarah seperti t->next
				t -> next = newNode; //t -> next mengarah newNode
				break; // Penghentian while
			}
			t = t -> next; //Node Selanjutnya
			j++;
		}
	}
}

//Penambahan Node Akhir Pada List
void tambahAkhir(string nama, int tahun, int harga){
	newNode = new Data();
	newNode->nama = nama;
	newNode->tahun = tahun;
	newNode->harga = harga;	
	newNode->next= NULL;
	tail->next = newNode;
	tail=newNode;
}

//Penghapusan Node Awal
void hapusAwal(){
	hapus = head;
	head = head->next;
	delete hapus;
}

//Penghapusan Node Tengah
void hapusTengah(int p){
	int j = 1;
	t = head;
	while(t){
		if(j == p - 1){ //Pemberhentian Posisi Sebelum Node Dihapus
			hapus = t -> next; //hapus Sebagai Node Setelah t
			t -> next = hapus -> next; //t -> next seperti hapus -> next
			hapus -> next = NULL; //hapus->next NULL
			delete hapus; //Perintah Menghapus Node
			break; //Penghentian while
		}
		j++;                        
	}
}

//Penghapusan Node Akhir
void hapusAkhir(){
	hapus = tail;
	cur = head;
	while(cur->next != tail){
		cur = cur->next;
	}
	tail = cur;
	tail->next = NULL;
	delete hapus;
}

//Pencetakan Data
void printData(){
	cur = head;
	while( cur != NULL){
		cout << "Nama Mobil		: " << cur->nama<<endl;
		cout << "Tahun Awal Produksi	: " << cur->tahun<<endl;
		cout << "Kisaran Harga Baru	: " << cur->harga<<endl;		
		cur = cur->next;		
		cout << endl <<endl;
	}
}

//Fungsi Main
int main(){
	cout<<"\tSingle Linked List Mobil" << endl;
	createData("Toyota Fortuner", 2004, 575000000);
	printData();	
	cout<<"--------------------------------------------" << endl;
	
	cout<<"\tPenambahan node di awal" << endl;
	tambahAwal("Pajero Sport", 1996, 625000000);
	printData();
	
	cout<<"--------------------------------------------" << endl;
	cout<<"\tPenambahan node di tengah" << endl;
	tambahTengah("Kijang Innova", 2004, 350000000, 2);
	printData();
	
	cout<<"--------------------------------------------" << endl;
	cout<<"\tPenambahan node di akhir" << endl;
	tambahAkhir("Mercy GL-Class", 2006, 1350000000);
	printData();
	
	cout<<"--------------------------------------------" << endl;
	cout<<"\tPenghapusan node di awal" << endl;
	hapusAwal();
	printData();
	
	cout<<"--------------------------------------------" << endl;
	cout<<"\tPenghapusan node di tengah" << endl;
	hapusTengah(1);
	printData();

	cout<<"--------------------------------------------" << endl;
	cout<<"\tSetelah node akhir dihapus" << endl;
	hapusAkhir();
	printData();
	cout<<"--------------------------------------------" << endl;
	
	return 0;	
}
