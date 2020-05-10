#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	if (a + b + c >= 22)
	{
		printf("bust\n");
	}

	else
	{
		printf("win\n");
	}

	return 0;
}