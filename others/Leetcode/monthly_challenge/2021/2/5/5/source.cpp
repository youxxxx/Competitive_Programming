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
	string simplifyPath(string path) {
		const int n = path.size();
		string sol = "/";
		string cur;


		for (int i = 0; i < n; i++) {
			if (path[i] == '/') {
				if (!cur.empty()) {
					if (cur != ".") {
						if (cur == "..") {
							sol.pop_back();

							while (!sol.empty() && sol.back() != '/') {
								sol.pop_back();
							}

							if (sol.empty()) {
								sol.push_back('/');
							}
						}

						else {
							sol.append(cur);

							sol.push_back('/');
						}
					}

					cur.clear();
				}
			}

			else {
				cur.push_back(path[i]);
			}
		}

		if (!cur.empty()) {
			if (cur != ".") {
				if (cur == "..") {
					sol.pop_back();

					while (!sol.empty() && sol.back() != '/') {
						sol.pop_back();
					}

					if (sol.empty()) {
						sol.push_back('/');
					}
				}

				else {
					sol.append(cur);

					sol.push_back('/');
				}

				cur.clear();
			}
		}

		if ((int)sol.size() != 1) {
			sol.pop_back();
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}