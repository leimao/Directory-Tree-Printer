#include <filesystem>
#include <fstream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using namespace filesystem;

vector<regex> ignoredFiles = { regex(".git"), regex(".gitignore") };
bool matched_any(string s, vector<regex>& reg_vec){	//whether if s matches any regex
	for( auto&& reg : reg_vec ){
		if( regex_match(s, reg) )	return true;
	}
	return false;
}

void replace_all(string& s, const string& _old, const string& _new){	//replace all `old` with `new` in s
	size_t start = s.find(_old);

	while( start != string::npos ){
		s.replace(start, _old.size(), _new);
		start += 4;	//to ignore (.*)
		start = s.find(_old, start);
	}
}

void gitIgnore(path& p){
	const string filePath = p.generic_string() + "/.gitignore";
	if( !exists(filePath) )
		return;

	ifstream fin(filePath);
	string s;
	while( fin >> s ){
		replace_all(s, "*", "(.*)");
		ignoredFiles.push_back(regex(s));
	}
	fin.close();
}

std::vector<std::string> tokenizeStr(const std::string& s, char sep)
{
    using namespace std;
    vector<string> tokens;

    istringstream stream( s );
    while ( !stream.eof() )
    {
        string x;               // empty string
        getline( stream, x, sep );  // try to read the next field into it
        tokens.push_back(x);
    }

    return tokens;
}
