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
		int n, m;

		scanf("%d %d", &n, &m);

		vector<int> a, b;

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			a.push_back(input);
		}

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			b.push_back(input);
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int moves = m;
		int ptr1 = 0, ptr2 = n - 1;

		while (moves && ptr1 < n && ptr2 >= 0 && a[ptr1] < b[ptr2])
		{
			moves--;
			a[ptr1++] = b[ptr2--];
		}

		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			sum += a[i];
		}

		printf("%d\n", sum);
	}

	return 0;
}