#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	char input[200];
	string str;
	int n;
	int i;
	int t, z;
	bool valid;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);
		scanf("%s", input);
		str = input;

		valid = false;

		if (n < 11)
		{
			printf("NO\n");

			continue;
		}

		for (i = 0; i <= n - 11; i++)
		{
			if (str[i] == '8')
			{
				printf("YES\n");

				valid = true;

				break;
			}
		}

		if (!valid)
		{
			printf("NO\n");
		}
	}

	return 0;
}