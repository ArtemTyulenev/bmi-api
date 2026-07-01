
#include <stdexcept>

using namespace std;

double calculateBMI(double weight, double height) {
    if (weight <= 0 || weight > 800) {
        throw invalid_argument("Weight must be between 0 and 800 kg");
    }
    if (height <= 0 || height > 300) {
        throw invalid_argument("Height must be between 0 and 300 cm");
    }
    double heightM = height / 100.0;
    return weight / (heightM * heightM);
}
