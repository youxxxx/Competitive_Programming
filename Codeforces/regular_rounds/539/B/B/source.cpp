#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	vector<int> arr;
	int i, j;
	int min = 101, minidx;
	int max = 0;
	int input;
	int n;
	int sum = 0;

	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		if (input < min)
		{
			min = input;
			minidx = i;
		}

		arr.push_back(input);

		sum += input;
	}

	arr.erase(arr.begin() + minidx);

	for (i = 0; i < n - 1; i++)
	{
		for (j = 2; j <= (int)sqrt(arr[i]); j++)
		{
			if (!(arr[i] % j))
			{
				if ((arr[i] / j)*(j - 1) - min * (j - 1) > max)
				{
					max = (arr[i] / j)*(j - 1) - min * (j - 1);
				}
			}
		}
	}

	printf("%d\n", sum - max);

	return 0;
}