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
	ListNode * rotateRight(ListNode* head, int k) {
		if (!head)
			return NULL;
		if (!k)
			return head;
		int length=0;
		ListNode * new_head,*new_end, *old_head=head, *old_end,*pnode=head;
		while (pnode)
		{
			++length;
			if (pnode->next == NULL)
				old_end = pnode;
			pnode= pnode->next;
		}
		k = k % length;
		if (!k)
			return head;
		pnode = head;
		int t = length - k;
		while (--t)
		{
			pnode = pnode->next;
		}
		new_end = pnode;
		new_head = pnode->next;
		old_end->next = old_head;
		new_end->next = NULL;
		return new_head;
	}
};