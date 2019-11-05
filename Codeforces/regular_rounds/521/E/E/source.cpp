#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;

int bin_search(vector<long long> &num, int lb, int ub)
{
	long long base = 1;
	int next;
	int i;

	if (ub - lb < 2)
	{
		return lb;
	}
	
	next = (lb + ub) / 2;

	for (i = num.size() - next; i < num.size(); i++)
	{
		if (num[i] < base)
		{
			break;
		}

		base *= 2;
	}

	if (i == num.size())
	{
		return bin_search(num, next, ub);
	}

	return bin_search(num, lb, next);
}

int main()
{
	int n, m;
	int i, j;
	long long input;
	map<long long, long long> list;
	map<long long, long long>::iterator it, ret;
	vector<long long> num;
	long long max = 0;
	long long sum;
	int ub;
	int lim;
	long long base, min;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		ret = list.find(input);

		if (ret == list.end())
		{
			list[input] = 1;
		}

		else
		{
			ret->second++;
		}
	}

	for(it=list.begin();it!=list.end();it++)
	{
		num.push_back(it->second);
	}

	sort(num.begin(), num.end());

	m = num.size();

	ub = 31;

	if (m + 1 < 31)
	{
		ub = m + 1;
	}

	lim = bin_search(num, 1, ub);

	for (i = 1; i <= lim; i++)
	{
		base = 2;

		min = num[m - i];

		for (j = m - i + 1; j < num.size(); j++)
		{
			if (num[j] / base < min)
			{
				min = num[j] / base;
			}

			base *= 2;
		}

		sum = ((long long)pow(2.0, i) - 1)*min;

		if (sum > max)
		{
			max = sum;
		}
	}

	printf("%I64d", max);

	return 0;
}