//Bai 2:
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
		//Nap chong nhap la ham ban
		friend istream& operator>>(istream&in,Phanso&p);
		friend ostream& operator<<(ostream&on,Phanso&p);
		void rutgon();
		//Nap trong toan tu:Cach 1
		Phanso operator+(Phanso b);
		//Ve nha lam
		Phanso operator-(Phanso b);
		Phanso operator*(Phanso b);
		Phanso operator/(Phanso b);
};
istream& operator>>(istream&in,Phanso&p){
	cout<<"Nhap tu:";
	in>>p.tuso;
	do{
		cout<<"Nhap mau:";
		in>>p.mauso;
		if(p.mauso==0){
			cout<<"Mau so phai khac 0.Vui long nhap lai\n";
		}
	}while  (p.mauso==0);
	return in;//Tra ve luong nhap
}
ostream& operator<<(ostream&on,Phanso&p){
	on<<p.tuso<<"/"<<p.mauso<<endl;
}
void Phanso::rutgon(){
	int a=abs(tuso);
	int b=abs(mauso);
	while (b!=0){
		int temp=a%b;
		a=b;
		b=temp;
	}
	int ucln=a;
	tuso/=ucln;
	mauso/=ucln;
	if(mauso<0){
		tuso=-tuso;
		mauso=-mauso;
	}
}
Phanso Phanso ::operator+(Phanso b){
	//1/2+1/3=5/6
	Phanso kq;
	kq.tuso=this->tuso*b.mauso+this->mauso*b.tuso;
	kq.mauso=this->mauso*b.mauso;
	kq.rutgon();
	return kq;
}
Phanso Phanso ::operator-(Phanso b){
	Phanso kq;
	kq.tuso=this->tuso*b.mauso-this->mauso*b.tuso;
	kq.mauso=this->mauso*b.mauso;
	kq.rutgon();
	return kq;
}
Phanso Phanso ::operator*(Phanso b){
	Phanso kq;
	kq.tuso=this->tuso*b.tuso;
	kq.mauso=this->mauso*b.mauso;
	kq.rutgon();
	return kq;
}
Phanso Phanso ::operator/(Phanso b){
	Phanso kq;
	kq.tuso=this->tuso*b.mauso;
	kq.mauso=this->mauso*b.tuso;
	kq.rutgon();
	return kq;
}
int main(){
	Phanso a,b;
	cout<<"Nhap phan so a:\n";
	cin>>a;
	cout<<"Nhap phan so b:\n";
	cin>>b;
	cout<<"\nPS a:"<<a<<endl;
	cout<<"PS b:"<<b<<endl;
	Phanso tong=a+b;
	Phanso hieu=a-b;
	Phanso tich=a*b;
	Phanso thuong=a/b;
	cout<<"Tong hai phan so:"<<tong<<endl;
	cout<<"Hieu hai phan so:"<<hieu<<endl;
	cout<<"Tich hai phan so:"<<tich<<endl;
	cout<<"Thuong hai phan so:"<<thuong<<endl;
	return 0;
}





