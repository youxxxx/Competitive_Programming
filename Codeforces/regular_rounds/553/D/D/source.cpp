#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool func(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.second - a.first < b.second - b.first;
}

int main()
{
	vector<pair<long long,long long>> arr;
	long long input1, input2;
	long long sum = 0;
	int n;
	int i;
	
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d %I64d", &input1, &input2);

		arr.push_back(pair<long long, long long>(input1, input2));
	}

	sort(arr.begin(), arr.end(), func);

	for (i = 0; i < n; i++)
	{
		sum += arr[i].first*i + arr[i].second*(n - i - 1);
	}

	printf("%I64d\n", sum);

	return 0;
}