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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *head, *ptr;
		ptr = head = new ListNode;

		int carry = 0;

		while (l1 || l2) {
			int cur = carry;

			if (l1) {
				cur += l1->val;

				l1 = l1->next;
			}

			if (l2) {
				cur += l2->val;

				l2 = l2->next;
			}

			ptr->next = new ListNode(cur % 10);
			ptr = ptr->next;

			carry = cur / 10;
		}

		if (carry) {
			ptr->next = new ListNode(1);
		}

		if (!head->next) {
			return head;
		}

		ptr = head;
		head = head->next;
		delete ptr;

		return head;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}