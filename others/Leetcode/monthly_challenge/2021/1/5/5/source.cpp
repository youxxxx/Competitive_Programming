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

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *sol = new ListNode;
		ListNode *ptr = head;
		ListNode *ptr2 = sol;
		int prev = -101;
		bool valid = false;

		while (ptr) {
			if (ptr->val == prev) {
				valid = false;
			}

			else {
				if (valid) {
					ptr2->next = new ListNode(prev);

					ptr2 = ptr2->next;
				}

				valid = true;
			}

			prev = ptr->val;

			ptr = ptr->next;
		}

		if (valid) {
			ptr2->next = new ListNode(prev);
		}

		ptr2 = sol;
		sol = sol->next;

		delete ptr2;

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}