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

 /*
given curr node
if the currnode val == currnode.next val then set currnode.next to currnode.next.next
have to make sure currnode.next exists
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* currNode = head;
        while (currNode != nullptr && currNode->next != nullptr) {
            if (currNode->val == currNode->next->val) currNode->next = currNode->next->next;
            else currNode = currNode->next;
        }
        return head;
    }
};