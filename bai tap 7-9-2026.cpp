//Bai 1:
#include <iostream>
#include <cmath>
using namespace std;
//Cau 1:Khai bao lop
class Phanso{
	private:
		int tuso;
		int mauso;
	public:
		//Ham tao khong doi
		Phanso(){
			tuso=0;
			mauso=1;
		}
		//Ham tao co doi(constructor)
		Phanso(int tu,int mau){
			this->tuso=tu;
			this->mauso=mau;
		}
		//Ham huy (destrucstor)
		~Phanso(){
			//Ham huy tu dong giai phong khi doi tuong ket thuc
		}
//Cau 2:Xay dung nhap,xuat,...
		void nhap();
		void xuat();
		void rutgon();
		void cong(Phanso b);
		//Ve nha lam
		void tru(Phanso b);
		void nhan(Phanso b);
		void chia(Phanso b);
};
void Phanso ::nhap(){
	cout<<"Nhap tu:";
	cin>>tuso;
	cout<<"Nhap mau:";
	cin>>mauso;
	if(mauso==0){
		cout<<"Loi mau so phai khac 0\n";
	}
}
void Phanso ::xuat(){
	cout<<tuso<<"/"<<mauso<<endl;
}
void Phanso ::rutgon(){
	int a=abs(tuso);
	int b=abs(mauso);
	while(b!=0){
		int temp=a%b;
		a=b;
		b=temp;
	}
	int ucln=a;
	if(ucln>0){
		tuso/=ucln;
		mauso/=ucln;
	}
	if(mauso<0){
		tuso=-tuso;
		mauso=-mauso;
	}
}
void Phanso ::cong(Phanso b){
	//1/2+1/3=5/6
	Phanso kq;
	kq.tuso=this->tuso*b.mauso+this->mauso*b.tuso;
	kq.mauso=mauso*b.mauso;
	kq.rutgon();
	kq.xuat();
}
void Phanso ::tru(Phanso b){
	Phanso kq;
	kq.tuso=this->tuso*b.mauso-this->mauso*b.tuso;
	kq.mauso=mauso*b.mauso;
	kq.rutgon();
	kq.xuat();
}
void Phanso ::nhan(Phanso b){
	Phanso kq;
	kq.tuso=this->tuso*b.tuso;
	kq.mauso=this->mauso*b.mauso;
	kq.rutgon();
	kq.xuat();
}
void Phanso ::chia(Phanso b){
	Phanso kq;
	if(b.mauso==0){
		cout<<"Khong the chia\n";
	}
	kq.tuso=this->tuso*b.mauso;
	kq.mauso=this->mauso*b.tuso;
	kq.rutgon();
	kq.xuat();
}
//Cau 3:
int main(){
	Phanso a,b;
	cout<<"Nhap phan so a\n";
	a.nhap();
	cout<<"Nhap phan so b\n";
	b.nhap();
	cout<<"Phan so a:";
	a.xuat();
	cout<<"Phan so b:";
	b.xuat();
	cout<<"Tong hai phan so la:";
	a.cong(b);
	cout<<"Hieu hai phan so la:";
	a.tru(b);
	cout<<"Tich hai phan so la:";
	a.nhan(b);
	cout<<"Hieu hai phan so la:";
	a.chia(b);
	return 0;
}





