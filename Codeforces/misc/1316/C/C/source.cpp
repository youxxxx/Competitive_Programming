#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, m, p;

	scanf("%d %d %d", &n, &m, &p);

	vector<int> a, b;

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		a.push_back(input);
	}

	for (int i = 0; i < m; i++)
	{
		int input;

		scanf("%d", &input);

		b.push_back(input);
	}

	int x, y;

	for (int i = 0; i < n; i++)
	{
		if (a[i] % p)
		{
			x = i;

			break;
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (b[i] % p)
		{
			y = i;

			break;
		}
	}

	printf("%d\n", x + y);

	return 0;
}