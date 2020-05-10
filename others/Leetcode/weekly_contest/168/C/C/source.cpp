#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
	int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
		int n;

		n = s.size();

		int lmax = 0;

		for (int i = minSize; i <= maxSize; i++) {
			map<string, int> list;
			map<string, int>::iterator ret;
			string cur;

			int cnt[26] = { 0, };
			int unique = 0;

			cur = s.substr(0, i);

			for (int j = 0; j < cur.size(); j++) {
				if (!(cnt[cur[j] - 'a']++)) {
					unique++;
				}
			}

			if (unique <= maxLetters) {
				ret = list.find(cur);

				if (ret == list.end()) {
					list[cur] = 1;

					if (lmax < 1)
					{
						lmax = 1;
					}
				}

				else {
					if (++ret->second > lmax) {
						lmax = ret->second;
					}
				}
			}

			for (int j = i; j < n; j++) {

				if (!(--cnt[cur.front() - 'a'])) {
					unique--;
				}

				cur.erase(cur.begin());

				if (!(cnt[s[j] - 'a']++)) {
					unique++;
				}
				
				cur.push_back(s[j]);
				
				if (unique <= maxLetters) {
					ret = list.find(cur);
					
					if (ret == list.end()) {
						list[cur] = 1;

						if (lmax < 1)
						{
							lmax = 1;
						}
					}

					else {
						if (++ret->second > lmax) {
							lmax = ret->second;
						}
					}
				}
			}
		}

		return lmax;
	}
};

int main()
{
	return 0;
}