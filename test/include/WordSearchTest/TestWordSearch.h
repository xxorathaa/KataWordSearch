#pragma once

#include <cppunit/extensions/HelperMacros.h>

class TestWordSearch : public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE( TestWordSearch );
   CPPUNIT_TEST( testReadingMissingFile );
   CPPUNIT_TEST( testReadingExistingFile );
   CPPUNIT_TEST( testGetSearchWord );
   CPPUNIT_TEST( testSetSearchWords );
   CPPUNIT_TEST( testSetPuzzleRow );
   CPPUNIT_TEST( testSearch_firstWord );
   CPPUNIT_TEST( testSearch_secondWord );
   CPPUNIT_TEST_SUITE_END();

public:
//   void setUp();
//   void tearDown();
   void testReadingMissingFile();
   void testReadingExistingFile();
   void testGetSearchWord();
   void testSetSearchWords();
   void testSetPuzzleRow();
   void testSearch_firstWord();
   void testSearch_secondWord();
};
