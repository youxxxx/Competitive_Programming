#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

bool func(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.first < b.first || a.first == b.first && a.second < b.second;
}

class comp
{
	bool operator() (const pair<long long, long long> &a, const pair<long long, long long> &b) const
	{
		return a.second > b.second;
	}
};

int main()
{
	int t, z;
	int n;
	char input[100001];
	string str;
	int min;
	int i, j;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		scanf("%s", input);

		str = input;

		min = n;

		for (i = n - 1; i >= 1; i--)
		{
			if (str[i] == str[0])
			{
				if (n - i < min)
				{
					min = n - i;
				}

				for (j = 1; j < min; j++)
				{
					if (str[i + j] != str[j])
					{
						min = j;

						break;
					}
				}
			}
		}

		printf("%s\n", (str.substr(0, min)).c_str());
	}

	return 0;
}