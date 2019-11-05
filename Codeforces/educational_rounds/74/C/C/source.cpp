#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<set>

using namespace std;

int main()
{
	int tc, cases;
	int n, h;
	long long a, b;
	int i;
	int input;
	vector<int> arr;
	int cnt;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d %d", &h, &n);

		arr.clear();

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			arr.push_back(input);
		}

		if (n == 1)
		{
			printf("0\n");

			continue;
		}

		cnt = 0;

		for (i = 0; i < n - 2; i++)
		{
			if (arr[i + 1] != arr[i + 2] + 1)
			{
				cnt++;
			}

			else
			{
				i++;
			}
		}

		if (arr[n - 1] >= 2 && !((n - cnt) % 2))
		{
			cnt++;
		}

		printf("%d\n", cnt);
	}

	return 0;
}