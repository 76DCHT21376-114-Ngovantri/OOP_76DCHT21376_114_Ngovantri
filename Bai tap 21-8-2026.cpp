#include <iostream>
#include <string>
using namespace std;
//Khai bao Nhan Vien
class NhanVien{
	private:
		string Hoten;
		string Manv;
		string ngaysinh;
		string diachi;
	public:
		void nhap(){
			cout<<"Nhap ho va ten:";
			getline (cin,Hoten);
			cout<<"Nhap ma nv:";
			getline(cin,Manv);
			cout<<"Nhap ngay sinh:";
			getline(cin,ngaysinh);
			cout<<"Nhap dia chi:";
			getline(cin,diachi);
		}
		void xuat(){
			cout<<"\n---THONG TIN NHAN VIEN---\n"<<endl;
			cout<<"Ho ten:"<<Hoten<<endl;
			cout<<"Ma nhan vien:"<<Manv<<endl;
			cout<<"Ngay sinh:"<<ngaysinh<<endl;
			cout<<"Dia chi:"<<diachi<<endl;
		}
};
//Khai bao main
int main(){
	//Khai bao mot doi tuong la Minh thuoc lop nhan vien
	NhanVien Minh;
	//Nhap thong tin cho Minh
	cout<<"Nhap thong tin cho nhan vien Minh:\n";
	Minh.nhap();
	//Xuat thong tin cua Minh
	Minh.xuat();
	return 0;
}



