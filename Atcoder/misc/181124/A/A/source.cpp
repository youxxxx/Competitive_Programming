#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	int n, i;
	int sum = 0;
	vector<int> arr;
	int input;
	int min, idx = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);

		sum += input;
	}

	min = abs(sum - arr[0]*n);

	for (i = 1; i < n; i++)
	{
		if (abs(sum - arr[i] * n) < min)
		{
			min = abs(sum - arr[i] * n);

			idx = i;
		}
	}

	printf("%d\n", idx);

	return 0;
}