#include<cstdio>
#include<string>

using namespace std;

int main()
{
	int n;
	int i, j;
	char input[200001];
	string s, t, sol;
	int carry = 0;
	char val;

	scanf("%d", &n);

	scanf("%s", input);
	s = input;
	scanf("%s", input);
	t = input;

	for (i = 0; i < n; i++)
	{
		if (carry)
		{
			val = ((t[i] - 'a') + (s[i] - 'a') + 26);
			carry = val % 2;
			val /= 2;

			if (val / 26)
			{
				for (j = i - 1; j >= 0; j--)
				{
					sol[j]++;

					if (!((sol[j] - 'a') / 26))
					{
						break;
					}

					sol[j] -= 26;
				}
			}

			val %= 26;
		}

		else
		{
			val = ((t[i] - 'a') + (s[i] - 'a'));
			carry = val % 2;
			val /= 2;
		}

		sol.push_back(val + 'a');
	}

	printf("%s\n", sol.c_str());

	return 0;
}