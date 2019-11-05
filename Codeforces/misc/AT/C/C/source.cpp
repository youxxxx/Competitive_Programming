#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool func(pair<pair<long long int, long long int>, pair<long long int, long long int>> &a, pair<pair<long long int, long long int>, pair<long long int, long long int>> &b)
{
	return a.first.first<b.first.first || a.first.second<b.second.second || a.second.first>b.second.first || a.second.second > b.second.second;
}

int main()
{
	vector<pair<pair<long long int, long long int>, pair<long long int, long long int>>> rect;
	long long int input[4];
	pair<pair<long long int, long long int>, pair<long long int, long long int>> data;
	vector<pair<pair<long long int, long long int>, pair<long long int, long long int>>> area1;
	bool *empty;
	int n;
	int i, j, k;

	scanf("%I64d", &n);

	empty = new bool[n];

	for (i = 0; i < n; i++)
	{
		empty[i] = false;

		for (j = 0; j < 4; j++)
		{
			scanf("%I64d", &input[j]);
		}

		data.first.first = input[0];
		data.first.second = input[1];
		data.second.first = input[2];
		data.second.second = input[3];

		rect.push_back(data);
	}

	//sort(rect.begin(), rect.end(), func);
	
	/*
	area1.push_back(rect[0]);
		
	for (i = 1; i < n; i++)
	{
		area0 = area1;

		for (j = area1.size() - 1; j >= 0; j--)
		{
			input[0] = area1[j].first.first;

			if (input[0] > rect[i].first.first)
			{
				input[0] = rect[i].first.first;
			}

			input[1] = area1[j].first.second;

			if (input[1] > rect[i].first.second)
			{
				input[1] = rect[i].first.second;
			}

			input[2] = area1[j].second.first;

			if (input[2] > rect[i].second.first)
			{
				input[2] = rect[i].second.first;
			}

			input[3] = area1[j].second.second;

			if (input[2] > rect[i].second.second)
			{
				input[2] = rect[i].second.second;
			}

			area1[j].first.first = input[0];
			area1[j].first.second = input[1];
			area1[j].second.first = input[2];
			area1[j].second.second = input[3];

			if (area1[j].first.first > area1[j].second.first || area1[j].first.second > area1[j].second.second)
			{
				area1.erase(area1.begin() + j);
			}
		}
	}
	*/

	area1.push_back(rect[1]);

	for (i = 1; i < n; i++)
	{
		area1.push_back(rect[0]);
	}



	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i - 2; j++)
		{
			for (k = 0; k < j; k++)
			{
				if (!empty[j] && !empty[k])
				{
					if(area1[j].first.first<=area1[k].first.first && area1[j].second.first>=area1[k].second.first)
					{
						if (area1[j].first.second <= area1[k].first.second && area1[j].second.second >= area1[k].second.second)
						{
							empty[k] = true;
						}
					}

					else if (area1[k].first.first <= area1[j].first.first && area1[k].second.first >= area1[j].second.first)
					{
						if (area1[k].first.second <= area1[j].first.second && area1[k].second.second >= area1[j].second.second)
						{
							empty[j] = true;
						}
					}
				}
			}
		}

		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}

			if (!empty[j])
			{
				if (area1[j].second.first < rect[i].first.first)
				{
					empty[j] = true;
				}

				else if (area1[j].second.second < rect[i].first.second)
				{
					empty[j] = true;
				}

				else if (rect[i].second.first < area1[j].first.first)
				{
					empty[j] = true;
				}

				else if (rect[i].second.second < area1[j].first.second)
				{
					empty[j] = true;
				}

				if (empty[j])
				{
					continue;
				}


				input[0] = area1[j].first.first;

				if (input[0] < rect[i].first.first)
				{
					input[0] = rect[i].first.first;
				}

				input[1] = area1[j].first.second;

				if (input[1] < rect[i].first.second)
				{
					input[1] = rect[i].first.second;
				}

				input[2] = area1[j].second.first;

				if (input[2] > rect[i].second.first)
				{
					input[2] = rect[i].second.first;
				}

				input[3] = area1[j].second.second;

				if (input[3] > rect[i].second.second)
				{
					input[3] = rect[i].second.second;
				}

				area1[j].first.first = input[0];
				area1[j].first.second = input[1];
				area1[j].second.first = input[2];
				area1[j].second.second = input[3];
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		if (!empty[i])
		{
			printf("%I64d %I64d", area1[i].first.first, area1[i].first.second);

			break;
		}
	}

	return 0;
}