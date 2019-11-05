#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int bin_search(vector<int> &arr, int lb, int ub, int h)
{
	int next;
	vector<int> temp;
	int i;
	long long sum = 0;

	if (ub - lb < 2)
	{
		return lb;
	}

	next = (lb + ub) / 2;

	temp = arr;

	sort(temp.begin(), temp.begin() + next);

	for (i = !(next % 2); i < next; i += 2)
	{
		sum += temp[i];

		if (sum > h)
		{
			break;
		}
	}

	if (sum <= h)
	{
		return bin_search(arr, next, ub, h);
	}

	return bin_search(arr, lb, next, h);
}

int main()
{
	vector<int> arr;
	int n, h;
	int i;
	int input;
	int cnt = 0;

	scanf("%d %d", &n, &h);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	/*
	for (i = 0; i < n / 2; i++)
	{
		if (h < arr[1])
		{
			if (arr[0] <= h)
			{
				cnt++;
			}

			break;
		}

		h -= arr[1];

		cnt += 2;

		arr.erase(arr.begin());
		arr.erase(arr.begin());
	}
	*/

	printf("%d\n", bin_search(arr,1,n+1,h));

	return 0;
}