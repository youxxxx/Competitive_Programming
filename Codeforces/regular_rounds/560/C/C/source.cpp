#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	char input[200001];
	string str, sol;
	int i;
	char cur;
	bool odd = false;
	int cnt = 0;

	scanf("%d", &n);

	scanf("%s", input);

	str = input;

	for (i = 0; i < n; i++)
	{
		if (!odd)
		{
			cur = str[i];

			sol.push_back(str[i]);

			odd = true;
		}

		else
		{
			if (str[i] == cur)
			{
				continue;
			}

			sol.push_back(str[i]);

			odd = false;
		}
	}

	if (sol.size() % 2)
	{
		sol.pop_back();
	}

	printf("%d\n%s\n", n - sol.size(), sol.c_str());

	return 0;
}