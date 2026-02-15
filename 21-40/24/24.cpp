#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    public:
    ListNode *swapPairs(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *res = new ListNode(0, head);
        ListNode *temp = res;
        while(temp->next->next != nullptr)
        {
            ListNode *x = temp->next;
            temp->next = temp->next->next;
            x->next = temp->next->next;
            temp->next->next = x;
            temp = temp->next->next;
            if(temp->next == nullptr)
                break;
        }
        return res->next;
    }
};

int main()
{
    ListNode *list = new ListNode(4);
    list = new ListNode(3, list);
    list = new ListNode(2, list);
    list = new ListNode(1, list);

    Solution solution;

    ListNode *res = solution.swapPairs(list);
    while(res != nullptr)
    {
        ListNode *temp = res;
        printf("%d ", res->val);
        res = res->next;
        delete temp;
    }
    return 0;
}