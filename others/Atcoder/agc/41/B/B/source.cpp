#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
	long long n, m, v, p;
	vector<long long> arr;

	scanf("%lld %lld %lld %lld", &n, &m, &v, &p);

	for (long long i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end(), greater<long long>());

	long long sol;

	sol = p;

	for (long long i = p; i < n; i++)
	{
		if (n - i >= v)
		{
			sol++;

			continue;
		}

		long long left;

		left = v - (n - i);

		if (left <= p && arr[i] + m >= arr[p - 1])
		{
			sol++;

			continue;
		}

		if (arr[i] + m < arr[p - 1])
		{
			continue;
		}


	}

	return 0;
}