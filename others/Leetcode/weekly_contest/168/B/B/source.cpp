#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
	bool isPossibleDivide(vector<int>& nums, int k) {
		int n;

		n = nums.size();

		if (n%k) {
			return false;
		}

		map<int, int> list;

		for (int i = 0; i < n; i++) {
			map<int, int>::iterator ret;

			ret = list.find(nums[i]);

			if (ret == list.end()) {
				list[nums[i]] = 1;
			}

			else {
				ret->second++;
			}
		}

		for (int i = 0; i < n / k; i++) {
			map<int, int>::iterator it;
			vector<map<int, int>::iterator> del;
			
			it = list.begin();
			int prev;

			prev = it->first;

			if (--it->second == 0) {
				del.push_back(it);
			}

			it++;
			
			for (int j = 1; j < k; j++)	{
				if (it == list.end() || it->first != prev + 1) {
					return false;
				}

				if (--it->second == 0) {
					del.push_back(it);
				}

				prev = it->first;

				it++;
			}

			for (int i = 0; i < del.size(); i++) {
				list.erase(del[i]);
			}
		}

		return true;
	}
};

int main()
{
	return 0;
}