#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<stack>
#include<queue>
#include<set>

using namespace std;

class comp
{
public:
	bool operator()(const pair<int, int> &a, const pair<int, int> &b)
	{
		return a.first > b.first;
	}
};

int main()
{
	int n;
	int arr[200001];
	pair<int,int> sol[200001];
	bool taken[200001] = { 0, };
	priority_queue < pair<int, int>, vector<pair<int, int>>, comp> pq;

	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d", &arr[i]);

		taken[arr[i]] = true;
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (!taken[i])
		{
			pq.push({ i,i });
		}
	}

	for (int i = n - 2; i >= 0; i--)
	{
		int sbit;
		int idx;

		sbit = pq.top().first;
		idx = pq.top().second;

		pair<int, int> temp = { 0,0 };

		while (idx == arr[i])
		{
			temp = pq.top();
			pq.pop();

			sbit = pq.top().first;
			idx = pq.top().second;
		}

		pq.pop();

		sol[i] = { arr[i],idx };

		int cand;

		cand = arr[i];

		if (cand != arr[0])
		{
			if (cand > sbit)
			{
				sbit = cand;
			}

			pq.push({ sbit,arr[i] });
		}
	}

	printf("%d\n", arr[0]);

	for (int i = 0; i < n - 1; i++)
	{
		printf("%d %d\n", sol[i].first, sol[i].second);
	}

	return 0;
}