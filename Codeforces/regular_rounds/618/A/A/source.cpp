#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

#define MOD 1000000007

using namespace std;

int main()
{
	int n;
	vector<int> arr;
	vector<int> bits[30];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		arr.push_back(input);

		int bit = 1;

		for (int j = 0; j < 30; j++)
		{
			if (bit&input)
			{
				bits[j].push_back(i);
			}

			bit <<= 1;
		}
	}

	for (int i = 29; i >= 0; i--)
	{
		if (bits[i].size() == 1)
		{
			int sol;

			printf("%d", arr[bits[i][0]]);

			for (int j = 0; j < n; j++)
			{
				if (j == bits[i][0])
				{
					continue;
				}

				printf(" %d", arr[j]);
			}

			return 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}