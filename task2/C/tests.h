#include "gtest/gtest.h"
#include "A/index.h"
#include "B/lib.h"

TEST(CHECK, Func_A) {
	ASSERT_EQ(1, A_res());
}

TEST(CHECK, Func_B) {
	ASSERT_EQ(2, B_res());
}