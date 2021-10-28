#include <iostream>
using namespace std;

//Deklarasi Double Linked List
struct Data{
	string nama;
	int tahun, harga;
	
	//Menggunakan 2 pointer 'next' dan 'prev'
	Data *next, *prev;
};

//Inisialisasi Double linked list
Data *head, *tail, *cur, *newNode, *hapus, *t;

//Pembuatan Elemen Double Linked List
void createData(string nama, int tahun, int harga){
	head = new Data();
	head -> nama = nama;
	head -> tahun = tahun;
	head -> harga = harga;
	head -> next = NULL;
	tail = head;
}

//Penambahan Node Awal Pada List
void tambahAwal(string nama, int tahun, int harga){
	if(head == NULL){
		cout << "Belum ada Double Linked List" ;
	}
	else{
		newNode = new Data();
		newNode -> nama = nama;
		newNode -> tahun = tahun;
		newNode -> harga = harga;
		newNode -> prev = NULL;
		newNode -> next = head;
		head -> prev = newNode;
		head = newNode;
	}
}

//Penambahan Node Tengah Pada List
void tambahTengah(string nama, int tahun, int harga, int p){
	if(head == NULL){
		cout << "Belum ada Double Linked List" ;
	}
	else{
		int j = 2;
		newNode = new Data(); //Pembuatan Node Baru
		newNode -> nama = nama;
		newNode -> tahun = tahun;  
		newNode -> harga = harga;
		newNode -> next = NULL;
		newNode -> prev = NULL;         	
		t = head;
		while(t){
			if(j == p){ //Pemberhentian Posisi Sebelum Penambahan Node
				newNode -> next = t -> next; //newNode->next mengarah seperti t->next
				t -> next -> prev = newNode; //Node Setelah t prevnya Mengarah ke Node newNode
				newNode -> prev = t; //newNode->prev mengarah ke t
				t -> next = newNode; //temp->next mengarah ke newNode
				break; //Penghentian while
			}
			t = t -> next; //Node Selanjutnya
			j++;
		}
	}
}

//Penambahan Node Akhir Pada List
void tambahAkhir(string nama, int tahun, int harga){
	if(head == NULL){
		cout << "Belum ada Double Linked List" ;
	}
	else{
		newNode = new Data();
		newNode -> nama = nama;
		newNode -> tahun = tahun;
		newNode -> harga = harga;
		newNode -> prev = tail;
		newNode -> next = NULL;
		tail -> next = newNode;
		tail = newNode;
	}
}

//Penghapusan Node Awal
void hapusAwal(){
	if(head == NULL){
		cout << "Belum ada Double Linked List" ;
	}
	else if (head -> next == NULL){
		hapus = head;
		head = NULL;
		tail = NULL;
		delete hapus;
	}
	else{
		hapus = head;
		head = hapus -> next;
		head -> prev = NULL;
		delete hapus;
	}
	cout << endl;
}

//Penghapusan Node Tengah
void hapusTengah(int posisi){
	int j = 1;
	t = head;
	while(t){
		if(j == posisi - 1){ //Pemberhentian Posisi Sebelum Node Dihapus
			hapus = t -> next; //hapus Sebagai Node Setelah t
			hapus -> next -> prev = t; //Node Setelah hapus prevnya mengarah ke t
			t -> next = hapus -> next; //t->next Mengarah Sama Seperti hapus->next
			hapus -> next = hapus -> prev = NULL; //hapus->next dan hapus->prev NULL
			delete hapus; //Perintah Menghapus Node
			break; //Penghentian While
		}
		j++;                        
	}
}

//Penghapusan Node Akhir
void hapusAkhir(){
	if(head == NULL){
		cout << "Belum ada Double Linked List" ;
	}
	else if (head -> next == NULL){
		hapus = head;
		head = NULL;
		tail = NULL;
		delete hapus;
	}
	else{
		hapus = tail;
		tail = hapus -> prev;
		tail -> next = NULL;
		delete hapus;
	}
	cout << endl;
}

//Pencetakan Data
void printData(){
	if(head == NULL){
		cout << "Double Linked List belum dibuat !!";
	}
	else{
		cur = head;
		while( cur != NULL){
		cout << "Nama Mobil		: " << cur->nama<<endl;
		cout << "Tahun Awal Produksi	: " << cur->tahun<<endl;
		cout << "Kisaran Harga Baru	: " << cur->harga<<endl;		
		cur = cur->next;		
		cout << endl <<endl;
		}
	}
}

//Fungsi Main
int main()
{
	cout<<"\tLinked List Mobil" << endl;
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
