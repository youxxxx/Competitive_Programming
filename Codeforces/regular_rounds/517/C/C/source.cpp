#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	long long n, m;
	long long temp;
	vector<long long> v1, v2;
	long long x;
	long long i;

	scanf("%I64d %I64d", &n, &m);

	x = long long(sqrt((double)(n + m)*2.0));

	while (x*(x+1)/2 < n + m)
	{
		x++;
	}

	while (x*(x+1)/2 > n + m)
	{
		x--;
	}

	for (i = 1; i <= x; i++)
	{
		v1.push_back(i);
	}

	temp = m;

	for (i = x - 1; i >= 0; i--)
	{
		if (temp - (i + 1) >= 0)
		{
			v1.erase(v1.begin() + i);

			v2.push_back(i + 1);

			temp -= i + 1;
		}
	}

	printf("%d\n", v1.size());

	for (i = 0; i < v1.size(); i++)
	{
		printf("%I64d ", v1[i]);
	}

	printf("\n%d\n", v2.size());

	for (i = 0; i < v2.size(); i++)
	{
		printf("%I64d ", v2[i]);
	}

	return 0;
}