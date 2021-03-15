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
		char input[200001];

		scanf("%s", input);
		const string str = input;
		const int n = str.size();
		int a = 0, b = 0;
		int sol = 0;

		for (int i = 0; i < n; i++)
		{
			switch (str[i])
			{
			case '(':
				a++;
				break;
			case ')':
				if (a)
				{
					a--;

					sol++;
				}
				break;
			case '[':
				b++;
				break;
			case ']':
				if (b)
				{
					b--;

					sol++;
				}
				break;
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}