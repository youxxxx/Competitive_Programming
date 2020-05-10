#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool func(pair<int, int> &a, pair<int, int> &b)
{
	return a.first < b.first || a.first == b.first && a.second < b.second;
}

int main()
{
	FILE *in, *out;
	int t, n, s, e;
	int i, j, k;
	long long int on, off,sol;
	int input1, input2;
	vector<pair<int, int>> laser;
	vector <pair<pair<int, int>, pair<int, int>>> cand;
	pair<int, int> dir1, dir2;
	int over0, over1;
	int x[4], y[4];

	in = fopen("replay_value.txt", "r");
	out = fopen("output.txt", "w");

	fscanf(in, "%d", &t);

	for (i = 0; i < t; i++)
	{
		fscanf(in, "%d %d %d", &n, &s, &e);

		laser.clear();
		cand.clear();

		for (j = 0; j < n; j++)
		{
			fscanf(in, "%d %d", &input1, &input2);

			laser.push_back(pair<int, int>(input1, input2));
		}

		if (n == 1)
		{
			fprintf(out, "Case #%d: 0\n", i + 1);

			continue;
		}

		sort(laser.begin(), laser.end());

		on = 0;
		off = 0;

		for (j = 1; j < n; j++)
		{
			for (k = 0; k < j; k++)
			{
				if (s < laser[j].second&&laser[j].second < laser[k].second)
				{
					dir1.first = k;
					dir1.second = 0;

					dir2.first = j;
					dir2.second = 1;

					cand.push_back(pair<pair<int, int>, pair<int, int>>(dir1, dir2));
				}

				if (s > laser[j].second&&laser[j].second > laser[k].second)
				{
					dir1.first = k;
					dir1.second = 2;

					dir2.first = j;
					dir2.second = 1;

					cand.push_back(pair<pair<int, int>, pair<int, int>>(dir1, dir2));
				}

				if (e < laser[k].second&&laser[k].second < laser[j].second)
				{
					dir1.first = k;
					dir1.second = 3;

					dir2.first = j;
					dir2.second = 0;

					cand.push_back(pair<pair<int, int>, pair<int, int>>(dir1, dir2));
				}

				if (e > laser[k].second&&laser[k].second > laser[j].second)
				{
					dir1.first = k;
					dir1.second = 3;

					dir2.first = j;
					dir2.second = 2;

					cand.push_back(pair<pair<int, int>, pair<int, int>>(dir1, dir2));
				}
			}
		}

		over0 = over1 = 0;

		for (j = 0; j < cand.size(); j++)
		{
			x[0] = cand[j].first.first;
			x[1] = cand[j].first.second;
			x[2] = cand[j].second.first;
			x[3] = cand[j].second.second;

			for (k = j + 1; k < cand.size(); k++)
			{
				y[0] = cand[k].first.first;
				y[1] = cand[k].first.second;
				y[2] = cand[k].second.first;
				y[3] = cand[k].second.second;

				if (x[0] == y[0] && x[1] == y[1]
					|| x[2] == y[2] && x[3] == y[3]
					|| x[0] == y[2] && x[1] == y[3]
					|| x[2] == y[0] && x[3] == y[1]
					)
				{
					over1++; 
				}

				if (x[0] != y[0] && x[2] != y[2]
					&& x[0] != y[2] && x[2] != y[0])
				{
					over0++;
				}
			}
		}

		sol = cand.size();
		if (n >= 3)
		{
			sol *= 4;

			sol -= over1;
		}

		if (n >= 4)
		{
			sol *= 4;

			sol -= over0;
		}

		for (j = 0; j < n - 4; j++)
		{
			sol = (sol * 4) % 1000000007;
		}

		fprintf(out, "Case #%d: %lld\n", i + 1, sol);
	}

	fclose(out);
	fclose(in);

	return 0;
}