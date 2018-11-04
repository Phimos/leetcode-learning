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
	ListNode * merge(ListNode* left, ListNode* right)
	{
		ListNode* newhead = NULL, *pre = NULL;
		while (left && right)
		{
			if (left->val < right->val)
			{
				if (!newhead)
				{
					newhead = pre = left;
					left = left->next;
				}
				else
				{
					pre->next = left;
					pre = pre->next;
					left = left->next;
				}
			}
			else
			{
				if (!newhead)
				{
					newhead = pre = right;
					right = right->next;
				}
				else
				{
					pre->next = right;
					pre = pre->next;
					right = right->next;
				}
			}
		}
		while (left)
		{
			pre->next = left;
			left = left->next;
			pre = pre->next;
		}
		while (right)
		{
			pre->next = right;
			right = right->next;
			pre = pre->next;
		}
		pre->next = NULL;
		return newhead;
	}

	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		else
		{
			ListNode* slow = head, *fast = head->next;
			while (fast != NULL && fast->next != NULL)
			{
				slow = slow->next;
				fast = fast->next->next;
			}
			ListNode* temp = slow->next;
			slow->next = NULL;
			ListNode* l = sortList(head);
			ListNode* r = sortList(temp);
			return merge(l, r);
		}
	}
};