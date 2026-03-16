#include <iostream>
using namespace std;

int amdau( float a[], int n)
{
	for ( int i = 1; i < n; i++)
	{
		if ( a[i] < 0)
			return a[i];
	}
	return -1;
}

int main()
{
	int n;
	float a[100];
	cout << "Nhap n = ";
	cin >> n;
	for ( int i = 0; i < n; i++)
		cin >> a[i];
	int kq = amdau(a, n);
	cout << kq;
	return 0;
}
