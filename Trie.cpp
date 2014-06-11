// Trie.cpp

#include "Trie.h"
#include "Node.h"
#include "Util.h"

Trie::Trie() {
  root = new Node( char(0), false );
}

Trie::~Trie() {
  delete root;
}

// add details
void Trie::addWord( std::string s ) {
  Node* current = root;

  if( s.length() == 0 ) {
    current->setCompleteWord();
    return;
  }

  // loop through each character and build a Trie
  for( int i = 0; i < s.length(); ++i ) {
    Node* nextNode = current->findChild( s[i] );
    if( !nextNode ) {
      Node* temp = new Node( s[i], false ) ;
      current->appendChild( temp );
      current = temp;
    } else {
      current = nextNode;
    }

    if( i == s.length() - 1 ) {
      current->setCompleteWord();
    }
  }
}

bool Trie::removeWord( std::string s ) {
  bool bRet = false;
  // effectively we are reseting the marker bit
  // we could potentially get rid of un wanted characters but I would leave up for optimization
  //TODO: optimize to remove un-necessary children
  Node* current = root;

  if( s.length() == 0 ) {
    current->setCompleteWord( false );
  }

  // loop through each character and build a Trie
  for( int i = 0; i < s.length(); ++i ) {
    Node* nextNode = current->findChild( s[i] );
    if( !nextNode ) {
    // if we dont find the child, the word is not in TRIE
    // bail out here
    bRet = true; // just for the hack of doing it
    break;
  } else {
    current = nextNode;
  }

  if( i == s.length() - 1 ) {
    bRet = true;
    current->setCompleteWord( false );
    break;
  }
}

return bRet;
}

void Trie::generatePrefixes(Node *node, string currentWord){
  
  std::vector<Node*> children = node->getChildren();

  bool validWord  = false;
  char c = node->getData();
  string newWord = currentWord.append(1, c);

  if( node->isCompleteWord() ) {
    validWord = true;

  // since we have a valid word, we should put in our queue
  // here we are also interested in prefixes
  // so we shall check if we have something on stack
    if( mLCWStack.size() > 0 ){
      std::list<std::string>::iterator itr = mLCWStack.begin();
      while( itr != mLCWStack.end() ){
        stringpair* sp = new stringpair(newWord, *itr);
        m_prefixQueue.push( sp );
        itr++;
      }
    }
    
    mLCWStack.push_back( newWord );
  }

  // recurse with next child
  for( int i = 0; i < children.size(); ++i) {
    Node* nextNode = children [ i ];
    generatePrefixes( nextNode, newWord );
  }


  // pop back the inserted word
  if( validWord ){
    mLCWStack.pop_front();
  }
}

void Trie::validateMatchForPrefix(const std::string targetString, const std::string prefix) {
  // since we have prefix, lets get the remaining part (?? can we call postfix)
  std::string secondPart = targetString.substr( prefix.length() );
  // for first char, check if there is path from root,
  // if it has, try following it.
  // if it matches all the way, we have got a composite word
  Node* curr = root;
  string compositeWord = prefix;
  
  for( int i = 0; i < secondPart.length(); i++ ) {
    Node* nextNode = curr->findChild( secondPart[ i ] );
    if( !nextNode ){
      return;
    }

  // we will always keep composite word upto date
  // if we find a complete word, we will just use composite
    compositeWord.append(1, secondPart[i]);

    if( nextNode->isCompleteWord() ){
      stringpair *sp = new stringpair( targetString, compositeWord );
    //TODO: validate sp here
      m_prefixQueue.push( sp );
    }

    curr = nextNode;
  }
}

string Trie::findLongestComposite(){
  mLCWStack.clear();

  // find all prefix matches
  generatePrefixes( root, "" ); 

  // LCW stack is now free to use
  mLCWStack.clear();

  // this shall give a queue full of string pairs
  // lets process each individually
  while( !m_prefixQueue.empty() ) {
  // get next pair
    stringpair *sp = m_prefixQueue.front();
    m_prefixQueue.pop();

  // if we already have a match, push it to stack
    if( sp->isMatch() ){
      mLCWStack.push_back( sp->compositeString );
    } else if( sp->compositeString.length() > sp->prefix.length() ){
      validateMatchForPrefix( sp->compositeString, sp->prefix );
    }
  }

  mLCWStack.sort();
  mLCWStack.unique();
  mLCWStack.sort( sortDescending );
  
  return "";
}

void Trie::printFirstN(const int n){
  // std::cout << std::endl <<"Printing Top : " << n  << " elements " << std::endl;

  if( n < mLCWStack.size() ) {
    std::list<std::string>::iterator itr = mLCWStack.begin();
    int i = 0;
    for( ; itr != mLCWStack.end() && i < n ; ++itr, ++i) {
      std::cout << std::string(*itr) << std::endl;
    }
  }else {
    for_each(mLCWStack.begin(), mLCWStack.end(), printString);
  }
}
