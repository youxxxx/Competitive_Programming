#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		char input[100001];
		string str;

		scanf("%d", &n);

		scanf("%s", input);
		str = input;

		int ptr1 = 0;

		while (ptr1 < n&&str[ptr1] == '0')
		{
			ptr1++;
		}

		int ptr2 = n - 1;

		while (ptr2 >= 0&&str[ptr2] == '1')
		{
			ptr2--;
		}

		if (ptr1 > ptr2)
		{
			printf("%s\n", str.c_str());

			continue;
		}

		string sol;

		for (int i = 0; i < ptr1; i++)
		{
			sol.push_back(str[i]);
		}

		sol.push_back('0');

		for (int i = ptr2 + 1; i < n; i++)
		{
			sol.push_back(str[i]);
		}

		printf("%s\n", sol.c_str());
	}

	return 0;
}