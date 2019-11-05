#include<cstdio>

using namespace std;

int main()
{
	int i;
	int input;
	int deg[4] = { 0, };
	int cnt1 = 0, cnt2 = 0;

	for (i = 0; i < 6; i++)
	{
		scanf("%d", &input);

		deg[input - 1]++;
	}

	for (i = 0; i < 4; i++)
	{
		if (deg[i] == 1)
		{
			cnt1++;
		}

		else if (deg[i] == 2)
		{
			cnt2++;
		}
	}

	if (cnt1 == 2 && cnt2 == 2)
	{
		printf("YES\n");
	}

	else
	{
		printf("NO\n");
	}

	return 0;
}