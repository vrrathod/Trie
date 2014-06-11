// Node.h

#include <iostream>
#include <vector>

#ifndef __NODE_H__
#define __NODE_H__

/**
 * The data structure to hold data at each node in trie.
 */
class Node
{
  // store each character
  char m_data;
  // is a word
  bool m_isCompleteWord;
  // children
  std::vector<Node*> m_children;

public:
  Node( char c, bool isWord );
  ~Node();
  // data
  char getData();
  // is complete word
  bool isCompleteWord();
  // set complete word
  void setCompleteWord(bool completeWord = true);
  // find child
  Node* findChild( const char c );
  // add children
  void appendChild( Node* node ) ;
  // list of children
  std::vector<Node*> getChildren();
};

#endif //__NODE_H__
