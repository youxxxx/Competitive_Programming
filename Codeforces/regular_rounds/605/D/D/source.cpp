#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	vector<int> arr;
	int lsucc[200001], rsucc[200001];

	scanf("%d", &n);

	int prev = 0;
	int cur = 0;
	int lmax = 0;

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		arr.push_back(input);

		if (input > prev)
		{
			cur++;
		}

		else
		{
			cur = 1;
		}

		if (cur > lmax)
		{
			lmax = cur;
		}

		lsucc[i] = cur;

		prev = input;
	}

	prev = 0;
	cur = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] < prev)
		{
			cur++;
		}

		else
		{
			cur = 1;
		}

		rsucc[i] = cur;

		prev = arr[i];
	}

	for (int i = 1; i < n - 1; i++)
	{
		if (arr[i - 1]<arr[i + 1] && lsucc[i - 1] + rsucc[i + 1]>lmax)
		{
			lmax = lsucc[i - 1] + rsucc[i + 1];
		}
	}

	printf("%d\n", lmax);

	return 0;
}