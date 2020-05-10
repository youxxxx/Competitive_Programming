#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int a, b;

		scanf("%d %d", &a, &b);

		int five, two;
		int diff;

		diff = abs(a - b);

		five = diff / 5;
		diff %= 5;
		two = diff / 2;
		diff %= 2;

		int sol;

		sol = five + two + diff;

		printf("%d\n", sol);
	}

	return 0;
}