#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int rowA = 0;
int colA = 0;
string arrayA[100][3];

void menu4 (){
	
	ofstream file;
	
	file.open("data.dat",ios::out);
	
	for(int i=0; i<rowA; i++){
		for(int j=0; j<colA; j++){
		file << arrayA[i][j]<<" \t\t";
		}
		file<<"\n";
	}
	
	file.close();
}

void readFile(){

	fstream InFile;
	InFile.open("data.dat",ios::in);

	string lineA, item;
	
	while (InFile.good()){
		while(getline(InFile, lineA)) {
			istringstream streamA(lineA);
			colA = 0;
			while (streamA >> item){
				arrayA[rowA][colA] = item;
				colA++;
			}
			rowA++;
		}
	}	
	
	 InFile.close();
	
}

void show(){
	for (int i=0; i<rowA; i++){
			cout<<"["<<i<<"]";
		for(int j=0; j<colA; j++){
			cout<< left << setw(9) << arrayA[i][j]<< " ";
		}
		cout<< endl;
	}
}
	
int main (){

	int menu;
	readFile();
	
	do{
	
	system("cls");
	cout<<"=========================="<<endl;
	cout<<"==== O STORE DATABASE ===="<<endl;
	cout<<"=========================="<<endl;
	cout<<endl;
	show();
	cout<<endl;
	
	cout<<"1. Tambah Produk\n";
	cout<<"2. Perbaharui Produk\n";
	cout<<"3. Hapus Produk\n";
	cout<<"4. Exit & Save\n\n";

	cout<<"Pilih : ";
	cin>>menu;
	
	if (menu==1){
		cout<<"Masukkan nama produk :";
		cin>> arrayA[rowA][0];
		cout<<"Masukkan stock produk :";
		cin>> arrayA[rowA][1];
		cout<<"Masukkan harga produk :";
		cin>> arrayA[rowA++][2];
		cout<<endl;
	} else if (menu == 2){ 
		int ro;
		cout<<"Masukkan index Produk : ";
		cin>>ro;
		cout<<"Masukkan nama produk :";
		cin>> arrayA[ro][0];
		cout<<"Masukkan stock produk : ";
		cin>> arrayA[ro][1];
		cout<<"Masukkan harga produk : ";
		cin>> arrayA[ro++][2];
		cout<<endl;
	} else if (menu == 3){
		int ro,temp;
		cout<<"Masukkan index Produk : ";
		cin>>ro;
		
		for(int i=ro;i<rowA;i++){
				arrayA[i][0] = arrayA[i+1][0];
				arrayA[i][1] = arrayA[i+1][1];
				arrayA[i][2] = arrayA[i+1][2];
		}	
		rowA--;
	} else if (menu == 4){
		menu4();
	}
	
	}while(menu!=4);

	return 0;
}
