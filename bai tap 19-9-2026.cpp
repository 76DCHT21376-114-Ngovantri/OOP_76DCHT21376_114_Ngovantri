//Bai 5:
#include <iostream>
#include <string>
using namespace std;
class nguoi{
	protected:
		string hoten;
		int namsinh;
 	public:
 		nguoi(){
 			hoten="";
 			namsinh=0;
		 }
 		void nhap(){
 			cout<<"Nhap ho va ten:";getline(cin,hoten);
 			cout<<"Nhap nam sinh:";cin>>namsinh;
		 }
		 void xuat(){
		 	cout<<"Ho ten:"<<hoten<<"|Nam sinh:"<<namsinh<<"|";
		 }
};
class sinhvien:public nguoi{
	private:
		string masv;
		float dtb;
	public:
		sinhvien():nguoi(){
			masv="";
			dtb=0;
		}	
		void nhap(){
			nguoi::nhap();
			cin.ignore();
			cout<<"Nhap ma sinh vien:";getline(cin,masv);
			cout<<"Nhap diem trung binh:";cin>>dtb;
		}
		void xuat(){
			nguoi::xuat();
			cout<<"Ma sinh vien:"<<masv<<"|Diem trung binh:"<<dtb;
		}
		//Ham getter thuan tien cho nhiem vu tim kiem
		string getmasv(){
			return masv;
		}
		string gethoten(){
			return hoten;
		}
};
int main(){
	int n;
	cout<<"Nhap so luong sinh vien:";cin>>n;
	sinhvien*ds=new sinhvien[n];
	for (int i=0;i<n;i++){
		cout<<"Nhap thong tin sinh vien thu "<<i+1<<":\n";
		cin.ignore();
		ds[i].nhap();
	}
	string tukhoa;
	cout<<"Nhap ho ten hoac ma sinh vien de tim kiem:";
	cin.ignore();
	getline(cin,tukhoa);
	bool timthay=false;
	cout<<"---KET QUA TIM KIEM---\n";
	for(int i=0;i<n;i++){
		if(ds[i].getmasv()==tukhoa||ds[i].gethoten()==tukhoa){
			ds[i].xuat();
			timthay=true;
		}
	}
	if(!timthay){
		cout<<"Khong tim thay sinh vien phu hop\n";
	}
	delete[]ds;
	return 0;
}




