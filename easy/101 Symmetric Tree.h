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
    
private:
    
    
    bool isMirror( TreeNode *_t1 , TreeNode *_t2 )
    {
        if( _t1 == NULL && _t2 == NULL ) return true;
        if( _t1 == NULL || _t2 == NULL ) return false;
        
        return ( ( _t1->val == _t2-> val ) && isMirror( _t1->left , _t2->right ) && isMirror( _t1->right , _t2->left ) );
    }
    
public:
    bool isSymmetric(TreeNode* root)
    {
        if( root == NULL )  return true;
        
        return isMirror( root , root );
    }
};