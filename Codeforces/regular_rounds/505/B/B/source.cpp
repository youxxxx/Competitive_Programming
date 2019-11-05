#include<cstdio>
#include<cmath>
#include<vector>
#include<set>

using namespace std;

int main()
{
	int n;
	vector<pair<long long int, long long int>> list;
	vector<int> prime;
	set<long long int> left;
	set<long long int>::iterator it;
	int i, j;
	long long int input1, input2, max = 0, bound;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d %I64d", &input1, &input2);

		if (max < input1)
		{
			max = input1;
		}

		if (max < input2)
		{
			max = input2;
		}

		list.push_back(pair<long long int, long long int>(input1, input2));
	}

	bound = (long long int)sqrt((double)max);

	prime.push_back(2);

	for (i = 3; i < bound; i++)
	{
		for (j = 0; j < prime.size(); j++)
		{
			if (!(i%prime[j]))
			{
				break;
			}
		}

		if (j == prime.size())
		{
			prime.push_back(i);
		}
	}

	for (i = 0; i < prime.size(); i++)
	{
		for (j = 0; j < n; j++)
		{
			if (list[j].first<prime[i] && list[j].second<prime[i])
			{
				printf("-1");

				return 0;
			}

			if (list[j].first%prime[i] && list[j].second%prime[i])
			{
				break;
			}
		}

		if (j == n)
		{
			printf("%d", prime[i]); 

			return 0;
		}
	}



	for (i = 0; i < n; i++)
	{
		if (list[i].first >= bound)
		{
			left.insert(list[i].first);
		}

		if (list[i].second >= bound)
		{
			left.insert(list[i].second);
		}
	}

	for (it=left.begin();it!=left.end();it++)
	{
		for (j = 0; j < n; j++)
		{
			if (list[j].first<*it && list[j].second<*it)
			{
				printf("-1");

				return 0;
			}

			if (list[j].first%*it && list[j].second%*it)
			{
				break;
			}
		}

		if (j == n)
		{
			printf("%I64d", *it);

			return 0;
		}
	}
	
	printf("-1");
	
	return 0;
}