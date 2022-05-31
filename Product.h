//
// Created by Фёдор Захаров on 31.05.2022.
//

#ifndef PRODUCT_BASE_PRODUCT_H
#define PRODUCT_BASE_PRODUCT_H
#include "string"

// class to contain name about
class ProductInfo{
public:
    ProductInfo(std::string info): m_info(info){};

    std::string get_info(){return m_info};
private:
    std::string m_info;
};

class Product{
public:
    Product(ProductInfo product_info): m_product_info(product_info){};

    virtual std::string get_info() =0;

    virtual double get_price() =0;

protected:
    ProductInfo m_product_info;
};


#endif //PRODUCT_BASE_PRODUCT_H
