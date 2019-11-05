#include<iostream>
using namespace std;
int main()
{

	long long n, m, sk = 0, str;
	cin >> n >> m;
	long long *a, *b;
	a = new long long[n];
	b = new long long[n];
	memset(b, 0, n);
	for (int i = 0; i < n; ++i)
	{

		cin >> a[i];
	}
	long long currspace = m;

	for (int i = 0; i < n; ++i)
	{
		if (a[i]<currspace)
		{
			currspace -= a[i];
			b[i] = 0;

		}

		else if (a[i] >= currspace)
		{
			a[i] -= currspace;
			b[i] = a[i] / m + 1;
			currspace = m - (a[i] % m);
		}
	}
	for (int i = 0; i < n; ++i)
	{

		cout << b[i] << " ";
	}






	return 0;
}