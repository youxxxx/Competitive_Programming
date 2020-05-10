#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
	vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum)
	{
		vector<vector<int>> emp, sol;
		vector<int> def;
		int n;
		int curup = 0, curlow = 0;
		vector<int> undefined;

		sol.push_back(def);
		sol.push_back(def);

		n = colsum.size();

		for (int i = 0; i < n; i++)
		{
			if (colsum[i] == 2)
			{
				sol[0].push_back(1);
				sol[1].push_back(1);

				curup++;
				curlow++;
			}

			else
			{
				sol[0].push_back(0);
				sol[1].push_back(0);

				if (colsum[i])
				{
					undefined.push_back(i);
				}
			}
		}

		if (curup > upper || curlow > lower || undefined.size() != upper + lower - (curup + curlow))
		{
			return emp;
		}

		else
		{
			for (int i = 0; i < upper - curup; i++)
			{
				sol[0][undefined[i]] = 1;
			}

			for (int i = upper - curup; i < undefined.size(); i++)
			{
				sol[1][undefined[i]] = 1;
			}
		}

		return sol;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 2, 1, 2, 0, 1, 0, 1, 2, 0, 1 };

	s.reconstructMatrix(5, 5, v);

	return 0;
}