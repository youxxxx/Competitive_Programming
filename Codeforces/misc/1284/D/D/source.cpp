#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

using namespace std;

bool func(pair<pair<int, int>, pair<int, int>> &a, pair<pair<int, int>, pair<int, int>> &b)
{
	return a.first.second < b.first.second;
}

class comp
{
public:
	bool operator()(pair<pair<int, int>, pair<int, int>> &a, pair<pair<int, int>, pair<int, int>> &b)
	{
		return a.first.second > b.first.second;
	}
};

int main()
{
	vector<pair<pair<int, int>, pair<int, int>>> arr, arr2;
	vector<pair<pair<int, int>, pair<int, int>>> lf, lf2;
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int al, ar, bl, br;

		scanf("%d %d %d %d", &al, &ar, &bl, &br);

		arr.push_back({ { al,ar },{ bl,br } });
		lf.push_back({ { al,ar },{ bl,br } });

		arr2.push_back({ { bl,br },{ al,ar } });
		lf2.push_back({ { bl,br },{ al,ar } });
	}

	sort(arr.begin(), arr.end(), func);
	sort(arr2.begin(), arr2.end(), func);
	sort(lf.begin(), lf.end());
	sort(lf2.begin(), lf2.end());

	{
		int ptr = 0;
		map<int, int> left, right;
		priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, comp> pq;

		for (int i = 0; i < n; i++)
		{
			while (!pq.empty() && pq.top().first.second < arr[i].first.first)
			{
				map<int, int>::iterator ret;

				ret = left.find(pq.top().second.first);

				if (--ret->second == 0)
				{
					left.erase(ret);
				}

				ret = right.find(pq.top().second.second);

				if (--ret->second == 0)
				{
					right.erase(ret);
				}

				pq.pop();
			}

			while (ptr < n&&lf[ptr].first.first <= arr[i].first.second)
			{
				map<int, int>::iterator ret;

				ret = left.find(lf[ptr].second.first);

				if (ret == left.end())
				{
					left[lf[ptr].second.first] = 1;
				}

				else
				{
					ret->second++;
				}

				ret = right.find(lf[ptr].second.second);

				if (ret == right.end())
				{
					right[lf[ptr].second.second] = 1;
				}

				else
				{
					ret->second++;
				}

				pq.push(arr[ptr++]);
			}

			map<int, int>::iterator ret;

			ret = left.end();
			ret--;

			if (ret->first == arr[i].second.first&&ret->second == 1)
			{
			}

			else
			{
				if (ret->first > arr[i].second.second)
				{
					printf("NO\n");

					return 0;
				}
			}

			ret = right.begin();

			if (ret->first == arr[i].second.second&&ret->second == 1)
			{
			}

			else
			{
				if (ret->first < arr[i].second.first)
				{
					printf("NO\n");

					return 0;
				}
			}
		}
	}

	{
		int ptr = 0;
		map<int, int> left, right;
		priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, comp> pq;

		for (int i = 0; i < n; i++)
		{
			while (!pq.empty() && pq.top().first.second < arr2[i].first.first)
			{
				map<int, int>::iterator ret;

				ret = left.find(pq.top().second.first);

				if (--ret->second == 0)
				{
					left.erase(ret);
				}

				ret = right.find(pq.top().second.second);

				if (--ret->second == 0)
				{
					right.erase(ret);
				}

				pq.pop();
			}

			while (ptr < n&&lf2[ptr].first.first <= arr2[i].first.second)
			{
				map<int, int>::iterator ret;

				ret = left.find(lf2[ptr].second.first);

				if (ret == left.end())
				{
					left[lf2[ptr].second.first] = 1;
				}

				else
				{
					ret->second++;
				}

				ret = right.find(lf2[ptr].second.second);

				if (ret == right.end())
				{
					right[lf2[ptr].second.second] = 1;
				}

				else
				{
					ret->second++;
				}

				pq.push(arr2[ptr++]);
			}

			map<int, int>::iterator ret;

			ret = left.end();
			ret--;

			if (ret->first == arr2[i].second.first&&ret->second == 1)
			{
			}

			else
			{
				if (ret->first > arr2[i].second.second)
				{
					printf("NO\n");

					return 0;
				}
			}

			ret = right.begin();

			if (ret->first == arr2[i].second.second&&ret->second == 1)
			{
			}

			else
			{
				if (ret->first < arr2[i].second.first)
				{
					printf("NO\n");

					return 0;
				}
			}
		}
	}

	printf("YES\n");

	return 0;
}