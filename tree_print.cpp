
#include "tree.h"

int main(int argc, char ** argv)
{
	Tree tree;
	read_dirs(argc, argv, tree);
	tree.print_tree();
	return 0;
}