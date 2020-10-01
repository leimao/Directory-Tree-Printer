#include "tree.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>	//for std::count

using namespace std;

// Helper functions

void read_dirs(int argc, char ** argv, Tree &tree)
{
	char sep('/');	//can be a string too, but considering generic paths, not having '\\'
	for (int i = 1; i < argc; i++)
	{
		TreeNode treenode;

		string dir = argv[i];

		string file_name = dir.substr( dir.find_last_of(sep) + 1 );	//getting the last token (eg. in "folder/file.txt" we get "file.txt" )

		treenode.depth = count(dir.begin(), dir.end(), sep);	//counting number of '/'
		treenode.name = file_name;

		tree.treenodes.push_back(treenode);

	}
}


void Tree::print_tree_simple() const
{
	for (auto treenode : treenodes)
	{
		cout << string((treenode.depth) * 5, ' ') << treenode.name << endl;
	}

}


void Tree::print_tree()
{

	int depth_largest = 0;
	for (auto treenode : treenodes)
	{
		if (treenode.depth > depth_largest)
		{
			depth_largest = treenode.depth;
		}
	}

	for (int i = 0; i <= depth_largest; i ++)
	{
		for (int j = 0; j < (int) treenodes.size(); )
		{
			
			while ((treenodes[j].depth != i) && (j < (int) treenodes.size()))
			{
				j ++;
			}


			treenodes[j].nodelabel.push_back(treenodes[j].name);

			int k = j+1;
			while ((treenodes[k].depth > treenodes[j].depth) && (k < (int) treenodes.size()))
			{
				k ++;
			}

			int last_element_index = j;
			for (int h = j + 1; h < k; h ++)
			{
				if (treenodes[h].depth == i + 1)
				{
					last_element_index = h;
				}
			}

			for (int h = j+1; h <= last_element_index; h ++)
			{
				if (h == last_element_index)
				{
					treenodes[h].nodelabel.push_back("└── ");
				}
				else if (treenodes[h].depth == i + 1)
				{
					treenodes[h].nodelabel.push_back("├── ");
				}
				else
				{
					treenodes[h].nodelabel.push_back("│   ");
				}
				
			}
			for (int h = last_element_index + 1; h < k; h ++)
			{
				treenodes[h].nodelabel.push_back("    ");
			}
			j = k;

		}

	}


	for (auto treenode : treenodes)
	{
		for (auto label : treenode.nodelabel)
		{
			cout <<  label;
		}
		cout << endl;
	}



}


