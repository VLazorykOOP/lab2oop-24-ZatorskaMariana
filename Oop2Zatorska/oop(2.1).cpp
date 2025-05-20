#include <iostream>

int compute(int a, int b, int c, int d) {
    int part1 = (b << 5) + b; // 33 * b
    int numerator = ((d << 3) + (d << 2) + (d << 1) + d) + ((a << 3) + (a << 2)); // d*15 + 12*a
    int part2 = numerator >> 9; // поділ на 512
    int part3 = (c << 6) + c; // 65 * c
    int part4 = (d << 3) + (d << 2) + (d << 1); // 14 * d
    return part1 + part2 - part3 + part4;
}

int main() {
    int a, b, c, d;
    std::cout << "Введіть значення a, b, c, d: ";
    std::cin >> a >> b >> c >> d;

    int result = compute(a, b, c, d);
    std::cout << "Результат: " << result << std::endl;
    return 0;
}
