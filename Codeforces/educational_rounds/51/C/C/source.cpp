#include<cstdio>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main()
{
	int n;
	int s[101] = { 0, };
	string sol;
	int input;
	int i;
	bool flag = false, first = false;
	vector<int> one, two, other, tot;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		s[input]++;

		tot.push_back(input);
	}

	for (i = 1; i <= 100; i++)
	{
		if (s[i])
		{
			if (s[i] == 1)
			{
				one.push_back(i);
			}

			else if (s[i] == 2)
			{
				two.push_back(i);
			}

			else
			{
				other.push_back(i);
			}
		}
	}

	if (one.size() % 2 && !other.size())
	{
		printf("NO");
	}

	else
	{
		if (one.size() % 2)
		{
			for (i = 0; i < n; i++)
			{
				if (s[tot[i]] == 1)
				{
					if (!flag)
					{
						sol.push_back('A');
					}

					else
					{
						sol.push_back('B');
					}

					flag = !flag;
				}

				else if (s[tot[i]] > 2)
				{
					if (!first)
					{
						sol.push_back('B');

						first = true;
					}

					else
					{
						sol.push_back('A');
					}
				}

				else
				{
					sol.push_back('A');
				}
			}
		}

		else
		{
			for (i = 0; i < n; i++)
			{
				if (s[tot[i]] == 1)
				{
					if (!flag)
					{
						sol.push_back('A');
					}

					else
					{
						sol.push_back('B');
					}

					flag = !flag;
				}

				else
				{
					sol.push_back('A');
				}
			}
		}

		printf("YES\n%s", sol.c_str());
	}

	return 0;
}