//
// Created by Фёдор Захаров on 31.05.2022.
//

#ifndef PRODUCT_BASE_PRODUCT_H
#define PRODUCT_BASE_PRODUCT_H
#include "string"


// basic class to contain name about
class ProductInfo{
public:
    ProductInfo(std::string info): m_info(info){};

    std::string get_info(){return m_info;};
private:
    std::string m_info;
};

// virtual class to contain ProductInfo
// and virtual methods get_info, get_price
class Product{
public:
    Product(ProductInfo product_info): m_product_info(product_info){};

    virtual std::string get_info(){};

    virtual double get_price(){};

protected:
    ProductInfo m_product_info;
};

// class for products priced by weight
// contain price per kg
class WeightProduct: public Product{
public:
    WeightProduct(ProductInfo product_info, double cost_per_kg):
        Product(product_info),m_cost_per_kg(cost_per_kg){}

        std::string get_info() override{ return m_product_info.get_info() + ": " \
        + std::to_string(m_cost_per_kg) + "per kg"; }


    double get_price() override { return m_cost_per_kg; }
private:
double m_cost_per_kg;
};

// class for products priced by amount
// contain price per amount
class AmountProduct: public Product{
public:
    AmountProduct(ProductInfo product_info, double cost_per_one):
            Product(product_info), m_cost_per_one(cost_per_one){}

    std::string get_info() override{ return m_product_info.get_info()+ ": "\
    +std::to_string(m_cost_per_one) + " per one"; }

    double get_price() override { return m_cost_per_one; }
private:
    double m_cost_per_one;
};

#endif //PRODUCT_BASE_PRODUCT_H
