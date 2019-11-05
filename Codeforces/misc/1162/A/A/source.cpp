#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int n, h, m;
	vector<int> height;
	int i, j;
	int sum = 0;
	int l, r, x;

	scanf("%d %d %d", &n, &h, &m);

	for (i = 0; i <= n; i++)
	{
		height.push_back(h);
	}
	
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &l, &r, &x);

		for (j = l; j <= r; j++)
		{
			if (x < height[j])
			{
				height[j] = x;
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		sum += height[i] * height[i];
	}

	printf("%d\n", sum);

	return 0;
}