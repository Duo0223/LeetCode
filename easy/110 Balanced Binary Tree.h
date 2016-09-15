/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int getHeight( TreeNode* root )
    {
        int left = 0, right = 0;
        if( !root || ( !root ->left && !root->right ) )
            return 0;
        if( root->left != NULL )
            left = 1 + getHeight( root->left );
        if( root->right != NULL )
            right = 1 + getHeight( root->right );
        return max( left, right );
    }
    
    bool isBalanced(TreeNode* root)
    {
        if( !root || ( !root->left && !root->right ) )
            return true;
        int left = (root->left == NULL) ? 0 : getHeight( root->left ) + 1;
        int right = (root->right == NULL) ? 0 : getHeight( root->right ) + 1;
        if( abs( left - right ) > 1 )
            return false;
        else if( !isBalanced( root->left ) || !isBalanced( root->right ) )
            return false;
        return true;
    }
};