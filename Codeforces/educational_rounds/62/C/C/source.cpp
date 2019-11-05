#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<functional>

using namespace std;

bool func(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.second > b.second;
}

int main()
{
	int n, k;
	vector<pair<long long, long long>> arr;
	priority_queue<long long,vector<long long>,greater<long long>> pq;
	long long input1, input2;
	long long lmax = 0, cand;
	long long psum = 0;
	int i;

	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d %I64d", &input1, &input2);

		arr.push_back(pair<long long, long long>(input1, input2));
	}

	sort(arr.begin(), arr.end(), func);

	for (i = 0; i < n; i++)
	{
		cand = (psum + arr[i].first)*arr[i].second;

		if (cand > lmax)
		{
			lmax = cand;
		}

		pq.push(arr[i].first);
		
		psum += arr[i].first;

		if (pq.size() == k)
		{
			psum -= pq.top();

			pq.pop();
		}
	}

	printf("%I64d\n", lmax);

	return 0;
}