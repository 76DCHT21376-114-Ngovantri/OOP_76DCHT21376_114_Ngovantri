#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
//Khai bao Nhan Vien
class NhanVien{
	private:
		string Hoten;
		string Manv;
		string ngaysinh;
		string diachi;
	public:
	//constructor khong doi
		NhanVien(){
			Hoten="";
			Manv="";
			ngaysinh="";
			diachi="";
		}
	//constructor co doi
		NhanVien(string Ht,string Ma,string ns,string dc){
			Hoten=Ht;
			Manv=Ma;
			ngaysinh=ns;
			diachi=dc;
		}
	//Phuong phap xuat thong tin theo tung cot	
		void xuat(){
			cout<<left<<setw(15)<<Hoten
				<<left<<setw(20)<<Manv
				<<left<<setw(20)<<ngaysinh
				<<left<<setw(20)<<diachi<<endl;
		}
};
//Khai bao main
int main(){
	int n;
	cout <<"Nhap so luong nhan vien:";
	cin>>n;
	cin.ignore();
	//Su dung vector (Cach 3)
	vector<NhanVien> ds;
	for (int i=0;i<n;i++){
		string Ht,Ma,ns,dc;
		cout<<"Nhap thong tin nhan vien thu:"<<i+1<<"\n";
		cout<<"Nhap ho va ten:";
		getline(cin,Ht);
		cout<<"Nhap ma nhan vien:";
		getline(cin,Ma);
		cout<<"Nhap ngay sinh:";
		getline(cin,ns);
		cout<<"Nhap dia chi:";
		getline(cin,dc);
		//Khoi tao doi tuong constructor
		NhanVien nv(Ht,Ma,ns,dc);
		ds.push_back(nv);
	}
	//Xuat nhan vien thei cot
	cout<<"----DANH SACH NHAN VIEN----\n";
	cout<<left<<setw(15)<<"Ho ten"
		<<left<<setw(20)<<"Ma nv"
		<<left<<setw(20)<<"ngay sinh"
		<<left<<setw(20)<<"dia chi"<<endl;
	//In danh sach nhan vien
	for(int i=0;i<ds.size();i++){
		ds[i].xuat();
	}
	return 0;
}



