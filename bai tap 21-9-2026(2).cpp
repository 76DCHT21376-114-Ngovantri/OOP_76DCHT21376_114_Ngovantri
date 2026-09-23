//Bai 30:
#include <iostream>
#include <cmath>
using namespace std;
class SP1{
	protected:
		float sothuc;
		float soao;
	public:
		SP1(float sothuc,float soao){
			this->sothuc=sothuc;
			this->soao=soao;
		}
		SP1(){
			sothuc=0;
			soao=0;
		}
		void nhap(){
			cout<<"Nhap so thuc:";cin>>sothuc;
			cout<<"Nhap so ao:";cin>>soao;
		}
		void in(){
			if(soao>=0){
				cout<<"So phuc:"<<sothuc<<"+"<<soao<<"i\n";
			}else{
				cout<<"So phuc:"<<sothuc<<"-"<<"i\n";
			}
		}
		float module(){
			return sqrt(sothuc*sothuc+soao*soao);
		}
};
class SP2:public SP1{
	public:
		//nap chong toan tu gan =
		bool operator=(SP2 a){
			sothuc=a.sothuc;
			soao=a.soao;
			return true;
		}
		//nap chong toan tu lon hon >
		bool operator>(SP2 a){
			return this->module()>a.module();
		}
};
int main(){
	int n;
	do{
		cout<<"Nhap so luong doi tuong (toi da 10):";cin>>n;
		if(n<1||n>10){
			cout<<"Sai so luong vui long nhap lai\n";
		}
	}while (n<1||n>10);
	SP2 ds[10];
	for(int i=0;i<n;i++){
		cout<<"Nhap so phuc "<<i+1<<":\n";
		ds[i].nhap();
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(ds[j]>ds[i]){
				SP2 temp;
				temp=ds[i];
				ds[i]=ds[j];
				ds[j]=temp;
			}
		}
	}
	cout<<"---DANH SACH GIAM DAN MODULE---\n";
	for (int i=0;i<n;i++){
		cout<<"So phuc "<<i+1<<":";
		ds[i].in();
		cout<<"Moldule="<<ds[i].module()<<endl;
	}
	return 0;
}





