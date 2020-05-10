#include<cstdio>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int main()
{
	int n;
	vector<int> arr;
	vector<int> sol;
	int input;
	int i;
	bool valid;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	while (!arr.empty())
	{
		valid = false;

		for (i = arr.size()-1; i >= 0; i--)
		{
			if (arr[i] == i + 1)
			{
				sol.insert(sol.begin(), arr[i]);

				arr.erase(arr.begin() + i);

				valid = true;

				break;
			}
		}
		
		if (!valid)
		{
			printf("-1\n");

			return 0;
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%d\n", sol[i]);
	}

	return 0;
}