//
// Created by Фёдор Захаров on 06.06.2022.
//
#pragma once

#include "PriceBase.h"

///-------------------------/PriceBase_Original/-------------------------------

PriceBase_Original::PriceBase_Original() {
    m_products_info = {
            {"Apple", ProductInfo("Holy Moly - sweet apple")},
            {"Cheese", ProductInfo("Camembert - I like it")},
            {"Pencil",ProductInfo("you can write with it")},
            {"Book",
             ProductInfo("Book 'Gang of Four' - Nice book, awesome patterns")},
            {"Laba",ProductInfo("fourth Laba - Illegal one, don't say Vadim Vitalyevich")}
    };
    m_products_weight_price = {
            {"Apple", WeightProduct(m_products_info.at("Apple"), 7.2)},
            {"Cheese", WeightProduct(m_products_info.at("Cheese"), 11.2)},
    };
    m_products_amount_price ={
            {"Pencil",AmountProduct(
                    m_products_info.at("Pencil"), 4.2)},
            {"Book",AmountProduct(m_products_info.at("Book"), 6.6)},
            {"Laba",AmountProduct(m_products_info.at("Laba"), 5.0)},
    };
}

PriceBase_Original& PriceBase_Original::Instance(){
    static PriceBase_Original instance;
        return instance;
    }

AmountProduct PriceBase_Original::get_product_amount_price(std::string name) {
    return m_products_amount_price.at(name);
}

WeightProduct PriceBase_Original::get_product_weight_price(std::string name) {
    return m_products_weight_price.at(name);
}

///-------------------------/PriceBase_Proxy/-------------------------------

WeightProduct PriceBase_Proxy::get_product_weight_price(std::string name) {

    //    check if there is necessary info in local memory
    for (auto[w_name , w_prod] : m_products_weight_price){
        if (w_name == name) return w_prod;
    }

    //    if not, go to main database
    auto answer = m_base.get_product_weight_price(name);
        m_products_weight_price.push_front({name, answer});
        if ( m_products_weight_price.size() >= m_size_of_memory ) m_products_weight_price.pop_back();
    return answer;

}

AmountProduct PriceBase_Proxy::get_product_amount_price(std::string name) {
//    check if there is necessary info in local memory
    for (auto[a_name , a_prod] : m_products_amount_price){
        if (a_name == name) return a_prod;
    }

//    if not, go to main database
    auto answer = m_base.get_product_amount_price(name);
    m_products_amount_price.push_front({name, answer});
    if ( m_products_amount_price.size() >= m_size_of_memory ) m_products_amount_price.pop_back();


    return  answer;

}

