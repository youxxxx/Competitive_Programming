#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

#define MOD 998244353 

using namespace std;

int main()
{
	int n;
	char input[1000001];
	string str, cand, rev;
	int i, j, k;
	int ptr1, ptr2;
	vector<int> idx[3];

	scanf("%s", input);

	str = input;
	n = str.size();
	
	for (i = 0; i < n; i++)
	{
		idx[str[i] - 'a'].push_back(i);
	}

	for (i = 0; i < 3; i++)
	{
		cand.clear();

		for (j = 0; j < ((int)idx[i].size() - 1) / 2; j++)
		{
			cand.push_back('a' + (char)i);

			ptr1 = idx[i][j] + 1;
			ptr2 = idx[i][(int)idx[i].size() - j - 1] - 1;

			if (abs(ptr1 - idx[i][j + 1]) < abs(ptr2 - idx[i][(int)idx[i].size() - j - 2]))
			{
				for (k = ptr1; k < idx[i][j + 1]; k++)
				{
					cand.push_back(str[k]);
				}
			}

			else if (abs(ptr1 - idx[i][j + 1]) > abs(ptr2 - idx[i][(int)idx[i].size() - j - 2]))
			{
				for (k = ptr2; k > idx[i][(int)idx[i].size() - j - 2]; k--)
				{
					cand.push_back(str[k]);
				}
			}

			else
			{
				for (k = ptr1; k < idx[i][j + 1] - 1; k++)
				{
					cand.push_back(str[k]);
				}
			}
		}

		if ((int)idx[i].size() % 2)
		{
			if (cand.size() * 2 + 1 >= n / 2)
			{
				if (cand.empty())
				{
					printf("%c", 'a' + (char)i);

					return 0;
				}

				printf("%s", cand.c_str());
				printf("%c", 'a' + (char)i);
				rev = cand;
				reverse(rev.begin(), rev.end());
				printf("%s", rev.c_str());
				printf("\n");

				return 0;
			}
		}
		
		else if (idx[i].size() != 0)
		{
			cand.push_back('a' + (char)i);

			ptr1 = idx[i][(int)idx[i].size() / 2 - 1] + 1;
			ptr2 = idx[i][(int)idx[i].size() / 2] - 1;

			if (cand.size() * 2 + (ptr2 - ptr1) + !((ptr2 - ptr1) % 2) >= n / 2)
			{
				rev = cand;
				reverse(rev.begin(), rev.end());

				for (k = ptr1; k <= ptr2 - (ptr2 - ptr1) % 2; k++)
				{
					cand.push_back(str[k]);
				}

				printf("%s", cand.c_str());
				printf("%s", rev.c_str());
				printf("\n");

				return 0;
			}
		}
	}

	printf("IMPOSSIBLE\n");

	return 0;
}