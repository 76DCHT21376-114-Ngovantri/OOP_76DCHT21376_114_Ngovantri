#include <iostream>
#include <vector>
using namespace std;
class matran{
	private:
		int Hang;
		int Cot;
		int a[100][100];
	public:
		void nhap(){
			cout<<"Nhap so hang:";
			cin>>Hang;
			cout<<"Nhap so cot:";
			cin>>Cot;
			cout<<"Nhap cac phan tu cua ma tran:\n";
			for (int i=0;i<Hang;i++){
				for (int j=0;j<Cot;j++){
					cout<<"a["<<i<<"]["<<j<<"]=";
					cin>>a[i][j];
				}
			}
		}
	//Phuong thuc xuat ma tran
		void xuat(){
			for (int i=0;i<Hang;i++){
				for (int j=0;j<Cot;j++){
					cout<<a[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
	friend matran congmatran(matran m1,matran m2);
};
//Ham ban(friend function)
matran congmatran(matran m1,matran m2){
	matran Ketqua;
	Ketqua.Hang=m1.Hang;
	Ketqua.Cot=m1.Cot;
	for (int i=0;i<m1.Hang;i++){
		for (int j=0;j<m1.Cot;j++){
			//Ham ban co quyen truy cap truc tiep mang a cua m1 va m2
			Ketqua.a[i][j]=m1.a[i][j]+m2.a[i][j];
		}
	}
	return Ketqua;
}
int main(){
	matran A,B,C;
	cout<<"NHAP MA TRAN A\n";
	A.nhap();
	cout<<"NHAP MA TRAN B\n";
	B.nhap();
	//Thuc hien cong 2 ma tran bang ham ban
	C=congmatran(A,B);
	cout<<"\n---------------\n";
	cout <<"Ma tran A ban dau:\n";
	A.xuat();
	cout<<"Ma tran B ban dau:\n";
	B.xuat();
	cout<<"Ma tran tong C=A+B:\n";
	C.xuat();
	return 0;
}





