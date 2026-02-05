#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
    void clear()
    {
        ListNode *curr = this;
        while(curr != nullptr)
        {
            ListNode *temp = curr;
            curr = curr->next;
            free(temp);
        }
        return;
    }
};

class Solution
{
    public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
};

ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int ten = 0;
    ListNode *res = new ListNode();
    ListNode *curr = res;

    while (l1 != nullptr || l2 != nullptr || ten == 1)
    {
        curr->next = new ListNode();
        curr = curr->next;
        curr->val = ten;
        curr->next = nullptr;

        if(l1 != nullptr)
            curr->val += l1->val;
        if(l2 != nullptr)
            curr->val += l2->val;
        if(curr->val > 9)
        {
            ten = 1;
            curr->val -= 10;
        } else
        {
            ten = 0;
        }
        if(l1 != nullptr)
            l1 = l1->next;
        if(l2 != nullptr)
            l2 = l2->next;
    }

    ListNode *temp = res->next;
    delete res;

    return temp;
}

int main()
{
    ListNode *l1 = (ListNode *)malloc(sizeof(ListNode));
    l1->next = (ListNode *)malloc(sizeof(ListNode));
    l1->next->next = (ListNode *)malloc(sizeof(ListNode));

    l1->val = 2;
    l1->next->val = 4;
    l1->next->next->val = 3;
    l1->next->next->next = nullptr;

    ListNode *l2 = (ListNode *)malloc(sizeof(ListNode));
    l2->next = (ListNode *)malloc(sizeof(ListNode));
    l2->next->next = (ListNode *)malloc(sizeof(ListNode));
    l2->next->next->next = nullptr;

    l2->val = 5;
    l2->next->val = 6;
    l2->next->next->val = 9;

    Solution sum;

    ListNode *res = sum.addTwoNumbers(l1, l2);
    while(res != nullptr)
    {
        printf("%d ", res->val);
        ListNode *temp = res;
        res = res->next;
        free(temp);
    }

    l1->clear(); 
    l1 = nullptr;
    l2->clear();
    l2 = nullptr;

    return 0;
}