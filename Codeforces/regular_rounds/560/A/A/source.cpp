#include<cstdio>
#include<vector>
#include<cmath>
#include<string>


using namespace std;

int main()
{
	int n;
	char input[200001];
	string str;
	int x, y;
	int i;
	int cnt = 0;

	scanf("%d %d %d", &n, &x, &y);

	scanf("%s", input);

	str = input;

	for (i = n - x; i < n; i++)
	{
		if (i == n - y - 1)
		{
			if (str[i] == '0')
			{
				cnt++;
			}
		}

		else
		{
			if (str[i] == '1')
			{
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}