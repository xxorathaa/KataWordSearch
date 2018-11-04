#include <cppunit/extensions/HelperMacros.h>

#include <WordSearchTest/TestWordSearch.h>

CPPUNIT_TEST_SUITE_REGISTRATION( TestWordSearch );

void TestWordSearch::testConstructor()
{
   WordSearch ws();
   CPPUNIT_ASSERT(true);
}
