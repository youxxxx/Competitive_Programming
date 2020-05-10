#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

class Solution {
public:
	string destCity(vector<vector<string>>& paths) {
		const int n = paths.size();
		set<string> a, b;

		for (int i = 0; i < n; i++) {
			a.insert(paths[i][0]);
			b.insert(paths[i][1]);
		}

		for (set<string>::iterator it = b.begin(); it != b.end(); it++) {
			set<string>::iterator ret;

			ret = a.find(*it);

			if (ret == a.end()) {
				return *it;
			}
		}

		return "";
	}
};

int main() {

	return 0;
}