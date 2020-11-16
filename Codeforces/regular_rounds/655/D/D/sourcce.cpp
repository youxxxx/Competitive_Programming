#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

int group[200001];

int uf(int a)
{
	if (a == group[a])
	{
		return a;
	}

	else return group[a] = uf(group[a]);
}

void disj(int a, int b)
{
	int next;
	int rvalue;
	int ar, br;

	ar = uf(a);
	br = uf(b);

	group[br] = ar;
}

class comp
{
public:
	bool operator() (const pair<long long, long long> &a, const pair<long long, long long> &b)
	{
		return a.first > b.first;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	int n;

	scanf("%d", &n);

	int left[200001];
	int right[200001];

	for (int i = 0; i <= n; i++)
	{
		group[i] = i;

		left[i] = (i + n - 1) % n;
		right[i] = (i + 1) % n;
	}

	priority_queue < pair<long long, long long>, vector<pair<long long, long long>>, comp> pq;

	long long arr[200001];

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);

		pq.push({ arr[i],i });
	}

	while (pq.size() != 1)
	{
		long long val = pq.top().first;
		int idx = pq.top().second;

		pq.pop();

		if (group[idx] != idx || val != arr[idx])
		{
			continue;
		}

		int nl = group[left[idx]];
		int nr = group[right[idx]];

		long long nval = arr[nl] + arr[nr];

		left[nr] = left[nl];
		right[nl] = right[nr];

		disj(nl, nr);

		arr[nl] = nval;

		pq.push({ nval,nl });
	}

	printf("%lld\n", pq.top().first);

	return 0;
}