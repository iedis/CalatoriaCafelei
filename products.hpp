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
            void removeProduct(Product oldProduct)
            {
                for(int i = 0; i < this->myProducts.size(); i ++)
                {
                    if(this->myProducts[i].getId() == oldProduct.getId())
                    {
                        this->myProducts.erase(this->myProducts.begin() + i);
                    }
                }
            }
//add new product
            void addProduct(Product newProduct)
            {
                myProducts.push_back(newProduct);
                int i = this->myProducts.size() - 1;
                this->productionCost += this->myProducts[i].getProductionCost() * this->myQuantities[i];
            }
//calculate production cost of current stock
            int calculateProductionCost()
            {
                for(int i = 0; i < this->myProducts.size(); i ++)
                {
                    this->productionCost += this->myProducts[i].getProductionCost() * this->myQuantities[i];
                }
                return this->productionCost;
            }
//read stock from file
            void readStock(std::string& fileName)
            {
                std::ifstream file(fileName);
                if(!file)
                {
                    std::cout << "The products file could not be opened! (Fisierul de produse nu a putut fi deschis)" << std::endl;
                    return;
                }
                Product temp;
                std::string line = "";
                int location;
                while(getline(file, line))
                {
                    location = line.find(',');
                    temp.setId(stoi(line.substr(0, location)));
                    line = line.substr(location + 1, line.length());

                    location = line.find(',');
                    temp.setName(line.substr(0, location));
                    line = line.substr(location + 1, line.length());

                    location = line.find(',');
                    temp.setPrice(stoi(line.substr(0, location)));
                    line = line.substr(location + 1, line.length());

                    location = line.find(',');
                    temp.setProductionCost(stoi(line.substr(0, location)));
                    line = line.substr(location + 1, line.length());  

                    this->myProducts.push_back(temp); 

                    location = line.find(',');
                    this->myQuantities.push_back(stoi(line.substr(0, location)));
                    line = line.substr(location + 1, line.length());                 
                }
                file.close();
            }    
    };