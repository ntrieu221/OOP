#include <iostream>
using namespace std;

int chandau( int a[], int n)
{
	for ( int i = 0; i < n; i++)
	{
		if ( a[i] % 2 == 0)
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
	int kq = chandau(a, n);
	cout << kq;
	return 0;
}
