#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int gcd(int a, int b)
{
	int temp;

	while (b != 0)
	{
		a %= b;

		temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	vector<int> arr;
	int n;
	int t, z;
	int i;
	int input;
	int cur;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			arr.push_back(input);
		}

		sort(arr.begin(), arr.end());

		cur = arr[1] - arr[0];

		for (i = 1; i < n - 1; i++)
		{
			cur = gcd(cur, arr[i + 1] - arr[i]);
		}

		cur = gcd(cur, arr[0] + 360 - arr[n - 1]);

		printf("%d\n", 360 / cur - n);

		arr.clear();
	}

	return 0;
}