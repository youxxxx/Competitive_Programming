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
	int maxDiff(int num) {

		int a;

		{
			int maxdigit = -1;

			stack<int> s;

			int temp;

			temp = num;

			while (temp) {
				s.push(temp % 10);

				temp /= 10;
			}

			temp = num;

			int res = 0;

			while (!s.empty()) {
				int digit;

				digit = s.top();
				s.pop();

				res *= 10;

				if (maxdigit==-1) {
					if (digit != 9) {
						maxdigit = digit;

						res += 9;
					}

					else {
						res += digit;
					}
				}

				else {
					if (digit == maxdigit) {
						res += 9;
					}
					
					else {
						res += digit;
					}
				}
			}

			a = res;
		}

		int b;
		
		{
			int maxdigit = -1;

			stack<int> s;

			int temp;

			temp = num;

			while (temp) {
				s.push(temp % 10);

				temp /= 10;
			}

			int cnt = 0;
			int target = 0;


			int res = 0;

			bool not1 = false;

			while (!s.empty()) {
				int digit;
				
				digit = s.top();
				s.pop();

				res *= 10;

				if (maxdigit == -1) {
					if (cnt + digit != 1 && !(not1&&digit == 1)) {
						maxdigit = digit;

						target = !cnt;

						res += target;
					}

					else {
						if (!cnt) {
							not1 = true;
						}

						res += digit;
					}
				}

				else {
					if (digit == maxdigit) {
						res += target;
					}

					else {
						res += digit;
					}
				}

				cnt = 1;
			}

			b = res;
		}


		return a - b;
	}
};

int main()
{
	Solution s;

	s.maxDiff(1101057);

	return 0;
}