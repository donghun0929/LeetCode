/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<pair<int, TreeNode*>> q;
        map<int, vector<int>> m;
        pair<int, TreeNode*> p;
        q.push(make_pair(0, root));

        if(!root)
            return v;
        while(!q.empty())
        {
            p = q.front();
            q.pop();

            if(m.find(p.first) != m.end())
            {
                vector<int> vv = m[p.first];
                vv.push_back(p.second->val);
                m.erase(p.first);
                m.insert({p.first, vv});
            }
            else
            {
                vector<int> vv ;
                vv.push_back(p.second->val);
                m.insert({p.first, vv});
            }
          
            if(p.second->left)
                q.push(make_pair(p.first-1, p.second->left));
            if(p.second->right)
                q.push(make_pair(p.first+1, p.second->right));
        }

        for (auto iter : m) {
      		v.push_back(iter.second);
      	}
                
        return v;
    }
};