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
    
    void DFS( TreeNode *root , int _level , int &_max )
    {
        if( root->left == NULL && root->right == NULL )
        {
            if( _level > _max  )
                _max = _level;
            return;
        }
        if( root->left != NULL )
            DFS(root->left , _level + 1 , _max );
        if( root->right != NULL)
            DFS(root->right , _level + 1 , _max );
    }
    
    int maxDepth(TreeNode* root)
    {
        if( root == NULL )
        {
            return 0;
        }
        int maxValue = 0;
        DFS(root , 1 , maxValue);
        return maxValue;
    }
};