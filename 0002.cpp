/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode * ans = new ListNode((l1->val + l2->val) % 10);
		ListNode * p = ans;
		int k = (l1->val + l2->val) / 10;
		l1 = l1->next;
		l2 = l2->next;
		while (l1 != NULL || l2 != NULL || k != 0)
		{
			p->next = new ListNode(((l1 != NULL ? l1->val : 0) + (l2 != 0 ? l2->val : 0) + k) % 10);
			k = ((l1 != NULL ? l1->val : 0) + (l2 != 0 ? l2->val : 0) + k) / 10;
			p = p->next;
			if (l1 != NULL)
				l1 = l1->next;
			if (l2 != NULL)
				l2 = l2->next;
		}
		return ans;
	}
};