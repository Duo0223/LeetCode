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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        int topIdx = 0;
        TreeNode* dfsStack[100] = { NULL };
        dfsStack[ topIdx ] = root;
    
        vector< string > paths;
        TreeNode* topNode = NULL;
        TreeNode* popNode = NULL;
        
        if( root == NULL )  return paths;
        
        while( topIdx >= 0 )
        {
            topNode = dfsStack[topIdx];
            
            if( popNode == NULL )
            {
                if( topNode->left != NULL )
                {
                    ++topIdx;
                    dfsStack[topIdx] = topNode->left;
                }
                else if( topNode -> right != NULL )
                {
                    ++topIdx;
                    dfsStack[topIdx] = topNode->right; 
                }
                else
                {
                    string path;
                    for( int i = 0 ; i <= topIdx ; ++i )
                    {
                        string node;
                        stringstream nodeSS( node );
                        nodeSS << dfsStack[i]->val;
                        path += nodeSS.str();
                        if( i != topIdx ) path += "->";
                    }
                    paths.push_back( path );
                    popNode = topNode;
                    --topIdx;
                }
            }
            else
            {
                if( popNode == topNode->left && topNode->right != NULL )
                {
                    ++topIdx;
                    dfsStack[topIdx] = topNode->right;
                    popNode = NULL;
                }
                else
                {
                    popNode = topNode;
                    --topIdx;
                }
            }
        }
        return paths;
    }
};