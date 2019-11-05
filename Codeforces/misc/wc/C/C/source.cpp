#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> cookie) {
	int answer = 0;
	int psum[2001];
	int sum = 0;
	int diff;
	int i, j;
	int n;
	multimap<int, multimap<int, int>> cand;
	multimap<int, multimap<int, int>>::iterator mit;
	multimap<int, int>::iterator it, it2;
	multimap<int, int> newval;
	int max = 0;

	n = cookie.size();
	psum[0] = 0;

	for (i = 0; i < n; i++)
	{
		sum += cookie[i];

		psum[i + 1] = sum;
	}

	for (i = 0; i <= n - 1; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			diff = psum[j] - psum[i];

			mit = cand.find(diff);

			newval.clear();

			if (mit == cand.end())
			{
				mit = cand.insert(pair<int, multimap<int, int>>(diff, newval));

				mit->second.insert(pair<int, int>(i + 1, j));
			}

			else
			{
				/*
				it = mit->second.find(i);

				if (it == mit->second.end())
				{
					mit->second[i] = j;
				}
				*/

				mit->second.insert(pair<int, int>(i + 1, j));
			}
		}
	}

	mit = cand.end();

	while (--mit != cand.begin())
	{
		it2 = it = mit->second.begin();

		while (it != mit->second.end())
		{
			while (++it2 != mit->second.end() && it2->first <= it->second);

			while (++it2 != mit->second.end())
			{
				if (it->second == it2->first - 1)
				{
					answer = mit->first;

					return answer;
				}
			}

			it++;
		}
	}

	it2 = it = mit->second.begin();

	while (it != mit->second.end())
	{
		while (++it2 != mit->second.end() && it2->first <= it->second)
		{
			if (it->first == it2->second - 1)
			{
				answer = mit->first;

				return answer;
			}
		}

		it++;
	}


	return answer;
}

int main()
{
	vector<int> input = { 1,1,2,3 };
	int answer;

	answer = solution(input);

	return 0;
}