#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	char input[100001];
	int n;
	string str;
	int i;
	char prev = 'L';
	bool flag = true;
	int start = -1;
	int sum[2] = { 0, };
	int tot[100001] = { 0, };

	scanf("%s", input);

	str = input;

	n = str.size();

	for (i = 0; i < n; i++)
	{
		if (str[i] != prev)
		{
			if (flag)
			{
				if (start != -1)
				{
					tot[start] += sum[!((i - start) % 2)];
					tot[start - 1] += sum[((i - start) % 2)];
				}
			}

			else
			{
				tot[i] += sum[((i - start) % 2)];
				tot[i - 1] += sum[!((i - start) % 2)];
			}

			flag = !flag;

			start = i;

			sum[0] = 1;
			sum[1] = 0;
		}

		else
		{
			sum[(i - start) % 2]++;
		}

		prev = str[i];
	}

	tot[start] += sum[!((i - start) % 2)];
	tot[start - 1] += sum[((i - start) % 2)];

	for (i = 0; i < n; i++)
	{
		printf("%d ", tot[i]);
	}

	printf("\n");

	return 0;
}