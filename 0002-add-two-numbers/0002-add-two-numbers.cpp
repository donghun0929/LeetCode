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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *retNode = new ListNode();
        ListNode *tmpNode = new ListNode();
        vector<int> v1;
        vector<int> v2;
        
        tmpNode = retNode;
        
        int n= 0;
        while(l1 != nullptr)
        {
            n = l1->val;
            v1.push_back(n);
            l1 = l1-> next;
        }
        while(l2 != nullptr)
        {
            n = l2->val;
            v2.push_back(n);
            l2 = l2-> next;
        }
        
        int idx = v1.size() > v2.size() ?  v1.size() : v2.size();
        v1.resize(idx);
        v2.resize(idx);
        
        int k = 0;
        for(int i = 0; i < idx ; i++)
        {
            n = v1[i]+v2[i]+k;
            if(n >= 10)
            {
                n= n%10;
                k = 1;
            }
            else
            {
                k = 0;
            }
            tmpNode -> val = n;
            if(i >= idx -1)
                break;
            tmpNode -> next = new ListNode();
            tmpNode = tmpNode->next;
        }
        if(k == 1)
        {
            
            tmpNode -> next = new ListNode();
            tmpNode = tmpNode->next;
            tmpNode -> val = k;
        }
        
        return retNode;
    }
};