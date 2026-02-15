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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *res = new ListNode(0, head);
        ListNode *before = res;
        bool label = true;
        ListNode *curr = head, *tail;
        for(int i = 0; i < k; i++)
        {
            if(curr == nullptr)
            {
                label = false;
                break;
            }
            tail = curr;
            curr = curr->next;
        }
        ListNode *after = curr;
        while(label)
        {
            curr = head;
            ListNode *next = curr->next, *past = nullptr;
            while(curr != tail)
            {
                curr->next = past;
                past = curr;
                curr = next;
                next = curr->next;
            }
            curr->next = past;
            before->next = tail;
            head->next = after;
            before = head;

            head = after;  
            curr = head;
            for(int i = 0; i < k; i++)
            {
                if(curr == nullptr)
                {
                    label = false;
                    break;
                }
                tail = curr;
                curr = curr->next;
            }
            after = curr;
        }
        curr = res;
        res = res->next;
        delete curr;
        return res;
    }
};

int main()
{
    ListNode *list = new ListNode(5);
    list = new ListNode(4, list);
    list = new ListNode(3, list);
    list = new ListNode(2, list);
    list = new ListNode(1, list);
    int k = 3;

    Solution solution;

    ListNode *res = solution.reverseKGroup(list, k);
    while(res != nullptr)
    {
        ListNode *temp = res;
        printf("%d ", res->val);
        res = res->next;
        delete temp;
    }
    return 0;
}