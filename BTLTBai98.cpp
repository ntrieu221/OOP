#include <iostream>
using namespace std;

int nhonhat( float a[], int n)
{
	int gtnn = 0;
	for ( int i = 1; i < n; i++)
	{
		if ( a[i] < a[gtnn])
			gtnn = i;	
	}
	return gtnn;
}

int main()
{
	int n;
	float a[100];
	cout << "Nhap = ";
	cin >> n;
	for ( int i = 0; i < n; i++)
		cin >> a[i];
	int kq = nhonhat(a ,n);
	cout << kq;
	return 0;
}
