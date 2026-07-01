#include <gtest/gtest.h>
#include <stdexcept>

using namespace std;

extern double calculateBMI(double weight, double height);

TEST(IMTCalculatorTest, CalculateNormal) {
    double bmi = calculateBMI(75, 175);
    EXPECT_NEAR(bmi, 24.4898, 0.001);
}

TEST(IMTCalculatorTest, CalculateUnderweight) {
    double bmi = calculateBMI(50, 175);
    EXPECT_NEAR(bmi, 16.3265, 0.001);
}

TEST(IMTCalculatorTest, CalculateOverweight) {
    double bmi = calculateBMI(85, 175);
    EXPECT_NEAR(bmi, 27.7551, 0.001);
}

TEST(IMTCalculatorTest, CalculateObesity) {
    double bmi = calculateBMI(120, 175);
    EXPECT_NEAR(bmi, 39.1837, 0.001);
}

TEST(IMTCalculatorTest, InvalidWeightThrows) {
    EXPECT_THROW(calculateBMI(0, 175), invalid_argument);
    EXPECT_THROW(calculateBMI(-10, 175), invalid_argument);
    EXPECT_THROW(calculateBMI(900, 175), invalid_argument);
}

TEST(IMTCalculatorTest, InvalidHeightThrows) {
    EXPECT_THROW(calculateBMI(75, 0), invalid_argument);
    EXPECT_THROW(calculateBMI(75, -5), invalid_argument);
    EXPECT_THROW(calculateBMI(75, 350), invalid_argument);
}
