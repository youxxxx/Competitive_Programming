#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

class comp
{
	bool operator() (const pair<int,int>& a, const pair<int,int> &b) const
	{
		return a.second < b.second;
	}
};

bool func(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int> &b)
{
	return a.second < b.second;
}

bool func2(const pair<int, int>& a, pair<int, int> &b)
{
	return a.second < b.second;
}

int main()
{
	bool taken[2001] = { false };
	int power[2001];
	int t;
	int i, n, m;
	int input1, input2, temp;
	int adv = 0;
	int pr[2001] = { 0, };
	int ptr;
	vector<pair<int, int>> hero;
	vector<pair<pair<int, int>, int>> two;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= 2 * n; i++)
	{
		scanf("%d", &power[i]);

		hero.push_back(pair<int, int>(i, power[i]));
	}

	sort(hero.begin(), hero.end(), func2);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &input1, &input2);

		pr[input1] = input2;
		pr[input2] = input1;

		if (power[input1] > power[input2])
		{
			temp = input1;
			input1 = input2;
			input2 = temp;
		}

		two.push_back(pair<pair<int, int>, int>(pair<int, int>(input1, input2), power[input2] - power[input1]));
	}

	sort(two.begin(), two.end(), func);

	scanf("%d", &t);

	for (i = 0; i < n; i++)
	{
		if (t == 2)
		{
			scanf("%d", &adv);

			taken[adv] = true;
		}

		if (pr[adv] && !taken[pr[adv]])
		{
			printf("%d\n", pr[adv]);
			fflush(stdout);

			taken[pr[adv]] = true;

			continue;
		}

		if (two.size())
		{
			ptr = two.size() - 1;

			while (ptr >= 0 && (taken[two[ptr].first.first] || taken[two[ptr].first.second]))
			{
				two.erase(two.begin() + ptr--);
			}

			if (ptr != -1)
			{
				printf("%d\n", two[ptr].first.second);
				fflush(stdout);

				taken[two[ptr].first.second] = true;

				two.erase(two.begin() + ptr);
			}

			else
			{
				ptr = hero.size() - 1;

				while (ptr >= 0 && (taken[hero[ptr].first]))
				{
					hero.erase(hero.begin() + ptr--);
				}

				printf("%d\n", hero[ptr].first);
				fflush(stdout);

				taken[hero[ptr].first] = true;

				hero.erase(hero.begin() + ptr);
			}
		}

		else
		{
			ptr = hero.size() - 1;

			while (ptr >= 0 && (taken[hero[ptr].first]))
			{
				hero.erase(hero.begin() + ptr--);
			}

			printf("%d\n", hero[ptr].first);
			fflush(stdout);

			taken[hero[ptr].first] = true;

			hero.erase(hero.begin() + ptr);
		}

		if (t == 1)
		{
			scanf("%d", &adv);

			taken[adv] = true;
		}
	}

	return 0;
}