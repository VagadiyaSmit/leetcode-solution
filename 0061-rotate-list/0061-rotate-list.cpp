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
    ListNode* rotateRight(ListNode* head, int k) {     // T.C = O(n) S.C = O(1)
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
        ListNode* last = head;
        ListNode* first = head;
        int count = 1;
        while(last -> next != NULL){
            last = last->next;
            count++;
        }
        k = k % count;
        if(k == 0)
            return head;
        
        last -> next = head;  // Make curculer

        for(int i = 1;i <count -k;i++){
            first = first->next;
        }
        ListNode* newHead = first->next;
        first->next = NULL;
        return newHead;
    }
};