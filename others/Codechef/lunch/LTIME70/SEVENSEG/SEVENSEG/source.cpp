#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int seg[10][7] = { { 1,1,1,1,0,1,1 },{ 0,0,1,0,0,1,0 },{ 0,1,1,1,1,0,1 },{ 0,1,1,0,1,1,1 },{ 1,0,1,0,1,1,0 },{ 1,1,0,0,1,1,1 },{ 1,1,0,1,1,1,1 },{ 0,1,1,0,0,1,0 },{ 1,1,1,1,1,1,1 },{ 1,1,1,0,1,1,1 } };
	int val[10] = { 0, };
	int cnt[10] = { 0, };
	int i, j, k;
	int n;
	int t, z;
	vector<int> num, light;
	int input1, input2;
	bool valid;
	int totbit, bitcnt;
	int lmin, lmax;
	int temp;
	int land;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 7; j++)
		{
			val[i] = val[i] * 2 + seg[i][j];
			cnt[i] += seg[i][j];
		}
	}

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		valid = true;

		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &input1, &input2);

			num.push_back(input1);
			light.push_back(input2);

			if (light[i] > cnt[num[i]])
			{
				valid = false;
			}
		}

		if (!valid)
		{
			printf("invalid\n");

			light.clear();
			num.clear();

			continue;
		}

		lmin = 11;
		lmax = -1;

		for (i = 0; i < 128; i++)
		{
			totbit = 0;
			temp = i;

			for (j = 0; j < 7; j++)
			{
				totbit += !(temp % 2);
				temp >>= 1;
			}

			for (j = 0; j < n; j++)
			{
				land = (i&val[num[j]]);

				temp = land;

				bitcnt = 0;

				for (k = 0; k < 7; k++)
				{
					bitcnt += temp % 2;
					temp >>= 1;
				}

				if (bitcnt != light[j])
				{
					break;
				}
			}

			if (j == n)
			{
				if (totbit < lmin)
				{
					lmin = totbit;
				}

				if (totbit > lmax)
				{
					lmax = totbit;
				}
			}
		}

		if (lmin == 11)
		{
			printf("invalid\n");
		}

		else
		{
			printf("%d %d\n", lmin, lmax);
		}

		light.clear();
		num.clear();
	}

	return 0;
}
