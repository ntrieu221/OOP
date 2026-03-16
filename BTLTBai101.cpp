#include <iostream>
using namespace std;

bool laSoHoanThien(int n)
{
	int S = 0;
	for ( int i = 1; i < n; i++)
	{
		if ( n % i == 0)
			S+=i;
	}
	if ( S == n)
		return true;
	else
		return false;
}

int SoHoanThienDau( int a[], int n)
{
	for ( int i = 0; i < n;i++)
	{
		if (laSoHoanThien(a[i]))
			return a[i];
	}
	return -1;
}

int main()
{
	int n;
	int a[100];
	cout << "Nhap n = ";
	cin >> n;
	for ( int i = 0; i < n; i++)
		cin >> a[i];
	int kq = SoHoanThienDau(a, n);
	cout << kq;
	return 0;
}
