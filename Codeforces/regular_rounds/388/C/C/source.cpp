#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

int main()
{
	int n;
	queue<char> q;
	char input;

	scanf("%d", &n);
	scanf("%c", &input);

	int left[256] = { 0, };

	for (int i = 0; i < n; i++)
	{
		scanf("%c", &input);

		left[input]++;

		q.push(input);
	}

	char state = 'D';
	int stack = 0;

	while (!q.size() != 1 && (left['D'] && left['R']))
	{
		char cur;

		cur = q.front();
		q.pop();

		if (stack&&state != cur)
		{
			stack--;

			left[cur]--;
		}

		else
		{
			state = cur;
			stack++;

			q.push(cur);
		}
	}

	printf("%c\n", q.front());

	return 0;
}
