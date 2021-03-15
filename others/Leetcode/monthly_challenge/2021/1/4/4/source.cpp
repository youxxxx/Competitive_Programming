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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *head, *ptr;

		if (!l1 && !l2) {
			return 0;
		}

		ptr = head = new ListNode;

		while (l1&&l2) {
			if (l1->val < l2->val) {
				ptr->next = new ListNode(l1->val);

				l1 = l1->next;
			}

			else {
				ptr->next = new ListNode(l2->val);

				l2 = l2->next;
			}

			ptr = ptr->next;
		}

		while (l1) {
			ptr->next = new ListNode(l1->val);

			l1 = l1->next;

			ptr = ptr->next;
		}

		while (l2) {
			ptr->next = new ListNode(l2->val);

			l2 = l2->next;

			ptr = ptr->next;
		}

		ListNode *temp = head;
		head = head->next;
		delete temp;

		return head;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}