#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int n, k;
	string str;
	char input[200001];
	int seq[26] = { 0, };
	int cnt[26] = { 0, };
	int i;
	int max = 0;
	char prev;

	scanf("%d %d", &n, &k);

	scanf("%s", input);

	str = input;

	prev = str[0];

	for (i = 0; i < n; i++)
	{
		if (str[i] != prev)
		{
			cnt[prev - 'a'] = 0;
		}

		cnt[str[i] - 'a']++;

		seq[str[i] - 'a'] += cnt[str[i] - 'a'] / k;

		cnt[str[i] - 'a'] %= k;

		prev = str[i];
	}

	for (i = 0; i < 26; i++)
	{
		if (seq[i] > max)
		{
			max = seq[i];
		}
	}

	printf("%d\n", max);

	return 0;
}