/* Viết chương trình nhập vào một mảng hai chiều các số nguyên, tìm các phần tử lớn thứ k của mảng (k được nhập từ
bàn phím, các phần tử có giá trị bằng nhau thì cùng nằm một cấp) */

#include<iostream>
using namespace std;

void fNhapMang(int a[20][20], int& m, int& n);
void fXuatMang(int a[20][20], int& m, int& n);
int fXuLiLuaChon();
void fChuyenMang2DThanh1D(int a[20][20], int& m, int& n, int b[], int& soLuong);
int fPhanTuLonThu_k(int a[20][20], int& m, int& n, int b[], int& soLuong, int k, int i_index[], int j_index[], int& count);
void fSapXepGiamDanMang1D(int b[], int& soLuong);
void fDoiViTri(int& a, int& b);
void fQuyDoiViTri(int a[20][20], int& m, int& n, int& STT, int giaTri, int i_index[], int j_index[], int& count);

int main()
{
	int Lenh = 1;
	while (Lenh != 0)
	{
		int a[20][20], m = 0, n = 0, i_index[200], j_index[200], count = 0, b[200], soLuong = 0;
		system("cls");
		fNhapMang(a, m, n);
		fXuatMang(a, m, n);
		fChuyenMang2DThanh1D(a, m, n, b, soLuong);
		fSapXepGiamDanMang1D(b, soLuong);
		int k;
		cout << "Nhap so k: "; cin >> k;
		while (cin.fail() || k <= 0 || k > m * n)
		{
			cin.clear(); cin.ignore();
			cout << "Nhap so k: "; cin >> k;
		}
		int check = fPhanTuLonThu_k(a, m, n, b, soLuong, k, i_index, j_index, count);
		if (check == 0)
		{
			cout << "Khong co phan tu nao lon thu " << k << endl;
		}
		else
		{
			cout << "Phan tu lon thu " << k << " co gia tri " << a[i_index[0]][j_index[0]] << ", nam o vi tri: " << "\t";
			for (int i = 0; i < count; i++)
			{
				cout << i_index[i] << "x" << j_index[i] << "\t";
			}
			cout << endl;
		}
		Lenh = fXuLiLuaChon();
	}	
}

int fXuLiLuaChon()
{
	char select;
	cout << "Ban co muon tiep tuc [Y/n]: "; cin >> select;
	while (cin.fail() || (select != 'Y' && select != 'y' && select != 'N' && select != 'n'))
	{
		cin.clear(); cin.ignore();
		cout << "Ban co muon tiep tuc [Y/n]: "; cin >> select;
	}
	if (select == 'Y' || select == 'y') { return 1; }
	else { return 0; }
}
void fNhapMang(int a[20][20], int& m, int& n)
{
	cout << "Nhap so dong: "; cin >> m;
	cout << "Nhap so cot: "; cin >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "] = "; cin >> a[i][j];
			while (cin.fail())
			{
				cin.clear(); cin.ignore();
				cout << "a[" << i << "][" << j << "] = "; cin >> a[i][j];
			}
		}
		cout << endl;
	}
	cout << endl;
}
void fXuatMang(int a[20][20], int& m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
void fChuyenMang2DThanh1D(int a[20][20], int& m, int& n, int b[], int& soLuong)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[soLuong] = a[i][j];
			soLuong += 1;
		}
	}
}
void fSapXepGiamDanMang1D(int b[], int& soLuong)
{
	for (int i = 0; i < soLuong; i++)
	{
		for (int j = i + 1; j < soLuong; j++)
		{
			if (b[i] < b[j]) { fDoiViTri(b[i], b[j]); }
		}
	}
}
void fDoiViTri(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int fPhanTuLonThu_k(int a[20][20], int& m, int& n, int b[], int& soLuong, int k, int i_index[], int j_index[], int& count)
{
	int dem = 0, STT = 1;
	for (int i = 1; i <= k; i++)
	{
		if (i > k) { return 0; }
		int giaTri = b[dem];
		for (int j = dem; j < soLuong; j++)
		{
			if (i == k)
			{
				fQuyDoiViTri(a, m, n, STT, giaTri, i_index, j_index, count);
				STT = STT + 1;
			}
			if (giaTri != b[j])
			{
				dem = j;
				break;
			}
		}
	}
}
void fQuyDoiViTri(int a[20][20], int& m, int& n, int& STT, int giaTri, int i_index[], int j_index[], int& count)
{
	int dem = 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == giaTri)
			{
				if (dem == STT)
				{
					i_index[count] = i;
					j_index[count] = j;
					count += 1;
					dem = dem + 1;
				}
				else { dem = dem + 1; }
			}
		}
	}
}