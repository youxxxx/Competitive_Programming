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
		vector<string> arr;
		string str;
		char input[11];
		int n;
		bool taken[4][10] = { 0, };

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%s", input);

			str = input;

			arr.push_back(str);

			for (int j = 0; j < 4; j++)
			{
				taken[j][str[j]-'0'] = true;
			}
		}

		int ptr = 0;
		int cnt = 0;

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (arr[i] == arr[j])
				{
					while (taken[0][ptr])
					{
						ptr++;
					}

					arr[j][0] = ptr + '0';

					taken[0][ptr] = true;

					cnt++;
				}
			}
		}

		printf("%d\n", cnt);

		for (int i = 0; i < n; i++)
		{
			printf("%s\n", arr[i].c_str());
		}
	}

	return 0;
}