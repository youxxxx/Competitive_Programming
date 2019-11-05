#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool func(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b)
{
	return a.first.first < b.first.first;
}

bool func2(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b)
{
	return a.first.first > b.first.first;
}

int main()
{
	int i;
	vector<pair<pair<int,int>,int>> inc, dec;
	vector<int> incsol, decsol;
	int input1, input2;
	int n;
	int cnt1 = 0, cnt2 = 0;
	int prev, cur;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &input1, &input2);

		if (input1 < input2)
		{
			inc.push_back(pair<pair<int, int>, int>(pair<int, int>(input1, input2), i + 1));
		}

		else
		{
			dec.push_back(pair<pair<int,int>,int>(pair<int, int>(input1, input2), i + 1));
		}
	}

	sort(inc.begin(), inc.end(), func2);
	sort(dec.begin(), dec.end(), func);

	if (!inc.empty())
	{
		cnt1++;

		incsol.push_back(inc[0].second);
		prev = inc[0].first.first;
		cur = inc[0].first.second;

		for (i = 1; i < inc.size(); i++)
		{
			if (inc[i].first.first < cur)
			{
				cnt1++;

				incsol.push_back(inc[i].second);
				prev = inc[i].first.first;
				cur = inc[i].first.second;
			}

			else if (inc[i].first.first<prev && inc[i].first.second>cur)
			{
				incsol.pop_back();
				incsol.push_back(inc[i].second);
				prev = inc[i].first.first;
				cur = inc[i].first.second;
			}
		}
	}

	if (!dec.empty())
	{
		cnt2++;

		decsol.push_back(dec[0].second);
		prev = dec[0].first.first;
		cur = dec[0].first.second;

		for (i = 1; i < dec.size(); i++)
		{
			if (dec[i].first.first > cur)
			{
				cnt2++;

				decsol.push_back(dec[i].second);
				prev = dec[i].first.first;
				cur = dec[i].first.second;
			}

			else if (dec[i].first.first>prev && dec[i].first.second<cur)
			{
				decsol.pop_back();
				decsol.push_back(dec[i].second);
				prev = dec[i].first.first;
				cur = dec[i].first.second;
			}
		}
	}
	
	if (cnt1 >= cnt2)
	{
		printf("%d\n", cnt1);

		for (i = 0; i < cnt1; i++)
		{
			printf("%d ", incsol[i]);
		}
	}

	else
	{
		printf("%d\n", cnt2);

		for (i = 0; i < cnt2; i++)
		{
			printf("%d ", decsol[i]);
		}
	}

	return 0;
}
