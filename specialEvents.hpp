    #include <string>
    #include <vector>
    #include <iostream>
    #include "products.hpp"

    class SeasonalMenu
    {
        private:
            std::vector<Product> seasonalProducts;
            int startDate;//format an,luna,zi
            int endDate;//idem startDate
        public:
    //getters and setters
            void setOneProduct(Product newProduct)
            {
                this->seasonalProducts.push_back(newProduct);
            }
            void setProducts(std::vector<Product> newProducts)
            {
                this->seasonalProducts = newProducts;
            }
            void setStartDate(int day, int month, int year)
            {
                this->startDate = year * 10000;
                this->startDate += month * 100;
                this->startDate += day;
            }
            void setEndDate(int day, int month, int year)
            {
                this->endDate = year * 10000;
                this->endDate += month * 100;
                this->endDate += day;
            }
            Product getOneProduct(int id)
            {
                return this->seasonalProducts[id - 1];
            }
            std::vector<Product> getProducts()
            {
                return this->seasonalProducts;
            }
            int getStartDate()
            {
                return this->startDate;
            }
            int getEndDate()
            {
                return this->endDate;
            }
    };