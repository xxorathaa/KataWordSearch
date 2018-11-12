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
   _puzzleSize++;
}

std::string WordSearch::search( const std::string& word )
{
   for( int y = 0; y < _puzzleSize; y++ )
   {
      for( int x = 0; x < _puzzleSize; x++ )
      {
         if( _puzzle[ y ][ x ] == word[ 0 ] )
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
   static const std::string EMPTY_STRING = "";
   static const int ARR_SIZE = 8;
   std::string words[ ARR_SIZE ] = { EMPTY_STRING, EMPTY_STRING, EMPTY_STRING, EMPTY_STRING,
                                     EMPTY_STRING, EMPTY_STRING, EMPTY_STRING, EMPTY_STRING };
   int wordRemainder = word.size() - 1;

   for( int i = 0; i < word.size(); i++ )
   {
      if( x + wordRemainder < _puzzleSize )
         words[ 0 ].push_back( _puzzle[ y ][ x + i ] );
      if( x + wordRemainder < _puzzleSize && y + wordRemainder < _puzzleSize )
         words[ 1 ].push_back( _puzzle[ y + i ][ x + i ] );
      if( y + wordRemainder < _puzzleSize )
         words[ 2 ].push_back( _puzzle[ y + i ][ x ] );
      if( x - wordRemainder >= 0 && y + wordRemainder < _puzzleSize )
         words[ 3 ].push_back( _puzzle[ y + i ][ x - i ] );
      if( x - wordRemainder >= 0 )
         words[ 4 ].push_back( _puzzle[ y ][ x - i ] );
      if( x - wordRemainder >= 0 && y - wordRemainder >= 0 )
         words[ 5 ].push_back( _puzzle[ y - i ][ x - i ] );
      if( y - wordRemainder >= 0 )
         words[ 6 ].push_back( _puzzle[ y - i ][ x ] );
      if( x + wordRemainder < _puzzleSize && y - wordRemainder >= 0 )
         words[ 7 ].push_back( _puzzle[ y - i ][ x + i ] );
   }

   output = word + ": (" + std::to_string( x ) + "," + std::to_string( y ) + ")";

   for( int i = 1; i < word.size(); i++ )
   {
      if( words[ 0 ] == word )
         output += ",(" + std::to_string( x + i ) + "," + std::to_string( y ) + ")";
      if( words[ 1 ] == word )
         output += ",(" + std::to_string( x + i ) + "," + std::to_string( y + i ) + ")";
      if( words[ 2 ] == word )
         output += ",(" + std::to_string( x ) + "," + std::to_string( y + i ) + ")";
      if( words[ 3 ] == word )
         output += ",(" + std::to_string( x - i ) + "," + std::to_string( y + i ) + ")";
      if( words[ 4 ] == word )
         output += ",(" + std::to_string( x - i ) + "," + std::to_string( y ) + ")";
      if( words[ 5 ] == word )
         output += ",(" + std::to_string( x - i ) + "," + std::to_string( y - i ) + ")";
      if( words[ 6 ] == word )
         output += ",(" + std::to_string( x ) + "," + std::to_string( y - i ) + ")";
      if( words[ 7 ] == word )
         output += ",(" + std::to_string( x + i ) + "," + std::to_string( y - i ) + ")";
   }

   for( int i = 0; i < ARR_SIZE; i++ )
   {
      if( words[ i ] == word )
         return true;
   }

   return false;
}

int WordSearch::getSearchWordQuantity()
{
   return _searchWords.size();
}
