#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	vector<int> arr, sol;
	int i, j;
	int input;
	int res;
	
	arr.push_back(0);

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	for (i = n / 2; i >= 1; i--)
	{
		res = 0;

		for (j = n / i; j >= 1; j--)
		{
			res = res && !arr[j*i] || !res&&arr[j*i];
		}

		arr[i] = res;
	}

	for (i = 1; i <= n; i++)
	{
		if (arr[i])
		{
			sol.push_back(i);
		}
	}

	printf("%d\n", sol.size());

	for (i = 0; i < sol.size(); i++)
	{
		printf("%d ", sol[i]);
	}

	printf("\n");
	
	return 0;
}