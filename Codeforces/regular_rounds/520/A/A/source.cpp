#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int n;
	int i;
	vector<int> arr;
	int input;
	int start;
	bool seq = false;
	int sum = 0, max = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	if (n == 1)
	{
		printf("0\n");

		return 0;
	}

	if (arr[0] == 1)
	{
		start = -1;

		seq = true;
	}

	for (i = 0; i < n - 1; i++)
	{
		if (!seq&&arr[i] + 1 == arr[i + 1])
		{
			start = i;

			seq = true;
		}

		else if (seq&&arr[i] + 1 != arr[i + 1])
		{
			if (i - start - 1 > max)
			{
				max = i - start - 1;
			}
			//sum += i - start - 1;

			seq = false;
		}
	}

	if (seq)
	{
		sum = n - start - 2;

		if (arr[n - 1] == 1000)
		{
			sum++;
		}

		if (sum > max)
		{
			max = sum;
		}
	}

	printf("%d\n", max);

	return 0;
}