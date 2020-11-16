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
#include<functional>

using namespace std;

int gcd(int a, int b)
{
	while (b)
	{
		a %= b;

		int temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		int arr[1001];

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		sort(&arr[0], &arr[n], greater<int>());

		bool check[1001] = { 0, };

		check[0] = true;

		int sol[1001];

		sol[0] = arr[0];
		
		int prev = arr[0];
		
		for (int i = 1; i < n; i++)
		{
			int gmax = 1;
			int lmin = 1001;
			int idx = 0;

			for (int j = 1; j < n; j++)
			{
				if (check[j])
				{
					continue;
				}

				const int g = gcd(arr[j], prev);

				if (g > gmax || g == gmax&&arr[j] < lmin)
				{
					gmax = g;
					lmin = arr[j];
					idx = j;
				}
			}

			check[idx] = true;
			prev = gmax;
			sol[i] = arr[idx];
		}

		for (int i = 0; i < n; i++)
		{
			printf("%d ", sol[i]);
		}

		printf("\n");
	}

	return 0;
}