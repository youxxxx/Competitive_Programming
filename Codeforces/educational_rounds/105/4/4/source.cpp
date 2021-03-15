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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		stack<ListNode*> s1, s2;

		while (headA) {
			s1.push(headA);

			headA = headA->next;
		}

		while (headB) {
			s2.push(headB);

			headB = headB->next;
		}

		ListNode* sol = 0;

		while (!s1.empty() && !s2.empty()) {
			if (s1.top() == s2.top()) {
				sol = s1.top();
			}

			s1.pop();
			s2.pop();
		}

		return sol;
	}
};

int main()
{

}