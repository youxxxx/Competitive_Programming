#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	int cases;

	freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	if (k > 4 * n*m - 2 * n - 2 * m)
	{
		printf("NO\n");

		return 0;
	}

	if (k <= 2 * (m - 1))
	{
		int r, l;

		r = k < m - 1 ? k : m - 1;
		l = k > m - 1 ? k - (m - 1) : 0;

		printf("2\n");

		printf("%d R\n", r);

		printf("%d L\n", l);

		return 0;
	}

	if (k <= 2 * (m - 1) + 2 * m*(n - 1))
	{
		int left;

		left = k - (2 * (m - 1));
		
		vector<pair<int,string>> moves;

		moves.push_back({ m - 1,"R" });

		for (int i = 0; i < m; i++)
		{
			int d, u;

			if (!left)
			{
				break;
			}

			if (left <= 2 * (n - 1))
			{
				d = k < n - 1 ? k : n - 1;
				u = k > n - 1 ? k - (n - 1) : 0;

				moves.push_back({ d, "D" });

				if (u)
				{
					moves.push_back({ u, "U" });
				}

				moves.push_back({ m - 1 - i,"L" });

				break;
			}

			moves.push_back({ n - 1, "D" });
			moves.push_back({ n - 1, "U" });

			left -= 2 * (n - 1);

			moves.push_back({ 1,"L" });
		}
		
		printf("%d\n", moves.size());

		for (int i = 0; i < moves.size(); i++)
		{
			printf("%d %s\n", moves[i].first, moves[i].second.c_str());
		}

		return 0;
	}

	int left;

	left = k - (2 * (m - 1) + (m - 1) * 2 * (n - 1));

	vector<pair<int, string>> moves;

	moves.push_back({ m - 1,"R" });

	for (int i = 0; i < m - 1; i++)
	{
		int d, u;

		if (!left)
		{
			break;
		}

		left -= 2 * (n - 1);

		moves.push_back({ n - 1, "D" });
		moves.push_back({ n - 1, "U" });

		moves.push_back({ 1,"L" });
	}

	for (int i = 1; i < n; i++)
	{
		if (!left)
		{
			break;
		}

		moves.push_back({ 1,"D" });
		left--;

		if (!left)
		{
			break;
		}

		if (left <= (m - 1) * 2)
		{
			int r, l;

			r = left < m - 1 ? left : m - 1;
			l = left > m - 1 ? left - (m - 1) : 0;

			moves.push_back({ r, "R" });

			if (l)
			{
				moves.push_back({ l, "L" });
			}

			break;
		}

		moves.push_back({ m - 1, "R" });

		moves.push_back({ m - 1, "L" });

		left -= (m - 1) * 2;
	}

	printf("%d\n", moves.size());

	for (int i = 0; i < moves.size(); i++)
	{
		printf("%d %s\n", moves[i].first, moves[i].second.c_str());
	}

	return 0;
}