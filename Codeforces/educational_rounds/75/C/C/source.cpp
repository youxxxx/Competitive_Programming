#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

int main()
{
	int tc, cases;
	int n;
	string str;
	string div0, div1, sol;
	char input[300001];
	int i, j, k;
	char cur;
	int parity[2];

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%s", input);

		str = input;

		div0.clear();
		div1.clear();
		sol.clear();

		n = str.size();

		for (i = 0; i < n; i++)
		{
			if (!((str[i] - '0') % 2))
			{
				div0.push_back(str[i]);
			}

			else
			{
				div1.push_back(str[i]);
			}
		}

		//sort(div0.begin(), div0.end());
		//sort(div1.begin(), div1.end());

		i = 0;
		j = 0;

		while (i != div0.size() && j != div1.size())
		{
			if (div0[i] < div1[j])
			{ 
				sol.push_back(div0[i++]);
			}

			else
			{
				sol.push_back(div1[j++]);
			}
		}

		for (k = i; k < div0.size(); k++)
		{
			sol.push_back(div0[k]);
		}

		for (k = j; k < div1.size(); k++)
		{
			sol.push_back(div1[k]);
		}

		printf("%s\n", sol.c_str());
	}

	return 0;
}