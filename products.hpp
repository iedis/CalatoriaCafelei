    #include <iostream> 
    #include <fstream>
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
                return this->name;
            }
            int getPrice()
            {
            return this->price;
            }
            int getProductionCost()
            {
                return this->productionCost;
            }    
//assign attributes from a csv line
            void assignProduct(std::string line)
            {
                int location;

                location = line.find(',');
                this->id = (stoi(line.substr(0, location)));
                line = line.substr(location + 1, line.length());

                location = line.find(',');
                this->name = (line.substr(0, location));
                line = line.substr(location + 1, line.length());

                location = line.find(',');
                this->price = (stoi(line.substr(0, location)));
                line = line.substr(location + 1, line.length());

                location = line.find(',');
                this->productionCost = (stoi(line.substr(0, location)));
                line = line.substr(location + 1, line.length());
            }
//initialize product
            void init(int id, std::string name, int price, int cost)
            {
                this->id = id;
                this->name = name;
                this->price = price;
                this->productionCost = cost;
            }                
    };

    class Stock
    {
        private:
            std::vector<Product> myProducts;
            std::vector<int> myQuantities;
            int productionCost;
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
            int getProductionCost()
            {
                return this->productionCost;
            }
//delete product
            void removeProduct(int id)
            {
                for(int i = 0; i < this->myProducts.size(); i ++)
                {
                    if(this->myProducts[i].getId() == id)
                    {
                        this->myProducts.erase(this->myProducts.begin() + i);
                    }
                }
            }
//add new product
            void addProduct(Product newProduct, int q)
            {
                myProducts.push_back(newProduct);
                this->myQuantities.push_back(q);
                this->productionCost += newProduct.getProductionCost() * q;
            }
//calculate production cost of current stock
            int calculateProductionCost()
            {
                int cost = 0;
                for(int i = 0; i < this->myProducts.size(); i ++)
                {
                    cost += this->myProducts[i].getProductionCost() * this->myQuantities[i];
                }
                return cost;
            }
//change quantity
            void changeQuantity(int id, int quantity)
            {
                int index;
                for(int i = 0; i < this->myProducts.size(); i ++)
                {
                    if(this->myProducts[i].getId() == id)
                    {
                        index = i;
                        i = this->myProducts.size();
                    }
                }
                this->myQuantities[index] = this->myQuantities[index] + quantity;
            }
    };