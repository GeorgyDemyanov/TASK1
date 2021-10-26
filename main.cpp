#include <iostream>
#include <cmath>
#include <array>

std::array<double, 2> f(const std::array<double, 2> &a) {
    std::array<double, 2> res;
    res[0] = a[0] * a[0] + a[1] * a[1] - 1;
    res[1] = a[1] - tan(a[0]);
    return res;
}

std::array<double, 2> MPI(const std::array<double, 2> &a0, double e) {
    std::array<double, 2> a = a0;
    std::array<double, 2> an = {atan(a[1]), sqrt(1 - a[0] * a[0])};
    while (std::abs(an[0] - a[0]) > e || std::abs(an[1] - a[1]) > e) {
        a = an;
        an = {atan(a[1]), sqrt(1 - a[0] * a[0])};
    }

    return an;
}

int main() {
    double e = 1e-6;
    std::array<double, 2> a0 = {0.5, 0.5};
    auto a = MPI(a0, e);

    std::cout << "x1 = " << a[0] <<" "<< "y1 = " << a[1] << std::endl;
    std::cout << "x2 = " << a[0] <<" "<< "y2 = " << a[1] << std::endl;
    return 0;
}
