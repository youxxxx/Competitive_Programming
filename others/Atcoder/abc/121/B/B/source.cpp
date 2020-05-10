#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n, m, c;
	int i, j;
	int b[20];
	int input;
	int sum;
	int cnt = 0;

	scanf("%d %d %d", &n, &m, &c);

	for (i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
	}
	
	for (i = 0; i < n; i++)
	{
		sum = 0;

		for (j = 0; j < m; j++)
		{
			scanf("%d", &input);

			sum += b[j] * input;
		}

		cnt += (sum + c > 0);
	}
	
	printf("%d\n", cnt);

	return 0;
}