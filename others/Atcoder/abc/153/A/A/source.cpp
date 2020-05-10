#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d\n", (a + b - 1) / b);

	return 0;
}