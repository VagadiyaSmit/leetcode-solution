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
    ListNode* removeNthFromEnd(ListNode* head, int n) {   //T.C = O(n) S.C = O(1)
        if(head == NULL){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = head;
        int count = 0;

        while( temp != NULL){ //O(n)
            count ++;
            temp = temp->next;
        }    //find previous Node of the node to delete

        temp = dummy;
        int pos = count - n;
        while(pos--){         //O(n)
            temp = temp ->next;
        }
        ListNode* del = temp->next;
        temp->next  = temp->next->next;
        delete del;

        return dummy->next;
    }
};