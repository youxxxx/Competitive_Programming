#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };


	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		char input[100001];
		string str;
		int dir[4] = { 0, };

		scanf("%s", input);

		str = input;

		n = str.size();

		for (int i = 0; i < n; i++)
		{
			switch (str[i])
			{
			case 'L':
				dir[0]++;
				break;
			case 'R':
				dir[1]++;
				break;
			case 'U':
				dir[2]++;
				break;
			case 'D':
				dir[3]++;
				break;
			}
		}

		int hmin, vmin;

		hmin = dir[0] < dir[1] ? dir[0] : dir[1];
		vmin = dir[2] < dir[3] ? dir[2] : dir[3];

		if (hmin == 0 && vmin == 0)
		{
			printf("0\n\n");
			
			continue;
		}

		if (hmin == 0)
		{
			printf("%d\n", 2);

			printf("UD\n");

			continue;
		}

		if (vmin == 0)
		{
			printf("%d\n", 2);

			printf("LR\n");

			continue;
		}

		printf("%d\n", hmin * 2 + vmin * 2);

		for (int i = 0; i < hmin; i++)
		{
			printf("L");
		}

		for (int i = 0; i < vmin; i++)
		{
			printf("U");
		}

		for (int i = 0; i < hmin; i++)
		{
			printf("R");
		}

		for (int i = 0; i < vmin; i++)
		{
			printf("D");
		}

		printf("\n");
	}

	return 0;
}