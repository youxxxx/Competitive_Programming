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

	for (int tc = 0; tc < cases; tc++)
	{
		vector<string> sol;
		int n, m;

		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++)
		{
			string cur;

			for (int j = 0; j < m; j++)
			{
				cur.push_back('B');
			}

			sol.push_back(cur);
		}

		sol[n - 1][m - 1] = 'W';

		for (int i = 0; i < n; i++)
		{
			printf("%s\n", sol[i].c_str());
		}
	}

	return 0;
}