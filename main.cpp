#include <iostream>
#include "Position.h"
int main() {
    ProductInfo a ("yablocko");
    Product a_prod (a);
    WeightProduct a_w_prod (a, 1.1);
    AmountProduct a_a_prod (a, 2.2);
    Position a_position (a_prod);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
