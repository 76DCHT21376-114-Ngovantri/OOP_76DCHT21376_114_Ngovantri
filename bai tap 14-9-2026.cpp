#include <iostream>
#include <string>
using namespace std;
class nguoi{
	protected:
		string hoten;
		int namsinh;
	public:
		//yeu cau them:tao ham tao
		//ham tao khong doi
		nguoi(){hoten="",namsinh=0;}
		//ham tao co doi
		nguoi(string ht,int ns){
			this->hoten=ht;
			this->namsinh=ns;
		}
		void nhap(){
			cout<<"Nhap ho va ten:";getline(cin,hoten);
			cout<<"Nhap nam sinh:";cin>>namsinh;
		}
		void xuat(){
			cout<<"Ho ten:"<<hoten<<"|Nam sinh:"<<namsinh<<endl;
		}
};
class SinhVien:public nguoi{
	private:
		string masv;
		float diemtb;
	public:
		//Goi lai ham tao co doi cua nguoi
		SinhVien():nguoi(){
		}
		//Goi lai ham tao co doi cua nguoi
		SinhVien(string hoten,int namsinh,string msv,float dtb):nguoi(hoten,namsinh){
			this->masv=msv;
			this->diemtb=dtb;
		}
		void nhap(){
			nguoi::nhap();//goi nhap cua lop nguoi,sinh vien duoc ke thua nguoi
			cin.ignore();
			cout<<"Nhap ma sinh vien:";getline(cin,masv);
			cout<<"Nhap diem trung binh:";cin>>diemtb;
		}
		void xuat(){
			nguoi::xuat();
			cout<<"Ma sinh vien:"<<masv<<"|Diem trung binh:"<<diemtb<<endl;
		}
		//getter diem trung binh(dung de so sanh diem trung binh)
		float getDTB() const{
			return diemtb;
		}
		bool sosanh(const SinhVien&a,const SinhVien&b){
			return a.getDTB()>b.getDTB();
		}
};
int main (){
	//Tao ham co doi
	cout<<"\nHam tao co doi\n";
	SinhVien dinh("Dinh",2000,"mn01",8);
	dinh.xuat();
	int n;
	cout<<"Nhap so luong sinh vien:";
	cin>>n;
	SinhVien*ds=new SinhVien[n];
	for(int i=0;i<n;i++){
		cout<<"Nhap thong tin sinh vien thu "<<i+1<<":"<<endl;
		cin.ignore();
		ds[i].nhap();
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(ds[i].getDTB()>ds[i].getDTB()){
				SinhVien temp=ds[i];
				ds[i]=ds[j];
				ds[j]=temp;
			}
		}
	}
	cout<<"\nDanh sach sap xep sinh vien theo diem giam dan diem trung binh\n";
	for (int i=0;i<n;i++){
			cout<<i+1<<".";
			ds[i].xuat();
	}
	delete[] ds;//giai phong bo nho 
	return 0;
}




