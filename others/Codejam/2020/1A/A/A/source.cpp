#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 1; tc <= cases; tc++)
	{
		vector<string> arr;
		vector<string> first, last;

		int n;

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			string str;
			char input[101];

			scanf("%s", input);
			str = input;

			arr.push_back(str);

			int ptr = str.size();

			for (int j = 0; j < str.size(); j++)
			{
				if (str[j] == '*')
				{
					ptr = j;

					break;
				}
			}

			if (ptr == str.size())
			{
				first.push_back(str);
				last.push_back(str);

				continue;
			}

			first.push_back(str.substr(0, ptr));

			ptr = -1;

			for (int j = str.size() - 1; j >= 0; j--)
			{
				if (str[j] == '*')
				{
					ptr = j;

					break;
				}
			}

			last.push_back(str.substr(ptr + 1));
		}

		bool valid = true;

		string fcand;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < first[i].size(); j++)
			{
				if (j >= fcand.size())
				{
					fcand.push_back(first[i][j]);
				}

				else
				{
					if (first[i][j] != fcand[j])
					{
						valid = false;

						break;
					}
				}
			}

			if (!valid)
			{
				break;
			}
		}

		if (!valid)
		{
			printf("Case #%d: *\n", tc);

			continue;
		}

		string lcand;

		for (int i = 0; i < 101; i++)
		{
			lcand.push_back('*');
		}

		int ptr = 100;

		for (int i = 0; i < n; i++)
		{
			for (int j = last[i].size() - 1; j >= 0; j--)
			{
				if (ptr == 100 - (last[i].size() - 1 - j))
				{
					lcand[ptr--] = last[i][j];
				}

				else
				{
					if (last[i][j] != lcand[100 - (last[i].size() - 1 - j)])
					{
						valid = false;

						break;
					}
				}
			}

			if (!valid)
			{
				break;
			}
		}

		if (!valid)
		{
			printf("Case #%d: *\n", tc);

			continue;
		}

		string sol;

		sol.append(fcand);

		for (int i = 0; i < n; i++)
		{
			for (int j = first[i].size(); j < arr[i].size() - last[i].size(); j++)
			{
				if (arr[i][j] != '*')
				{
					sol.push_back(arr[i][j]);
				}
			}
		}

		sol.append(lcand.substr(ptr + 1));

		printf("Case #%d: %s\n", tc, sol.c_str());
	}

	return 0;
}