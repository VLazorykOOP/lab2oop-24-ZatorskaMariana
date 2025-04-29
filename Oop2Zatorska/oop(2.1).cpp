#include <iostream>

int computeExpression(int a, int b, int c, int d) {
    int term1 = (b << 5) + b;  // 33 * b
    int term2 = ((d << 3) + (d << 2) + (d << 1) + d   // d * 15
                + (a << 3) + (a << 2)) >> 9;          // + 12 * a, all / 512
    int term3 = (c << 6) + c;  // 65 * c
    int term4 = (d << 3) + (d << 2) + (d << 1);  // d * 14

    return term1 + term2 - term3 + term4;
}

int main() {
    int a, b, c, d;
    std::cout << "Enter integers a, b, c, d: ";
    std::cin >> a >> b >> c >> d;

    int result = computeExpression(a, b, c, d);
    std::cout << "Result: " << result << std::endl;

    return 0;
}

