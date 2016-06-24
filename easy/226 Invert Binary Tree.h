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
    TreeNode* invertTree(TreeNode* root)
    {
        if( root == NULL )
            return NULL;
        
        queue< TreeNode* > BFS_Buffer;
        BFS_Buffer.push( root );
        
        while ( !BFS_Buffer.empty() )
        {
            TreeNode *node = BFS_Buffer.front();
            BFS_Buffer.pop();
            
            TreeNode* tmpNode = node->left;
            node->left = node->right;
            node->right = tmpNode;
            
            if( node->right != NULL )
            {
                BFS_Buffer.push( node->right );
            }
            if( node->left != NULL )
            {
                BFS_Buffer.push( node->left );
            }
        }
        return root;
    }
};