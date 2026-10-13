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
   
    void deleteNode(ListNode* node) {           //T.C = O(1) S.C = O(1)
        
        //only bypass the all Node after the (node -> val) ,also considering (node -> val)Node
        
        ListNode* nextNode = node -> next;  
        node -> val = nextNode -> val;
        node -> next = nextNode -> next;
        delete nextNode;
    }
};