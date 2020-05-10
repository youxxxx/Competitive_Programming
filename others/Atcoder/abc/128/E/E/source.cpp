#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<functional>

using namespace std;

bool func(const pair<pair<long long, long long>, long long> &a, const pair<pair<long long, long long>, long long> &b)
{
	return a.first.first < b.first.first;
}

class comp
{
public:
	bool operator() (const pair<pair<long long, long long>, long long>& a, const pair<pair<long long, long long>, long long> &b) const
	{
		return a.second > b.second;
	}
};

bool func2(const pair<long long, int> &a, const pair<long long, int> &b)
{
	return a.first < b.first;
}

bool func3(const pair<long long, int> &a, const pair<long long, int> &b)
{
	return a.second < b.second;
}

int main()
{
	int n, m;
	int i, j;
	vector<pair<pair<long long, long long>, long long>> interv;
	priority_queue<pair<pair<long long, long long>, long long>, vector<pair<pair<long long, long long>, long long>>, comp> pq;
	vector<pair<long long, int>> person, sol;
	long long input1, input2, input3;
	int ptr = 0;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%lld %lld %lld", &input1, &input2, &input3);

		interv.push_back(pair<pair<long long, long long>, long long>(pair<long long, long long>(input1 - input3, input2 - input3), input3));
	}

	sort(interv.begin(), interv.end(), func);

	for (i = 0; i < m; i++)
	{
		scanf("%lld", &input1);

		person.push_back(pair<long long,int>(input1,i));
	}

	sort(person.begin(), person.end(), func2);

	for (i = 0; i < m; i++)
	{
		while (ptr < n&&interv[ptr].first.first <= person[i].first)
		{
			pq.push(interv[ptr++]);
		}

		while (!pq.empty() && pq.top().first.second <= person[i].first)
		{
			pq.pop();
		}

		if (pq.empty())
		{
			sol.push_back(pair<long long, int>(-1, person[i].second));
		}

		else
		{
			sol.push_back(pair<long long, int>(pq.top().second, person[i].second));
		}
	}

	sort(sol.begin(), sol.end(), func3);

	for (i = 0; i < m; i++)
	{
		printf("%lld\n", sol[i].first);
	}

	return 0;
}