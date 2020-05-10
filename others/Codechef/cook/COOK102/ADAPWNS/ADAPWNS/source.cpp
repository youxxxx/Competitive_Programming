#include<cstdio>
#include<cmath>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int t, z;
	int n;
	char input[1000];
	string str;
	int i;
	vector<int> coord;
	int res;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%s", input);

		str = input;

		for (i = 0; i < str.size(); i++)
		{
			if (str[i] == 'P')
			{
				coord.push_back(i - coord.size());
			}
		}

		res = 0;

		for (i = 0; i < coord.size(); i++)
		{
			res += coord[i];
		}

		if (res % 2)
		{
			printf("Yes\n");
		}

		else
		{
			printf("No\n");
		}

		coord.clear();
	}

	return 0;
}