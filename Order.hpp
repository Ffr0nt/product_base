//
// Created by Фёдор Захаров on 05.06.2022.
//
#pragma once

#include "Order.h"

// gets cost of all products in an order
double Order::get_cost() {
    double answer = 0;
    for (auto pos : m_ptr_positions){
        answer += pos->get_cost();
    }
    return answer;
}

//prints info about every product
void Order::get_info() {
    std::cout << "--------------------------------------";
    for (auto pos : m_ptr_positions){
        std::cout << std::endl << "Product info: "<< pos->get_ptr_product()->get_info();
        std::cout << std::endl << "Quantity: " << pos->get_quantity();
        std::cout << std::endl << "Cost: "<< pos->get_cost()<< std::endl;
    }
    std::cout<<  "--------------------------------------" << std::endl;
}


// shows if order is empty
bool Order::empty() {
    return m_ptr_positions.empty();
}

// clear all the positions in order
void Order::clear() {
    m_ptr_positions.clear();
}

// add position to the order
void Order::add_position(Position* ptr_pos) {
    m_ptr_positions.push_back(ptr_pos);
}






