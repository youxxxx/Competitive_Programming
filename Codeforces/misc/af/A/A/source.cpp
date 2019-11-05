#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int dnc(vector<int> &arr, int lb, int ub)
{
	int i;
	int next;
	int l, r;

	if (ub - lb == 1)
	{
		return 1;
	}

	next = (lb + ub) / 2;
	l = dnc(arr, lb, next);
	r = dnc(arr, next, ub);

	if (l + r == ub - lb)
	{
		if (arr[next - 1] <= arr[next])
		{
			return ub - lb;
		}
	}

	return l > r ? l : r;
}

int main()
{
	int n;
	int i;
	vector<int> arr;
	int input;
	int lmax = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	printf("%d\n", dnc(arr, 0, n));

	return 0;
}