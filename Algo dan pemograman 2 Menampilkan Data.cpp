#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Buku{
	private:
	char kode[10], judul[35], pengarang[25];
	int jml;
public:
	void info_buku() const;
};

void baca_buku();

int main() {
	baca_buku();
	return 0;
}
void Buku::info_buku()const{

     cout<< left << setw (10)<< kode
         <<setw(35)<< judul
         <<setw(25)<<pengarang
         <<setw(10)<<jml<<endl;
}
void baca_buku (){
     ifstream file_buku ("BUKU.DAT", ios::binary);
     if (!file_buku) {
     	cerr<<"file tidak dapat dibuka!"<<endl;
     	return;
	 }
Buku buku_perpustakaan;

cout<<"<<Daftar Buku>>" <<endl <<endl;
cout<<"==============================================================="<<endl;
cout<<"Kode Buku  Judul Buku          Pengarang        Jumlah"<<endl;
cout<<"==============================================================="<<endl;

while (file_buku.read(reinterpret_cast<char*>(&buku_perpustakaan), sizeof(buku_perpustakaan))){
	buku_perpustakaan.info_buku();
}
     file_buku.close ();
cout<< "=============================================================="<<endl;
}
