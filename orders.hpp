    #include <iostream>
    #include <string>
    #include <vector>
    #include "products.hpp"
    #include "clients.hpp"

    class Order
    {
        private:
            int id;
            Client client;
            std::vector<Product> products;
            std::vector<int> quantity;
            int totalValue;
        public:
//getters and setters
            void setId(int id)
            {
                this->id = id;
            }
            void setClient(Client client)
            {
                this->client = client;
            }
            void setOneProduct(Product newProduct)
            {
                this->products.push_back(newProduct);
            }
            void setAllProducts(std::vector<Product> newProducts)
            {
                this->products = newProducts;
            }
            void setOneQuantity(int newQuantity)
            {
                this->quantity.push_back(newQuantity);
            }
            void setAllQuantities(std::vector<int> newQuantities)
            {
                this->quantity = newQuantities;
            }
            void setTotalValue(int total)
            {
                this->totalValue = total;
            }
            int getId()
            {
                return this->id;
            }
            Client getClient()
            {
                return this->client;
            }
            std::vector<Product> getAllProducts()
            {
                return this->products;
            }
            std::vector<int> getAllQuantities()
            {
                return this->quantity;
            }
            int getTotal()
            {
                return this->totalValue;
            }

//apply customer discount
            int discount(int sum)
            {
                int discount;
                if(this->client.getNOrders() >= 5)
                {
                    discount = 5 / 100 * sum;
                    sum -= discount;
                }
                return sum;
            }
//calculate total value of order
            int caluclateTotalValue()
            {
                int i, sum = 0, discount;
                for(i = 0; i < this->products.size();i ++)
                {
                    sum += this->quantity[i] * this->products[i].getPrice();
                }
                this->totalValue = sum;
                return this->discount(sum);
            }
    };