#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	long long n, m;
	long long i;
	//vector<long long> arr;
	long long input;
	long long max = 0, sum = 0, left = 0;
	map<long long, long long> blocks;
	map<long long, long long>::iterator it,  it2, ret;

	scanf("%I64d %I64d", &n, &m);

	max = n;

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		sum += input;

		if (input > max)
		{
			max = input;
		}

		ret = blocks.find(input);

		if (ret == blocks.end())
		{
			blocks[input] = 1;
		}

		else
		{
			ret->second++;
		}
	}

	if (blocks.size() == 1)
	{
		if (n > max)
		{
			printf("%I64d\n", sum - n);
		}

		else
		{
			printf("%I64d\n", sum - max);
		}

		return 0;
	}
	
	it = blocks.end();

	while (--it != blocks.begin())
	{
		it2 = it;
		it2--;

		left -= it->first - it->second - it2->first;

		if (left < 0)
		{
			sum += left;

			left = 0;
		}
	}

	if (it->first != 1)
	{
	//	if (it->first - it2->second > left)
		left -= it->first - it2->second - it2->first;

		if (left < 0)
		{
			sum += left;

			left = 0;
		}
	}

	printf("%I64d\n", sum - n);

	return 0;
}