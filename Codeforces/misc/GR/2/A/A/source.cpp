#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	vector<int> arr;
	int n;
	int i;
	int input;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	if (arr[0] != arr[n - 1])
	{
		printf("%d\n", n - 1);

		return 0;
	}

	for (i = 1; i < n / 2; i++)
	{
		if (arr[i] != arr[0] || arr[n - i - 1] != arr[0])
		{
			printf("%d\n", n - 1 - i);

			return 0;
		}
	}

	printf("%d\n", n / 2);

	return 0;
}