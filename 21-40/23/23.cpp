#include<iostream>
#include<vector>

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *res = new ListNode();
        ListNode *temp = res;
        int i = 0;
        while(i < lists.size())
        {
            if(lists[i] == nullptr)
            {
                swap(lists[i], lists.back());
                lists.pop_back();
                continue;
            }
            i++;
        }
        while(!lists.empty())
        {
            int idx = 0, mini = lists[0]->val;
            for(i = 1; i < lists.size(); i++)
            {
                if(lists[i]->val < mini)
                {
                    idx = i; 
                    mini = lists[i]->val;
                }
            }
            temp->next = lists[idx];
            temp = temp->next;
            lists[idx] = lists[idx]->next;
            if(lists[idx] == nullptr)
            {
                swap(lists[idx], lists.back());
                lists.pop_back();
            }
        }
        temp = res;
        res = res->next;
        delete temp;
        return res;
    }
};

int main()
{
    vector<ListNode *> lists;
    ListNode *list = new ListNode(5);
    list = new ListNode(4, list);
    list = new ListNode(1, list);
    lists.push_back(list);
    list = new ListNode(4); list = new ListNode(3, list); list = new ListNode(1, list);
    lists.push_back(list);
    list = new ListNode(6); list = new ListNode(2, list);
    lists.push_back(list);

    Solution solution;
    ListNode *res = solution.mergeKLists(lists);
    while(res != nullptr)
    {
        ListNode *temp = res;
        printf("%d ", res->val);
        res = res->next;
        delete temp;
    }
    return 0;
}