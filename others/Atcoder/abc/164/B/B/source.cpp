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
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	int val;

	val = (c + b - 1) / b - (a + d - 1) / d;

	if (val <= 0)
	{
		printf("Yes\n");
	}

	else
	{
		printf("No\n");
	}

	return 0;
}