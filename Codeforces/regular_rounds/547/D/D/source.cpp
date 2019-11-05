#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	char input[150001];
	int n;
	int i, j;
	string a, b;
	int acnt[26] = { 0, };
	int bcnt[26] = { 0, };
	vector<int> aloc[26], bloc[26];
	vector<int> aqloc, bqloc;
	int aleft = 0, bleft = 0;
	int aq = 0, bq = 0;
	int lmin;
	int cnt = 0;
	vector<pair<int, int>> sol;
	pair<int, int> cur;


	scanf("%d", &n);

	scanf("%s", input);
	a = input;
	scanf("%s", input);
	b = input;

	for (i = 0; i < n; i++)
	{
		if (a[i] >= 'a'&&a[i] <= 'z')
		{
			acnt[a[i] - 'a']++;

			aloc[a[i] - 'a'].push_back(i + 1);
		}

		else
		{
			aq++;

			aqloc.push_back(i + 1);
		}

		if (b[i] >= 'a'&&b[i] <= 'z')
		{
			bcnt[b[i] - 'a']++;

			bloc[b[i] - 'a'].push_back(i + 1);
		}

		else
		{
			bq++;

			bqloc.push_back(i + 1);
		}
	}

	for (i = 0; i < 26; i++)
	{
		lmin = acnt[i] < bcnt[i] ? acnt[i] : bcnt[i];

		cnt += lmin;

		for (j = 0; j < lmin; j++)
		{
			cur = pair<int, int>(aloc[i].back(), bloc[i].back());
			sol.push_back(cur);

			aloc[i].pop_back();
			bloc[i].pop_back();
		}

		acnt[i] -= lmin;
		bcnt[i] -= lmin;

		aleft += acnt[i];
		bleft += bcnt[i];
	}

	for (i = 0; i < 26; i++)
	{
		if (aleft == 0 || bq == 0)
		{
			break;
		}

		lmin = acnt[i] < bq ? acnt[i] : bq;

		for (j = 0; j < lmin; j++)
		{
			cur = pair<int, int>(aloc[i].back(), bqloc.back());
			sol.push_back(cur);

			aloc[i].pop_back();
			bqloc.pop_back();
		}

		acnt[i] -= lmin;
		bq -= lmin;

		cnt += lmin;
	}

	for (i = 0; i < 26; i++)
	{
		if (bleft == 0 || aq == 0)
		{
			break;
		}

		lmin = bcnt[i] < aq ? bcnt[i] : aq;

		for (j = 0; j < lmin; j++)
		{
			cur = pair<int, int>(aqloc.back(), bloc[i].back());
			sol.push_back(cur);

			aqloc.pop_back();
			bloc[i].pop_back();
		}

		aq -= lmin;
		bcnt[i] -= lmin;

		cnt += lmin;
	}

	/*
	lmin = aleft < bq ? aleft : bq;
	cnt += lmin;
	aleft -= lmin;
	bq -= lmin;

	lmin = bleft < aq ? bleft : aq;
	cnt += lmin;
	bleft -= lmin;
	aq -= lmin;
	*/

	lmin = aq < bq ? aq : bq;

	for (j = 0; j < lmin; j++)
	{
		cur = pair<int, int>(aqloc.back(), bqloc.back());
		sol.push_back(cur);

		aqloc.pop_back();
		bqloc.pop_back();
	}

	cnt += lmin;

	printf("%d\n", cnt);

	for (i = 0; i < cnt; i++)
	{
		printf("%d %d\n", sol[i].first, sol[i].second);
	}

	return 0;
}