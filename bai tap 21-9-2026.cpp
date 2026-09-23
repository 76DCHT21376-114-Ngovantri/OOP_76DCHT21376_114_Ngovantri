//Bai 27:
#include <iostream>
#include <cmath>
using namespace std;
int ucln(int a,int b){
	a=abs(a);
	b=abs(b);
	while(b!=0){
		int r=a%b;
		a=b;
		b=r;
	}
	return a;
}
class PS1{
	protected:
		int tuso;
		int mauso;
	public:
		PS1() {
     	   tuso = 0;
        	mauso = 1;
    	}
		void nhap(){
			cout<<"Nhap tu so:";cin>>tuso;
		do{
			cout<<"Nhap mau so:";cin>>mauso;
			if(mauso==0){
				cout<<"Loi vui long nhap lai\n";
			}
		}	while(mauso==0);
		}
		void toigian(){
			int uc=ucln(tuso,mauso);
			tuso/=uc;
			mauso/=uc;
			if(mauso<0){
				tuso=-tuso;
				mauso=-mauso;
			}
		}
		void xuat(){
			toigian();
			if(mauso==1){
				cout<<tuso;
			}else{
				cout<<tuso<<"/"<<mauso;
			}
		}
};
class PS2:public PS1{
	public:
		bool operator=(PS2 a){
			tuso=a.tuso;
			mauso=a.mauso;
			return true;
		}		
		//nap chong toan tu
		bool operator >(PS2 a){
			return tuso*a.mauso>mauso*a.tuso;//1*3>1*2=>true
		}
};
int main(){
	int n;
	do{
		cout<<"Nhap so luong phan so(max 10):";cin>>n;
		if(n<1||n>10){
			cout<<"So luong khong hop le\n";
		}
	}while (n<1||n>10);
	PS2 ds[10];
	for (int i=0;i<n;i++){
		cout<<"Nhap phan so thu "<<i+1<<":\n";
		ds[i].nhap();
	}
	//Sap xep toan tu giam dan
	for(int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if(ds[j]>ds[i]){
				PS2 temp;
				temp=ds[i];
				ds[i]=ds[j];
				ds[j]=temp;
			}
		}
	}
	cout<<"Danh sach sap xep giam dan\n";
	for (int i=0;i<n;i++){
		cout<<"Phan so "<<i+1<<":";
		ds[i].xuat();
		cout<<"\n";
	}
	return 0;
}
