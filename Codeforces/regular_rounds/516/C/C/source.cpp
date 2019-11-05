#include<cstdio>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int n;
	char input[100001];
	int i, j;
	int cnt[26] = { 0, };
	string s, sol;
	string part1, paste;
	vector<pair<int,int>> even, odd;

	scanf("%d", &n);

	scanf("%s", input);

	s = input;

	for (i = 0; i < n; i++)
	{
		cnt[s[i] - 'a']++;
	}
	/*
	for (i = 0; i < 26; i++)
	{
		if (cnt[i])
		{
			if (cnt[i] % 2)
			{
				even.push_back(pair<int,int>(i,cnt[i]));
			}

			else
			{
				odd.push_back(pair<int, int>(i, cnt[i]));
			}
		}
	}

	if (even.size() == odd.size())
	{
		for (i = 0; i < even.size(); i++)
		{
			for(j=0;j<e)
		}
	}
	*/

	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < cnt[i]; j++)
		{
			printf("%c", i + 'a');
		}
	}

	return 0;
}