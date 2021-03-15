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
	int countStudents(vector<int>& students, vector<int>& sandwiches) {
		const int n = students.size();

		queue<int> q[2];

		for (int i = 0; i < n; i++)
		{
			q[0].push(students[i]);
		}

		bool change = true;
		int ptr = 0;
		int bit = 0;

		while (change)
		{
			change = false;

			while (!q[bit].empty() && ptr != n)
			{
				if (q[bit].front() == sandwiches[ptr])
				{
					ptr++;

					change = true;
				}

				else
				{
					q[!bit].push(q[bit].front());
				}

				q[bit].pop();
			}

			bit = !bit;
		}

		return n - ptr;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}