#include <iostream>


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
        ListNode *result = new ListNode();
        ListNode *curr_sum = new ListNode();
        ListNode *curr_l1 = l1;
        ListNode *curr_l2 = l2;
        int residual = 0;
        bool first_node = true;
        do{
            int first = 0, second = 0;
            if(curr_l1!=NULL){
                first = curr_l1->val;
                // pass to next one
                curr_l1 = curr_l1->next;
            }
            if(curr_l2!=NULL){
                second = curr_l2->val;
                // pass to next one
                curr_l2 = curr_l2->next;
            }
            int sum = first + second + residual;
            int module_number = sum % 10;
            residual = (sum - module_number) / 10;
            //Store the value
            curr_sum->val=module_number;
            //Store head of the list
            if(first_node){
                result = curr_sum;
                first_node = false;
            }
            //Check if there is a next node
            if(residual != 0 || (curr_l1!=NULL || curr_l2!=NULL)){
                curr_sum->next = new ListNode();
                curr_sum = curr_sum->next;
            }
        } while (residual != 0 || (curr_l1!=NULL || curr_l2!=NULL));

        return result;
    }
};

int main(){
    // [9,9,9,9,9,9,9]
    ListNode *l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    // [9,9,9,9]
    ListNode *l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
    Solution sol;
    ListNode *result = sol.addTwoNumbers(l1, l2);
    while(result!=NULL){
        std::cout << result->val << std::endl;
        result = result->next;
    }
    return 0;
}