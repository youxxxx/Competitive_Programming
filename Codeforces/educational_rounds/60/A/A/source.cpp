#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	vector<long long> arr;
	long long input;
	long long max = 0;
	int n;
	int i;
	int cnt;
	int seq = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		if (input > max)
		{
			max = input;
		}

		arr.push_back(input);
	}

	cnt = 0;

	for (i = 0; i < n; i++)
	{
		if (arr[i] == max)
		{
			cnt++;

			if (cnt > seq)
			{
				seq = cnt;
			}
		}

		else
		{
			cnt = 0;
		}
	}

	printf("%d\n", seq);

	return 0;
}