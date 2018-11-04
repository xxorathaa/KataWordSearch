#include <string>

#include <cppunit/extensions/HelperMacros.h>

#include <WordSearch/WordSearch.h>
#include <WordSearchTest/TestWordSearch.h>

CPPUNIT_TEST_SUITE_REGISTRATION( TestWordSearch );

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

