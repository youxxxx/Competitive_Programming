#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

#define MOD 1000000007

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		string s;
		char input[1000001];

		scanf("%d", &n);
		scanf("%s", input);
		s = input;

		long long sol;

		sol = s.size();

		queue<pair<pair<int, int>,int>> ptr;
		string path;
		int cursor = 0;

		path = s;

		for (int i = 0; i < n; i++)
		{
			string target;

			if (sol <= 2 * n && path[cursor] >= '2')
			{
				ptr.push({ { sol,i + 1 }, (path[cursor] - '1') });
			}

			long long add;

			add = (sol - i - 1)*(path[cursor] - '1') % MOD;

			sol = (sol + add) % MOD;

			if (ptr.empty())
			{
				++cursor;
			}

			else
			{
				if (++cursor == ptr.front().first.first)
				{
					cursor = ptr.front().first.second;

					if (--ptr.front().second == 0)
					{
						ptr.pop();
					}
				}
			}

			path.push_back(path[cursor]);
		}

		printf("%d\n", sol);
	}

	return 0;
}