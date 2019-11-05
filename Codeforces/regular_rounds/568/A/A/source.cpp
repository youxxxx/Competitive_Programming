#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long arr[3];
	long long i;
	long long sol1, sol2, sol;
	long long d;

	for (i = 0; i < 3; i++)
	{
		scanf("%lld", &arr[i]);
	}

	scanf("%lld", &d);

	sort(&arr[0], &arr[3]);

	sol1 = arr[1] - arr[0];
	sol2 = arr[2] - arr[1];

	sol = (sol2 > d ? 0 : d - sol2) + (sol1 > d ? 0 : d - sol1);

	printf("%lld\n", sol);

	return 0;
}