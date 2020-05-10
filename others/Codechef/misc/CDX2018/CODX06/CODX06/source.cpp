#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t, z;
	long long s, k;
	vector<long long> arr;
	long long input, sum, cnt;
	int i;
	int n;
	vector<long long>::iterator it;
	pair<vector<long long>::iterator, vector<long long>::iterator> range;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %lld %lld", &n, &s, &k);

		sum = 0;

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			//arr.push_back(input);

			sum += input;
		}
		/*
		sort(arr.begin(), arr.end());

		range = equal_range(arr.begin(), arr.end(), k);
		
		it = range.second;

		cnt = 0;

		while (it-- != arr.begin() && sum < s)
		{
			sum += *it;

			cnt++;
		}

		printf("%lld\n", cnt);

		arr.clear();
		*/

		if (sum > s)
		{
			sum = s;
		}

		printf("%lld\n", (s - sum + k - 1) / k);
	}

	return 0;
}