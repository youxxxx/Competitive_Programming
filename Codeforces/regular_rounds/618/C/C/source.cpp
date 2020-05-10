#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>

#define MOD 1000000007

using namespace std;

int main()
{
	long long n;

	scanf("%lld", &n);

	long long arr[1000001];

	for (long long i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}

	stack<pair<double, long long>> s;

	for (long long i = 0; i < n; i++)
	{
		double curval;
		long long curlen = 1;

		curval = (double)arr[i];

		while (!s.empty() && s.top().first > curval)
		{
			curval = ((double)curlen*curval + (double)s.top().second*s.top().first) / (double)(curlen + s.top().second);
			curlen += s.top().second;
			
			s.pop();
		}

		s.push({ curval,curlen });
	}

	long long ptr = n - 1;

	double sol[1000001];

	while (!s.empty())
	{
		for (long long i = ptr; i > ptr - s.top().second; i--)
		{
			sol[i] = s.top().first;
		}

		ptr -= s.top().second;

		s.pop();
	}

	for (long long i = 0; i < n; i++)
	{
		printf("%.10lf\n", sol[i]);
	}

	return 0;
}