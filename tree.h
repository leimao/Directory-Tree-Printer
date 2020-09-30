#ifndef TREE_H
#define TREE_H

#include <string>
#include <vector>

using namespace std;

// The algorithm might be asymptotically slow, which could be as worse as O(n^3), because I did not implement the tree using pointers.
// However, in practice, it should be sufficient since the user will only print the directory tree that is not too large.
// Ideally, DFS should be the right algirthm to print the tree. 

struct TreeNode
{
	string name;
	int depth;
	vector<string> nodelabel;
};

struct Tree
{
	// 1D treenodes
	vector<TreeNode> treenodes;
	void print_tree_simple() const;
	void print_tree();
};


void read_dirs(const vector<string>& argv, Tree &tree);

#endif