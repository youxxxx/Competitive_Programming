#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int t, n;
	vector<long long> hill;
	int i, j, z;
	int input;
	int prev;
	int cnt;
	bool inc, dec, right;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		prev = 0;
		cnt = 1;

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			hill.push_back(input);
		}

		if (hill[1] > hill[0])
		{
			inc = true;

			right = false;
		}

		else
		{
			inc = false;

			//dec = true;

			right = true;
		}

		for (i = 1; i < n - 1; i++)
		{
			if (inc)
			{
				if (hill[i + 1] < hill[i])
				{
					inc = false;

					//dec = true;
					if (!right)
					{
						right = true;

						cnt++;
					}
				}
			}

			else// if(dec)
			{
				if (hill[i + 1] > hill[i])
				{
					inc = true;

					//dec = false;

					right = false;
				}
			}
		}

		if (!right)
		{
			cnt++;
		}

		printf("%d\n", cnt);
	}

	return 0;

}