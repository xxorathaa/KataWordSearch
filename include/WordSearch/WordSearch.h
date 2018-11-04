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
   void setSearchWords( std::string line );

private:
   std::vector< std::string > _searchWords;
};
