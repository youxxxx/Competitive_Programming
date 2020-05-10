#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

class Solution {
public:
	int subtractProductAndSum(int n)
	{
		int sum = 0, prod = 1;

		if (n == 0)
		{
			return 0;
		}

		while (n)
		{
			sum += n % 10;
			prod *= n % 10;

			n /= 10;
		}

		return prod - sum;
	}
};

using namespace std;

int main()
{


	return 0;
}