//
// Created by Фёдор Захаров on 31.05.2022.
//

#ifndef PRODUCT_BASE_POSITION_H
#define PRODUCT_BASE_POSITION_H

#include "Product.h"
// virtual class that contains Product
// get virtual pure methods get_cost, get_quantity
class Position{
public:
    Position(Product* product): m_product(product){};

    Product* get_ptr_product(){return m_product;}

    virtual double get_cost()=0;

    virtual double get_quantity()=0;
protected:
    Product* m_product;
};

class AmountPosition: public Position{
public:
    AmountPosition(Product* product, size_t amount): Position(product), m_amount(amount){};

    double get_cost() override{ return m_product->get_price() * m_amount;}

    double get_quantity() override {return m_amount;}

private:
    size_t m_amount;
};

class WeightPosition: public Position{
public:
    WeightPosition(Product* product, size_t weight): Position(product), m_weight(weight){};

    double get_cost() override{ return m_product->get_price() * m_weight;}

    double get_quantity() override {return m_weight;}

private:
    size_t m_weight;
};

#endif //PRODUCT_BASE_POSITION_H
