#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

long long gcd(long long a, long long b)
{
	long long temp;

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
	int n;
	int i;
	vector<int> arr;
	int prev;
	int input;
	int cnt = 1;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	if (arr[0] != 1)
	{
		arr[0]--;
	}

	prev = arr[0];

	for (i = 1; i < n; i++)
	{
		if (arr[i] > prev)
		{
			if (arr[i] - 1 > prev)
			{
				prev = arr[i] - 1;
			}

			else
			{
				prev = arr[i];
			}

			cnt++;
		}

		else if (arr[i] == prev)
		{
			prev = arr[i] + 1;

			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}