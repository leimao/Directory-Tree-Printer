#include "tree.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <fstream>
#include <filesystem>

#define GIT_IGNORE true
#if GIT_IGNORE
	#include "git_ignore_util.hpp"
#endif

using namespace std;
using namespace filesystem;

static path tree_root = ".";
static vector<string> files;
void get_allFiles(const path& root){
	if( !exists(root) || !is_directory(root) )	return;

	for( const auto& entry : directory_iterator(root) ){
		string filename = entry.path().filename().generic_string();
		#if GIT_IGNORE
			if( matched_any(filename, ignoredFiles) )
				continue;
		#endif

		files.push_back( relative(entry.path(), tree_root).generic_string() );

		if( entry.is_directory() )
			get_allFiles(entry);
	}
}

int main(int argc, char** argv){

	static path tree_root;
	tree_root = current_path();
	if(argc > 1){
		tree_root = argv[1];
	}

    string root_name = relative(tree_root, current_path()).generic_string();
	current_path(tree_root);	//`cd` to the chosen directory

	#if GIT_IGNORE
		gitIgnore(tree_root);
	#endif

	get_allFiles(".");	//since we `cd` into the tree_root, we can simply start this function, irrespective of what the root_folder should have been

	Tree tree;

	read_dirs(files, tree, root_name);
	tree.print_tree();
	// tree.print_tree_simple();
	return 0;

}
