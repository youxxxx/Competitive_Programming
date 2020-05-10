#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 1; tc <= cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		set<string> state;

		string cur;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cur.push_back(j + '1');
			}
		}

		state.insert(cur);

		queue<pair<string, int>> q;

		q.push({ cur,0 });

		bool found = false;

		while (!q.empty())
		{
			string cur;
			int num;

			bool sorted = true;

			cur = q.front().first;
			num = q.front().second;
			q.pop();

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (cur[i*m + j] != i + '1')
					{
						sorted = false;

						break;
					}
				}

				if (!sorted)
				{
					break;
				}
			}



			string next;

			for (int i = 0; i < n*m - 1; i++)
			{
				for (int j = i + 1; j < n*m; j++)
				{
					for (int k = i + 1; k <= j; k++)
					{
						next.push_back(cur[k]);
					}

					for (int k = 0; k <= i; k++)
					{
						next.push_back(cur[k]);
					}

					for (int k = j + 1; k < n * m; k++)
					{
						next.push_back(cur[k]);
					}

					set<string>::iterator ret;

					ret = state.find(next);

					if (ret == state.end())
					{
						q.push({ next,num + 1 });
					}
				}
			}
		}
	}

	return 0;
}