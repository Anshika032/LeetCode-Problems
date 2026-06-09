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
 using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
   ListNode* resultHead = NULL;
   ListNode* resultTail = NULL;
   int carry = 0;

   while (l1 != NULL || l2 != NULL || carry !=0){
    int x = ( l1 != NULL) ? l1->val : 0;
    int y = ( l2 != NULL) ? l2->val : 0;

    int sum = x + y + carry;
    int digit = sum % 10;
    carry = sum/10;
    ListNode* newNode = new ListNode(digit);

            
            if (resultHead == NULL) {
                resultHead = newNode;
                resultTail = newNode;
            } else {
                resultTail->next = newNode;
                resultTail = newNode;
            }

           
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }

        return resultHead;
    }
};
