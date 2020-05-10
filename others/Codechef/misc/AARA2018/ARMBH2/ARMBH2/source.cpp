#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int t, z;
	vector<vector<long long>> mat;
	vector<long long> empt;
	long long input;
	long long max = 0, lmax;
	int n, m, k;
	int i, j;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		max = 0;

		scanf("%d %d %d", &n, &m, &k);

		for (i = 0; i < n; i++)
		{
			lmax = 0;

			mat.push_back(empt);

			for (j = 0; j < m; j++)
			{
				scanf("%lld", &input);

				if (j >= k)
				{
					lmax -= mat[i][j - k];
				}

				lmax += input;

				if (lmax > max)
				{
					max = lmax;
				}

				mat[i].push_back(input);
			}
		}

		for (i = 0; i < m; i++)
		{
			lmax = 0;

			for (j = 0; j < n; j++)
			{
				if (j >= k)
				{
					lmax -= mat[j - k][i];
				}

				lmax += mat[j][i];

				if (lmax > max)
				{
					max = lmax;
				}
			}
		}

		printf("%lld\n", max);

		mat.clear();
	}

	return 0;
}