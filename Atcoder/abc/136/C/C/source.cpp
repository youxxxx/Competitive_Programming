#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int input, prev = -1;
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		if (input > prev)
		{
			input--;
		}

		else if (input < prev)
		{
			printf("No\n");

			return 0;
		}

		prev = input;
	}

	printf("Yes\n");

	return 0;
}