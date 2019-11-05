#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>

using namespace std;

int main()
{
	int n;
	int i;
	vector<long long> arr;
	long long input, max = 0;
	stack<pair<long long, int>> s;
	pair<long long, int> cur;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);

		if (input > max)
		{
			max = input;
		}
	}

	if (n == 1)
	{
		printf("YES\n");
		
		return 0;
	}

	cur = pair<long long, int>(arr[0], 0);

	s.push(cur);

	for (i = 1; i < n; i++)
	{
		cur = s.top();

		if (arr[i] > arr[i-1])
		{
			while (!s.empty() && s.top().first <= arr[i])
			{
				cur = s.top();

				s.pop();

				if (((i - cur.second) % 2))
				{
					if (cur.first == arr[i])
					{
						break;

						s.pop();
					}

					printf("NO\n");

					return 0;
				}
			}

			if (cur.first == arr[i])
			{
				s.push(pair<long long, int>(arr[i], cur.second));
			}

			else
			{
				s.push(pair<long long, int>(arr[i], cur.second));
			}
		}

		else if (arr[i] < arr[i] - 1)
		{
			s.push(pair<long long, int>(arr[i], i));
		}
	}

	cur = s.top();

	if (cur.first < max)
	{
		while (!s.empty() && s.top().first < max)
		{
			cur = s.top();

			s.pop();

			if (!((n - cur.second) % 2))
			{
				printf("NO\n");

				return 0;
			}
		}
	}
	
	printf("YES\n");

	return 0;
}