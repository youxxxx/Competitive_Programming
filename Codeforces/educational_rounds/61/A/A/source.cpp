#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int cnt[4];
	int i;

	for (i = 0; i < 4; i++)
	{
		scanf("%d", &cnt[i]);
	}

	if (cnt[0] == cnt[3] && (cnt[2] == 0 || cnt[0] != 0))
	{
		printf("1\n");
	}

	else
	{
		printf("0\n");
	}

	return 0;
}