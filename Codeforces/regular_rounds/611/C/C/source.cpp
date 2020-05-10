#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<stack>

using namespace std;

class comp
{
public:
	bool operator() (const pair<int, int> &a, const pair<int, int> &b)
	{
		return a.first < b.first;
	}
};

int main()
{
	int n;
	int give[200001];
	bool take[200001] = { 0, };
	stack<int> s;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &give[i]);

		take[give[i]] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!take[i])
		{
			s.push(i);
		}
	}

	int last = 0;

	for (int i = 1; i <= n; i++)
	{
		if (!give[i])
		{
			int temp;

			if (s.top() == i)
			{
				temp = s.top();
				s.pop();

				if (s.empty())
				{
					give[i] = give[last];
					give[last] = i;
				}

				else
				{
					give[i] = s.top();
					s.pop();

					s.push(temp);
				}
			}

			else
			{
				give[i] = s.top();

				s.pop();
			}

			last = i;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", give[i]);
	}

	return 0;
}