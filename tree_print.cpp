
#include "tree.h"
#include <iostream>
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
	tree_root = argc >= 2 ? argv[1] : current_path();

	#if GIT_IGNORE
		gitIgnore(tree_root);
	#endif

	get_allFiles(tree_root);

	Tree tree;

	read_dirs(files, tree);
	tree.print_tree();
	return 0;

}