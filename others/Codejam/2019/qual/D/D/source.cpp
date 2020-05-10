#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t, z;
	int n, b, f;
	int i, j;
	int ub;
	string query, answer, pad;
	char input[2048];
	vector<int> count[2], sol;
	int idx;
	int bit, len;
	int cnt;
	int off;
	int verdict;
	char prev;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d %d", &n, &b, &f);

		ub = (n + 15) / 16 * 16;

		len = 16;

		bit = 0;

		for (i = 0; i < n; i++)
		{
			query.push_back('0' + bit);

			if (!((i + 1) % len))
			{
				bit = !bit;
			}
		}

		for (i = n; i < ub; i++)
		{
			pad.push_back('0' + bit);

			if (!((i + 1) % len))
			{
				bit = !bit;
			}
		}

		printf("%s\n", query.c_str());
		fflush(stdout);

		scanf("%s", input);
		answer = input;
		answer += pad;

		cnt = 0;

		prev = '0';

		for (i = 0; i < ub - b; i++)
		{
			if (answer[i] != prev)
			{
				count[0].push_back(cnt);

				cnt = 0;

				prev = answer[i];
			}

			cnt++;
		}

		count[0].push_back(cnt);

		len /= 2;

		idx = 0;

		query.clear();
		pad.clear();

		while (len)
		{
			idx = !idx;

			bit = 0;

			for (i = 0; i < n; i++)
			{
				query.push_back('0' + bit);

				if (!((i + 1) % len))
				{
					bit = !bit;
				}
			}

			for (i = n; i < ub; i++)
			{
				pad.push_back('0' + bit);

				if (!((i + 1) % len))
				{
					bit = !bit;
				}
			}

			printf("%s\n", query.c_str());
			fflush(stdout);

			scanf("%s", input);
			answer = input;
			answer += pad;

			cnt = 0;
			off = 0;

			for (i = 0; i < ub/len/2; i++)
			{
				count[idx].push_back(0);
				count[idx].push_back(0);

				for (j = 0; j < count[!idx][i]; j++)
				{
					if (answer[off + j] == '0')
					{
						count[idx][i * 2]++;
					}

					else
					{
						count[idx][i * 2 + 1]++;
					}
				}

				off += count[!idx][i];
			}

			len /= 2;

			count[!idx].clear();
			query.clear();
			pad.clear();
		}

		for (i = 0; i < n; i++)
		{
			if (!count[0][i])
			{
				sol.push_back(i);
			}
		}

		for (i = 0; i < b; i++)
		{
			printf("%d ", sol[i]);
		}

		printf("\n");
		fflush(stdout);

		scanf("%d", &verdict);

		if (verdict == -1)
		{
			return 0;
		}

		count[0].clear();
		sol.clear();
	}

	return 0;
}