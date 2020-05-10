#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	long long arr[50];
	int i;
	double sol;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}

	sort(&arr[0], &arr[n]);

	sol = (double)arr[0];

	for (i = 1; i < n; i++)
	{
		sol = (sol + (double)arr[i]) / 2.0;
	}

	printf("%.7lf\n", sol);

	return 0;
}
