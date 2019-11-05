#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<set>

using namespace std;

int main()
{
	int tc, cases;
	int n, d;
	long long a, b;
	int i;
	int input;
	vector<int> arr;
	set<int> list;
	set<int>::iterator it;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d %d", &n, &d);

		//arr.clear();
		list.clear();

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			//arr.push_back(input);

			list.insert(input);
		}

		//sort(arr.begin(), arr.end(),greater<int>());

		it = list.end();

		it--;
		
		i = 0;

		while (1)
		{
			if (*it - i*d <= 0)
			{
				break;
			}

			i++;

			if (it == list.begin())
			{
				break;
			}

			it--;
		}

		printf("%d\n", i);
	}

	return 0;
}