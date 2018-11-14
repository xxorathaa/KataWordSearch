CC = g++
INCLUDE_DIR = ./src
SRC_DIR = ./src/WordSearch
TEST_INCLUDE_DIR = ./test/src
TEST_DIR = ./test/src/WordSearchTest
CPPUNIT_INCLUDE_DIR = ./cppunit/include
CPPUNIT_LIB_DIR = ./cppunit/src/cppunit/.libs 
OUTPUT_DIR = ./bin
OBJECT_DIR = ./obj

CPPFLAGS = -I$(INCLUDE_DIR) -Wall
TESTCPPFLAGS = -I$(TEST_INCLUDE_DIR) -I$(CPPUNIT_INCLUDE_DIR) -L$(CPPUNIT_LIB_DIR) -lcppunit
CPPUNIT_DLL = ./cppunit/src/cppunit/.libs/cygcppunit-1-12-1.dll

all: WordSearch WordSearchTest

WordSearch: $(SRC_DIR)/main.cpp $(SRC_DIR)/WordSearch.o | directory
	mv $(SRC_DIR)/WordSearch.o $(OBJECT_DIR)
	$(CC) -o $(OUTPUT_DIR)/WordSearch.exe $(SRC_DIR)/main.cpp $(OBJECT_DIR)/WordSearch.o $(CPPFLAGS)

WordSearchTest: $(TEST_DIR)/main.cpp $(TEST_DIR)/TestWordSearch.cpp | directory
	cp $(CPPUNIT_DLL) $(OUTPUT_DIR)
	$(CC) -o $(OUTPUT_DIR)/WordSearchTest.exe $(TEST_DIR)/main.cpp $(TEST_DIR)/TestWordSearch.cpp $(OBJECT_DIR)/WordSearch.o $(CPPFLAGS) $(TESTCPPFLAGS)

.PHONY: clean directory

clean:
	rm $(OUTPUT_DIR)/*
	rm $(OBJECT_DIR)/*

directory:
	mkdir -p $(OUTPUT_DIR)
	mkdir -p $(OBJECT_DIR)