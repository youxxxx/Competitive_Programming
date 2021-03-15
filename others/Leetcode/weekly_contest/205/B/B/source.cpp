#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<cstring>
#include<functional>

using namespace std;

class Solution {
public:
	int numTriplets(vector<int>& nums1, vector<int>& nums2) {
		const int n = nums1.size(), m = nums2.size();
		map<long long, int> list, list2;

		for (int i = 0; i < m; i++) {
			map<long long, int>::iterator ret = list.find(nums2[i]);

			if (ret == list.end()) {
				list[nums2[i]] = 1;
			}

			else {
				ret->second++;
			}
		}

		for (int i = 0; i < n; i++) {
			map<long long, int>::iterator ret = list2.find(nums1[i]);

			if (ret == list2.end()) {
				list2[nums1[i]] = 1;
			}

			else {
				ret->second++;
			}
		}

		int rvalue = 0;

		for (int i = 0; i < n; i++) {
			long long val = (long long)nums1[i] * (long long)nums1[i];

			for (int j = 0; j < m; j++) {
				if (val%nums2[j]) {
					continue;
				}
				const long long other = val / nums2[j];

				map<long long, int>::iterator ret = list.find(other);


				if (ret == list.end()) {
					continue;
				}

				rvalue += ret->second - (other == nums2[j]);
			}
		}

		for (int i = 0; i < m; i++) {
			long long val = (long long)nums2[i] * (long long)nums2[i];

			for (int j = 0; j < n; j++) {
				if (val%nums1[j]) {
					continue;
				}
				const long long other = val / nums1[j];

				map<long long, int>::iterator ret = list2.find(other);


				if (ret == list2.end()) {
					continue;
				}

				rvalue += ret->second - (other == nums1[j]);
			}
		}

		return rvalue / 2;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);


	return 0;
}