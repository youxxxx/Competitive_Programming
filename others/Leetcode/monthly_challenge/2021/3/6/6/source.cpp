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

bool func(const string &a, const string &b) {
	return a.size() < b.size();
}

class Solution {
public:
	int minimumLengthEncoding(vector<string>& words) {
		int sol = 0;
		set<string> list;

		sort(words.begin(), words.end(), func);

		const int n = words.size();

		for (int i = 0; i < n; i++) {
			const int m = words[i].size();

			for (int j = m - 1; j >= 0; j--) {
				set<string>::iterator ret = list.find(words[i].substr(j));

				if (ret != list.end()) {
					list.erase(ret);

					sol -= m - j + 1;
				}
			}

			list.insert(words[i]);

			sol += m + 1;
		}

		return sol;
	}
};

int main()
{

}