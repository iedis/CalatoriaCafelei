    #include <iostream> 
    #include <string>
    #include <vector>
    #define SPACE 50
    #define NOPRODUCT 20

    class Product
    {
        private:
            int id;
            std::string name;
            int price;
            int productionCost;
        public:
//getters and setters
            void setId(int id)
            {
                this->id = id;
            }
            void setName(std::string name)
            {
                this->name = name;
            }
            void setPrice(int price)
            {
                this->price = price;
            }
            void setProductionCost(int cost)
            {
                this->productionCost = cost;
            }
            int getId()
            {
                return this->id;
            }
            std::string getName()
            {
                this->name;
            }
            int getPrice()
        {
            return this->price;
        }
            int getProductionCost()
            {
                return this->productionCost;
            }
    };

    class Stock
    {
        private:
            std::vector<Product> myProducts;
            std::vector<int> myQuantities;
        public:
//getters and setters
            void setOneProduct(Product newProduct)
            {
                this->myProducts.push_back(newProduct); 
            }
            void setAllProducts(std::vector<Product> products)
            {
                this->myProducts = products;
            }
            void setOneQuantity(int newQunatity)
            {
                this->myQuantities.push_back(newQunatity);
            }
            void setAllQuantities(std::vector<int> quantities)
            {
                this->myQuantities = quantities;
            }
            std::vector<Product> getAllProducts()
            {
                return this->myProducts;
            }
            std::vector<int> getAllQuantities()
            {
                return this->myQuantities;
            }
//delete product
            void removeProduct(Product oldProduct)
            {
                myProducts.erase(find(myProducts.begin(), myProducts.end(), oldProduct));
            }
//add new product
            void addProduct(Product newProduct)
            {
                myProducts.push_back(newProduct);
            }
    };