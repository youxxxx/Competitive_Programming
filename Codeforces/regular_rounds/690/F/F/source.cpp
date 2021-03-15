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

#define N 200000

/*
void addl(int idx, int val)
{
	for (; idx <= N * 2; idx += (-idx)&idx)
	{
		lefta[idx] += val;
	}
}

int getl(int idx)
{
	int rvalue = 0;

	for (; idx; idx -= (-idx)&idx)
	{
		rvalue += lefta[idx];
	}

	return rvalue;
}

int psuml(int r, int l)
{
	return getl(r) - getl(l);
}

void addr(int idx, int val)
{
	for (; idx <= N * 2; idx += (-idx)&idx)
	{
		righta[idx] += val;
	}
}

int getr(int idx)
{
	int rvalue = 0;

	for (; idx; idx -= (-idx)&idx)
	{
		rvalue += righta[idx];
	}

	return rvalue;
}

int psumr(int r, int l)
{
	return getr(r) - getr(l);
}
*/

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		//list.clear();
		//map<int, int> idx;
		pair<int,int> list[N * 2 + 1];

		int n;

		scanf("%d", &n);

		/*
		for (int i = 1; i <= n * 2; i++)
		{
			lefta[i] = righta[i] = 0;
		}
		*/

		pair<int, int> raw[N + 1];

		for (int i = 0; i < n; i++)
		{
			int l, r;

			scanf("%d %d", &l, &r);

			list[i * 2] = { l ,i * 2 };
			list[i * 2 + 1] = { r, i * 2 + 1 };

			raw[i] = { l,r };
		}

		/*
		for (set<int>::iterator it = list.begin(); it != list.end(); it++)
		{
			idx[*it] = cnt++;
		}
		*/

		sort(&list[0], &list[2 * n]);

		int prev = -1;
		int cnt = 0;

		pair<int, int> arr[N + 1];

		for (int i = 0; i < 2 * n; i++)
		{
			if (list[i].first != prev)
			{
				prev = list[i].first;

				cnt++;
			}

			if (list[i].second % 2)
			{
				arr[list[i].second / 2].second = cnt;
			}

			else
			{
				arr[list[i].second / 2].first = cnt;
			}
		}

		/*
		for (int i = 0; i < n; i++)
		{
			arr[i] = { idx[raw[i].first],idx[raw[i].second] };

			addl(arr[i].first, 1);
			addr(arr[i].second, 1);
		}
		*/

		int larr[N * 2 + 1];
		int rarr[N * 2 + 1];

		for (int i = 0; i <= cnt; i++)
		{
			larr[i] = rarr[i] = 0;
		}

		int lefta[N * 2 + 2];
		int righta[N * 2 + 2];

		lefta[0] = righta[0] = 0;

		for (int i = 0; i < n; i++)
		{
			//arr[i] = { idx[raw[i].first],idx[raw[i].second] };

			larr[arr[i].first]++;
			rarr[arr[i].second]++;
		}

		for (int i = 1; i < cnt; i++)
		{
			lefta[i] = lefta[i - 1] + larr[i];
			righta[i] = righta[i - 1] + rarr[i];
		}

		int lmin = n - 1;

		for (int i = 0; i < n; i++)
		{
			const int l = arr[i].first;
			const int r = arr[i].second;

			/*
			const int lcnt = getr(l - 1);
			const int rcnt = psuml(cnt, r);
			*/

			const int lcnt = righta[l - 1];
			const int rcnt = lefta[cnt - 1] - lefta[r];

			lmin = min(lmin, lcnt + rcnt);
		}

		printf("%d\n", lmin);
	}

	return 0;
}