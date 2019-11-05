#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	int i;
	int key[2] = { 0, }, chest[2] = { 0, };
	int input;
	int sol = 0;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		chest[input % 2]++;
	}

	for (i = 0; i < m; i++)
	{
		scanf("%d", &input);

		key[!(input % 2)]++;
	}

	for (i = 0; i < 2; i++)
	{
		sol += chest[i] <= key[i] ? chest[i] : key[i];
	}

	printf("%d\n", sol);

	return 0;
}