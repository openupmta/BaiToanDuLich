#include<iostream>
#include<fstream>
using namespace std;
int n; //So thanh pho 
int c[100][100]; //Ma tran chi phi 
int x[100]; //chua cac thanh pho da xet
int chuaXet[100]; //cac thanh pho chua xet
int kq[100]; //luu tru duong di cho chi phi nho nhat 
int MIN = 0;//bien luu tru chi phi nho nhat cua doan duong tim dc 
int a = 1; //a =1 chua co duong nao duoc tim, a= 0 da co duong di tim dc 
void input(const char* fileName)
{

	ifstream in;
	in.open(fileName);
	if (in.fail()) cout << "Fail!!!";
	else
	{
		while (!in.eof())
		{
			in >> n;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					in >> c[i][j];
				}
			}
		}
	}

	in.close();
}
//ham nhap du lieu dauvao 
void Init() {
	input("input.txt");

	//danh dau cac thanh pho chua xet 
	x[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		chuaXet[i] = 1;
	}
}
//Ham hien thi ket ua cua thuat toan 
void output(const char* fileName)
{
	ofstream out;
	out.open(fileName);
	out << "\n Chi phi cua hanh trinh la: " << MIN<<"\n";
	out << "1 => ";
	for (int i = 2; i <= n; i++)
	{
		out <<  kq[i] << " => ";
	}

	out.close();
}
void Result()
{
	//dinh dau tien 
	cout << "\n T1=> ";
	//cac dinh tiep theo 
	for (int i = 2; i <= n; i++)
	{
		cout << "T" << kq[i] << "=>";
	}
	cout << "T1";
	//chi ohi cua ham hanh trinh 
	cout << "\n Chi phi cua hanh trinh la: " << MIN;
}

//Ham thuc hien thu cac cach chon x[i]

void NhanhCan(int i) {
	for (int j = 2; j <= n; j++) {//Xet tu thanh pho thu 2
		if (chuaXet[j]) //neu gap thanh pho chua di ua 
		{
			x[i] = j; //thu di ua thnah pho 
			chuaXet[j] = 0;//danh dau thanh pho 
			if (i == n)
			{
				//goi ham tinh toan va cap nhan can
				int S = 0; //khai bao bien de luu gia tri nhanh can 
				for (int i = 1; i <= n - 1; i++)
				{
					S = S + c[x[i]][x[i + 1]]; //chi phi = chi phi buoc trc + chi phi hien tai  
				}
				S = S + c[x[n]][1]; // Cap nhao chi phi can nhanh tu dinh cuoi den dinh xuat phat 
				if (S < MIN || a == 1) {
					a = 0;
					MIN = S;//Gan chi phi can nhanh bang chi phi hanh trinh 
					for (int i = 1; i <= n; i++)
					{
						kq[i] = x[i];//ghi nho va gan cac dinh da xet vao ket ua 
					}
				}
			}
			else
			{
				NhanhCan(i + 1);//chon tiep 
			}
			chuaXet[j] = 1;
		}
	}
}



int main()
{
	
	Init();
	
	NhanhCan(2);
	output("ouputnhanhcan.txt");
	return 0;
}