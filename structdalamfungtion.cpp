#include<iostream>

using namespace std;

struct matkul {
	string nmMatkul;
	string kdMatkul;
};

struct komB {
		string nama,nim;
		int ipk;
		matkul mtkl;
		string hobi[3];
};

//struct dalam parameter fungsi
void tampilkanMahasiswa (komB data){
	cout << "Nama Mahasiswa 1 : " << data.nama <<endl;
	cout << "Nim Mahasiswa 1 : " << data.nim<<endl;
	cout << "IPK Mahasiswa 1 : " << data.ipk<<endl;
	cout << "Hobi 1 Mahasiswa 1 : " << data.hobi[0]<<endl;
	cout << "Hobi 2 Mahasiswa 1 : " << data.hobi[1]<<endl;
	cout << "Hobi 3 Mahasiswa 1 : " << data.hobi[2]<<endl;
	cout << "Mata Kuliah yg diambil : " <<data.mtkl.nmMatkul <<endl;
	cout << "Mata Kuliah yg diambil : " <<data.mtkl.kdMatkul <<endl;
}

int main(){
	komB mhs[4];
	
	mhs[0].nama = "Edi";
	mhs[0].nim = "201402017";
	mhs[0].ipk = 3;
	mhs[0].hobi[0]="Memancing";
	mhs[0].hobi[1]="Membaca";
	mhs[0].hobi[2]="Makan";
	mhs[0].mtkl.nmMatkul = "SDA";
	mhs[0].mtkl.kdMatkul = "TIF123";
	
	//akses fungsi
	tampilkanMahasiswa(mhs[0]);
	
	
	
}
