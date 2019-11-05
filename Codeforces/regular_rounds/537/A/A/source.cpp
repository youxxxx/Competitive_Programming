#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n;
	char input[2000];
	string s, t;
	char vowel[5] = { 'a','e','i','o','u' };
	int i, j, k;

	scanf("%s", &input);
	t = input;
	scanf("%s", &input);
	s = input;

	if (t.size() != s.size())
	{
		printf("No\n");

		return 0;
	}

	for (i = 0; i < s.size(); i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (t[i] == vowel[j])
			{
				break;
			}
		}

		for (k = 0; k < 5; k++)
		{
			if (s[i] == vowel[k])
			{
				break;
			}
		}

		if (j == 5 && k != 5 || j != 5 && k == 5)
		{
			break;
		}
	}

	if (i == s.size())
	{
		printf("Yes\n");
	}

	else
	{
		printf("No\n");
	}

	return 0;
}