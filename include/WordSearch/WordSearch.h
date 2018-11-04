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

private:
   std::vector< std::string > _searchWords;
   std::vector< std::vector < char > > _puzzle;
};
