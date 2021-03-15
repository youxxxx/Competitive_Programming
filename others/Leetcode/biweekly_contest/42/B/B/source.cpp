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

class Solution {
public:
	double averageWaitingTime(vector<vector<int>>& customers) {
		const int n = customers.size();

		long long sum = 0;

		int prev = 0;

		for (int i = 0; i < n; i++)
		{
			const long long a = customers[i][0];
			const long long t = customers[i][1];

			if (prev <= a)
			{
				prev = a + t;
			}

			else
			{
				prev += t;
			}

			sum += prev - a;
		}

		return (double)sum / (double)n;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}