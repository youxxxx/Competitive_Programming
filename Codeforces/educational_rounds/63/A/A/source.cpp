#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	char input[300001];
	string str;
	int n;
	int i;
	char lmax;
	int idx;

	scanf("%d", &n);

	scanf("%s", input);

	str = input;

	lmax = str[0];
	idx = 0;

	for (i = 1; i < n; i++)
	{
		if (str[i] < lmax)
		{
			printf("YES\n%d %d\n", idx + 1, i + 1);

			return 0;
		}

		lmax = str[i];
		idx = i;
	}

	printf("NO\n");

	return 0;
}