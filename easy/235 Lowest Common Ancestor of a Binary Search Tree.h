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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		if( root == NULL )
			return NULL;
		
		TreeNode* 			myStack[1000] = { NULL };
		queue< TreeNode* > 	path;
		TreeNode * 			found = NULL;
		TreeNode *			nextFind = NULL;
		TreeNode *			pop = NULL;
		int 	 			topIndex = 0;
		
		myStack[topIndex] = root;
	
        while( topIndex >= 0 )
		{
			TreeNode* top = myStack[ topIndex ];
			
			// first find p or q
			if( found == NULL && ( top == p || top == q ) )
			{
				if( top == p )
				{
					found = p;
					nextFind = q;
				}
				else
				{
					found = q;
					nextFind = p;
				}
				
				for( int i = topIndex ; i >= 0 ; --i )
					path.push( myStack[ i ] );
			}
			
			// find the next 
			if( top == nextFind )
			{
				while( ! path.empty() )
				{
					TreeNode *LCA = path.front();
					path.pop();
					
					for( int i = topIndex ; i >= 0 ; --i  )
						if( LCA == myStack[i] )
							return LCA;
				}
			}
			
			// left first
			if( pop == NULL )
			{
				if( top->left != NULL )
				{
					++topIndex;
					myStack[topIndex] = top->left;
				}
				else if( top->right != NULL )
				{
					++topIndex;
					myStack[topIndex] = top->right;
				}
				else	
				{
					pop = top;
					--topIndex;
				}
			}
			else
			{
				if( pop == top->left )
				{
					if( top->right != NULL )
					{
						++topIndex;
						myStack[topIndex] = top->right;
						pop = NULL;
					}
					else
					{
						pop = top;
						--topIndex;
					}
				}
				else if( pop == top->right )
				{
					pop = top;
					--topIndex;
				}
			}
		}
		return NULL;
    }
};