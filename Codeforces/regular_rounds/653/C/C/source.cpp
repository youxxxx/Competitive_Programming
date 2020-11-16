#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		char input[51];
		string str;

		scanf("%s", input);
		str = input;

		int lmin = 0;
		int cur = 0;

		for (int i = 0; i < n; i++)
		{
			if (str[i] == '(')
			{
				cur++;
			}

			else
			{
				cur--;
			}

			if (cur < lmin)
			{
				lmin = cur;
			}
		}

		printf("%d\n", -lmin);
	}

	return 0;
}