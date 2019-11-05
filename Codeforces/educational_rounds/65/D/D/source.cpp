#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

int main()
{
	char input[200001];
	string str, sol;
	int n;
	int i;
	bool lodd = false, rodd = false;

	scanf("%d", &n);
	scanf("%s", input);
	str = input;

	for (i = 0; i < n; i++)
	{
		if (str[i] == '(')
		{
			if (!lodd)
			{
				sol.push_back('0');

				lodd = !lodd;
			}

			else
			{
				sol.push_back('1');

				lodd = !lodd;
			}
		}

		else
		{
			if (!rodd)
			{
				sol.push_back('0');

				rodd = !rodd;
			}

			else
			{
				sol.push_back('1');

				rodd = !rodd;
			}
		}
	}

	printf("%s", sol.c_str());

	return 0;
}