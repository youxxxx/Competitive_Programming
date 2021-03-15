#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

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

		char input[201];

		scanf("%s", input);
		const string str = input;
		const string target = "2020";

		bool found = false;

		for (int i = 0; i <= 4; i++)
		{
			bool valid = true;

			for (int j = 0; j < i; j++)
			{
				if (str[j] != target[j])
				{
					valid = false;

					break;
				}
			}

			if (!valid)
			{
				continue;
			}

			for (int j = i; j < 4; j++)
			{
				if (str[j + n - 4] != target[j])
				{
					valid = false;

					break;
				}
			}

			if (valid)
			{
				found = true;

				break;
			}
		}

		if (found)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}