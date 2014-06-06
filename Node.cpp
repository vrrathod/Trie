// Node.cpp

#include "Node.h"

Node::Node( char c, bool isWord ): m_data(c), m_isCompleteWord(isWord) {
	//
}

Node::~Node() {
	// delete children
	std::vector<Node*>::iterator itr;
	for( itr = m_children.begin(); itr != m_children.end(); ++itr ) {
		delete static_cast<Node*> (*itr);
	}

	m_children.clear();
}

	// data
char Node::getData() {
	return m_data;
}

// is complete word
bool Node::isCompleteWord() {
	return m_isCompleteWord;
}
// set complete word
void Node::setCompleteWord( bool completeWord ){
	m_isCompleteWord = completeWord;
}

// find child
Node* Node::findChild( const char c ) {
	Node* returnNode = NULL;
	std::vector<Node*>::iterator itr;
	for( itr = m_children.begin(); itr != m_children.end(); ++itr ) {
		Node* temp = static_cast<Node*> (*itr);
		if( temp->getData() == c ) {
			returnNode = temp;
			break;
		}
	}

	return returnNode;
}

// add children
void Node::appendChild( Node* node ) {
	if( node ) {
		m_children.push_back( node );
	}
}


// list of children
std::vector<Node*> Node::getChildren() {
	return m_children;
}