#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		char input[101];

		scanf("%s", input);

		string str = input;
		const int n = str.size();
		vector<int> arr;
		int cur = 0;

		for (int i = 0; i < n; i++)
		{
			if (str[i] == '0')
			{
				if (cur)
				{
					arr.push_back(cur);
				}

				cur = 0;
			}

			else
			{
				cur++;
			}
		}

		if (cur)
		{
			arr.push_back(cur);
		}

		sort(arr.begin(), arr.end(), greater<int>());

		int sol = 0;

		for (int i = 0; i < arr.size(); i += 2)
		{
			sol += arr[i];
		}

		printf("%d\n", sol);
	}

	return 0;
}