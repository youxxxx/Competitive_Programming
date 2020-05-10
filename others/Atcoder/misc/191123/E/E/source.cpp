#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<cstring>
#include<deque>

using namespace std;

int main()
{
	int n;
	vector<int> undefined, defined, red, blue;
	int r = 0, b = 0;
	char color[200];

	memset(color, -1, sizeof(color));

	scanf("%d", &n);

	for (int i = 1; i <= 2 * n; i++)
	{
		undefined.push_back(i);
	}

	while (defined.size() < n - 1)
	{
		char input[10];
		string answer, prev;
		deque<int> dq;
		deque<int>::iterator it;

		for (int i = 0; i < n - defined.size(); i++)
		{
			dq.push_back(undefined[i]);
		}

		printf("?");

		for (int i = 0; i < defined.size(); i++)
		{
			printf(" %d", defined[i]);
		}

		for (it = dq.begin(); it != dq.end(); it++)
		{
			printf(" %d", *it);
		}

		printf("\n");
		fflush(stdout);

		scanf("%s", input);

		answer = input;

		if (answer == "-1")
		{
			return 0;
		}

		prev = answer;

		for (int i = 1; i < undefined.size(); i++)
		{
			dq.pop_front();

			dq.push_back(undefined[(i + undefined.size() * 2 + n - 1 - defined.size()) % (undefined.size())]);

			printf("?");

			for (int j = 0; j < defined.size(); j++)
			{
				printf(" %d", defined[j]);
			}

			for (it = dq.begin(); it != dq.end(); it++)
			{
				printf(" %d", *it);
			}

			printf("\n");
			fflush(stdout);

			scanf("%s", input);

			answer = input;

			if (answer == "-1")
			{
				return 0;
			}

			if (answer != prev)
			{
				int x, y;

				x = (i + 2 * undefined.size() - 1) % (undefined.size());
				y = (i + 2 * undefined.size() + n - defined.size() - 1) % (undefined.size());

				defined.push_back(undefined[x]);
				defined.push_back(undefined[y]);

				if (answer == "Blue")
				{
					color[undefined[x]] = 'R';
					color[undefined[y]] = 'B';
				}

				else
				{
					color[undefined[x]] = 'B';
					color[undefined[y]] = 'R';
				}

				r++;
				b++;

				if (x < y)
				{
					undefined.erase(undefined.begin() + y);
					undefined.erase(undefined.begin() + x);
				}

				else
				{
					undefined.erase(undefined.begin() + x);
					undefined.erase(undefined.begin() + y);
				}

				break;
			}

			prev = answer;
		}
	}

	for (int i = 0; i < undefined.size(); i++)
	{
		char input[10];
		string answer;

		printf("?");

		for (int j = 0; j < defined.size(); j++)
		{
			printf(" %d", defined[j]);
		}

		printf(" %d\n", undefined[i]);
		fflush(stdout);

		scanf("%s", input);
		answer = input;

		if (answer == "-1")
		{
			return 0;
		}

		if (answer == "Blue")
		{
			color[undefined[i]] = 'B';

			b++;
		}

		else
		{
			color[undefined[i]] = 'R';

			r++;
		}

		if (b == n)
		{
			for (int j = i + 1; j < undefined.size(); j++)
			{
				color[undefined[j]] = 'R';
			}

			break;
		}

		else if (r == n)
		{
			for (int j = i + 1; j < undefined.size(); j++)
			{
				color[undefined[j]] = 'B';
			}

			break;
		}
	}

	printf("! ");

	for (int i = 1; i <= 2 * n; i++)
	{
		printf("%c", color[i]);
	}

	printf("\n");
	fflush(stdout);

	return 0;
}
