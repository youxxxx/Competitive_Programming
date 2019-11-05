#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	double input;
	int i;
	double sol = 0.0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lf", &input);

		sol += (double)1.0 / input;
	}

	printf("%.7lf\n", (double)1.0 / sol);

	return 0;
}
