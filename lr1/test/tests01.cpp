#include <gtest/gtest.h>
#include "../include/conversion12to24.h" 

TEST(test_01, basic_conversion_am)
{
    ASSERT_TRUE(convert12To24(8, 30, "am") == "0830");
}

TEST(test_02, basic_conversion_pm)
{
    ASSERT_TRUE(convert12To24(8, 30, "pm") == "2030");
}

TEST(test_03, midnight_case)
{
    ASSERT_TRUE(convert12To24(12, 00, "pm") == "0000");
}

TEST(test_04, noon_case)
{
    ASSERT_TRUE(convert12To24(12, 00, "am") == "1200");
}

TEST(test_05, single_digit_minutes)
{
    ASSERT_TRUE(convert12To24(9, 05, "am") == "0905");
}

TEST(test_06, evening_time)
{
    ASSERT_TRUE(convert12To24(11, 45, "pm") == "2345");
}

TEST(test_07, morning_time)
{
    ASSERT_TRUE(convert12To24(6, 15, "am") == "0615");
}

TEST(test_08, afternoon_time)
{
    ASSERT_TRUE(convert12To24(3, 30, "pm") == "1530");
}

TEST(test_09, validation_correct)
{
    ASSERT_TRUE(isValid12HourTime(8, 30, "am") == true);
}

TEST(test_10, validation_wrong_hour)
{
    ASSERT_TRUE(isValid12HourTime(15, 30, "am") == false);
}

TEST(test_11, validation_wrong_minute)
{
    ASSERT_TRUE(isValid12HourTime(8, 70, "am") == false);
}

TEST(test_12, validation_wrong_period)
{
    ASSERT_TRUE(isValid12HourTime(8, 30, "xm") == false);
}

TEST(test_13, parse_correct_format)
{
    int hour, minute;
    std::string period;
    ASSERT_TRUE(parseTimeString("8:30 am", hour, minute, period) == true);
    ASSERT_TRUE(hour == 8);
    ASSERT_TRUE(minute == 30);
    ASSERT_TRUE(period == "am");
}

TEST(test_14, parse_incorrect_format)
{
    int hour, minute;
    std::string period;
    ASSERT_TRUE(parseTimeString("8.30 am", hour, minute, period) == false);
}

TEST(test_15, parse_with_spaces)
{
    int hour, minute;
    std::string period;
    ASSERT_TRUE(parseTimeString("12:00 pm", hour, minute, period) == true);
    ASSERT_TRUE(hour == 12);
    ASSERT_TRUE(minute == 0);
    ASSERT_TRUE(period == "pm");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}