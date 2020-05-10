#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	//freopen("input.txt", "r", stdin);

	int cnt[100001] = { 0, };
	vector<int> loc[100001];
	int one[2], two[2];
	vector<vector<int>> arr;
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n - 2; i++)
	{
		int a, b, c;
		vector<int> cur;

		scanf("%d %d %d", &a, &b, &c);

		loc[a].push_back(i);
		loc[b].push_back(i);
		loc[c].push_back(i);

		cur.push_back(a);
		cur.push_back(b);
		cur.push_back(c);

		cnt[a]++;
		cnt[b]++;
		cnt[c]++;

		arr.push_back(cur);
	}

	int optr = 0, tptr = 0;

	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == 1)
		{
			one[optr++] = i;
		}

		else if (cnt[i] == 2)
		{
			two[tptr++] = i;
		}
	}

	vector<int> sol;

	sol.push_back(one[0]);

	int ptr;

	ptr = loc[one[0]][0];

	for (int i = 0; i < 3; i++)
	{
		if (arr[ptr][i] == one[0])
		{
			arr[ptr].erase(arr[ptr].begin() + i);

			break;
		}
	}

	int next;

	int nptr;

	int other;

	for (int i = 0; i < 2; i++)
	{
		if (arr[ptr][i] == two[0] || arr[ptr][i] == two[1])
		{
			if (arr[ptr][i] == two[0])
			{
				next = two[0];

				other = two[1];
			}

			else
			{
				next = two[1];

				other = two[0];
			}

			break;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < loc[arr[ptr][i]].size(); j++)
		{
			if (loc[arr[ptr][i]][j] == ptr)
			{
				loc[arr[ptr][i]].erase(loc[arr[ptr][i]].begin() + j);

				break;
			}
		}
	}

	nptr = loc[next][0];

	int right = loc[one[1]][0];
	int right_two;

	for (int i = 0; i < 3; i++)
	{
		if (arr[right][i] == other)
		{
			for (int j = 0; j < loc[arr[right][i]].size(); j++)
			{
				if (loc[arr[right][i]][j] == right)
				{
					loc[arr[right][i]].erase(loc[arr[right][i]].begin() + j);

					break;
				}
			}
		}
	}

	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < loc[arr[ptr][j]].size(); i++)
		{
			if (loc[arr[ptr][j]][i] == ptr)
			{
				loc[arr[ptr][j]].erase(loc[arr[ptr][j]].begin() + i);

				break;
			}
		}
	}

	ptr = nptr;

	int num;

	num = next;

	for (int k = 1; k < n - 2; k++)
	{
		sol.push_back(num);

		for (int i = 0; i < arr[ptr].size(); i++)
		{
			if (arr[ptr][i] == num)
			{
				arr[ptr].erase(arr[ptr].begin() + i);

				break;
			}
		}

		for (int i = 0; i < arr[ptr].size(); i++)
		{
			num = arr[ptr][i];

			for (int j = 0; j < loc[num].size(); j++)
			{
				if (loc[num][j] == ptr)
				{
					if (loc[num].size() == 2)
					{
						next = num;

						int k;

						k = 1 - j;

						nptr = loc[num][k];
					}

					loc[num].erase(loc[num].begin() + j);

					break;
				}
			}
		}

		num = next;
		ptr = nptr;
	}

	sol.push_back(other);
	sol.push_back(one[1]);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", sol[i]);
	}

	return 0;
}