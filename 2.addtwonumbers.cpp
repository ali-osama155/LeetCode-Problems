#include <iostream>
//*********version 1.0**************
/*//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
class Solution {
public:



int helper(ListNode* head, int& multiplier) {
    if (head == nullptr) {
        return 0;
    }
    
    int result = helper(head->next, multiplier);
    result += head->val * multiplier;
    multiplier *= 10;
    return result;
}

int listToInteger(ListNode* head) {
    int multiplier = 1;
    return helper(head, multiplier);
}



ListNode* integerToList(int number) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;

    if (number == 0) {
        return new ListNode(0);
    }

    while (number > 0) {
        int digit = number % 10;  
        current->next = new ListNode(digit);  
        current = current->next;  
        number /= 10;  
    }

    return dummy->next;  
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int f1 = listToInteger(l1);   
    int f2 = listToInteger(l2);
    int sum = f1 + f2;
    return integerToList(sum);

    }*/
   //********version 2.0 *********/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummy->next;
    }
};

int main() {
    // Creating the linked lists [2, 4, 9] and [5, 6, 4, 9]
    ListNode* z = new ListNode(9);
    z->next = new ListNode(9);
    z->next->next = new ListNode(9);

    ListNode* x = new ListNode(9);
    x->next = new ListNode(9);
    x->next->next = new ListNode(9);
    x->next->next->next = new ListNode(9);

    Solution s1;
    ListNode* soul = s1.addTwoNumbers(z, x);

    // Printing the result
    ListNode* current = soul;
    while (current != nullptr) {
        std::cout << current->val << std::endl;
        current = current->next;
    }

    // Clean up memory
    while (soul != nullptr) {
        ListNode* next = soul->next;
        delete soul;
        soul = next;
    }

    return 0;
}



