#include<cstdio>
#include<vector>
#include<cmath>
#include<set>
#include<map>

using namespace std;

int main()
{
	long long sum = 0;
	long long input;
	vector<long long> arr;
	long long n, s;
	long long i, j;
	long long min = 100000001, max = 0;
	long long cnt = 0;
	long long cand, height;
	long long sol;
	long long left;
	long long cur, acc = 0;
	map<long long, long long> blocks;
	map<long long, long long>:: iterator it, prev, ret;
	

	scanf("%I64d %I64d", &n, &s);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);

		sum += input;

		ret = blocks.find(input);

		if (ret == blocks.end())
		{
			blocks[input] = 1;
		}

		else
		{
			ret->second++;
		}

		if (input < min)
		{
			min = input;
		}

		if (input > max)
		{
			max = input;
		}
	}

	if (sum < s)
	{
		printf("-1\n");

		return 0;
	}

	if (n == 1)
	{
		printf("%I64d\n", arr[0] - s);

		return 0;
	}

	/*
	left = sum - s;

	height = left / n;

	if (min < cand)
	{
		cand = min + height*(n - 1);

		while (height > min && cand > left)
		{
			height--;

			cand -= n - 1;
		}

		while(height <= )
	}

	else
	{
		cand = height*n;
	}
	*/

	if ((sum - s) / n <= min)
	{
		printf("%I64d\n", (sum - s) / n);

		return 0;
	}

	/*
	it = blocks.end();
	it--;

	while (it != blocks.begin())
	{
		prev = it;
		prev--;

		cnt += it->second;

		cur = prev->first;

		acc += it->first - prev->first * cnt;

		if (acc >= s)
		{
			break;
		}

		it--;
	}
	*/

	printf("%I64d\n", min);

	return 0;
}