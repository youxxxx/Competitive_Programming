#include<cstdio>
#include<string>

using namespace std;

int main()
{
	int n, m;
	int i;
	string s, t;
	char input[200001];
	int ptr = -1, ptr2;

	scanf("%d %d", &n, &m);

	ptr2 = n;

	scanf("%s", input);
	s = input;
	scanf("%s", input);
	t = input;

	if (m < n - 1)
	{
		printf("NO");

		return 0;
	}

	while (ptr < n - 1 && s[++ptr] != '*')
	{
		if (s[ptr] != t[ptr])
		{
			printf("NO");

			return 0;
		}
	}

	if (ptr == n - 1 && n == m)
	{
		printf("YES");

		return 0;
	}

	ptr--;

	while (ptr2 > 0 && s[--ptr2] != '*')
	{
		if (s[ptr2] != t[m - n + ptr2])
		{
			printf("NO");

			return 0;
		}
	}

	if (ptr2 == ptr + 1)
	{
		printf("YES");
	}

	else
	{
		printf("NO");
	}

	return 0;
}