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
    queue<TreeNode*> q;
    queue<TreeNode*> tempQ;
    queue<TreeNode*> newQ;
    stack<TreeNode*> s;
    bool bZigZag = false;
    vector<vector<int>> vv;
    vector<int> v;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root == NULL)
            return vv;
        TreeNode* now;
        q.push(root);
        v.push_back(root->val);
        vv.push_back(v);
        while(!q.empty())
        {
            tempQ = queue<TreeNode*>();
            tempQ = q;
            q=queue<TreeNode*>();
            v.clear();
            
            //if(bZigZag)
            //{
                while(!tempQ.empty())
                {
                    s.push(tempQ.front());
                    tempQ.pop();
                }
                while(!s.empty())
                {
                    tempQ.push(s.top());
                    s.pop();
                }
            //}
            
            while(!tempQ.empty())
            {
                now = tempQ.front();
                tempQ.pop();

                if(!bZigZag)
                {            

                    if(now->right != NULL)
                        newQ.push(now->right);
                    if(now->left != NULL)
                        newQ.push(now->left);
                    
                    if(now->right != NULL)
                        v.push_back(now->right->val);
                    if(now->left != NULL)
                        v.push_back(now->left->val);                
                }
                else
                {
                    if(now->left != NULL)
                        newQ.push(now->left);
                    if(now->right != NULL)
                        newQ.push(now->right);

                    if(now->left != NULL)
                        v.push_back(now->left->val);
                    if(now->right != NULL)
                        v.push_back(now->right->val);
                }
            }
            bZigZag = bZigZag ? false: true;
            if(v.size() != 0)
            {   
                vv.push_back(v);
            }
            q = newQ;
            newQ =queue<TreeNode*>();
        }
        return vv;
    }
};