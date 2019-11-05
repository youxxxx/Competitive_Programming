#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int tot[2] = { 0, };
	int i;
	int input;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		tot[input % 2]++;
	}

	printf("%d\n", tot[0] < tot[1] ? tot[0] : tot[1]);

	return 0;
}