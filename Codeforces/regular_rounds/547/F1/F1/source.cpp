#include<cstdio>
#include<vector>
#include<set>

using namespace std;

int main()
{
	int n;
	int i, j, k;
	vector<int> arr;
	vector<pair<int,int>> temp, mlist;
	int input;
	int lmax = 0, lmin = 0;
	int smax = 0, smin = 0;
	int psum[1501];
	int off, idx;
	int maxcnt = 0, cnt = 0;
	set<int> pws;
	set<int>::iterator it;

	psum[0] = 0;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &input);

		psum[i] = psum[i - 1] + input;

		/*

		smax += input;
		smin += input;

		if (smax < 0)
		{
			smax = 0;
		}

		if (smin > 0)
		{
			smin = 0;
		}

		if (smax > lmax)
		{
			lmax = smax;
		}

		if (smin < lmin)
		{
			lmin = smin;
		}
		*/
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < i; j++)
		{
			pws.insert(psum[i] - psum[j]);
		}
	}

	for (it = pws.begin(); it != pws.end(); it++)
	{
		off = idx = cnt = 0;

		for (j = 1; j <= n; j++)
		{
			for (k = idx; k < j; k++)
			{
				if (psum[j] - psum[k] == *it)
				{
					cnt++;

					idx = j;

					temp.push_back(pair<int, int>(k + 1, j));

					break;
				}
			}
		}

		if (cnt > maxcnt)
		{
			maxcnt = cnt;

			mlist = temp;
		}

		temp.clear();
	}

	printf("%d\n", maxcnt);

	for (i = 0; i < maxcnt; i++)
	{
		printf("%d %d\n", mlist[i].first, mlist[i].second);
	}

	return 0;
}