#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	int n, m;
	int i;
	int spos, tpos;
	char input[200000];
	string s, t;

	scanf("%d", &cases); 

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%s", input);
		s = input;
		n = s.size();

		scanf("%s", input);
		t = input;
		m = t.size();

		for (i = m - 1; i >= 0; i--)
		{
			if (t[i] == '1')
			{
				break;
			}
		}

		tpos = m - 1 - i;

		for (i = n - 1 - tpos; i >= 0; i--)
		{
			if (s[i] == '1')
			{
				break;
			}
		}

		spos = n - 1 - (i + tpos);

		printf("%d\n", spos);
	}

	return 0;
}