#include <cppunit/extensions/HelperMacros.h>

class TestWordSearch : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( TestWordSearch );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST_SUITE_END();

public:
//  void setUp();
//  void tearDown();

  void testConstructor();
};
