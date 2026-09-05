//Bai 6:
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//Cau 1:Khai bao lop
class SinhVien{
	private:
		string hoten;
		int namsinh;
		float diem[5];
	public:
//Cau 2:Xay dung cac phuong thuc
		void nhap(){
			cout<<"Nhap ho va ten:";
			getline(cin,hoten);
			cout<<"Nhap nam sinh:";
			cin>>namsinh;
			cout<<"Nhap diem 5 mon hoc:\n";
			for (int i=0;i<5;i++){
				cout <<"Mon "<<i+1<<":";
				cin>>diem[i];
			}
		}
		float diemtrungbinh(){
			float tong=0;
			for(int i=0;i<5;i++){
				tong+=diem[i];
			}
			return tong/5;
		}
		void xuat(){
			cout<<"Ho va ten:"<<hoten
				<<"|Nam sinh"<<namsinh
				<<"|Diem trung binh"<<diemtrungbinh()<<endl;
		}
		bool comonthilai(){
			for (int i=0;i<5;i++){
				if(diem[i]<5.0){
					return true;
				}
			}
			return false;
		}
		void inmonthilai(){
			if(comonthilai()){
				cout<<"Sinh vien:"<<hoten<<endl;
				cout<<"Cac mon phai thi lai:\n";
				for (int i=0;i<5;i++){
					if(diem[i]<5.0){
						cout<<"Mon "<<i+1<<":"<<diem[i]<<"diem\n";
					}
				}
			}
		}
};
//Cau 3:Nhap n sinh vien va in
int main (){
	int n;
	cout<<"Nhap so luong sinh vien:";
	cin>>n;
	cin.ignore();
	vector<SinhVien> ds(n);
	for (int i=0;i<n;i++){
		cout<<"Nhap thong tin sinh vien thu:"<<i+1<<"\n";
		ds[i].nhap();
		cout<<"Danh sach sinh vien phai thi lai\n";
		bool cothilai=false;
		for (int i=0;i<n;i++){
			if(ds[i].comonthilai()){
				ds[i].inmonthilai();
				cothilai=true;
			}
		}
		if(!cothilai){
			cout<<"Khong co sinh vien nao thi lai"; 
		}
	}
	return 0;
}






