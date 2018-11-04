#include <string>

#include <cppunit/extensions/HelperMacros.h>

#include <WordSearch/WordSearch.h>
#include <WordSearchTest/TestWordSearch.h>

CPPUNIT_TEST_SUITE_REGISTRATION( TestWordSearch );

//void setUp()
//{
//   std::string puzzleFile = "C:\\Users\\alyss\\git\\KataWordSearch\\test\\src\\WordSearchTest\\testPuzzleFile.txt";
//   WordSearch ws( puzzleFile );
//}
//
//void tearDown()
//{
//}

void TestWordSearch::testReadingMissingFile()
{
   try
   {
      std::string puzzleFile = "C:\\Users\\alyss\\git\\KataWordSearch\\test\\src\\WordSearchTest\\missingFile.txt";
      WordSearch ws( puzzleFile );
   }
   catch( ... )
   {
      CPPUNIT_FAIL( "no expected exceptions" );
   }
}

void TestWordSearch::testReadingExistingFile()
{
   try
   {
      std::string puzzleFile = "C:\\Users\\alyss\\git\\KataWordSearch\\test\\src\\WordSearchTest\\testPuzzleFile.txt";
      WordSearch ws( puzzleFile );
   }
   catch( ... )
   {
      CPPUNIT_FAIL( "no expected exceptions" );
   }
}

void TestWordSearch::testGetSearchWord()
{
   std::string puzzleFile = "C:\\Users\\alyss\\git\\KataWordSearch\\test\\src\\WordSearchTest\\testPuzzleFile.txt";
   WordSearch ws( puzzleFile );
   CPPUNIT_ASSERT_EQUAL( std::string( "BONES" ), ws.getSearchWord( 0 ) );
   CPPUNIT_ASSERT_EQUAL( std::string( "KHAN" ), ws.getSearchWord( 1 ) );
   CPPUNIT_ASSERT_EQUAL( std::string( "KIRK" ), ws.getSearchWord( 2 ) );
   CPPUNIT_ASSERT_EQUAL( std::string( "SCOTTY" ), ws.getSearchWord( 3 ) );
   CPPUNIT_ASSERT_EQUAL( std::string( "SPOCK" ), ws.getSearchWord( 4 ) );
   CPPUNIT_ASSERT_EQUAL( std::string( "SULU" ), ws.getSearchWord( 5 ) );
   CPPUNIT_ASSERT_EQUAL( std::string( "UHURA" ), ws.getSearchWord( 6 ) );
}

void TestWordSearch::testSetSearchWords()
{
   std::string puzzleFile = "C:\\Users\\alyss\\git\\KataWordSearch\\test\\src\\WordSearchTest\\testPuzzleFile.txt";
   WordSearch ws( puzzleFile );
   std::string line = "CAT,DOG,FISH";
   ws.setSearchWords( line );

   CPPUNIT_ASSERT_EQUAL( std::string( "CAT" ), ws.getSearchWord( 7 ) );
   CPPUNIT_ASSERT_EQUAL( std::string( "DOG" ), ws.getSearchWord( 8 ) );
   CPPUNIT_ASSERT_EQUAL( std::string( "FISH" ), ws.getSearchWord( 9 ) );
}

void TestWordSearch::testSetPuzzleRow()
{
   std::string puzzleFile = "C:\\Users\\alyss\\git\\KataWordSearch\\test\\src\\WordSearchTest\\testPuzzleFile.txt";
   WordSearch ws( puzzleFile );

   std::string line = "A,B,C,D,E,F,G,H,I,J,K,L,M,N,O";

   try
   {
      ws.setPuzzleRow( line );
   }
   catch( ... )
   {
      CPPUNIT_FAIL( "no expected exceptions" );
   }

}
