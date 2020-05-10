#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	vector<string> arr;

	bool taken[101] = { 0, };
	bool ispalin[101] = { 0, };

	for (int i = 0; i < n; i++)
	{
		char input[51];
		string str;

		scanf("%s", input);
		str = input;

		arr.push_back(str);

		bool palindromic = true;

		for (int j = 0; j < m / 2; j++)
		{
			if (str[j] != str[m - j - 1])
			{
				palindromic = false;

				break;
			}
		}

		ispalin[i] = palindromic;
	}
	
	vector<int> left, right;

	for (int i = 0; i < n - 1; i++)
	{
		if (taken[i])
		{
			continue;
		}

		for (int j = i + 1; j < n; j++)
		{
			if (taken[j])
			{
				continue;
			}

			bool reverse = true;

			for (int k = 0; k < m; k++)
			{
				if (arr[i][k] != arr[j][m - k - 1])
				{
					reverse = false;;

					break;
				}
			}

			if (reverse)
			{
				left.push_back(i);
				right.push_back(j);

				taken[i] = taken[j] = true;
				break;
			}
		}
	}

	string sol;

	for (int i = 0; i < left.size(); i++)
	{
		sol.append(arr[left[i]]);
	}

	for (int i = 0; i < n; i++)
	{
		if (!taken[i] && ispalin[i])
		{
			sol.append(arr[i]);

			break;
		}
	}

	for (int i = right.size() - 1; i >= 0; i--)
	{
		sol.append(arr[right[i]]);
	}

	printf("%d\n%s\n", sol.size(), sol.c_str());

	return 0;
}