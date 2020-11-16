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
		int arr[200001];

		scanf("%d", &n);

		priority_queue<pair<int, int>> pq;

		pq.push({ n,0 });

		for (int i = 1; i <= n; i++)
		{
			int start, len;

			len = pq.top().first;
			start = -(pq.top().second);

			pq.pop();

			int mid;

			mid = start + (len - 1) / 2;

			arr[mid] = i;

			if (mid != start)
			{
				pq.push({ mid - start,-start });
			}

			if (mid != start + len - 1)
			{
				pq.push({ len - (mid - start + 1),-(mid + 1) });
			}
		}

		for (int i = 0; i < n; i++)
		{
			printf("%d ", arr[i]);
		}

		printf("\n");
	}

	return 0;
}