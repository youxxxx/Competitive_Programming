#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool func(const pair<pair<long long, long long>, long long> &a, pair<pair<long long, long long>, long long> &b)
{
	return a.second > b.second;
}

int main()
{
	int n;
	vector<pair<pair<long long,long long>,long long>> p;
	long long input1, input2;
	int i;
	long long tot = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld %lld", &input1, &input2);

		p.push_back(pair<pair<long long, long long>, long long>(pair<long long, long long>(input1, input2), input1 + input2));
	}

	sort(p.begin(), p.end(), func);

	for (i = 0; i < n; i++)
	{
		if (!(i % 2))
		{
			tot += p[i].first.first;
		}

		else
		{
			tot -= p[i].first.second;
		}
	}

	printf("%lld\n", tot);

	return 0;
}