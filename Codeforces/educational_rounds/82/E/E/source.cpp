#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<set>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		string s, t;
		char input[401];

		scanf("%s", input);
		s = input;
		scanf("%s", input);
		t = input;

		int n, m;

		n = s.size();
		m = t.size();

		int ptr = 0;

		for (int i = 0; i < n; i++)
		{
			if (ptr == m)
			{
				break;
			}

			if (s[i] == t[ptr])
			{
				ptr++;
			}
		}

		if (ptr == m)
		{
			printf("YES\n");

			continue;
		}

		bool found = false;

		for (int i = 1; i < m; i++)
		{
			int ptr1, ptr2;
			int cnt1[26] = { 0, }, cnt2[26] = { 0, };

			for (int j = 0; j < i; j++)
			{
				cnt1[t[j] - 'a']++;
			}

			for (int j = i; j < m; j++)
			{
				cnt2[t[j] - 'a']++;
			}

			ptr1 = 0;
			ptr2 = i;

			for (int j = 0; j < n; j++)
			{
				if (ptr1 == i)
				{
					for (int k = j; k < n; k++)
					{
						if (ptr2 == m)
						{
							break;
						}

						if(s[k] == t[ptr2])
						{
							ptr2++;
						}
					}

					break;
				}

				if (ptr2 == m)
				{
					for (int k = j; k < n; k++)
					{
						if (ptr1 == i)
						{
							break;
						}

						if (s[k] == t[ptr1])
						{
							ptr1++;
						}
					}

					break;
				}

				if (s[j] == t[ptr1] && s[j] == t[ptr2])
				{
					if (cnt1[s[j] - 'a'] < cnt2[s[j] - 'a'])
					{
						ptr1++;
						cnt1[s[j] - 'a']--;
					}

					else
					{
						ptr2++;
						cnt2[s[j] - 'a']--;
					}
				}

				else if (s[j] == t[ptr1])
				{
					ptr1++;
					cnt1[s[j] - 'a']--;
				}

				else if (s[j] == t[ptr2])
				{
					ptr2++;
					cnt2[s[j] - 'a']--;
				}
			}

			if (ptr1 == i&&ptr2 == m)
			{
				found = true;

				break;
			}
		}

		if (found)
		{
			printf("YES\n");
		}
		
		else
		{
			printf("NO\n");
		}
	}

	return 0;
}