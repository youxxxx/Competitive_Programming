#include<cstdio>

using namespace std;

int main()
{
	int t, v;
	int x, y, z;
	int cand;
	
	scanf("%d", &t);

	for (v = 0; v < t; v++)
	{
		scanf("%d %d %d", &x, &y, &z);

		if (x + y + z == 0 || x + y - z == 0 || x - y + z == 0 || x - y - z == 0 || -x + y + z == 0 || -x + y - z == 0 || -x - y + z == 0 || -x - y - z == 0)
		{
			printf("yes\n");
		}

		else
		{
			printf("no\n");
		}
	}

	return 0;	
}