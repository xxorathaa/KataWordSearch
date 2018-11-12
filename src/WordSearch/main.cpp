#include <WordSearch/WordSearch.h>
#include <iostream>
int main( int argc, char* argv[] )
{
   WordSearch ws( "C:\\Users\\alyss\\git\\KataWordSearch\\puzzleFile.txt" );

   for( int i = 0; i < ws.getSearchWordQuantity(); i++)
      std::cout << ws.search( ws.getSearchWord( i ) ) << std::endl;
}
