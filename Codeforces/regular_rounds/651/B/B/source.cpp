#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
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

		vector<int> idx[2];

		for (int i = 0; i < 2 * n; i++)
		{
			int input;

			scanf("%d", &input);

			idx[input % 2].push_back(i + 1);
		}

		int sel = 0;
		int ptr[2] = { 0, };

		for (int i = 0; i < n - 1; i++)
		{
			if (idx[sel].empty() || ptr[sel] >= idx[sel].size() - 1)
			{
				sel = !sel;
			}

			printf("%d %d\n", idx[sel][ptr[sel]], idx[sel][ptr[sel] + 1]);

			ptr[sel] += 2;
		}
	}

	return 0;
}