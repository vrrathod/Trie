// Trie Main

#include <iostream>
#include <string>
#include <memory>
#include <fstream>

#include "Trie.h"
#include "Util.h"

//#define _MEASURE_PERFORMANCE_ 1

int main( int argc, char** argv ){

  /// parse commandline params
  if( argc < 2 ) {
    printHelp(argv[0]);
    return 0;
  } 
  // make sure file name exists
  string path = argv[1];

  // topN
  int nCount = 1;
  if( argc >= 3 ){
    nCount = atoi( argv[2] );
  } 

  
#ifdef _MEASURE_PERFORMANCE_
  ProcessCounter p ("main");
#endif
  
  auto_ptr<Trie> trie( new Trie() );
  
#ifdef _MEASURE_PERFORMANCE_
  {
    ProcessCounter p1("adding elements");
#endif //_MEASURE_PERFORMANCE_
    
    // string path = "/Users/viral/Downloads/Aspera/wordsforproblem.txt";
    
    std::ifstream inputFileStream(path);
    std::string str;
    
    while( std::getline( inputFileStream, str ) ) {
      str = trim(str);
      // add it to common list
      trie->addWord(str);
    }
#ifdef _MEASURE_PERFORMANCE_
  } {
    ProcessCounter p2("finding composite ") ;
#endif //_MEASURE_PERFORMANCE_
    
    trie->findLongestComposite();
    
#ifdef _MEASURE_PERFORMANCE_
  } {
    ProcessCounter(" finding top n ");
#endif //_MEASURE_PERFORMANCE_
    
    trie->printFirstN(nCount);
    
#ifdef _MEASURE_PERFORMANCE_
  }
#endif //_MEASURE_PERFORMANCE_
  
  return 0;
}
