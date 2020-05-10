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
	int k, a, b;

	scanf("%d %d %d", &k, &a, &b);

	int ka, kb;

	ka = a / k;
	kb = b / k;

	if (ka == kb && a%k)
	{
		printf("NG\n");
	}

	else
	{
		printf("OK\n");
	}

	return 0;
}