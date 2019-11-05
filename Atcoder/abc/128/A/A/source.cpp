#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>

using namespace std;

int main()
{
	int a, p;
	int tot;

	scanf("%d %d", &a, &p);

	tot = a * 3 + p;

	printf("%d\n", tot / 2);
	
	return 0;
}