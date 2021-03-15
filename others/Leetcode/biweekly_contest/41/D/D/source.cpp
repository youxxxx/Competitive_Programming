#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

#define MAX 9999999

class Solution {
public:
	int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
		const int n = boxes.size();
		int sptr = 1;
		int eptr = 1;
		int sval = boxes[0][1];
		int eval = boxes[0][1];
		int sdiff = 1;
		int ediff = 1;
		int lmin[100001];

		for (int i = 1; i <= n; i++) {
			lmin[i] = MAX;
		}

		lmin[0] = 0;

		for (int i = 0; i < n; i++) {
			if (i != 0) {
				sval -= boxes[i - 1][1];
				eval -= boxes[i - 1][1];

				if (boxes[i][0] != boxes[i - 1][0]) {
					sdiff--;
					ediff--;
				}
			}

			if (lmin[i] == MAX) {
				continue;
			}

			while (eptr != n && eptr - i < maxBoxes) {
				if (eval + boxes[eptr][1] > maxWeight) {
					break;
				}

				if (boxes[eptr - 1][0] != boxes[eptr][0]) {
					sptr = eptr;
					sval = eval;
					sdiff = ediff;
					ediff++;
				}

				eval += boxes[eptr][1];
				eptr++;
			}

			if (eptr == n || sptr == i) {
				sptr = eptr;
				sval = eval;
				sdiff = ediff;
			}

			lmin[sptr] = min(lmin[sptr], lmin[i] + sdiff + 1);
			lmin[eptr] = min(lmin[eptr], lmin[i] + ediff + 1);

			/*
			sval -= boxes[i][1];
			eval -= boxes[i][1];

			if (i != 0 && boxes[i][0] != boxes[i - 1][0]) {
				sdiff--;
				ediff--;
			}
			*/
		}

		return lmin[n];
	}
};

int main()
{
	Solution s;
	vector<vector<int>> arr = { { 2,4 },{ 2,5 },{ 3,1 },{ 3,2 },{ 3,7 },{ 3,1 },{ 4,4 },{ 1,3 },{ 5,2 } };

	s.boxDelivering(arr, 5, 5, 7);

	return 0;
}