#include <iostream>
using namespace std;

int tontaikhong( int a[], int n)
{
	for ( int i = 0; i < n; i++)
	{
		if ( a[i] == 0)
			return -1;
	}
	return 0;
}

int main()
{
	int n;
	int a[100];
	cout << "Nhap n = ";
	cin >> n;
	for ( int i = 0; i < n; i++)
		cin >> a[i];
	cout << tontaikhong(a , n);
	return 0;
}
