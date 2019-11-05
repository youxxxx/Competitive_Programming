#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	vector<int> arr, sum;
	int cur = 0;
	int input;
	int i;
	int lmin = 10001;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);

		cur += input;

		sum.push_back(cur);
	}

	for (i = 0; i < n - 1; i++)
	{
		if (abs((sum[n - 1] - sum[i]) - sum[i]) < lmin)
		{
			lmin = abs((sum[n - 1] - sum[i]) - sum[i]);
		}
	}

	printf("%d\n", lmin);

	return 0;
}