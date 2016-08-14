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
public:
    bool hasPathSum(TreeNode* root, int sum) 
    {
        if( root == NULL ) return false;
        
        stack< TreeNode* > dfs;
        int nowSum = root->val;
        dfs.push( root );
        TreeNode* node = NULL;
        TreeNode* popNode = NULL;
        while( !dfs.empty() )
        {
            node = dfs.top();
            if( popNode == NULL )
            {
                if( node->left != NULL )
                {
                    dfs.push( node->left );
                    nowSum += node->left->val;
                }
                else if( node->right != NULL  )
                {
                    dfs.push( node->right );
                    nowSum += node->right->val;
                }
                else
                {
                    if( nowSum == sum ) return true;
                    popNode = node;
                    dfs.pop();
                    nowSum -= popNode->val;
                }
            }
            else
            {
                if( popNode == node->left )
                {
                    if( node->right != NULL )
                    {
                        popNode = NULL;
                        dfs.push( node->right );
                        nowSum += node->right->val;
                    }
                    else
                    {
                        popNode = node;
                        dfs.pop();
                        nowSum -= popNode->val;
                    }
                }
                else if( popNode == node->right )
                {
                    popNode = node;
                    dfs.pop();
                    nowSum -= popNode->val;
                }
            }
        }
        return false;
        
    }
};