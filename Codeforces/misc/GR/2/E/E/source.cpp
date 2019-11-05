#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

int main()
{
	int n, i;
	long long input;
	long long cnt = 0;
	long long rem = 0, lmin;

	scanf("%d", &n);

	scanf("%I64d", &input);

	cnt += input / 3;

	rem = input % 3;

	for (i = 1; i < n; i++)
	{
		scanf("%I64d", &input);

		lmin = rem < input / 2 ? rem : input / 2;

		cnt += lmin;

		input -= lmin * 2;

		cnt += input / 3;

		rem = rem - lmin + input % 3;
	}

	printf("%I64d\n", cnt);

	return 0;
}