#include<cstdio>

using namespace std;

int main()
{
	int n;
	int ax, ay, bx, by, cx, cy;

	scanf("%d %d %d %d %d %d %d", &n, &ax, &ay, &bx, &by, &cx, &cy);

	if (bx<ax&&cx<ax&&by<ay&&cy<ay
		|| bx<ax&&cx<ax&&by>ay&&cy>ay
		|| bx>ax&&cx>ax&&by<ay&&cy<ay
		|| bx>ax&&cx>ax&&by>ay&&cy>ay
		)
	{
		printf("YES");
	}

	else
	{
		printf("NO");
	}

	return 0;
}