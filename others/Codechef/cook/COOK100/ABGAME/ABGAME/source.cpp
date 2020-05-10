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
	int ab, a, b;
	vector<pair<int, char>> points;

	input = new char[200001];

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%s", input);

		str = input;

		ab = 0;
		a = 0;
		b = 0;

		for (i = 0; i < str.size(); i++)
		{
			if (str[i] != '.')
			{
				if (str[i] == 'A')
				{
					points.push_back(pair<int, char>(i, 'A'));
				}

				else
				{
					points.push_back(pair<int, char>(i, 'B'));
				}
			}
		}

		n = points.size();

		for (i = 0; i < n / 2; i++)
		{
			if (points[i * 2].second == points[i * 2 + 1].second)
			{
				if (points[i * 2].second=='A')
				{
					a += points[i * 2 + 1].first - points[i * 2].first - 1;
				}

				else
				{
					b += points[i * 2 + 1].first - points[i * 2].first - 1;
				}
			}

			else if(points[i * 2 + 1].first - points[i * 2].first > 1)
			{
				ab++;
			}
		}

		if (n % 2)
		{
			if (points[n - 1].second=='A')
			{
				a += str.size() - 1 - points[n - 1].first;
			}

			else
			{
				b += str.size() - 1 - points[n - 1].first;
			}
		}

		/*
		if (ab % 2)
		{
			if (a >= b)
			{
				printf("A\n");
			}

			else
			{
				printf("B\n");
			}
		}
		
		else
		{ 
			if (a > b)
			{
				printf("A\n");
			}

			else
			{
				printf("B\n");
			}
		}
		*/

		a += ab % 2;

		if (a > b)
		{
			printf("A\n");
		}

		else
		{
			printf("B\n");
		}

		points.clear();
	}

	return 0;
}