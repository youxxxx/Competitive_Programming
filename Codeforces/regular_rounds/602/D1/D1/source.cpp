#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool func(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first > b.first || a.first == b.first&&a.second < b.second;
}

bool func2(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second < b.second;
}

int main()
{
	int n;
	vector<pair<int, int>> arr;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		arr.push_back(make_pair(input,i));
	}

	sort(arr.begin(), arr.end(), func);

	vector<pair<pair<int, int>,int>> query;
	int m;

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int size, pos;

		scanf("%d %d", &size, &pos);

		query.push_back(make_pair(make_pair(size, pos), i));
	}

	sort(query.begin(), query.end());

	vector<pair<int, int>> box, answer;
	vector<pair<int, int>>::iterator it;

	for (int i = 0; i < m; i++)
	{
		vector<pair<int, int>>::iterator ret;

		for (int j = box.size(); j < query[i].first.first; j++)
		{
			ret = lower_bound(box.begin(), box.end(), arr[j], func2);

			box.insert(ret, arr[j]);
		}

		answer.push_back(make_pair(box[query[i].first.second - 1].first, query[i].second));
	}

	sort(answer.begin(), answer.end(), func2);

	for (int i = 0; i < m; i++)
	{
		printf("%d\n", answer[i].first);
	}

	return 0;
}