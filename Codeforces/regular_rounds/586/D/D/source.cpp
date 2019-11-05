#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	long long input;
	int lmax[64] = { 0, };
	vector<int> list[64];
	vector<long long> arr;
	bool marked[200000] = { 0, };
	int lmin;
	int lidx;
	int i, j;

	scanf("%d", &n);

	lmin = n;

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);
		
		for (j = 0; j < 64; j++)
		{
			if (input % 2)
			{
				lmax[j]++;

				list[j].push_back(i);

				break;
			}

			input /= 2;
		}
	}

	

	for (i = 0; i < 64; i++)
	{
		if (n - lmax[i] <= lmin)
		{
			lmin = n - lmax[i];

			lidx = i;
		}
	}

	printf("%d\n", lmin);

	for (i = 0; i < list[lidx].size(); i++)
	{
		marked[list[lidx][i]] = true;
	}

	for (i = 0; i < n; i++)
	{
		if (!marked[i])
		{
			printf("%lld ", arr[i]);
		}
	}

	return 0;
} 