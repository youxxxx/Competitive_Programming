#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long n, m;
	char input[100001];
	string str;
	vector<string> winner = { "tokitsukaze","quailty","once again" };
	long long i, j;
	long long left[2], right[2];
	long long cnt[2] = { 0, };
	long long cur[2] = { 0, };
	long long card, del;
	bool no[2] = { 0, };
	bool second = false;
	bool quwin = true;

	scanf("%lld %lld", &n, &m);

	if (n == m)
	{
		printf("%s\n", winner[0].c_str());

		return 0;
	}

	scanf("%s", input);
	str = input;

	for (i = 0; i < n; i++)
	{
		cnt[str[i] - '0']++;
	}

	for (i = 0; i < m; i++)
	{
		card = str[i] - '0';

		cur[card]++;
	}

	left[0] = left[1] = -1;
	right[0] = right[1] = -1;

	for (i = m; i < n; i++)
	{
		card = str[i] - '0';

		if (card == 0)
		{
			left[0] = i;

			break;
		}
	}

	for (i = m; i < n; i++)
	{
		card = str[i] - '0';

		if (card == 1)
		{
			left[1] = i;

			break;
		}
	}

	for (i = n - 1; i >= m; i--)
	{
		card = str[i] - '0';

		if (card == 0)
		{
			right[0] = i;

			break;
		}
	}

	for (i = n - 1; i >= m; i--)
	{
		card = str[i] - '0';

		if (card == 1)
		{
			right[1] = i;

			break;
		}
	}

	if (cnt[0] - cur[0] == 0 || cnt[1] - cur[1] == 0)
	{
		printf("%s\n", winner[0].c_str());

		return 0;
	}

	for (i = 0; i <= 1; i++)
	{
		if (!(cnt[i] - cur[i] <= m && (left[i]==-1 || right[i] - left[i] < m)))
		{
			break;
		}
	}

	if (i == 2)
	{
		second = true;
	}

	quwin = quwin&&second;

	for (i = m; i < n; i++)
	{
		second = false;
		card = str[i] - '0';
		del = str[i - m] - '0';

		cur[card]++;
		cur[del]--;
		
		if (cnt[0] - cur[0] == 0 || cnt[1] - cur[1] == 0)
		{
			printf("%s\n", winner[0].c_str());

			return 0;
		}

		if (right[card] == i)
		{
			right[card] = -1;
		}

		if (left[card] == i)
		{
			left[card] = -1;

			for (j = i + 1; j < n; j++)
			{
				if (str[j] - '0' == card)
				{
					left[card] = j;

					break;
				}
			}

			if (left[card] == -1)
			{
				right[card] = -1;
			}
		}

		if (i - m < left[del])
		{
			left[del] = i - m;
		}

		if (right[del] == -1 || i - m > right[del])
		{
			right[del] = i - m;
		}

		for (j = 0; j <= 1; j++)
		{
			if (!(cnt[j] - cur[j] <= m && (left[j] == -1 || right[j] - left[j] < m)))
			{
				break;
			}
		}

		if (j == 2)
		{
			second = true;
		}

		quwin = quwin&&second;
	}

	if (quwin)
	{
		printf("%s\n", winner[1].c_str());
	}

	else
	{
		printf("%s\n", winner[2].c_str());
	}

	return 0;
}