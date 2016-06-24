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
    
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        queue< TreeNode * > pQ;
        queue< TreeNode * > qQ;
        
        if( p != NULL && q != NULL )
        {
            pQ.push( p );
            qQ.push( q );
            while( !pQ.empty() && !qQ.empty() )
            {
                TreeNode *nowP = pQ.front();
                TreeNode *nowQ = qQ.front();
                pQ.pop();
                qQ.pop();
                
                if( nowP->val != nowQ->val )
                    return false;
                
                if( nowP->left != NULL && nowQ->left != NULL )
                {
                    pQ.push( nowP->left );
                    qQ.push( nowQ->left );
                }
                else if( nowP->left != nowQ->left )
                    return false;
                
                
                if( nowP->right != NULL && nowQ->right != NULL )
                {
                    pQ.push( nowP->right );
                    qQ.push( nowQ->right );
                }
                else if( nowP->right != nowQ->right )
                    return false;
                
            }
        }
        else if( p != q )
            return false;
        
        return true;
        
    }
};