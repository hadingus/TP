//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem/path.hpp>

class TreeTestCase : public ::testing::Test {
public:
    static void SetUpTestCase();
    static void TearDownTestCase();

    static std::string test_path;
    static std::string file_path;
};

std::string TreeTestCase::test_path{""};
std::string TreeTestCase::file_path{""};

