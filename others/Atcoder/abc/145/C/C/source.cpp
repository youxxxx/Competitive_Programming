#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	long long n;
	vector<long long> arr;
	vector<pair<long long, long long>> loc;
	double sol = 0.0;
	long long perm = 1;

	//freopen("input.txt", "r", stdin);

	scanf("%lld", &n);

	for (long long i = 0; i < n; i++)
	{
		long long input1, input2;

		scanf("%lld %lld", &input1, &input2);

		arr.push_back(i);

		loc.push_back(make_pair(input1, input2));

		perm *= i + 1;
	}

	for (long long i = 0; i < perm; i++)
	{
		for (long long j = 0; j < n - 1; j++)
		{
			double xsq, ysq;

			xsq = (double)loc[arr[j+1]].first - (double)loc[arr[j]].first;
			xsq = xsq*xsq;
			ysq = (double)loc[arr[j + 1]].second - (double)loc[arr[j]].second;
			ysq = ysq*ysq;

			sol += sqrt(xsq + ysq);
		}

		next_permutation(arr.begin(), arr.end());
	}

	sol /= (double)perm;

	printf("%.10lf\n", sol);

	return 0;
}