#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
	int findSpecialInteger(vector<int>& arr) {
		int cnt = 1;

		for (int i = 1; i < arr.size(); i++) {
			if (arr[i] != arr[i - 1])
			{
				cnt = 1;
			}

			else
			{
				cnt++;
			}

			if (cnt > arr.size() / 4)
			{
				return arr[i];
			}
		}

		return arr[0];
	}
};

int main()
{
	return 0;
}