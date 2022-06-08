#include <iostream>
#include "Client.h"
#include "PriceBase.h"

void test_1(); //constructors
void test_2(); // methods of Order
void test_3(); // methods of Client
void test_4();

int main() {
    test_1();
    test_2();
    test_3();
    test_4();

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
    WeightProduct prod_1 (inf_1, 5.2);
    WeightPosition pos_1 (&prod_1, 2.2);

    ProductInfo inf_2 ("cucumber");
    WeightProduct prod_2 (inf_2, 1.1);
    WeightPosition pos_2 (&prod_2, 5.1);

    ProductInfo inf_3 ("hammer");
    AmountProduct prod_3 (inf_3, 19);
    AmountPosition pos_3 (&prod_3, 1);

    Order order;
    std::cout << std::endl << "Is empty?: " << order.empty() << std::endl;
    std::cout <<"here positions are added"<< std::endl;

    order.add_position(&pos_1);
    order.add_position(&pos_2);
    order.add_position(&pos_3);

    std::cout << std::endl << "Is empty?: " << order.empty() << std::endl;
    order.get_info();
    std::cout  << "Total coast: " << order.get_cost();
    std::cout << std::endl << "Is empty?: " << order.empty();

}

void test_3(){
    ProductInfo inf_1 ("apple");
    WeightProduct prod_1 (inf_1, 5.2);
    WeightPosition pos_1 (&prod_1, 2.2);

    ProductInfo inf_2 ("cucumber");
    WeightProduct prod_2 (inf_2, 1.1);
    WeightPosition pos_2 (&prod_2, 5.1);

    ProductInfo inf_3 ("hammer");
    AmountProduct prod_3 (inf_3, 19);
    AmountPosition pos_3 (&prod_3, 1);

    Order order;
    order.add_position(&pos_1);
    order.add_position(&pos_2);
    order.add_position(&pos_3);

    Client feo;
    feo.pay_and_recive_order(order);

    feo.earn_money(100);

    std::cout << std::endl << "Order get cost: " << order.get_cost()<< std::endl;

    std::cout << std::endl << int( feo.pay_and_recive_order(order) );

    std::cout  << "Is order empty?: " << order.empty() << std::endl;

}

void test_4(){

};