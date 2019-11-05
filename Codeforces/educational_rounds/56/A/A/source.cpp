#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int t;
	int i;

	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);

		printf("%d\n", (n + 6) / 7);
	}

	return 0;
}