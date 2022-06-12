//
// Created by Фёдор Захаров on 05.06.2022.
//

#ifndef PRODUCT_BASE_CLIENT_H
#define PRODUCT_BASE_CLIENT_H
#include "Order.h"

class Client{

    class Balance{
    public:
        void add_money(double money) {m_money += money;}
        bool waste_money(double money){
            if (m_money >= money){m_money-= money; return true;}
            else  return false;
        };
    private:
        double m_money = 0;
    };

public:
    void earn_money(double money){ m_balance.add_money(money); }
    bool pay_and_recive_order(Order& order){
        if(m_balance.waste_money( order.get_cost()) ){
            order.clear();
            return true;}
        else { std::cout << "Not enough money for this order!"<<std::endl; return false;}
    };
private:
    Balance m_balance;
};

#endif //PRODUCT_BASE_CLIENT_H
