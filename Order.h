//
// Created by Фёдор Захаров on 01.06.2022.
//

#ifndef PRODUCT_BASE_ORDER_H
#define PRODUCT_BASE_ORDER_H

#include "Position.h"
#include "vector"
#include <iostream>

class Order{
public:
    friend class Client;

    Order() = default;

    void add_position(Position* ptr_pos);

    double get_cost();

    void get_info();

    bool empty();

private:
    void clear(){
        m_ptr_positions.clear();
    };

    std::vector<Position*> m_ptr_positions;
};

#endif //PRODUCT_BASE_ORDER_H

#include "Order.hpp"
