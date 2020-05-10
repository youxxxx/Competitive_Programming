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
		char input[100001];
		string str;

		scanf("%s", &input);
		str = input;

		bool valid = true;

		for (int i = 0; i < str.size() - 1; i++)
		{
			if (str[i] == str[i + 1] && str[i] != '?')
			{
				valid = false;

				break;
			}
		}

		if (!valid)
		{
			printf("-1\n");
		}

		else
		{
			for (int i = 0; i < str.size(); i++)
			{
				bool taken[3] = { 0, };

				if (str[i] == '?')
				{
					if (i > 0)
					{
						taken[str[i - 1] - 'a'] = true;
					}

					if (i < str.size() - 1)
					{
						taken[str[i + 1] - 'a'] = true;
					}

					for (int j = 0; j < 3; j++)
					{
						if (!taken[j])
						{
							str[i] = j + 'a';

							break;
						}
					}
				}
			}

			printf("%s\n", str.c_str());
		}
	}

	return 0;
}