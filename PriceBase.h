//
// Created by Фёдор Захаров on 05.06.2022.
//

#ifndef PRODUCT_BASE_PRICEBASE_H
#define PRODUCT_BASE_PRICEBASE_H
#include "string"
#include "map"
#include "list"
#include "Order.h"
using string =  std::string;
using inf_for_map = std::initializer_list<std::pair<string,ProductInfo>>;
using weight_for_map = std::initializer_list<std::pair<string, WeightProduct>>;
using amount_for_map = std::initializer_list<std::pair<string, AmountProduct>>;

class PriceBase_Parent {
public:
// virtual methods
    virtual WeightProduct get_product_weight_price(std::string name) = 0;

    virtual AmountProduct get_product_amount_price(std::string name) = 0;
};

class PriceBase_Original: public PriceBase_Parent{
public:
    PriceBase_Original(const PriceBase_Original &) = delete;

    static PriceBase_Original& Instance();

    WeightProduct get_product_weight_price(std::string name) override;

    AmountProduct get_product_amount_price(std::string name) override;

private:
    std::map<string, ProductInfo> m_products_info;
    std::map<string, WeightProduct> m_products_weight_price;
    std::map<string, AmountProduct> m_products_amount_price;
protected:
    PriceBase_Original();
};

class PriceBase_Proxy:  public PriceBase_Parent{
public:
    PriceBase_Proxy(const size_t& size_of_memory) : m_size_of_memory(size_of_memory) {};

    WeightProduct get_product_weight_price(std::string name) override;

    AmountProduct get_product_amount_price(std::string name) override;
private:

    PriceBase_Original& m_base = PriceBase_Original::Instance();
    size_t m_size_of_memory;
//    std::map<string, ProductInfo> m_products_info;
    std::list< std::pair<string, WeightProduct> > m_products_weight_price;
    std::list< std::pair<string, AmountProduct> > m_products_amount_price;
};




#endif //PRODUCT_BASE_PRICEBASE_H
#include "PriceBase.hpp"