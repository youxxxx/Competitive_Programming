#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<functional>
#include<map>

#define MOD 998244353

using namespace std;

int main()
{
	int n, k;
	vector<long long> arr;
	long long input;
	int *pre;
	long long tot = 1, sub = 0, next = 0, mul;
	long long sol;
	int i;

	scanf("%d %d", &n, &k);

	pre = new int[n];

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);

		pre[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		if (arr[i] == -1)
		{
			mul = k;

			sub = 0;

			if (i - 2 >= 0)
			{
				if (arr[i - 2] != -1)
				{
					mul--;

					if (i + 2 < n)
					{
						if (arr[i+2] != -1)
						{
							if (arr[i + 2] != arr[i - 2])
							{
								mul--;
							}
						}

						else
						{
							pre[i + 2] = arr[i - 2];
						}
					}
				}

				else
				{
					if (i + 2 < n)
					{
						if (arr[i + 2] != -1)
						{
							if (pre[i])
							{
								if (arr[i + 2] != pre[i])
								{
									sub = k - 2;
								}

								else
								{
									sub = k - 1;
								}
							}

							else
							{
								sub = k - 1;
							}
						}

						else
						{

						}
					}
				}
			}

			if (i + 2 < n)
			{


				if (arr[i + 2] == -1)
				{
					pre[i + 2] = true;
				}
			}

			tot = (tot*mul) % MOD;
			//sub = (sub*k) % MOD;

			/*
			if (pre[i])
			{
				sub = (sub + MOD - 1) % MOD;
			}
			*/
		}
	}

	//sol = (tot - sub + MOD) % MOD;

	printf("%I64d\n", sol);

	return 0;
}