#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	char input[100001];
	string str, sol;
	int n;
	int i;
	int start = 0;
	vector<pair<int, int>> arr;
	int cur, cnt = 1;
	int lmax[2] = { 0, }, totmax = 0;
	int temp[2];

	scanf("%s", input);

	str = input;

	n = str.size();

	cur = str[0];

	for (i = 0; i < n; i++)
	{
		str[i] -= '0';
	}

	for (i = 1; i < n; i++)
	{
		if (str[i] != cur)
		{
			arr.push_back(make_pair(cur, cnt));

			cnt = 1;
			cur = !cur;
		}

		else
		{
			cnt++;
		}
	}

	arr.push_back(make_pair(cur, cnt));

	start = arr.size() - 1;

	if (arr.back().first == 0)
	{
		lmax[0] = arr.back().second;

		totmax = arr.back().second;

		start = arr.size() - 2;
	}

	for (i = start; i - 1 >= 0; i-=2)
	{

	}



	return 0;
}