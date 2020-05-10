#include<cstdio>

using namespace std;

int main()
{
	int t, z;
	int n, x;
	int i;
	int cnt;
	char letter;
	char input;
	char u, l1, l2;
	
	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d %c", &n, &x, &letter);

		cnt = 0;

		for (i = 0; i < x; i++)
		{
			scanf("%c", &input);

			scanf("%c = %c + %c", &u, &l1, &l2);
		}

		for (i = x; i < n; i++)
		{
			scanf("%c", &input);

			scanf("%c = %c + %c", &u, &l1, &l2);

			if (l1 == letter || l2 == letter)
			{
				cnt++;
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}