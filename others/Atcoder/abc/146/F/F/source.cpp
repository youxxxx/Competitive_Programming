#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	char input[1000000];
	string str;

	scanf("%d %d", &n, &m);

	scanf("%s", input);
	str = input;

	vector<int> move;

	int loc = n;

	while (loc)
	{
		int lmax;

		lmax = loc - (loc - m > 0 ? loc - m : 0);

		int next;
		next = loc;

		for (int i = lmax; i >= 1; i--)
		{
			if (str[loc - i] == '0')
			{
				next = loc - i;

				break;
			}
		}

		if (next == loc)
		{
			printf("-1\n");

			return 0;
		}

		move.push_back(loc - next);

		loc = next;
	}

	for (int i = move.size() - 1; i >= 0; i--)
	{
		printf("%d ", move[i]);
	}

	printf("\n");

	return 0;
}