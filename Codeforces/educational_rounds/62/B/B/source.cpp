#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int t, z;
	int n;
	char input[1000];
	string str;
	int i;
	int lcnt = 0, rcnt = 0;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		scanf("%s", input);

		str = input;

		if (str.front() == '>' || str.back() == '<')
		{
			printf("0\n");

			continue;
		}

		lcnt = rcnt = 0;

		for (i = 0; i < n; i++)
		{
			if (str[i] == '>')
			{
				break;
			}

			lcnt++;
		}

		for (i = n - 1; i >= 0; i--)
		{
			if (str[i] == '<')
			{
				break;
			}

			rcnt++;
		}

		printf("%d\n", lcnt < rcnt ? lcnt : rcnt);
	}

	return 0;
}