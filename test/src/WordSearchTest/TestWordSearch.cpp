#include <string>

#include <cppunit/extensions/HelperMacros.h>

#include <WordSearch/WordSearch.h>
#include <WordSearchTest/TestWordSearch.h>

CPPUNIT_TEST_SUITE_REGISTRATION( TestWordSearch );

void TestWordSearch::setUp()
{
   std::string puzzleFile = "C:\\Users\\alyss\\git\\KataWordSearch\\test\\src\\WordSearchTest\\testPuzzleFile.txt";
   _ws = new WordSearch( puzzleFile );
}

void TestWordSearch::tearDown()
{
}

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
   CPPUNIT_ASSERT_EQUAL( std::string( "BONES" ), _ws->getSearchWord( 0 ) );
   CPPUNIT_ASSERT_EQUAL( std::string( "KHAN" ), _ws->getSearchWord( 1 ) );
   CPPUNIT_ASSERT_EQUAL( std::string( "KIRK" ), _ws->getSearchWord( 2 ) );
   CPPUNIT_ASSERT_EQUAL( std::string( "SCOTTY" ), _ws->getSearchWord( 3 ) );
   CPPUNIT_ASSERT_EQUAL( std::string( "SPOCK" ), _ws->getSearchWord( 4 ) );
   CPPUNIT_ASSERT_EQUAL( std::string( "SULU" ), _ws->getSearchWord( 5 ) );
   CPPUNIT_ASSERT_EQUAL( std::string( "UHURA" ), _ws->getSearchWord( 6 ) );
}

void TestWordSearch::testSetSearchWords()
{
   std::string line = "CAT,DOG,FISH";
   _ws->setSearchWords( line );

   CPPUNIT_ASSERT_EQUAL( std::string( "CAT" ), _ws->getSearchWord( 7 ) );
   CPPUNIT_ASSERT_EQUAL( std::string( "DOG" ), _ws->getSearchWord( 8 ) );
   CPPUNIT_ASSERT_EQUAL( std::string( "FISH" ), _ws->getSearchWord( 9 ) );
}

void TestWordSearch::testSetPuzzleRow()
{
   std::string line = "A,B,C,D,E,F,G,H,I,J,K,L,M,N,O";

   try
   {
      _ws->setPuzzleRow( line );
   }
   catch( ... )
   {
      CPPUNIT_FAIL( "no expected exceptions" );
   }

}

void TestWordSearch::testSearch_firstWord()
{
   CPPUNIT_ASSERT_EQUAL( std::string( "BONES: (0,6),(0,7),(0,8),(0,9),(0,10)" ), _ws->search( _ws->getSearchWord( 0 ) ) );
}

void TestWordSearch::testSearch_secondWord()
{
   CPPUNIT_ASSERT_EQUAL( std::string( "KHAN: (5,9),(5,8),(5,7),(5,6)" ), _ws->search( _ws->getSearchWord( 1 ) ) );
}

void TestWordSearch::testFindWord()
{
   std::string actual;

   CPPUNIT_ASSERT( _ws->findWord( 0, 6, "BONES", actual ) );
   CPPUNIT_ASSERT_EQUAL( std::string( "BONES: (0,6),(0,7),(0,8),(0,9),(0,10)" ), actual );
}
