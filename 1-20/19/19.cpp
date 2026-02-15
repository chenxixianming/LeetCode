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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int num = 0;
        ListNode *temp = head;
        while(temp != nullptr)
        {
            num++;
            temp = temp->next;
        }
        num -= n;
        head = new ListNode(0, head);
        temp = head;
        while(num > 0)
        {
            temp = temp->next;
            num--;
        }
        // printf("%d", temp->val);
        ListNode *temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
        return head->next;
    }
};

int main()
{
    ListNode *temp = new ListNode(5);
    ListNode *head = new ListNode(4, temp);
    temp = new ListNode(3, head);
    head = new ListNode(2, temp);
    temp = new ListNode(1, head); head = temp;
    int n = 2;

    Solution solution;
    ListNode *res = solution.removeNthFromEnd(head, n);
    while(res != nullptr)
    {
        printf("%d ", res->val);
        temp = res;
        res = res->next;
        delete temp;
    }
    return 0;
}