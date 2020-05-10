#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	int m;

	m = (int)(double)n / 1.08;

	if ((int)((double)m *1.08) == n)
	{
		printf("%d\n", m);

		return 0;
	}

	if ((int)((double)(m + 1) *1.08) == n)
	{
		printf("%d\n", m + 1);

		return 0;
	}

	printf(":(\n");

	return 0;
}