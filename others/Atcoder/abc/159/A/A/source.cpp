#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	printf("%d\n", n*(n - 1)/2 + m*(m - 1)/2);

	return 0;
}