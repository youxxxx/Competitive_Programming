#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int input;
		int base;

		scanf("%d", &input);

		base = (int)log10(input);

		vector<int> nums;

		while (input)
		{
			nums.push_back(input % 10);

			input /= 10;
		}

		int cur;

		cur = nums.back();

		int minus = 0;

		for (int i = (int)nums.size() - 2; i >= 0; i--)
		{
			if (nums[i] > cur)
			{
				break;
			}

			if (nums[i] < cur)
			{
				minus = 1;

				break;
			}
		}

		printf("%d\n", base * 9 + cur - minus);
	}

	return 0;
}