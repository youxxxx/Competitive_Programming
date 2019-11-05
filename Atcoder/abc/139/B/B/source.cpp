#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d\n", (b - 1 + a - 2) / (a - 1));

	return 0;
}