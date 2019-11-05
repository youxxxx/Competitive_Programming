#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

bool func(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.first < b.first;
}

class comp
{
public:
	bool operator() (const pair<long long, long long> &a, const pair<long long, long long> &b)
	{
		return a.second < b.second;
	}
};

int main()
{
	int n, m;
	vector<pair<long long, long long>> work;
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, comp> pq;
	long long input1, input2;
	int i, j, ptr;
	long long sol = 0;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%lld %lld", &input1, &input2);

		work.push_back(pair<long long, long long>(input1, input2));
	}

	sort(work.begin(), work.end());

	ptr = 0;

	for (i = 1; i <= m; i++)
	{
		for (j = ptr; j < n; j++)
		{
			if (work[j].first > i)
			{
				break;
			}

			pq.push(work[j]);
		}

		if (!pq.empty())
		{
			sol += pq.top().second;

			pq.pop();
		}

		ptr = j;
	}

	printf("%lld\n", sol);

	return 0;
}