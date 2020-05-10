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
	int s, w;

	scanf("%d %d", &s, &w);

	if (s <= w)
	{
		printf("unsafe\n");
	}

	else
	{
		printf("safe\n");
	}

	return 0;
}