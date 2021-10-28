#include <iostream>
using namespace std;

int maksimal = 5;
string arrayBuku[5];
int top = 0;


bool isFull()
{
  if( top == maksimal ){
    return true;
  }else{
    return false;
  }
}

bool isEmpty()
{
  if( top == 0 ){
    return true;
  }else{
    return false;
  }
}

//insert data
void pushArray(string data){
  if( isFull() ){
    cout << "Data penuh" << endl;
  }else{
    arrayBuku[top] = data;
    top++;
  }
}

//hapus data
void popArray()
{
  if( isEmpty() ){
    cout << "Data kosong!!" << endl;
  }else{
    arrayBuku[top-1] = "";
    top--;
  }
}

//cetak data
void displayArray(){
  if( isEmpty() ){
    cout << "Data kosong!!" << endl;
  }else{
    cout << "Data stack " << endl;
    cout << "===========" <<endl;
    for( int i = maksimal - 1; i >= 0; i-- ){
      if( arrayBuku[i] != "" ){
        cout << "Data : " << arrayBuku[i] << endl;
      }
    }
    cout << "\n" << endl;
  }
}


int main(){

  pushArray("Matematika");
  displayArray();
  
  pushArray("Web Programming");
  pushArray("Pemrograman Berbasis Objek");
  pushArray("Sistem Operasi");
  pushArray("Struktur Data");
  displayArray();


  popArray();
  displayArray();


}
