#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		char input[101];
		string a, b, c;

		scanf("%s", input);
		a = input;
		scanf("%s", input);
		b = input;
		scanf("%s", input);
		c = input;

		n = a.size();

		bool valid = true;

		for (int i = 0; i < n; i++)
		{
			if (!(a[i] == c[i] || b[i] == c[i]))
			{
				valid = false;

				break;
			}
		}

		if (valid)
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