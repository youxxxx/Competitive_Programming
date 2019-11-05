#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	int sum = 0;
	int input;
	vector<int> arr;
	int n;
	int i, j;
	int min = 999999;
	int cnt = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);

		sum += (input * i) * 2;
	}

	for (i = 0; i < n; i++)
	{
		cnt = 0;

		for (j = 0; j < n; j++)
		{
			cnt += ((abs(j - i) + i) * arr[j]) * 2;
		}

		if (cnt < min)
		{
			min = cnt;
		}
	}

	printf("%d\n", sum + min);

	return 0;
}