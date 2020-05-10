#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	char *input;
	int t, z;
	string str;
	int i, n;
	int cnt;
	vector<int> cut;

	input = new char[100001];

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%s", input);

		str = input;

		n = str.size();

		cnt = 0;

		for (i = 0; i < n; i++)
		{
			if (str[i] == str[i + 1])
			{
				cnt++;

				cut.push_back(i);
			}

			if (cnt == 3)
			{
				break;
			}
		}

		if (str[n - 1] == str[0])
		{
			cnt++;

			cut.push_back(n - 1);
		}

		if (cnt == 0)
		{
			printf("yes\n");
		}

		else if (cnt == 1)
		{
			printf("no\n");
		}

		else if (cnt == 2)
		{
			if (str[cut[0]] != str[cut[1]])
			{
				printf("yes\n");
			}

			else
			{
				printf("no\n");
			}
		}

		else
		{
			printf("no\n");
		}

		cut.clear();
	}

	return 0;
}