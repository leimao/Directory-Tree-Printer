#include "tree.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Helper functions
void read_dirs(const vector<string>& argv, Tree& tree){
	char sep('/');

	for( auto& dir : argv )	//iterate through all directories received
	{
		TreeNode treenode;
		// vector<string> string_tokens{ tokenizeStr(dir, sep) };

		auto n_tokens = count(dir.begin(), dir.end(), '/');

		treenode.depth = n_tokens;
		treenode.name = dir.substr(dir.find_last_of(sep) + 1);	//get the last token in `dir`

		tree.treenodes.push_back(treenode);
	}
}


void Tree::print_tree_simple() const{
	for( auto treenode : treenodes ){
		cout << string((treenode.depth) * 5, ' ') << treenode.name << endl;
	}
}


void Tree::print_tree(){

	int depth_largest = 0;
	for( auto treenode : treenodes ){
		if( treenode.depth > depth_largest ){
			depth_largest = treenode.depth;
		}
	}

	for( int i = 0; i <= depth_largest; i++ ){
		for( int j = 0; j < (int) treenodes.size(); ){

			while( (treenodes[j].depth != i) && (j < (int) treenodes.size()) ){
				j++;
			}


			treenodes[j].nodelabel.push_back(treenodes[j].name);

			int k = j + 1;
			while( (treenodes[k].depth > treenodes[j].depth) && (k < (int) treenodes.size()) ){
				k++;
			}

			int last_element_index = j;
			for( int h = j + 1; h < k; h++ ){
				if( treenodes[h].depth == i + 1 ){
					last_element_index = h;
				}
			}

			for( int h = j + 1; h <= last_element_index; h++ ){
				if( h == last_element_index ){
					treenodes[h].nodelabel.push_back("└── ");
				} else if( treenodes[h].depth == i + 1 ){
					treenodes[h].nodelabel.push_back("├── ");
				} else{
					treenodes[h].nodelabel.push_back("│   ");
				}

			}
			for( int h = last_element_index + 1; h < k; h++ ){
				treenodes[h].nodelabel.push_back("    ");
			}
			j = k;

		}

	}

	for( auto treenode : treenodes ){
		for( auto label : treenode.nodelabel ){
			cout << label;
		}
		cout << endl;
	}

}


