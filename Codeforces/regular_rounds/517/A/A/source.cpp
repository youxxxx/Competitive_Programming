#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int n, m, k;
	int i;
	int sum = 0;

	scanf("%d %d %d", &n, &m, &k);
	
	for (i = 0; i < k; i++)
	{
		sum += (n + m - 2 - 8 * i) * 2;
	}

	printf("%d\n", sum);

	return 0;
}