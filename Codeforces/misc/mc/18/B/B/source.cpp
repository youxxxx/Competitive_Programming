#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

long long int search(vector<long long int> &arr, long long int lb, long long int ub, long long int target)
{
	long long int next;

	if (lb + 1 == ub)
	{
		return lb;
	}

	next = (lb + ub) / 2;

	if (arr[next] == target)
	{
		return next;
	}

	if (arr[next] > target)
	{
		return search(arr, lb, next, target);
	}

	return search(arr, next, ub, target);
}

int main()
{
	long long int n, s, sol = 0, input;
	vector<long long int> arr;
	long long int i, index;

	scanf("%I64d %I64d", &n, &s);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	index = search(arr, 0, n, s);

	if (index < n / 2 && arr[index] <= s)
	{
		if (index < n - 1)
		{
			index++;
		}
	}
	
	if (index > n / 2 && arr[index] >= s)
	{
		if (index > 0)
		{
			index--;
		}
	}

	if (index < n / 2)
	{
		for (i = index; i <= n / 2; i++)
		{
			sol += abs(arr[i] - s);
		}
	}

	else
	{
		for (i = n / 2; i <= index; i++)
		{
			sol += abs(arr[i] - s);
		}
	}

	printf("%I64d", sol);

	return 0;
}