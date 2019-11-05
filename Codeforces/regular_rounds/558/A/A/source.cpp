#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int n, m;
	int sol;

	scanf("%d %d", &n, &m);

	if (m == 0)
	{
		sol = 1;
	}

	else if (m < n / 2)
	{
		sol = m;
	}

	else if (n - m < n / 2)
	{
		sol = n - m;
	}

	else if (m == n)
	{
		sol = 0;
	}

	else
	{
		sol = n / 2;
	}

	printf("%d\n", sol);

	return 0;
}