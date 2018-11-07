#pragma once

#include <string>
#include <vector>

class WordSearch
{
public:
   WordSearch();
   WordSearch( const std::string& puzzleFile );
   ~WordSearch();

   std::string getSearchWord( int index );
   void setSearchWords( const std::string& line );
   void setPuzzleRow( const std::string& line );
   std::string search( const std::string& word );
   bool findWord( int x, int y, const std::string& word, std::string& output );

private:
   std::vector< std::string > _searchWords;
   std::vector< std::vector < char > > _puzzle;

   int _puzzleSize = 0;
};
