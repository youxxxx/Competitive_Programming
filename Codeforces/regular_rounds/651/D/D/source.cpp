#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int n, k;

	scanf("%d %d", &n, &k);

	vector<int> arr;

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		arr.push_back(input);
	}

	int lb = 0, ub = 1000000000;

	for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)
	{
		bool valid = false;

		if (k % 2)
		{
			int cnt = k / 2 + 1;

			for (int i = 0; i < n; i++)
			{
				if (arr[i] <= next)
				{
					i++;

					cnt--;
				}

				if (!cnt)
				{
					break;
				}
			}

			if (!cnt)
			{
				valid = true;
			}

			else
			{
				cnt = k / 2;

				for (int i = 1; i < n - 1; i++)
				{
					if (arr[i] <= next)
					{
						i++;

						cnt--;
					}

					if (!cnt)
					{
						break;
					}
				}

				if (!cnt)
				{
					valid = true;
				}
			}
		}

		else
		{
			int cnt = k / 2;

			for (int i = 0; i < n - 1; i++)
			{
				if (arr[i] <= next)
				{
					i++;

					cnt--;
				}

				if (!cnt)
				{
					break;
				}
			}

			if (!cnt)
			{
				valid = true;
			}

			else
			{
				cnt = k / 2;

				for (int i = 1; i < n; i++)
				{
					if (arr[i] <= next)
					{
						i++;

						cnt--;
					}

					if (!cnt)
					{
						break;
					}
				}

				if (!cnt)
				{
					valid = true;
				}
			}
		}

		if (valid)
		{
			ub = next;
		}

		else
		{
			lb = next;
		}
	}

	printf("%d\n", ub);

	return 0;
}