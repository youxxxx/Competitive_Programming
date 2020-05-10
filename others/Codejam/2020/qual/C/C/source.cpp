#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 1; tc <= cases; tc++)
	{
		int n;
		vector<pair<pair<int, int>, int>> arr;

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			int l, r;

			scanf("%d %d", &l, &r);

			arr.push_back({ { l,r },i });
		}

		sort(arr.begin(), arr.end());

		char ch[2] = { 'C','J' };
		int cur = 0;
		int last[2] = { 0,0 };
		bool valid = true;
		vector<pair<int, int>> sol;

		for (int i = 0; i < n; i++)
		{
			if (last[cur] <= arr[i].first.first)
			{
				last[cur] = arr[i].first.second;

				sol.push_back({ arr[i].second,cur });
			}

			else if (last[!cur] <= arr[i].first.first)
			{
				cur = !cur;

				last[cur] = arr[i].first.second;

				sol.push_back({ arr[i].second,cur });
			}

			else
			{
				valid = false;

				break;
			}
		}

		if (!valid)
		{
			printf("Case #%d: IMPOSSIBLE\n", tc);
		}

		else
		{
			sort(sol.begin(), sol.end());

			printf("Case #%d: ", tc);

			for (int i = 0; i < n; i++)
			{
				printf("%c", ch[sol[i].second]);
			}

			printf("\n");
		}
	}

	return 0;
}