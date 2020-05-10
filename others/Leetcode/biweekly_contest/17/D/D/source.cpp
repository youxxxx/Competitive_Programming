#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<map>

using namespace std;

class Solution {
public:
	int distinctEchoSubstrings(string text) {
		int n;

		n = text.size();

		map<string, set<int>> list;
		set<string> sol;

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			string cur;

			for (int j = i; j < n; j++) {
				cur.push_back(text[j]);

				map<string, set<int>>::iterator ret;
				set<string>::iterator ret2;

				ret2 = sol.find(cur);

				if (ret2 != sol.end()) {
					continue;
				}

				ret = list.find(cur);

				if (ret == list.end()) {
					set<int> emp;

					list[cur] = emp;

					list[cur].insert(i);
				}

				else {
					set<int>::iterator ret2;

					bool done = false;

					if (i - (j - i + 1) >= 0) {
						ret2 = ret->second.find(i - (j - i + 1));

						if (ret2 != ret->second.end()) {
							sol.insert(ret->first);

							cnt++;

							done = true;
						}
					}

					if (!done) {
						ret->second.insert(i);
					}
				}
			}
		}

		/*
		map<string, set<int>>::iterator it;

		for (it = list.begin(); it != list.end(); it++) {
			set<int>::iterator it2;

			for (it2 = it->second.begin(); it2 != it->second.end(); it2++) {
				set<int>::iterator ret;

				ret = it->second.find(*it2 + (int)(it->first.size()));

				if (ret != it->second.end()) {
					cnt++;

					break;
				}
			}
		}
		*/

		return cnt;
	}
};

int main()
{
	Solution s;

	s.distinctEchoSubstrings("abcabcabc");

	return 0;
}