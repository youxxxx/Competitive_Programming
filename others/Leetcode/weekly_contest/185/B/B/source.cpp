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
	vector<vector<string>> displayTable(vector<vector<string>>& orders) {
		const int n = orders.size();
		vector<vector<string>> sol;
		set<string> food;
		bool check[501] = { 0, };
		map<string, int> tot[501];

		for (int i = 0; i < n; i++) {
			food.insert(orders[i][2]);

			int val = 0;

			for (int j = 0; j < orders[i][1].size(); j++) {
				val += orders[i][1][j] - '0';
				val *= 10;
			}

			val /= 10;

			check[val] = true;

			map<string, int>::iterator ret;

			ret = tot[val].find(orders[i][2]);

			if (ret == tot[val].end()) {
				tot[val][orders[i][2]] = 1;
			}

			else {
				ret->second++;
			}
		}

		vector<string> temp;

		temp.push_back("Table");

		map<string, int> foodlist;

		int cnt = 0;

		for (set<string>::iterator it = food.begin(); it != food.end(); it++) {
			temp.push_back(*it);

			foodlist[*it] = cnt++;
		}

		sol.push_back(temp);

		for (int i = 1; i <= 500; i++) {

			if (check[i]) {
				vector<int> emp;

				for (int i = 0; i < food.size(); i++) {
					emp.push_back(0);
				}

				for (map<string, int>::iterator it = tot[i].begin(); it != tot[i].end(); it++) {
					int idx;

					idx = foodlist[it->first];

					emp[idx] += it->second;
				}

				string i2s2;

				int temp;

				temp = i;

				while (temp)
				{
					i2s2.insert(i2s2.begin(), temp % 10 + '0');

					temp /= 10;
				}

				vector<string> list;

				list.push_back(i2s2);

				for (int i = 0; i < food.size(); i++) {
					int temp;
					string i2s;

					temp = emp[i];

					if (temp == 0) {
						i2s.push_back('0');
					}

					while (temp) {
						i2s.insert(i2s.begin(), temp % 10 + '0');

						temp /= 10;
					}

					list.push_back(i2s);
				}

				sol.push_back(list);
			}
		}

		return sol;
	}
};

int main()
{
	Solution s;

	vector<vector<string>> list = { { "David","3","Ceviche" },{ "Corina","10","Beef Burrito" },{ "David","3","Fried Chicken" },{ "Carla","5","Water" },{ "Carla","5","Ceviche" },{ "Rous","3","Ceviche" } };

	s.displayTable(list);

	return 0;
}