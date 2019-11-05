#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

long long bin_search(long long lb, long long ub, long long target)
{
	long long next;

	if (ub - lb < 2)
	{
		return lb;
	}

	next = (lb + ub) / 2;

	if (next*(next - 1) / 2 > target)
	{
		return bin_search(lb, next, target);
	}

	else
	{
		return bin_search(next, ub, target);
	}
}

int main()
{
	int tc, cases;
	long long n;
	long long subt, cnt;
	long long val;
	long long temp;
	long long prev;
	long long i, j;
	vector<pair<long long,long long>> seven;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%lld", &n);

		seven.clear();

		prev = 1000000;

		temp = n;

		while (temp) 
		{
			subt = bin_search(2, prev, temp);

			val = subt*(subt - 1) / 2;

			cnt = temp / val;

			seven.push_back(make_pair(subt, cnt));

			prev = subt;

			temp %= val;
		}

		prev = 0;

		printf("1");

		for (i = seven.size() - 1; i >= 0; i--)
		{
			for (j = prev; j < seven[i].first; j++)
			{
				printf("3");
			}

			for (j = 0; j < seven[i].second; j++)
			{
				printf("7");
			}
			
			prev = seven[i].first;
		}

		printf("\n");
	}

	return 0;
}