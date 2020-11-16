#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
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
		int cnt[26] = { 0, };

		char input;

		scanf("%c", &input);

		do
		{
			scanf("%c", &input);

			cnt[input - 'a']++;
		} while (input != 10);

		scanf("%d", &n);

		int arr[1226];
		bool visited[1226];
		int left = n;

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);

			visited[i] = false;
		}

		vector<int> zero;
		vector<int> taken[26];

		for (int i = 0; i < n; i++)
		{
			if (!arr[i])
			{
				zero.push_back(i);

				visited[i] = true;

				left--;
			}
		}

		int ptr = 25;

		char sol[1226];

		sol[n] = 0;

		while (cnt[ptr--] < zero.size());

		const int start = ptr + 1;

		vector<int> list[2];

		for (int i = 0; i < zero.size(); i++)
		{
			sol[zero[i]] = start + 'a';

			taken[start].push_back(i);

			list[0].push_back(zero[i]);
		}

		int tot[26] = { 0, };
		int bit = 1;

		while (left)
		{
			list[bit] = list[!bit];
			int subptr = 0;
			int val = 0;

			for (int i = 0; i < list[bit].size(); i++)
			{
				val += list[!bit][i] + 1;
			}

			for (int i = 0; i < n; i++)
			{
				val -= list[!bit].size() - subptr * 2;

				while (subptr < list[!bit].size() && list[!bit][subptr] <= i)
				{
					subptr++;
				}

				if (!visited[i])
				{
					if (val == arr[i])
					{
						list[bit].push_back(i);

						taken[ptr].push_back(i);

						left--;

						visited[i] = true;

						tot[ptr]++;
					}
				}
			}

			sort(list[bit].begin(), list[bit].end());

			bit = !bit;
			ptr--;
		}

		ptr = start - 1;
		int ptr2 = start - 1;

		while (ptr >= 0 && ptr2 >= 0)
		{
			while (tot[ptr] > cnt[ptr2])
			{
				ptr2--;
			}

			for (int i = 0; i < taken[ptr].size(); i++)
			{
				sol[taken[ptr][i]] = ptr2 + 'a';
			}

			ptr--;
			ptr2--;
		}

		printf("%s\n", sol);
	}

	return 0;
}