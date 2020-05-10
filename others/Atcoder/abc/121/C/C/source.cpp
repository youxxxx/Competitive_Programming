#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

bool func(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.first < b.first;
}

int main()
{
	long long n, m;
	long long i;
	long long input1, input2;
	vector<pair<long long, long long>> arr;
	long long cnt = 0;
	long long add;
	long long cost = 0;

	scanf("%lld %lld", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%lld %lld", &input1, &input2);

		arr.push_back(pair<long long, long long>(input1, input2));
	}

	sort(arr.begin(), arr.end(), func);

	for (i = 0; i < n&&cnt < m; i++)
	{
		add = (m - cnt < arr[i].second) ? m - cnt : arr[i].second;

		cnt += add;

		cost += add*arr[i].first;
	}

	printf("%lld\n", cost);

	return 0;
}