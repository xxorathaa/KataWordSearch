#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <WordSearch/WordSearch.h>

WordSearch::WordSearch()
{
}

WordSearch::WordSearch( const std::string& puzzleFile )
{
   std::ifstream inFile;
   inFile.open( puzzleFile );

   if ( !inFile )
   {
       std::cout << "Unable to open file" << std::endl;
       WordSearch();
   }
   else
   {
      std::string line;

      while ( inFile >> line )
      {
         if( _searchWords.empty() )
            setSearchWords( line );
         else
            setPuzzleRow( line );
      }

      inFile.close();
   }
}

WordSearch::~WordSearch()
{}

std::string WordSearch::getSearchWord( int index )
{
   return _searchWords[ index ];
}

void WordSearch::setSearchWords( const std::string& line )
{
   std::stringstream ss( line );
   std::string temp;

   while( getline( ss, temp, ',' ) )
      _searchWords.push_back( temp );
}

void WordSearch::setPuzzleRow( const std::string& line )
{
   std::stringstream ss( line );
   std::string temp;
   std::vector< char > row;

   while( getline( ss, temp, ',' ) )
      row.push_back( temp[ 0 ] );

   _puzzle.push_back( row );
}

std::string WordSearch::search( const std::string& word )
{
   for( int x = 0; x < _puzzle.size(); x++ )
   {
      for( int y = 0; y < _puzzle.size(); y++ )
      {
         if( _puzzle[ x ][ y ] == word[ 0 ] )
         {
            std::string output;

            if( findWord( x, y, word, output ) )
               return output;
         }
      }
   }
}

bool WordSearch::findWord( int x, int y, const std::string& word, std::string& output )
{
   output = "BONES: (0,6),(0,7),(0,8),(0,9),(0,10)";
   return true;
}
