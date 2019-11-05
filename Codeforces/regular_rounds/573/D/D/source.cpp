#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int n;
	int i;
	long long input;
	vector<long long> arr;
	map<long long, long long> list;
	map<long long, long long>::iterator it, ret, it2;
	vector<string> winner = { "sjfnb", "cslnb" };
	int dup = 0;
	long long sum = 0;	

	scanf("%d", &n);

	if (n == 1)
	{
		scanf("%lld", &input);

		printf("%s\n", winner[!(input % 2)].c_str());

		return 0;
	}

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);

		ret = list.find(input);

		if (ret == list.end())
		{
			list[input] = 1;
		}

		else
		{
			if (++ret->second == 3)
			{
				printf("%s\n", winner[1].c_str());

				return 0;
			}
		}

		sum += input;
	}

	sort(arr.begin(), arr.end());

	for (it = list.begin(); it != list.end(); it++)
	{
		it2 = it;
		it2++;

		if (it2 == list.end())
		{
			break;
		}

		if (it->first == it2->first - 1 && it2->second == 2)
		{
			printf("%s\n", winner[1].c_str());

			return 0;
		}
	}

	if (arr[0] == 0 && arr[1] == 0)
	{
		printf("%s\n", winner[1].c_str());

		return 0;
	}

	for (i = 0; i < n - 1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			if (++dup == 2)
			{
				printf("%s\n", winner[1].c_str());

				return 0;
			}
		}
	}

	printf("%s\n", winner[!((sum - (long long)(n - 1)*(long long)n / 2) % 2)].c_str());

	return 0;
}