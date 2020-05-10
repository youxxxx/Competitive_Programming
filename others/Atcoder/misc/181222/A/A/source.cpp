#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n;
	int cnt = 0;
	int i;

	scanf("%d", &n);

	for (i = 0; i < 4; i++)
	{
		if (n % 10 == 2)
		{
			cnt++;
		}

		n /= 10;
	}

	printf("%d\n", cnt);

	return 0;
}