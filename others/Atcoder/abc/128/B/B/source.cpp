#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>

using namespace std;

bool func(const pair<pair<string, int>, int> &a, const pair<pair<string, int>, int> &b)
{
	return a.first.first < b.first.first || a.first.first == b.first.first&&a.first.second > b.first.second;
}

int main()
{
	vector<pair<pair<string, int>,int>> list;
	char input[20];
	int input2;
	string str;
	int n;
	int i;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s %d", input, &input2);

		str = input;

		list.push_back(pair<pair<string, int>, int>(pair<string, int>(str, input2), i + 1));
	}

	sort(list.begin(), list.end(), func);

	for (i = 0; i < n; i++)
	{
		printf("%d\n", list[i].second);
	}

	return 0;
}