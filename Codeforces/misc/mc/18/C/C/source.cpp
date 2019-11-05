#include<cstdio>
#include<cmath>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int n;
	int tog[2][2] = { 0, };
	string a, b;
	char input[1000001];
	int i;

	scanf("%d", &n);

	scanf("%s", input);
	a = input;

	scanf("%s", input);
	b = input;
	
	if (a[0] == b[0])
	{
		tog[0][1] = -1;
	}

	else
	{
		tog[0][0] = 1;
		tog[0][1] = 1;
	}

	for (i = 1; i < n; i++)
	{
		if (a[i] == b[i])
		{
			tog[i % 2][0] = tog[!(i % 2)][0];
			tog[i % 2][1] = -1;
		}

		else
		{
			tog[i % 2][0] = tog[!(i % 2)][0] + 1;
			tog[i % 2][1] = tog[!(i % 2)][0] + 1;

			if (a[i] == b[i - 1] && tog[!(i % 2)][1] >= 0 && tog[!(i % 2)][1] < tog[i % 2][0])
			{
				tog[i % 2][0] = tog[!(i % 2)][1];
			}
		}
	}

	printf("%d", tog[!(n % 2)][0]);

	return 0;
}