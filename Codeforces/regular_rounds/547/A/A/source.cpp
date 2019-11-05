#include<cstdio>

using namespace std;

int main()
{
	int n, m;
	int cnt = 0;

	scanf("%d %d", &n, &m);

	if (m%n)
	{
		printf("-1\n");

		return 0;
	}

	m /= n;

	while (!(m % 2))
	{
		m /= 2;

		cnt++;
	}

	while (!(m % 3))
	{
		m /= 3;

		cnt++;
	}

	if (m!=1)
	{
		printf("-1\n");

		return 0;
	}

	printf("%d\n", cnt);

	return 0;
}