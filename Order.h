//
// Created by Фёдор Захаров on 01.06.2022.
//

#ifndef PRODUCT_BASE_ORDER_H
#define PRODUCT_BASE_ORDER_H
#include "Position.h"
#include "vector"

class Order{
public:
    Order() = default;
    void add_position(){};

    double get_cost(Position* ptr_pos);

    void get_info();

    bool empty();

private:
    void clear();

    std::vector<Position*> m_ptr_positions;
};

#endif //PRODUCT_BASE_ORDER_H
