#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int i;
	vector<int> sol1, sol2;

	scanf("%d", &n);

	if (!(n % 2))
	{
		printf("NO\n");

		return 0;
	}

	for (i = 0; i < n / 2; i++)
	{
		sol1.push_back(i * 2 + 1);
		sol2.push_back(i * 2 + 2);
		sol1.push_back(2 * n + 1 - (i * 2 + 1));
		sol2.push_back(2 * n + 1 - (i * 2 + 2));
	}

	sol1.push_back(n);
	sol2.push_back(n + 1);

	printf("YES\n");

	for (i = 0; i < n; i++)
	{
		printf("%d ", sol1[i]);
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", sol2[i]);
	}

	return 0;
}
