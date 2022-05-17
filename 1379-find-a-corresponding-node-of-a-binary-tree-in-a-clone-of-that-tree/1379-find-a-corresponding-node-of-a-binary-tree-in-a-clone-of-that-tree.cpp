/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    bool bFind = false;
    TreeNode* retNode;
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        findCopyNode(original, cloned, target);
        
        return retNode;
    }
    
    void findCopyNode(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        if(bFind||original==NULL)
            return;
        
        if(target->val == cloned->val)
        {
            bFind = true;
            retNode = cloned;
        }
        else
        {
            findCopyNode(original->right, cloned->right, target);
            findCopyNode(original->left, cloned->left, target);
        }
    }
};