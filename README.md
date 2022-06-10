# Product Base
This is a prototype of a payment system that allows
the customer to have a balance and use it to pay for orders. Orders, in turn, consist of items that can be both weighty and quantitative. The cost of goods per unit of weight or quantity is stored in the database. To develop this program, UML diagrams describing it from different angles are presented below.
## Product
<img width="605" alt="Product" src="https://user-images.githubusercontent.com/91899443/172855174-9cee4569-4a18-400e-ab2d-00a29b3d5327.png">

get_info(): returns a string in the format: "product info : cost per kg"

get_info(): returns a string in the format: "product info : cost per one"

## Position
<img width="694" alt="Снимок экрана 2022-06-09 в 16 15 22" src="https://user-images.githubusercontent.com/91899443/172855980-d079637b-7f97-4927-9e99-fe769c5c7f09.png">

## Order
![Order](https://user-images.githubusercontent.com/91899443/172854335-0dcc0dfc-a69e-4bbc-947c-9d6b2d61229c.png)

add_position - if we add a position where the product is among the products of existing positions, then we need to replace the old position, not add a new one.

get_cost - returns the sum of the cost of all positions.

get_info - prints out all the information about the order, example:

<img width="749" alt="Пример" src="https://user-images.githubusercontent.com/91899443/172856769-a2bd974b-ce01-4db7-bf3a-0f282f9be264.png">

## Client
![Client](https://user-images.githubusercontent.com/91899443/172856058-3220fc99-dfe0-494b-9111-a7c695fea60e.png)

earn_money - puts money on the balance

pay_and_recive_order - tries to pay for the order accepted in the arguments, if there was not enough money, it will print "Not enough money to pay for order!" and it will return false if the payment was successful, then it will clear all the order items and print "The order is recieved!" Important: only the client is able to clean the order items from within himself (no one else).

If there is not enough money, then waste_money will return false without changing m_money

## PriceBase
![PriceBase](https://user-images.githubusercontent.com/91899443/172856013-f518ee74-2bd0-4a84-8dc9-4091ca1f15ce.png)

This class stores  positions, in order to include them in order. Consist of two parts: ProductBase_Original and ProductBase_Proxy, which are connected as in proxy pattern. ProductBase_Original - stores all info about products Products (ProductInfo, WheightProduct and AmountProduct). Meanwhile ProductBase_Proxy stores m_size_of_memory objects in its resources (in order to give fast access ).

