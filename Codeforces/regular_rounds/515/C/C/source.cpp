#include<cstdio>

int main()
{
	int min=0, max=0;
	char query, nl;
	int id;
	int n;
	int i;
	int name[200001];
	int lowval;

	scanf("%d", &n);

	scanf("%c %c %d",&nl, &query, &id);

	name[id] = 0;

	for (i = 1; i < n; i++)
	{
		scanf("%c %c %d", &nl, &query, &id);

		if (query == 'L')
		{
			name[id] = --min;
		}

		else if (query == 'R')
		{
			name[id] = ++max;
		}

		else
		{
			lowval = name[id] - min;

			if (max - name[id] < lowval)
			{
				lowval = max - name[id];
			}

			printf("%d\n", lowval);
		}
	}

	return 0;
}