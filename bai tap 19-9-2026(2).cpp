//Bai 16:
#include <iostream>
using namespace std;
class Monhoc{
	protected:
		string tenmon;
		float CC;
		float KT;
		float DT;
	public:
		Monhoc(){
			tenmon="";
			CC=0;
			KT=0;
			DT=0;
		}
		void nhap(){
			cout<<"Nhap ten mon:";getline(cin,tenmon);
			cout<<"Nhap diem chuyen can:";cin>>CC;
			cout<<"Nhap diem kiem tra:";cin>>KT;
			cout<<"Nhap diem thi:";cin>>DT;
		}
		void xuat(){
			cout<<"|Ten mon:"<<tenmon<<"|Diem CC:"<<CC<<"|Diem KT:"<<KT<<"|Diem thi:"<<DT<<"|";
		}
};
class Sinhvien:public Monhoc{
	private:
		string hoten;
		string lop;
		string masv;
	public:
		Sinhvien():Monhoc(){
			hoten="";
			lop="";
			masv="";
		}
		void nhap(){
			cout<<"Nhap ho va ten:";getline(cin,hoten);
			cout<<"Nhap lop:";getline(cin,lop);
			cout<<"Nhap ma sinh vien:";getline(cin,masv);
			Monhoc::nhap();
		}
		float tinhdiemhocphan(){
			return CC*0.1+KT*0.3+DT*0.6;
		}
		void xuat(){
			cout<<"Ho ten:"<<hoten<<"|Ten lop:"<<lop<<"|Ma sv:"<<masv;
			Monhoc::xuat();
			cout<<"Diem HP"<<tinhdiemhocphan();
		}
		bool bicamthi(){
			return (CC<5||KT==0);
		}
};
int main (){
	int n;
	cout<<"So sinh vien la:";cin>>n;
	Sinhvien*ds=new Sinhvien[n];
	for(int i=0;i<n;i++){
		cout<<"Thong tin sinh vien thu "<<i+1<<":\n";
		cin.ignore();
		ds[i].nhap();
	}
	bool cocamthi=false;
	for (int i=0;i<n;i++){
		if(ds[i].bicamthi()){
			ds[i].xuat();
			cocamthi=true;
		}
	}
	if(!cocamthi){
		cout<<"Khong co sinh vien nao bi cam thi\n";
	}
	delete[] ds;//Giai phong bo nho
	return 0;
}




