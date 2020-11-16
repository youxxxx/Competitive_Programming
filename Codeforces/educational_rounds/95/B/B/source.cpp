#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

#define MOD 1000000007

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);
		
		int arr[101];

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		vector<int> idx;
		vector<int> val;

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			if (!input)
			{
				idx.push_back(i);
				val.push_back(arr[i]);
			}
		}

		sort(val.begin(), val.end(), greater<int>());

		for (int i = 0; i < val.size(); i++)
		{
			arr[idx[i]] = val[i];
		}

		for (int i = 0; i < n; i++)
		{
			printf("%d ", arr[i]);
		}

		printf("\n");
	}

	return 0;
}