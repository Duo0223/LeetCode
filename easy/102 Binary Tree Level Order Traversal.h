/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7


return:
   
[
  [15,7],
  [9,20],
  [3]
]
*/
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
	
	typedef struct
	{
		TreeNode* 	ptr;
		int			level;
	} NodeType ;
	
	void pushNodeToBFS( TreeNode *_node , int _level , queue< NodeType > &_queue )
	{
		if( _node == NULL )
			return;
		
		NodeType node;
		node.ptr = _node;
		node.level = _level;
		_queue.push( node );
		return;
	}

    vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector< vector< int > >	ret;
		queue< NodeType >       BFS;
		queue< vector< int > >  myQueue;
		ret.clear();
		
		if( root == NULL )	return ret;
		
		NodeType node;
		node.ptr = root;
		node.level = 0;
		
		BFS.push( node );
		
		int nowLevel = -1;
		
		while( !BFS.empty() )
		{
			NodeType currNode = BFS.front();
			BFS.pop();
			
			// push to ret vector
			if( nowLevel != currNode.level )
			{
				vector< int > tmp;
				tmp.push_back( currNode.ptr->val );
				myQueue.push( tmp );
				nowLevel = currNode.level;
			}
			else
			{
				myQueue.back().push_back( currNode.ptr->val );
			}				
			
			pushNodeToBFS( currNode.ptr->left , currNode.level + 1 , BFS );
			pushNodeToBFS( currNode.ptr->right , currNode.level + 1 , BFS );	
		}

		while( !myQueue.empty() )
		{
			ret.push_back( myQueue.front() );
			myQueue.pop();
		}
		return ret;
    }
};