#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	int x, y, a, b, c;

	scanf("%d %d %d %d %d", &x, &y, &a, &b, &c);

	vector<long long> r, g, l;

	for (int i = 0; i < a; i++)
	{
		long long input;

		scanf("%lld", &input);
		
		r.push_back(input);
	}

	for (int i = 0; i < b; i++)
	{
		long long input;

		scanf("%lld", &input);

		g.push_back(input);
	}

	for (int i = 0; i < c; i++)
	{
		long long input;

		scanf("%lld", &input);

		l.push_back(input);
	}

	sort(r.begin(), r.end(), greater<int>());
	sort(g.begin(), g.end(), greater<int>());
	sort(l.begin(), l.end(), greater<int>());

	long long sol = 0;

	priority_queue<long long, vector<long long>, greater<long long>> pq[2];

	for (int i = 0; i < x; i++)
	{
		sol += r[i];

		pq[0].push(r[i]);
	}

	for (int i = 0; i < y; i++)
	{
		sol += g[i];

		pq[1].push(g[i]);
	}

	for (int i = 0; i < c; i++)
	{
		int idx;

		if (pq[0].empty() && pq[1].empty())
		{
			break;
		}

		if (pq[0].empty())
		{
			idx = 1;
		}

		else if (pq[1].empty())
		{
			idx = 0;
		}

		else
		{
			if (pq[0].top() < pq[1].top())
			{
				idx = 0;
			}

			else
			{
				idx = 1;
			}
		}

		if (pq[idx].top() >= l[i])
		{
			break;
		}

		sol -= pq[idx].top();
		sol += l[i];
		pq[idx].pop();
	}

	printf("%lld\n", sol);

	return 0;
}