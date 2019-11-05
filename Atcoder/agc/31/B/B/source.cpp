#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

class comp
{
public:
	bool operator () (const pair<pair<long long, long long>, long long> &a, const pair<pair<long long, long long>, long long> &b)
	{
		return a.first.second > b.first.second;
	}
};

class comp2
{
public:
	bool operator () (const pair<long long, long long> &a, const pair<long long, long long> &b)
	{
		return a.first > b.first;
	}
};

int main()
{
	long long n;
	pair<pair<long long, long long>, long long> cur2, next;
	priority_queue<pair<pair<long long, long long>, long long>, vector<pair<pair<long long, long long>, long long>>, comp> pq;
	priority_queue < pair<long long, long long>, vector<pair<long long, long long>>, comp2> q;
	pair<long long, long long> cur;
	long long tot = 1;
	long long psum;
	long long *prev;
	long long i;
	long long input;

	scanf("%lld", &n);

	prev = new long long[n + 1];

	for (i = 0; i <= n; i++)
	{
		prev[i] = -1;
	}

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		if (prev[input] != -1 && i - prev[input] > 1)
		{
			q.push(pair<long long, long long>(prev[input], i));
		}

		prev[input] = i;
	}

	while (!q.empty())
	{
		cur = q.top();
		q.pop();

		psum = 0;

		while (!pq.empty() && pq.top().first.second <= cur.first)
		{
			cur2 = pq.top();
			pq.pop();

			psum = (psum + cur2.second) % 1000000007;
		}

		tot = (tot + psum + 1) % 1000000007;

		next.first = cur;
		next.second = psum * 2 + 1;
		
		pq.push(next);
	}
	
	printf("%lld\n", tot);

	return 0;
}