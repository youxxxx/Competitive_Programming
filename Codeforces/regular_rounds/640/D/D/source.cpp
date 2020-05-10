#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		deque<int> dq;

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			dq.push_back(input);
		}
		
		int base;

		base=dq.front();
		dq.pop_front();
		bool flag = true;
		int a, b = 0;
		int cnt = 1;

		a = base;

		while (!dq.empty())
		{
			int sum = 0;

			while (!dq.empty() && sum <= base)
			{
				if (flag)
				{
					sum += dq.back();
					dq.pop_back();
				}

				else
				{
					sum += dq.front();
					dq.pop_front();
				}
			}

			if (flag)
			{
				b += sum;
			}

			else
			{
				a += sum;
			}

			base = sum;

			cnt++;

			flag = !flag;
		}

		printf("%d %d %d\n", cnt, a, b);
	}

	return 0;
}