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
	ListNode * swapPairs(ListNode* head) {
		if (head == NULL)
			return head;
		ListNode * p = head, *q = head->next, *front, *back;
		front = NULL;
		if (q)
			head = q;
		while (p&&q)
		{
			back = q->next;
			if (front)
				front->next = q;
			p->next = back;
			q->next = p;
			front = p;
			p = back;
			if (p)
				q = p->next;
		}
		return head;
	}
};