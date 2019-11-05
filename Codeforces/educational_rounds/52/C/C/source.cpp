#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

long long bin(vector<long long> &arr, long long lb, long long ub, long long target)
{
	long long next;

	if (ub - lb <= 1)
	{
		return lb;
	}

	next = (lb + ub) / 2;

	if (target == arr[next])
	{
		return next;
	}

	if (target < arr[next])
	{
		return bin(arr, lb, next, target);
	}

	return bin(arr, next, ub, target);
}

int main()
{
	vector<long long> tower, acc;
	long long input;
	long long n, k;
	long long cur = 1, pre, sum = 0, left = 0, block, firstcut, height, width, max;
	long long i;
	long long cnt = 0, cut, sum2 = 0;

	scanf("%I64d %I64d", &n, &k);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		tower.push_back(input);
	}

	if (n == 1)
	{
		printf("0");

		return 0;
	}

	sort(tower.begin(), tower.end());

	pre = tower.back();

	cur = 1;

	for (i = tower.size() - 2; i >= 0; i--)
	{
		if (pre != tower[i])
		{
			height = (pre - tower[i]);

			width = (tower.size() - i - 1);

			if (left + height*width < k)
			{
				left += height*width;

				pre = tower[i];

				continue;
			}

			block = height*width;

			sum += block;

			firstcut = (k - left) / width;

			height -= firstcut;

			max = k / width;

			cnt += height / max + 1;

			height -= height / max*max;

			if (height == 0)
			{
				cnt--;

				height += max;
			}

			left = height*width;

			acc.push_back(sum);

			pre = tower[i];
		}
	}

	if (left != 0)
	{
		cnt++;
	}

	/*
	sum += tower[0] * tower.size();

	acc.push_back(sum);

	while (!acc.empty())
	{
		cut = bin(acc, 0, acc.size(), k + sum2);

		sum2 = acc[cut];

		acc.erase(acc.begin(), acc.begin() + cut + 1);

		cnt++;
	}
	*/

	printf("%I64d", cnt);

	return 0;
}