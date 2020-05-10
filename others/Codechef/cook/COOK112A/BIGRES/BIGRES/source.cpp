#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
	long long cases;

	scanf("%lld", &cases);

	for (long long tc = 0; tc < cases; tc++)
	{
		vector<long long> x;
		vector<long long> h;

		long long n;

		scanf("%lld", &n);

		for (long long i = 0; i < n; i++)
		{
			long long input;

			scanf("%lld", &input);

			x.push_back(input);

			scanf("%lld", &input);

			h.push_back(input);
		}

		sort(h.begin(), h.end());

		vector<int> v;
		long long prev = 0;

		for (long long i = 1; i < n; i++)
		{
			long long add;

			add = x[i] - x[i - 1];

			prev += add;

			v.push_back(prev);

			prev = add;
		}

		v.push_back(prev);

		sort(v.begin(), v.end());

		long long sum = 0;

		for (long long i = 0; i < n; i++)
		{
			sum += v[i] * h[i];
		}

		printf("%lld\n", sum);
	}

	return 0;
}