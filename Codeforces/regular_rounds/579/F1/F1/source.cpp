#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

bool func(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first > b.first || a.first == b.first && a.second > b.second;
}

int main()
{
	int n, r;
	vector<pair<int, int>> pos, neg;
	vector<int> z;
	int i, j;
	int input1, input2;
	int negsum = 0;
	bool visited[200] = { 0, };
	//bool change;

	scanf("%d %d", &n, &r);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &input1, &input2);

		if (input2 > 0)
		{
			pos.push_back(make_pair(input1, input2));
		}

		else if (input2 < 0)
		{
			neg.push_back(make_pair(input1, input2));

			negsum += input2;
		}

		else
		{
			z.push_back(input1);
		}
	}

	sort(pos.begin(), pos.end());

	//sort(neg.begin(), neg.end(), func);

	for (i = 0; i < pos.size(); i++)
	{
		if (pos[i].first > r)
		{
			break;
		}

		r += pos[i].second;
	}

	if (i != pos.size())
	{
		printf("NO\n");

		return 0;
	}

	for (i = 0; i < z.size(); i++)
	{
		if (z[i] > r)
		{
			break;
		}
	}

	if (i != z.size())
	{
		printf("NO\n");

		return 0;
	}

	if (r + negsum < 0)
	{
		printf("NO\n");

		return 0;
	}

	r += negsum;

	for (i = 0; i < neg.size(); i++)
	{
		for (j = 0; j < neg.size(); j++)
		{
			if (!visited[j] && r - neg[j].second >= neg[j].first)
			{
				visited[j] = true;

				r -= neg[j].second;

				break;
			}
		}

		if (j == neg.size())
		{
			printf("NO\n");

			return 0;
		}
	}

	printf("YES\n");

	return 0;
}