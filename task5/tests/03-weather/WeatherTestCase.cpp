//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"

using ::testing::Return;

void WeatherTestCase::SetUp() {
    Madrid.status_code = 200;
    Madrid.text =
            "{\"cod\":\"200\",\"message\":0.0036,\"cnt\":40,\"list\":[{\"dt\":1485799200,\"main\":{\"temp\":13.00}}]}";

    Moscow.status_code = 200;
    Moscow.text =
            "{\"cod\":\"200\",\"message\":0.0036,\"cnt\":40,\"list\":[{\"dt\":1485799200,\"main\":{\"temp\":25.00}}]}";

    Rome.status_code = 400;
    Rome.text =
            "{\"cod\":\"200\",\"message\":0.0036,\"cnt\":40,\"list\":[{\"dt\":1485799200,\"main\":{\"temp\":35.00}}]}";
}

TEST_F(WeatherTestCase, Test1) {
    EXPECT_CALL(weather, Get("Madrid"))
            .Times(1)
            .WillRepeatedly(Return(Madrid));
    ASSERT_NO_THROW(weather.Get("Madrid"));
}

TEST_F(WeatherTestCase, Test2) {
    EXPECT_CALL(weather, Get("Madrid"))
            .Times(1)
            .WillRepeatedly(Return(Madrid));
    EXPECT_CALL(weather, Get("Moscow"))
            .Times(1)
            .WillRepeatedly(Return(Moscow));

    ASSERT_EQ(weather.FindDiffBetweenTwoCities("Moscow", "Madrid"), 12);
}

TEST_F(WeatherTestCase, Test3) {
    ASSERT_NO_THROW(weather.SetApiKey("Hey"));
}

TEST_F(WeatherTestCase, Test4) {
    EXPECT_CALL(weather, Get("Rome"))
            .Times(1)
            .WillRepeatedly(Return(Rome));
    ASSERT_THROW(weather.GetResponseForCity("Rome"), std::invalid_argument);
}

TEST_F(WeatherTestCase, Test5)
{
    EXPECT_CALL(weather, Get("Madrid"))
            .Times(1)
            .WillRepeatedly(Return(Madrid));
    EXPECT_CALL(weather, Get("Moscow"))
            .Times(1)
            .WillRepeatedly(Return(Moscow));

    ASSERT_EQ(weather.GetDifferenceString("Moscow", "Madrid"),
              "Weather in Moscow is warmer than in Madrid by 12 degrees");
}

TEST_F(WeatherTestCase, Test6)
{
    EXPECT_CALL(weather, Get("Madrid"))
            .Times(1)
            .WillRepeatedly(Return(Madrid));
    EXPECT_CALL(weather, Get("Moscow"))
            .Times(1)
            .WillRepeatedly(Return(Moscow));

    ASSERT_EQ(weather.GetDifferenceString("Madrid", "Moscow"),
              "Weather in Madrid is colder than in Moscow by 12 degrees");
}

