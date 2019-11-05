#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	string fix[101][2];
	char status[101][2];
	bool mark[2];
	int occ[101] = { 0, };
	int i, j;
	char input[200];
	vector<string> cand;
	string str;
	string comb;
	vector<pair<int, int>> rindex;

	scanf("%d", &n);

	for (i = 0; i < n * 2 - 2; i++)
	{
		scanf("%s", input);
		str = input;
		fix[str.size()][occ[str.size()]] = str;

		rindex.push_back(pair<int, int>(str.size(), occ[str.size()]++));
	}

	if (fix[1][0] + fix[n - 1][0] == fix[n - 1][1] + fix[1][1])
	{
		cand.push_back(fix[1][0] + fix[n - 1][0]);
	}

	if (fix[1][0] + fix[n - 1][1] == fix[n - 1][0] + fix[1][1])
	{
		cand.push_back(fix[1][0] + fix[n - 1][1]);
	}

	if (fix[1][1] + fix[n - 1][0] == fix[n - 1][1] + fix[1][0])
	{
		cand.push_back(fix[1][1] + fix[n - 1][0]);
	}

	if (fix[1][1] + fix[n - 1][1] == fix[n - 1][0] + fix[1][0])
	{
		cand.push_back(fix[1][1] + fix[n - 1][1]);
	}

	if (cand.size() == 1)
	{
	}

	else
	{
		for (i = 2; i < (n + 1) / 2; i++)
		{
			mark[0] = mark[1] = false;

			comb = fix[i][0] + fix[n - i][0];

			if (comb == fix[n - i][1] + fix[i][1])
			{
				for (j = 0; j < cand.size(); j++)
				{
					if (comb == cand[j])
					{
						mark[j] = true;

						break;
					}
				}
			}

			comb = fix[i][0] + fix[n - i][1];

			if (comb == fix[n - i][0] + fix[i][1])
			{
				for (j = 0; j < cand.size(); j++)
				{
					if (comb == cand[j])
					{
						mark[j] = true;

						break;
					}
				}
			}

			comb = fix[i][1] + fix[n - i][0];

			if (comb == fix[n - i][1] + fix[i][0])
			{
				for (j = 0; j < cand.size(); j++)
				{
					if (comb == cand[j])
					{
						mark[j] = true;

						break;
					}
				}
			}

			comb = fix[i][1] + fix[n - i][1];

			if (comb == fix[n - i][0] + fix[i][0])
			{
				for (j = 0; j < cand.size(); j++)
				{
					if (comb == cand[j])
					{
						mark[j] = true;

						break;
					}
				}
			}

			for (j = cand.size() - 1; j >= 0; j--)
			{
				if (mark[j] == false)
				{
					cand.erase(cand.begin() + j);
				}
			}

			if (cand.size() == 1)
			{
				break;
			}
		}

		if (!(n % 2))
		{
			comb = fix[n / 2][0] + fix[n / 2][1];

			for (j = 0; j < cand.size(); j++)
			{
				if (comb == cand[j])
				{
					mark[j] = true;

					break;
				}
			}

			comb = fix[n / 2][1] + fix[n / 2][0];

			for (j = 0; j < cand.size(); j++)
			{
				if (comb == cand[j])
				{
					mark[j] = true;

					break;
				}
			}

			for (j = cand.size() - 1; j >= 0; j--)
			{
				if (mark[j] == false)
				{
					cand.erase(cand.begin() + j);
				}
			}
		}
	}

	for (i = 1; i < (n + 1) / 2; i++)
	{
		comb = fix[i][0] + fix[n - i][0];

		if (comb == fix[n - i][1] + fix[i][1] && comb == cand[0])
		{
			status[i][0] = 'P';
			status[n - i][0] = 'S';
			status[n - i][1] = 'P';
			status[i][1] = 'S';

			continue;
		}
		
		comb = fix[i][0] + fix[n - i][1];

		if (comb == fix[n - i][0] + fix[i][1] && comb == cand[0])
		{
			status[i][0] = 'P';
			status[n - i][1] = 'S';
			status[n - i][0] = 'P';
			status[i][1] = 'S';

			continue;
		}

		comb = fix[i][1] + fix[n - i][0];

		if (comb == fix[n - i][1] + fix[i][0] && comb == cand[0])
		{
			status[i][1] = 'P';
			status[n - i][0] = 'S';
			status[n - i][1] = 'P';
			status[i][0] = 'S';

			continue;
		}

		comb = fix[i][1] + fix[n - i][1];

		if (comb == fix[n - i][0] + fix[i][0] && comb == cand[0])
		{
			status[i][1] = 'P';
			status[n - i][1] = 'S';
			status[n - i][0] = 'P';
			status[i][0] = 'S';

			continue;
		}
	}

	if (!(n % 2))
	{
		comb = fix[n / 2][0] + fix[n / 2][1];

		if (comb == cand[0])
		{
			status[n - i][0] = 'P';
			status[n - i][1] = 'S';
		}

		else
		{
			status[n - i][1] = 'P';
			status[n - i][0] = 'S';
		}
	}

	for (i = 0; i < n * 2 - 2; i++)
	{
		printf("%c", status[rindex[i].first][rindex[i].second]);
	}

	return 0;
}