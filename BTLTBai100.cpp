#include <iostream>
#include <cmath>
using namespace std;

bool laSNT( int n)
{
	if ( n < 2) return false;
	for ( int i = 2; i < sqrt(n); i++)
	{
		if ( n % i == 0)
			return false;
	}
	return true;
}

int nguyentodau( int a[], int n)
{
	for ( int i = 0; i < n; i++)
	{
		if (laSNT(a[i]))
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
	int kq = nguyentodau(a, n);
	cout << kq;
	return 0;
}
