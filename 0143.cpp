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
	void reorderList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return;
		else
		{
			ListNode *slow = head, *fast = head->next;
			while (fast && fast->next)
			{
				slow = slow->next;
				fast = fast->next->next;
			}
			ListNode *temp = slow->next, * pre = NULL, *now = NULL;
			slow->next = NULL;
			while (temp)
			{
				now = temp;
				temp = temp->next;
				now->next = pre;
				pre = now;
			}
			ListNode* newhead = head;
			head = head->next;
			while (head && pre)
			{
				newhead->next = pre;
				pre = pre->next;
				newhead = newhead->next;
				newhead->next = head;
				head = head->next;
				newhead = newhead->next;
			}
			newhead->next = pre;
		}
	}
};