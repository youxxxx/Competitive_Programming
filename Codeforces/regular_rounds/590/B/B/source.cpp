#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<deque>

using namespace std;

int main()
{
	int n, m;
	int i;
	set<int> tot;
	set<int>::iterator ret;
	deque<int> list;
	int input, del;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		ret = tot.find(input);

		if (ret == tot.end())
		{
			if (list.size() == m)
			{
				del = list.back();
				list.pop_back();

				tot.erase(del);
			}

			list.push_front(input);
			tot.insert(input);
		}
	}

	printf("%d\n", list.size());

	while (!list.empty())
	{
		printf("%d ", list.front());

		list.pop_front();
	}

	return 0;
}