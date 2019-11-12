#include<iostream>
#include<fstream>
using namespace std;
int n; //So thanh pho 
int c[100][100]; //Ma tran chi phi 
int daXet[100]; //cac thanh pho chua xet
int tour[100];
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

int GTS(int dDau)
{
	int v,
		k,
		w;
	int mini;
	int cost;
	for (k = 1; k <= n; k++)
	{
		daXet[k] = 0;
	}
	cost = 0;
	int i;
	v = dDau;
	i = 1;
	tour[i] = v;
	daXet[v] = 1;
	while (i < n)
	{
		mini = INT_MAX;
		for (int k = 1; k <= n; k++)
		{
			if (!daXet[k])
			{
				if (mini > c[v][k])
				{
					mini = c[v][k];
					w = k;
				}
			}
		}
		v = w;
		i++;
		tour[i] = v;
		daXet[v] = 1;
		cost += mini;
	}
	cost += c[v][dDau];
	return cost;

	
}

void output(const char* fileName)
{
	ofstream out;
	out.open(fileName);
	
	
	out << "Tong chi phi : " << GTS(1)<<"\n";
	out << "1 => ";
	for (int i = 2; i <= n; i++)
	{
		out << tour[i] << " => ";
	}
	out.close();
}
int main()
{
	input("input.txt");
	output("outputthamlam.txt");
	return 0;
}