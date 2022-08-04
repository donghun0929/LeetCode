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
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        vector<vector<int>> vv(101);
        TreeNode *tempNode;
       
        int k = reqTree(root, vv);
        vv.resize(k);
        return vv;
    }
    
    int reqTree(TreeNode* root, vector<vector<int>> & vv)
    {
        if(!root)
        {
            return 0;
        }
        int nLeft = reqTree(root->left, vv);
        int nRight = reqTree(root->right, vv);
        
        int retVal =  nLeft >= nRight ? nLeft  : nRight;
        vv[retVal].push_back(root->val);
        
        return ++retVal;
    }
};