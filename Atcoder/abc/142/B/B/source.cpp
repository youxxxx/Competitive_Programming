#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, k;
	int i;
	int cnt = 0;
	int input;

	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		cnt += (input >= k);
	}

	printf("%d\n", cnt);

	return 0;
}