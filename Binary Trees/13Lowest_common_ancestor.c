/*The lowest common ancestor is the lowest node in the tree that has both n1 and n2 as descendants, where n1 and n2 are the nodes for which we wish to find the LCA. Hence, the LCA of a binary tree with nodes n1 and n2 is the shared ancestor of n1 and n2 that is located farthest from the root. 

Approach-The idea is to traverse the tree starting from the root. If any of the given keys (n1 and n2) matches with the root, then the root is LCA (assuming that both keys are present). If the root doesn’t match with any of the keys, we recur for the left and right subtree. 

The node which has one key present in its left subtree and the other key present in the right subtree is the LCA. 
If both keys lie in the left subtree, then the left subtree has LCA also, 
Otherwise, LCA lies in the right subtree.  
*/


// C Program to find LCA of n1 and n2 using one traversalof
// Binary Tree
#include <stdio.h>
#include <stdlib.h>

// A Binary Tree Node
typedef struct Node {
	struct Node *left, *right;
	int key;
} Node;

// Utility function to create a new tree Node
Node* newNode(int key)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

// This function returns pointer to LCA of two given values
// n1 and n2. This function assumes that n1 and n2 are
// present in Binary Tree
Node* findLCA(Node* root, int n1, int n2)
{
	// Base case
	if (root == NULL)
		return NULL;

	// If either n1 or n2 matches with root's key, report
	// the presence by returning root (Note that if a key is
	// ancestor of other, then the ancestor key becomes LCA
	if (root->key == n1 || root->key == n2)
		return root;

	// Look for keys in left and right subtrees
	Node* left_lca = findLCA(root->left, n1, n2);
	Node* right_lca = findLCA(root->right, n1, n2);

	// If both of the above calls return Non-NULL, then one
	// key is present in once subtree and other is present
	// in other, So this node is the LCA
	if (left_lca && right_lca)
		return root;

	// Otherwise check if left subtree or right subtree is
	// LCA
	return (left_lca) ? left_lca : right_lca;
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree given in the above example
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	printf("LCA(4, 5) = %d", findLCA(root, 4, 5)->key);
	printf("\nLCA(4, 6) = %d", findLCA(root, 4, 6)->key);
	printf("\nLCA(3, 4) = %d", findLCA(root, 3, 4)->key);
	printf("\nLCA(2, 4) = %d", findLCA(root, 2, 4)->key);
	
	return 0;
}

