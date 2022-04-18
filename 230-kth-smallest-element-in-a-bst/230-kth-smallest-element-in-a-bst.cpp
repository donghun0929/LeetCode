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
    map<int, int> m;
    int kthSmallest(TreeNode* root, int k) {
        TreeSearch(root);
        
        int count =1;
        for(auto iter=m.begin();iter!=m.end();iter++){
            if(count== k)
                return iter->first;
            count++;
        }
        
        return 1;
        
    }
    void TreeSearch(TreeNode* root)
    {
        if(!root)
            return;
        m[root->val]++;
        TreeSearch(root->left);
        TreeSearch(root->right);
    }
};