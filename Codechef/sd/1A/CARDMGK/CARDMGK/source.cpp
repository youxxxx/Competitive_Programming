#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	long long input, min;
	vector<long long> deck;
	int i, j;
	int t, n;
	int midx;

	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);

		deck.clear();

		min = 1000000001;

		for (j = 0; j < n; j++)
		{
			scanf("%lld", &input);

			if (input < min)
			{
				min = input;

				midx = j;
			}

			deck.push_back(input);
		}

		if (midx == 0)
		{
			for (j = n - 1; j >= 1; j--)
			{
				if (deck[j] > min)
				{
					break;
				}
			}

			midx = (j + 1) % n;
		}

		for (j = 0; j < n - 1; j++)
		{
			if (deck[(midx + j) % n] > deck[(midx + j + 1) % n])
			{
				printf("NO\n");

				break;
			}
		}

		if (j == n - 1)
		{
			printf("YES\n");
		}
	}

	return 0;
}