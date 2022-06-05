#include <iostream>
#include "Order.h"

void test_1(); //constructors
void test_2(); // functions of order

int main() {

    test_2();

    return 0;
}

void test_1(){
    ProductInfo inf ("yablocko");

    AmountProduct a_a_prod (inf,1);
    WeightProduct a_w_prod (inf, 1.1);

    WeightPosition w_pos (&a_a_prod, 2.2);
    AmountPosition a_pos (&a_w_prod, 1.1);

}

void test_2(){
    ProductInfo inf_1 ("apple");
    WeightProduct prod_1 (inf_1, 1.1);
    WeightPosition pos_1 (&prod_1, 2.2);

    ProductInfo inf_2 ("cucumber");
    WeightProduct prod_2 (inf_2, 1.1);
    WeightPosition pos_2 (&prod_2, 5.1);

    ProductInfo inf_3 ("hammer");
    AmountProduct prod_3 (inf_3, 1.1);
    AmountPosition pos_3 (&prod_2, 1);

    Order order;
    order.add_position(&pos_1);
    order.add_position(&pos_2);
    order.add_position(&pos_3);

    order.get_info();
}