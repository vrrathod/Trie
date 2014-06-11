// Utilities!

// 1. ProcessCounter class : measures performance by clock speed
// 2. trimming functions for std::string
////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

#ifndef __UTIL_H__
#define __UTIL_H__

class ProcessCounter
{
  std::string m_tag;
  clock_t m_start;
public:
  ProcessCounter(std::string tag) {
    m_start = clock();
    m_tag = tag;
  }
  ~ProcessCounter() {
    clock_t timeTaken = clock() - m_start;
    std::cout << std::endl << "[ " << m_tag << " ] = { " ;
    std::cout << "Ticks : " << timeTaken;
    std::cout << ", Time  : " << ((float) timeTaken)/CLOCKS_PER_SEC << " s } ; " << std::endl;
  }
  
};

////////////////////////////////////////////////////////////////////////////////////////////
// trim from start
static inline std::string &ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
  return s;
}

////////////////////////////////////////////////////////////////////////////////////////////
// trim from end
static inline std::string &rtrim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
  return s;
}

////////////////////////////////////////////////////////////////////////////////////////////
// trim from both ends
static inline std::string &trim(std::string &s) {
  return ltrim(rtrim(s));
}

////////////////////////////////////////////////////////////////////////////////////////////
// sort by length descending
static inline bool sortDescending( std::string a, std::string b) {
  return ( a.length() > b.length() );
}

////////////////////////////////////////////////////////////////////////////////////////////
// print string
static inline void printString( std::string s ) {
  std::cout << s << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////////////
// print help 
inline void printHelp( const std::string progName ){
  std::cout << "Usage : " << progName << std::endl;
  std::cout << " " << progName <<" <filePath> " << std::endl;
  std::cout << "  <filePath> is path to file containing sorted list of words all small case" << std::endl;
  std::cout << std::endl;
}
#endif // __UTIL_H__
