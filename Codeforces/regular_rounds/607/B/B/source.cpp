#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		string s, s2, t;
		char input[10001];

		scanf("%s", input);
		s = input;
		s2 = s;

		scanf("%s", input);
		t = input;

		sort(s2.begin(), s2.end());

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != s2[i])
			{
				for (int j = s.size() - 1; j > i; j--)
				{
					if (s[j] == s2[i])
					{
						char temp;

						temp = s[i];
						s[i] = s[j];
						s[j] = temp;

						break;
					}
				}

				break;
			}
		}

		if (s < t)
		{
			printf("%s\n", s.c_str());
		}

		else
		{
			printf("---\n");
		}
	}

	return 0;
}