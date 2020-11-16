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

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		vector<int> list[5001];
		set<int> gangs;

		int arr[5001];

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);

			gangs.insert(arr[i]);
		}

		if (gangs.size() == 1)
		{
			printf("NO\n");

			continue;
		}

		printf("YES\n");

		map<int, int> idx;
		int cnt = 0;

		for (set<int>::iterator it = gangs.begin(); it != gangs.end(); it++)
		{
			idx[*it] = cnt++;
		}

		for (int i = 1; i <= n; i++)
		{
			list[idx[arr[i]]].push_back(i);
		}
		
		int lmin = 5000;
		int lidx = 0;

		for (int i = 0; i < cnt; i++)
		{
			if (list[i].size() < lmin)
			{
				lmin = list[i].size();

				lidx = i;
			}
		}

		vector<int> other;

		for (int i = 0; i < cnt; i++)
		{
			if (i == lidx)
			{
				continue;
			}

			for (int j = 0; j < list[i].size(); j++)
			{
				other.push_back(list[i][j]);
			}
		}

		for (int i = 0; i < lmin; i++)
		{
			printf("%d %d\n", other[0], list[lidx][i]);
		}

		for (int i = 1; i < other.size(); i++)
		{
			printf("%d %d\n", other[i], list[lidx][0]);
		}
	}

	return 0;
}