#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	char input[1000001];
	string str1, str2;
	int i, j;
	int n, m;
	int loop, t;
	int ptr1, ptr2;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &t);

	for (loop = 0; loop < t; loop++)
	{
		scanf("%s", input);
		str1 = input;
		scanf("%s", input);
		str2 = input;

		if (str2.size() < str1.size())
		{
			printf("NO\n");

			continue;
		}

		ptr1 = ptr2 = 0;
		n = str1.size();
		m = str2.size();

		while (ptr1 != n&&ptr2 != m)
		{
			if (str1[ptr1] == str2[ptr2])
			{
				ptr1++;
				ptr2++;

				continue;
			}

			if (ptr1 == 0)
			{
				break;
			}

			if (str2[ptr2] != str1[ptr1 - 1])
			{
				break;
			}

			while (ptr2 != m &&str2[ptr2] == str1[ptr1 - 1])
			{
				ptr2++;
			}
		}

		if (ptr1 != n)
		{
			printf("NO\n");

			continue;
		}

		if (ptr2 != m)
		{
			while (ptr2 != m)
			{
				if (str2[ptr2] != str1.back())
				{
					break;
				}

				ptr2++;
			}

			if (ptr2 != m)
			{
				printf("NO\n");

				continue;
			}
		}

		printf("YES\n");
	}

	return 0;
}