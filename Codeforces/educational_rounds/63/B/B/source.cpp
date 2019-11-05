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
	int num;
	int i;
	char lmax;
	int idx;
	int cnt = 0;
	int life;
	vector<int> eight, neight;
	int ecnt = 0, ncnt = 0;

	scanf("%d", &n);

	scanf("%s", input);

	str = input;

	num = (n - 11) / 2;

	for (i = 0; i < n; i++)
	{
		if (str[i] == '8')
		{
			cnt++;

			eight.push_back(i);
		}

		else
		{
			neight.push_back(i);
		}
	}

	if (cnt <= num)
	{
		printf("NO\n");

		return 0;
	}

	life = num;

	for (i = 0; i < n; i++)
	{
		if (str[i] == 0)
		{
			continue;
		}

		if (life == 0)
		{
			break;
		}

		if (str[i] != '8')
		{
			str[i] = 0;
		}

		else
		{
			str[neight[ncnt++]] = 0;

			if (ncnt == neight.size())
			{
				printf("YES\n");

				return 0;
			}
		}

		if (str[i] == '8')
		{
			str[i] = 0;
		}
		
		else
		{
			str[eight[ecnt++]] = 0;

			if (ecnt == eight.size())
			{
				printf("NO\n");

				return 0;
			}
		}

		life--;
	}

	if (str[i] == '8')
	{
		printf("YES\n");
	}

	else
	{
		printf("NO\n");
	}

	return 0;
}