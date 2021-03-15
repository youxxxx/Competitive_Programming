#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	pair<int, int> arr[200001];

	for (long long tc = 0; tc < cases; tc++)
	{
		long long n, m;

		scanf("%lld %lld", &n, &m);

		for (long long i = 0; i < m; i++)
		{
			long long x, y;

			scanf("%lld %lld", &y, &x);

			arr[i] = { x,y - 1 };
		}

		if (m % 2)
		{
			printf("NO\n");

			continue;
		}

		sort(&arr[0], &arr[m]);

		long long blocked = 0;
		long long y = 0;

		string answer = "YES";

		for (long long i = 0; i < m; i++)
		{
			if (blocked)
			{
				if (!((blocked + y + arr[i].first + arr[i].second) % 2) || i < m - 1 && arr[i+1].first==arr[i].first)
				{
					answer = "NO";

					break;
				}

				blocked = 0;
			}

			else
			{
				blocked = arr[i].first;

				y = arr[i].second;
			}
		}

		printf("%s\n", answer.c_str());
	}

	return 0;
}