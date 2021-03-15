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
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int ptr1 = m - 1;
		int ptr2 = n - 1;
		for (int i = m + n - 1; i >= 0; i--) {
			if (ptr1 == -1) {
				nums1[i] = nums2[ptr2--];
			}

			else if (ptr2 == -1 || nums1[ptr1] > nums2[ptr2]) {
				nums1[i] = nums1[ptr1--];
			}

			else {
				nums1[i] = nums2[ptr2--];
			}
		}
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}