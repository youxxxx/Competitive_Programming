#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int n, i;
	char input[100001];
	vector<pair<int,int>> seq;
	string str;
	bool gold = false;
	int start;
	int max = 0;

	scanf("%d", &n);
	scanf("%s", input);

	str = input;

	for (i = 0; i < n; i++)
	{
		if (!gold)
		{
			if (str[i] == 'G')
			{
				gold = true;

				start = i;
			}
		}
		
		else
		{
			if (str[i] == 'S')
			{
				gold = false;

				seq.push_back(pair<int, int>(start, i));
			}
		}
	}

	if (gold)
	{
		seq.push_back(pair<int, int>(start, n));
	}

	if (seq.empty())
	{
		printf("0\n");
	}

	else if (seq.size() == 1)
	{
		printf("%d\n", seq[0].second - seq[0].first);
	}

	else if (seq.size() == 2)
	{
		if (seq[1].first == seq[0].second + 1)
		{
			printf("%d\n", seq[1].second - seq[0].first - 1);
		}

		else
		{
			max = seq[0].second - seq[0].first;

			if (seq[1].second - seq[1].first - 1> max)
			{
				max = seq[1].second - seq[1].first - 1;
			}

			printf("%d\n", max);
		}
	}

	else
	{
		for (i = 0; i < seq.size() - 1; i++)
		{
			if (seq[i].second - seq[i].first > max)
			{
				max = seq[i].second - seq[i].first;
			}

			if (seq[i + 1].first == seq[i].second + 1)
			{
				if (seq[i + 1].second - seq[i].first > max)
				{
					max = seq[i + 1].second - seq[i].first;
				}
			}
		}

		if (seq.back().second - seq.back().first > max)
		{
			max = seq.back().second - seq.back().first;
		}

		printf("%d\n", max);
	}

	return 0;
}