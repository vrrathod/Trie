// Trie.h

#include <iostream>
#include <list>
#include <queue>
#include <string>

#include "Node.h"

using namespace std;

struct stringpair {
	string compositeString;
	string prefix;
	stringpair(string afull,string afoundpart):compositeString(afull),prefix(afoundpart) {}
//	void print() {
//		std::cout << "{ " << compositeString << ", " << prefix << " }" << std::endl;
//	}

	bool isMatch() {
		return (compositeString == prefix);
	}
};

class Trie
{
	Node* root;
	list<string> mLCWStack;
	queue<stringpair*> m_prefixQueue;
	string mLCW;

public:
	Trie();
	~Trie();
	
	// add details
	void addWord( std::string s ) ;
	bool removeWord( std::string s ) ;

	// labour job
 	void generatePrefixes(Node *node, std::string currentWord);
    void validateMatchForPrefix(const std::string targetString, const std::string prefix);
	std::string findLongestComposite();
    void printFirstN(const int n);
    
};