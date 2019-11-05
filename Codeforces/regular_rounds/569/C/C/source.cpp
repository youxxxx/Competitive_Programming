#define _USE_MATH_DEFINES

#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n, q;
	vector<long long> arr;
	vector<pair<long long, long long>> sol;
	long long input;
	long long cand1, cand2;
	long long lmax = 0;
	int i;

	scanf("%d %d", &n, &q);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);
	}

	for (i = 0; i < n - 1; i++)
	{
		cand1 = arr[0];
		cand2 = arr[1];

		sol.push_back(make_pair(cand1, cand2));

		if (cand1 > cand2)
		{
			arr.erase(arr.begin() + 1);
			arr.push_back(cand2);
		}

		else
		{
			arr.erase(arr.begin());
			arr.push_back(cand1);
		}
	}

	for (i = 0; i < q; i++)
	{
		scanf("%lld", &input);

		input--;

		if (input < n - 1)
		{
			printf("%lld %lld\n", sol[input].first, sol[input].second);
		}

		else
		{
			printf("%lld %lld\n", arr[0], arr[input % (n - 1) + 1]);
		}
	}

	return 0;
}