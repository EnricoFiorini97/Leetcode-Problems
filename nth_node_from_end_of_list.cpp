/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution 
{
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) 
        {
            int size = 0; ListNode* cpy = head;
            
            while (cpy)
            {   cpy = cpy->next;  ++size;  }
            
            if (n == size)          return head->next;
            
            int target = size - n; ListNode* itr = head;
            
            for (int i = 0; i < target - 1; ++i, itr = itr->next);
            
            itr->next = itr->next->next;
            
            return head;
        }
};
