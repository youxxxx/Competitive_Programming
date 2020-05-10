#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp;

		a %= b;

		temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int n;

	scanf("%d", &n);

	int sol = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int ab;

			ab = gcd(i, j);

			for (int k = 1; k <= n; k++)
			{
				sol += gcd(ab, k);
			}
		}
	}

	printf("%d\n", sol);

	return 0;
}