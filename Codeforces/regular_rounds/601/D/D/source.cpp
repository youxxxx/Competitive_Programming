#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;
	char type[62];

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (int i = 0; i < 10; i++)
	{
		type[i] = '0' + i;
	}

	for (int i = 10; i < 36; i++)
	{
		type[i] = 'A' + i - 10;
	}

	for (int i = 36; i < 62; i++)
	{
		type[i] = 'a' + i - 36;
	}

	for (int tc = 0; tc < cases; tc++)
	{
		vector<string> field;
		string line;
		int n, m, c;

		scanf("%d %d %d", &n, &m, &c);

		int tot = 0;

		for (int i = 0; i < n; i++)
		{
			string str;
			char input[101];

			scanf("%s", input);

			str = input;

			field.push_back(str);

			if (i % 2)
			{
				for (int j = m - 1; j >= 0 ; j--)
				{
					if (str[j] == 'R')
					{
						tot++;
					}

					line.push_back(str[j]);
				}
			}

			else
			{
				for (int j = 0; j < m; j++)
				{
					if (str[j] == 'R')
					{
						tot++;
					}

					line.push_back(str[j]);
				}
			}
		}

		int q, r;

		q = tot / c;
		r = tot%c;

		vector<int> sol;

		if (q == 0 && r == 0)
		{
			for (int i = 0; i < c - 1; i++)
			{
				sol.push_back(1);
			}

			sol.push_back(n*m - c - 1);
		}

		else if (q == 0 && r != 0)
		{
			int numofzeroes;

			numofzeroes = c - r;

			int acc = 0;

			for (int i = 0; i < n*m; i++)
			{
				if (line[i] == 'R')
				{
					if (numofzeroes)
					{
						sol.push_back(1);
					}

					else
					{
						acc++;
					}
				}

				else
				{
					if (numofzeroes)
					{
						sol.push_back(1);

						numofzeroes--;
					}

					else
					{
						acc++;
					}
				}
			}

			sol.push_back(acc);
		}

		else
		{
			int bleft, sleft;
			int acc = 0;
			int big, small;

			bleft = r;
			sleft = c - r;
			big = q + 1;
			small = q;
			int num = 0;

			for (int i = 0; i < n*m; i++)
			{
				if (line[i] == 'R')
				{
					if (bleft)
					{
						if (++num == big)
						{
							sol.push_back(++acc);

							acc = 0;

							num = 0;

							bleft--;
						}

						else
						{
							acc++;
						}
					}

					else if (sleft != 1)
					{
						if (++num == small)
						{
							sol.push_back(++acc);

							acc = 0;

							num = 0;

							sleft--;
						}

						else
						{
							acc++;
						}
					}

					else
					{
						acc++;
					}
				}

				else
				{
					acc++;
				}
			}

			sol.push_back(acc);
		}

		string str;
		vector<string> output;

		int ptr = 0;

		for (int i = 0; i < sol.size(); i++)
		{
			int row, col;

			for (int j = 0; j < sol[i]; j++)
			{
				str.push_back(type[i]);

				if (!((ptr + 1) % m))
				{
					output.push_back(str);

					str.clear();
				}

				ptr++;
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (!(i % 2))
			{
				printf("%s\n", output[i].c_str());
			}

			else
			{
				for (int j = m - 1; j >= 0; j--)
				{
					printf("%c", output[i][j]);
				}

				printf("\n");
			}
		}
	}

 	return 0;
}