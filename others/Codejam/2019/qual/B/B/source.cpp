#include<cstdio>
#include<string>

using namespace std;

int main()
{
	int t, z;
	char input[100002];
	string str, sol;
	int n, i;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %s", &n, input);

		str = input;

		for (i = 0; i < str.size(); i++)
		{
			if (str[i] == 'S')
			{
				sol.push_back('E');
			}

			else
			{
				sol.push_back('S');
			}
		}

		printf("Case #%d: %s\n", z + 1, sol.c_str());

		sol.clear();
	}

	return 0;
}