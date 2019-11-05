#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n;
	int cnt = 0;
	int h, w;
	int input1, input2;
	int i;

	scanf("%d %d %d", &n, &h, &w);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &input1, &input2);

		if (input1 >= h&&input2 >= w)
		{
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}