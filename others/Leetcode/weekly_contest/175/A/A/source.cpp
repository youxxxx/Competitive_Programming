#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool checkIfExist(vector<int>& arr) {

		int n;
		n = arr.size();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}

				if (arr[i] == arr[j] * 2) {
					return true;
				}
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	vector<int> arr = { 3,1,7,11 };

	s.checkIfExist(arr);

	return 0;
}