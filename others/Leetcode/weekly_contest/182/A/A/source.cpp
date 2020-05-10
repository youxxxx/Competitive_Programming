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
#include<functional>

using namespace std;

class Solution {
public:
	int findLucky(vector<int>& arr) {
		map<int, int> list;
		int n;

		n = arr.size();

		for (int i = 0; i < n; i++) {
			map<int, int>::iterator ret;

			ret = list.find(arr[i]);

			if (ret == list.end())
			{
				list[arr[i]] = 1;
			}

			else
			{
				ret->second++;
			}
		}

		map<int, int>::iterator it;
		
		it = list.end();

		while (it-- != list.begin())
		{
			if (it->first == it->second)
			{
				return it->first;
			}
		}

		return -1;
	}
};

int main()
{

	return 0;
}