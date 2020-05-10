//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include <boost/filesystem/operations.hpp>
#include <fstream>

using boost::filesystem::create_directory;
using boost::filesystem::remove_all;
using boost::filesystem::current_path;

void TreeTestCase::SetUpTestCase() {
    test_path = current_path().string() + "/TmpTest";
    file_path = test_path + "/temp.txt";
    create_directory(test_path);

    std::ofstream fout(file_path);
    fout << "Hello world";
    fout.close();
}

void TreeTestCase::TearDownTestCase() {
    remove_all(test_path);
}

TEST_F(TreeTestCase, Test1) {
    ASSERT_THROW(GetTree(test_path + "/abacaba", true), std::invalid_argument);
}

TEST_F(TreeTestCase, Test2) {
    ASSERT_THROW(GetTree(file_path, true), std::invalid_argument);
}

TEST_F(TreeTestCase, Test3) {
    ASSERT_NO_THROW(GetTree(test_path, true));
}

TEST_F(TreeTestCase, Test4) {
    ASSERT_NO_THROW(GetTree(test_path, false));
}

TEST_F(TreeTestCase, Test5) {
    ASSERT_EQ(GetTree(test_path, true), GetTree(test_path, true));
}
