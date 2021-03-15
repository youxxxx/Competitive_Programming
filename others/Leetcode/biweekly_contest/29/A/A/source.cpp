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

class Solution {
public:
	double average(vector<int>& salary) {
		const int n = salary.size();

		sort(salary.begin(), salary.end());

		int sum = 0;

		for (int i = 1; i < n - 1; i++)
		{
			sum += salary[i];
		}

		return (double)sum / (double)(n - 2);
	}
};

int main()
{

	return 0;
}