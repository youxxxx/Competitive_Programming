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

int gcd(int a, int b)
{
	while (b)
	{
		a %= b;

		int temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	vector<int> prime = { 2 };

	for (int i = 3; i < 32000; i+=2)
	{
		bool isprime = true;

		for (int j = 0; j < prime.size() && prime[j] * prime[j] <= i; j++)
		{
			if (!(i%prime[j]))
			{
				isprime = false;

				break;
			}
		}

		if (isprime)
		{
			prime.push_back(i);
		}
	}

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		int temp = n;

		vector<pair<int, int>> list;

		for (int i = 0; i < prime.size() && temp != 1; i++)
		{
			if (!(temp%prime[i]))
			{
				int cnt = 0;

				while (!(temp%prime[i]))
				{
					temp /= prime[i];

					cnt++;
				}

				list.push_back({ prime[i],cnt });
			}
		}

		if (temp != 1)
		{
			list.push_back({ temp,1 });
		}

		if (list.size() == 1)
		{
			int cur = list[0].first;

			for (int i = 0; i < list[0].second; i++)
			{
				printf("%d ", cur);

				cur *= list[0].first;
			}

			printf("\n0\n");

			continue;
		}

		if (list.size() == 2 && list[0].second == 1 && list[1].second == 1)
		{
			printf("%d %d %d\n1\n", list[0].first, list[1].first, list[0].first*list[1].first);

			continue;
		}

		vector<int> pw;

		for (int i = 0; i < list.size(); i++)
		{
			pw.push_back(0);
		}

		vector<int> sol;

		for (int i = 0; i < list.size() - 1; i++)
		{
			int cur = list[i].first;

			for (int j = 0; j < list.size(); j++)
			{
				pw[j] = 0;
			}

			pw[i] = 1;

			while (pw[i] && cur != n)
			{
				sol.push_back(cur);

				for (int j = list.size() - 1; j >= i; j--)
				{
					if (pw[j] != list[j].second)
					{
						cur *= list[j].first;

						pw[j]++;

						break;
					}

					cur /= (int)pow(list[j].first, list[j].second);

					pw[j] = 0;
				}
			}

			if (gcd(list[i + 1].first, sol.back()) == 1)
			{
				int temp = sol.back();
				sol.back() = sol[sol.size() - 2];
				sol[sol.size() - 2] = temp;
			}
		}

		for (int i = 0; i < sol.size(); i++)
		{
			printf("%d ", sol[i]);
		}

		int cur = list.back().first;

		for (int i = 0; i < list.back().second; i++)
		{
			printf("%d ", cur);

			cur *= list.back().first;
		}

		printf("%d\n0\n", n);
	}

	return 0;
}