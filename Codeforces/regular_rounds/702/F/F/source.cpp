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

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		map<int, int> list;

		for (int i = 1; i <= n; i++)
		{
			int input;

			scanf("%d", &input);

			map<int, int>::iterator ret = list.find(input);

			if (ret == list.end())
			{
				list[input] = 1;
			}

			else
			{
				ret->second++;
			}
		}

		map<int, int> cnt;

		for (map<int, int>::iterator it = list.begin(); it != list.end(); it++)
		{
			map<int, int>::iterator ret = cnt.find(it->second);

			if (ret == cnt.end())
			{
				cnt[it->second] = 1;
			}

			else
			{
				ret->second++;
			}
		}

		vector<int> acc;

		acc.push_back(0);

		for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
		{
			acc.push_back(acc.back() + it->first * it->second);
		}

		int ptr = (int)acc.size() - 2;

		map<int, int>::iterator it = cnt.end(), it2;

		it2 = it;

		it2--;

		int prev = it2->first;

		int rcnt = 0;

		int sum = 0;

		int sol = 1000000000;

		while (it != cnt.begin())
		{
			it--;

			sum += (prev - it->first)*rcnt;

			sol = min(sol, acc[ptr--] + sum);

			prev = it->first;
			rcnt += it->second;
		}

		printf("%d\n", sol);
	}

	return 0;
}