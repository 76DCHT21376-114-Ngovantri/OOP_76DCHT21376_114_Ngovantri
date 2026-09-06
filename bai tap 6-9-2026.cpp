//Bai 7:
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//Cau 1:
class SinhVien{
	private:
		string hoten;
		int namsinh;
		float diem[4];
		float diemTB;
//Cau 2:
	public:
		void nhap(){
			cout<<"Nhap ho va ten:";
			getline(cin,hoten);
			cout<<"Nhap nam sinh:";
			cin>>namsinh;
			cout<<"Nhap diem 4 mon hoc:\n";
			for (int i=0;i<4;i++){
				cout<<"Mon "<<i+1<<":";
				cin>>diem[i];
			}
			diemtrungbinh();
		}
		void diemtrungbinh(){
			float tong=0;
			for(int i=0;i<4;i++){
				tong+=diem[i];
			}
			diemTB=tong/4;
			cout<<"Diem trung binh cua sinh vien la:"<<diemTB<<endl;
		}
		bool sinhvienthitotnghiep(){
			//Neu co mon nao duoi 5 la false 
			for (int i=0;i<4;i++){
				if(diem[i]<5){
					return false;
				}
			}
			//Kiem tra diem trung binh duoi 7
			if(diemTB<7){
				return true;
			}
			return false;
		}
		void xuat(){
			cout<<"Ho va ten:"<<hoten
				<<"|Nam sinh:"<<namsinh
				<<"|Diem trung binh:"<<diemTB<<endl;
		}
};
//Cau 3:
int main(){
	int n;
	cout<<"So sinh vien thi la:";
	cin>>n;
	cin.ignore();
	//Khai bao mang dong
	vector<SinhVien> ds(n);
	for(int i=0;i<n;i++){
		cout<<"Nhap thong tin sinh vien thu "<<i+1<<"\n";
		ds[i].nhap();
		cin.ignore();
	}
	//In danh sach sinh vien thoa man
	cout<<"\nDanh sach sinh vien thoa man thi tot nghiep\n";
	bool cosinhvien=false;
	for (int i=0;i<n;i++){
		if(ds[i].sinhvienthitotnghiep()){
			ds[i].xuat();
			cosinhvien=true;
		}
	}
	if(!cosinhvien){
		cout<<"Khong co sinh vien nao thoa man thi tot nghiep";
	}
	return 0;
}






