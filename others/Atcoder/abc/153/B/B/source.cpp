#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int h;
	int n;

	scanf("%d %d", &h, &n);
	
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		sum += input;
	}

	if (sum >= h)
	{
		printf("Yes\n");
	}

	else
	{
		printf("No\n");
	}

	return 0;
}