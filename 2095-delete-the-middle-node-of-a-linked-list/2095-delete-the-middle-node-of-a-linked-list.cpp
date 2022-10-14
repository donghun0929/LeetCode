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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int k = 0;
        vector<int> v;
        
        ListNode* searchMidHead = head;
        while(searchMidHead)
        {
            v.push_back(searchMidHead->val);
            searchMidHead= searchMidHead->next;
            k++;
        }
        k= k/2;
        v.erase(v.begin()+k);
        
        
        for(int i = v.size()-1; i >= 0; i--)
        {
            searchMidHead= new ListNode(v[i],searchMidHead);
        }
        
        return searchMidHead;
    }
};