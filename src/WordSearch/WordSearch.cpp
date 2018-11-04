#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <WordSearch/WordSearch.h>


WordSearch::WordSearch()
{
}

WordSearch::WordSearch( const std::string& puzzleFile )
{
   try
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
            std::cout << line << std::endl;

            if( _searchWords.empty() )
               setSearchWords( line );
//            else
//            {
//
//            }
         }
      }
   }
   catch( ... )
   {
   }
}

WordSearch::~WordSearch()
{}

std::string WordSearch::getSearchWord( int index )
{
   return _searchWords[ index ];
}

void WordSearch::setSearchWords( std::string line )
{
   std::stringstream ss( line );
   std::string temp;
   while( getline( ss, temp, ',' ) )
      _searchWords.push_back( temp );
}
