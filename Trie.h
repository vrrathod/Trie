// Trie.h

#include <iostream>
#include <list>
#include <queue>
#include <string>

#include "Node.h"

using namespace std;

/**
 * Data structure to hold pair of strings. One of the string is composite word.
 * The other is prefix of the composite.
 */
struct stringpair {
  /// composite word
  string compositeString;
  /// prefix string
  string prefix;
  
  /// constructor
  stringpair(string afull,string afoundpart)
    :compositeString(afull),prefix(afoundpart) {}
  
  /**
   * Checks if a given prefix is composite word by itself.
   * This is a termination condition for our search of the word.
   * 
   * @return true if prefix is a composite word.
   */
  bool isMatch() {
    return (compositeString == prefix);
  }
};

/**
 *  Trie data structure implementation
 *  provides means to efficiently search string data.
 */
class Trie
{
  /// root node for the trie data structure
  Node* root;

  /// this is a dual purpose list.
  /// 1. during generation of prefixes, it holds the words to generate composite, prefix pairs
  /// 2. during validation, it holds list of composite words. 
  list<string> mLCWStack; 

  /// queue to hold pair of composite and prefix words
  queue<stringpair*> m_prefixQueue;

public:
  Trie();
  ~Trie();
  
  /**
   * adds given word into trie data structure. 
   * @param s word to be added.
   */
  void addWord( std::string s ) ;

  /**
   * Removes given string from trie data structure. It just un-marks for a complete word. This does not adjust tree.
   * @param  s string to be removed
   * @return  true if string is removed, false otherwise.
   */
  bool removeWord( std::string s ) ;

/**
 * Given a starting node and current word, it shall recursively try to find the 
 * best prefix and generate composite and prefix pairs.
 * @param node        starting node.
 * @param currentWord current word
 */
  void generatePrefixes(Node *node, std::string currentWord);
  
  /** Given a target string and a prefix, this shall process the reminder of the target string to match other words.
    @param targetString potential composite word.
    @param prefix       prefix of the targetString that has already been matched.
   */
    void validateMatchForPrefix(const std::string targetString, const std::string prefix);

  /** This is to go function when all the words are added. This should generate all the pre-fixes. Also 
      it shall generate appropriate list for all the composite words.
   */
      void findLongestComposite();

  /** Prints first n composite words found. 
    In case if n > count, prints all composite words.

    @param n  number of composite words to print
   */
    void printFirstN(const int n);

  /** Prints results as expected. The output is in following format.
    Longest Composite Word: <word>
    Second Longest Word   : <word>
    Total word count      : <count>
    
    @param None
  */
    void printResults() ;
  };