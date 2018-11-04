#include <fstream>
#include <string>
#include <iostream>
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
         while (inFile >> line)
         {
            std::cout << line << std::endl;
         }
      }
   }
   catch( ... )
   {
   }
}

WordSearch::~WordSearch()
{}
