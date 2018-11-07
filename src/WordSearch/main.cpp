#include <WordSearch/WordSearch.h>

int main( int argc, char* argv[] )
{
   WordSearch ws( "C:\\Users\\alyss\\git\\KataWordSearch\\puzzleFile.txt" );

   for( int i = 0; i < ws._searchWords.size(); i++)
      ws.search( ws._searchWords[ i ] );
}
