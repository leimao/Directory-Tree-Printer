#include "tree.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>	//for std::count

using namespace std;

// Helper functions
void read_dirs(const vector<string>& argv, Tree& tree, const string& root_name){
    TreeNode treenode;
    treenode.depth = 0;
    treenode.name = root_name;
    tree.treenodes.push_back(treenode);

	for( auto& dir : argv )	//iterate through all directories received
	{

		string file_name = dir.substr( dir.find_last_of('/') + 1 );	//getting the last token (eg. in "folder/file.txt" we get "file.txt" )

		treenode.depth = count(dir.begin(), dir.end(), '/') + 1;	//counting number of '/'
		treenode.name = file_name;

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

			while( (treenodes[j].depth != i) && (j < (int) treenodes.size()) ){	//loop till treenodes[j] depth is i
				j++;
			}

			if(j==treenodes.size()) continue;
			treenodes[j].nodelabel.push_back(treenodes[j].name);

			int k = j+1;
			while( (k < (int) treenodes.size()) && (treenodes[k].depth > treenodes[j].depth) ){	//loop untill treenodes[k] is NOT a subdir/file inside of treenodes[j]
				k++;
			}

			int last_element_index = j;
			for( int h = j + 1; h < k; h++ ){	//this will only loop through subdir/files inside it
				if( treenodes[h].depth == i + 1 ){
					last_element_index = h;
				}
			}	//after this, last_element_index will be last index such that the file is directly under treenode[j]

			int h;
			for( h = j + 1; h <= last_element_index; h++ ){
				if(h == last_element_index){
					treenodes[h].nodelabel.push_back("└── ");
				}
				else if( treenodes[h].depth == i + 1 ){	//ie. if directly under treenode[j]
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


