#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<stack>
#include<set>

using namespace std;

int main()
{
	int n;
	int arr[200002] = { 0, };

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		arr[input]++;
	}

	int cnt = 0;
	int lmin = 0, lmax = 0;

	for (int i = 1; i <= n; i++)
	{
		if (arr[i] || cnt)
		{
			cnt++;
		}

		if (cnt == 3)
		{
			lmin++;

			cnt = 0;
		}
	}

	if (cnt)
	{
		lmin++;
	}

	int right[200002] = { 0, };

	for (int i = 1; i <= n; i++)
	{
		if ((right[i] + arr[i]) && !arr[i - 1] && !right[i - 1])
		{
			arr[i - 1] = 1;
			arr[i]--;
		}

		if ((right[i]+arr[i])>1)
		{
			arr[i]--;

			right[i + 1] = 1;
		}
	}
	
	for (int i = 0; i <= n + 1; i++)
	{
		arr[i] += right[i];

		lmax += !!arr[i];
	}

	printf("%d %d\n", lmin, lmax);

	return 0;
}