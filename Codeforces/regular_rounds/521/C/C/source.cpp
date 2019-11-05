#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main()
{
	int n;
	int i;
	long long input;
	vector<long long> arr;
	long long sum = 0;
	long long max = 0, bean = 0;
	int maxcnt = 0, cnt = 0;
	int idx;
	bool two = true;
	vector<int> list;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);

		sum += input;

		if (input > max)
		{
			max = input;
		}
	}

	for (i = 0; i < n; i++)
	{
		if (arr[i] == max)
		{
			maxcnt++;
		}
	}

	if (maxcnt == 1)
	{
		two = false;

		for (i = 0; i < n; i++)
		{
			if(arr[i]>bean&&arr[i]<max)
			{
				bean = arr[i];
			}

			else if(arr[i]==max)
			{
				idx = i;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		if (sum - arr[i] - max == max && arr[i] != max)
		{
			cnt++;

			list.push_back(i + 1);
		}
	}

	if (two)
	{
		if (sum - max * 2 == max)
		{
			cnt += maxcnt;

			for (i = 0; i < n; i++)
			{
				if (arr[i] == max)
				{
					list.push_back(i + 1);
				}
			}
		}
	}

	else
	{
		if (sum - max - bean == bean)
		{
			cnt++;

			list.push_back(idx + 1);
		}
	}

	printf("%d\n", cnt);

	for (i = 0; i < list.size(); i++)
	{
		printf("%d ", list[i]);
	}

	return 0;
}