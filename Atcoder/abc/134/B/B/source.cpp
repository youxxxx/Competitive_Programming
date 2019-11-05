#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	printf("%d\n", (n + m * 2) / (m * 2 + 1));

	return 0;
}