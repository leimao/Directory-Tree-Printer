#include "tree.h"
#include <string>
#include <iostream>
#include <vector>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;


// Helper functions

void read_dirs(int argc, char ** argv, Tree &tree)
{
	char_separator<char> sep("/");
	typedef tokenizer<char_separator<char> > Token;

	for (int i = 1; i < argc; i++)
	{
		TreeNode treenode;

		string dir = argv[i];
		Token tokens(dir, sep);
		unsigned int n_tokens = 0;
		// Count tokens
		vector<string> string_tokens;
		for (Token::iterator it = tokens.begin(); it != tokens.end(); it++)
		{
			string_tokens.push_back(*it);
			n_tokens ++;
		}

		treenode.depth = n_tokens - 1;
		treenode.name = string_tokens[n_tokens-1];

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


