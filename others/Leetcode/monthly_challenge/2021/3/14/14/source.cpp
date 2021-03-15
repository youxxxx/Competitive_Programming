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
	ListNode* swapNodes(ListNode* head, int k) {
		int cnt = 0;

		ListNode *ptr = head;
		ListNode *left;

		while (ptr) {
			if (++cnt == k) {
				left = ptr;
			}
			ptr = ptr->next;
		}

		ptr = head;

		while (cnt-- != k) {
			ptr = ptr->next;
		}

		const int temp = left->val;
		left->val = ptr->val;
		ptr->val = temp;

		return head;
	}
};

int main()
{

}