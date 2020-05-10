#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

#define MOD 1000000007

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	vector<pair<int, int>> arr(100000);

	for (int i = 0; i < n; i++)
	{
		int x, y;

		scanf("%d %d", &x, &y);

		arr[i] = { x,y };
	}

	if (n % 2)
	{
		printf("NO\n");

		return 0;
	}

	for (int i = 0; i < n / 2; i++)
	{
		int x1, y1;
		int x2, y2;

		x1 = arr[(i + 1) % n].first - arr[i].first;
		y1 = arr[(i + 1) % n].second - arr[i].second;
		x2 = arr[(i + n / 2 + 1) % n].first - arr[(i + n / 2) % n].first;
		y2 = arr[(i + n / 2 + 1) % n].second - arr[(i + n / 2) % n].second;

		if (x1 != -x2 || y1 != -y2)
		{
			printf("NO\n");

			return 0;
		}
	}

	printf("YES\n");

	return 0;
}