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
class Solution {
public:
    void reorderList(ListNode* head) {  //T.C = O(n) S.C = O(1)
        if(!head || !head ->next)
            return;
        //1.find middle using slow-fast approach
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next && fast->next->next){
            slow = slow->next;
            fast = fast ->next->next;

        }
        //2.split into two halves
        ListNode* secondHead = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = secondHead;
        while(curr){
            ListNode* next = curr ->next;
            curr-> next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* second = prev;   // head of reversed second half
        //3.merge two halves alternately
        ListNode* first = head;
        while(second){
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};