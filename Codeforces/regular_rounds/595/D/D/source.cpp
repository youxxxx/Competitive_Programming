#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

class comp
{
public:
	bool operator()(const pair<pair<int,int>,int> &a, const pair<pair<int, int>, int> &b)
	{
		return a.first.second < b.first.second;
	}
};

bool func(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
{
	return a.first.first < b.first.first;
}

int main()
{
	int n, k;
	int cnt[200001] = { 0, };
	int rcnt[200001] = { 0, };
	vector<pair<pair<int, int>, int>> arr;
	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, comp> pq;
	int i, j;
	int l, r;
	int ptr = 0, ptr2 = 200001;
	int lmin;
	
	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &l, &r);

		arr.push_back(make_pair(make_pair(l, r), i + 1));
	}

	sort(arr.begin(), arr.end(), func);

	for (i = 0; i < n; i++)
	{
		pq.push(arr[i]);

		cnt[arr[i].first.first]++;
		rcnt[arr[i].first.second]++;

		if (arr[i].first.second < ptr2)
		{
			ptr2 = arr[i].first.second;
		}

		if(pq.)

		while (cnt[ptr] == 0)
		{
			ptr++;
		}

		while (rcnt[ptr2] == 0)
		{
			ptr2++;
		}
	}

	return 0;
}