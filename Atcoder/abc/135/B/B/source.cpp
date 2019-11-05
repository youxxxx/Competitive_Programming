#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int n;
	int i;
	int cnt = 0;
	int input;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &input);

		if (input != i)
		{
			cnt++;
		}
	}

	if (cnt > 2)
	{
		printf("NO\n");
	}

	else
	{
		printf("YES\n");
	}
	
	return 0;
}
