#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int i;
	long long input;
	vector<long long> arr;
	bool flag[2] = { 0, };

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		flag[input % 2] = true;

		arr.push_back(input);
	}

	if (!flag[0] || !flag[1])
	{
		for (i = 0; i < n; i++)
		{
			printf("%lld ", arr[i]);
		}
	}

	else
	{
		sort(arr.begin(), arr.end());

		for (i = 0; i < n; i++)
		{
			printf("%lld ", arr[i]);
		}
	}

	return 0;
} 