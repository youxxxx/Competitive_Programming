#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool func(pair<long long, long long> &a, pair<long long, long long> &b)
{
	return a.second < b.second;
}

int main()
{
	int n;
	int i;
	vector<pair<long long,long long>> arr;
	long long x, y;
	long long input1, input2;
	vector<long long> tv;
	long long sum = 0;
	int ptr;

	scanf("%d %I64d %I64d", &n, &x, &y);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d %I64d", &input1, &input2);

		arr.push_back(pair<long long,long long>(input1,input2));

		sum = (sum + (input2 - input1) * y) % 1000000007;
	}

	sort(arr.begin(), arr.end(), func);

	tv.push_back(arr[0].second);

	//sum = (sum + (((arr[0].second - arr[0].first) % 1000000007) * y) % 1000000007) % 1000000007;

	ptr = 0;

	for (i = 1; i < n; i++)
	{
		if (tv[(ptr + 1) % tv.size()] >= arr[i].first)
		{
			tv.insert(tv.begin() + ++ptr, arr[i].second);
		}

		else
		{
			ptr = (ptr + 1) % tv.size();
			tv[ptr % tv.size()] = arr[i].second;
		}

		//sum = (sum + (((arr[i].second - arr[i].first) % 1000000007) * y) % 1000000007) % 1000000007;
	}

	sum = (sum + ((long long)tv.size() * x) % 1000000007) % 1000000007;

	printf("%I64d", sum);

	return 0;
}