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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *res = new ListNode();
        ListNode *temp = res;
        while(!(list1 == nullptr && list2 == nullptr))
        {
            if(list1 == nullptr)
            {
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
                continue;
            }
            if(list2 == nullptr)
            {
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
                continue;
            }
            if(list1->val <= list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
                continue;
            }
            temp->next = list2;
            list2 = list2->next;
            temp = temp->next;
        }
        return res->next;
    }
};

int main()
{
    ListNode *list1 = nullptr, *list2 = nullptr;
    // list1 = new ListNode(4); list1 = new ListNode(2, list1); list1 = new ListNode(1, list1);
    // list2 = new ListNode(4); list2 = new ListNode(3, list2); list2 = new ListNode(1, list2);

    Solution solution;
    ListNode *res = solution.mergeTwoLists(list1, list2);
    while(res != nullptr)
    {
        ListNode *temp = res;
        printf("%d ", res->val);
        res = res->next;
        delete temp;
    }
    return 0;
}