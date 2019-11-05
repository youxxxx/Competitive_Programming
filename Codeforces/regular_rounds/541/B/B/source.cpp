#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	vector<long long> a, b;
	int i;
	long long ai, bi;
	long long cnt = 0;
	long long prev = -1;
	long long lmax, umin, umax;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d %I64d", &ai, &bi);

		a.push_back(ai);
		b.push_back(bi);
	}

	umin = a[0] < b[0] ? a[0] : b[0];
	umax = a[0] > b[0] ? a[0] : b[0];

	cnt += umin + 1;

	if (umax - 1 > prev &&umin != umax)
	{
		prev = umax - 1;
	}

	else if (umin == umax)
	{
		prev = umax;
	}

	for (i = 1; i < n; i++)
	{
		lmax = a[i] > b[i] ? a[i] : b[i];
		umin = a[i] < b[i] ? a[i] : b[i];
		umax = a[i] > b[i] ? a[i] : b[i];

		if (umin > prev)
		{
			cnt += umin - prev;
		}

		if (umax - 1 > prev &&umin != umax)
		{
			prev = umax - 1;
		}

		else if (umin == umax)
		{
			prev = umax;
		}
	}

	printf("%I64d\n", cnt);

	return 0;
}