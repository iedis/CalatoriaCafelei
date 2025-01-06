    #include <iostream> 
    #include <fstream>
    #include <string>
    #include <vector>
    #include "employees.hpp"
    #include "specialEvents.hpp"

    #define NPROD 20
//AICI am folosit DESIGN PATTERNS: FACADE
    class CoffeeHouse
    {
        private:
            Manager myManager;
            std::vector<Barista> myBaristas;
            std::vector<Waiter> myWaiters;
            std::vector<int> myWages;
            Stock myStock;
            std::vector<Order> myOrders;
            SeasonalMenu currentSeasonalMenu;
        public:
//getters and setters
            void setManager(Manager manager)
            {
                this->myManager = manager;
            }
            void setOneBarista(Barista barista)
            {
                this->myBaristas.push_back(barista);
            }
            void setBaristas(std::vector<Barista> baristas)
            {
                this->myBaristas = baristas;
            }
            void setOneWaiter(Waiter waiter)
            {
                this->myWaiters.push_back(waiter);
            }
            void setWaiters(std::vector<Waiter> waiters)
            {
                this->myWaiters = waiters;
            }
            void setOneWage(int wage)
            {
                this->myWages.push_back(wage);
            }
            void setWages(std::vector<int> wages)
            {
                this->myWages = wages;
            }
            void setStock(Stock myStock)
            {
                this->myStock = myStock;
            }
            void setOneOrder(Order order)
            {
                this->myOrders.push_back(order);
            }
            void setOrders(std::vector<Order> orders)
            {
                this->myOrders = orders;
            }
            void setSeasonalMenu(SeasonalMenu newMenu)
            {
                this->currentSeasonalMenu = newMenu;
            }
            Manager getManager()
            {
                return this->myManager;
            }
            Barista getOneBarista(int index)
            {
                return this->myBaristas[index];
            }
            std::vector<Barista> getBaristas()
            {
                return this->myBaristas;
            }
            Waiter getOneWaiter(int index)
            {
                return this->myWaiters[index];
            }
            std::vector<Waiter> getWaiters()
            {
                return this->myWaiters;
            }
            int getOneWage(int index)
            {
                return this->myWages[index];
            }
            std::vector<int> getWages()
            {
                return this->myWages;
            }
            Stock getStock()
            {
                return this->myStock;
            }
            Order getOneOrder(int index)
            {
                return this->myOrders[index];
            }
            std::vector<Order> getOrders()
            {
                return this->myOrders;
            }
            SeasonalMenu getSeasonalMenu()
            {
                return currentSeasonalMenu;
            }
//constructor
            CoffeeHouse(){}
//hire new empolyee
        //AICI am folosit TEMPLATES
            template <typename T>
            void hireEmployee(T newEmployee, std::string fileName)
            {
        //AICI am folosit EXCEPTII
                try
                {
                    std::ofstream file;
                    file.open(fileName, std::ios::app);
                    if(!file)
                    {
                        throw "The employees file could not be opened! (Fisierul de angajati nu a putut fi deschis)";
                    }
                    file << std::endl << newEmployee.getId() << "," << newEmployee.getName() << "," << newEmployee.getJob() << "," 
                    << newEmployee.getShiftStart() << "," << newEmployee.getShiftEnd() << "," << newEmployee.getWage();
                    file.close();
                }
                catch(std::string msg)
                {
                    std::cout << "------------------------------------------" << std::endl;
                    std::cout << msg << std::endl;
                }
            }
//rewrite employee file
            void rewriteEmployee(Manager newManager,std::vector<Waiter> newWaiters,std::vector<Barista> newBaristas, std::string fileName)
            {
                try
                {
                    std::ofstream file;
                    file.open(fileName);
                    if(!file)
                    {
                        throw "The employee file could not be opened! (Fisierul de angajati nu a putut fi deschis)";
                    }
                    file << newManager.getId() << "," << newManager.getName() << "," << newManager.getJob() << "," 
                    << newManager.getShiftStart() << "," << newManager.getShiftEnd() << "," << newManager.getWage();
                    for(int i = 0; i < newBaristas.size(); i ++)
                    {
                        file << std::endl << newBaristas[i].getId() << "," << newBaristas[i].getName() << "," << newBaristas[i].getJob() << "," 
                        << newBaristas[i].getShiftStart() << "," << newBaristas[i].getShiftEnd() << "," << newBaristas[i].getWage();
                    }
                    for(int i = 0; i < newWaiters.size(); i ++)
                    {
                        file << std::endl << newWaiters[i].getId() << "," << newWaiters[i].getName() << "," << newWaiters[i].getJob() << "," 
                        << newWaiters[i].getShiftStart() << "," << newWaiters[i].getShiftEnd() << "," << newWaiters[i].getWage();
                    }
                    file.close();
                }
                catch(std::string msg)
                {
                    std::cout << "------------------------------------------" << std::endl;
                    std::cout << msg << std::endl;
                }
            }
//write new order to file
            void writeOrder(Order newOrder, std::string& fileName)
            {
                try
                {

                    std::ofstream file;
                    file.open(fileName, std::ios::app);
                    if(!file)
                    {
                        throw "The employee file could not be opened! (Fisierul de angajati nu a putut fi deschis)";
                    }
                    file << std::endl << newOrder.getId() << "," << newOrder.getClient().getName() << "," <<newOrder.getClient().getNOrders() << ","
                    << newOrder.getNrOfProducts() << ",";
                    for(int i = 0; i < newOrder.getAllProducts().size(); i ++)
                    {
                        file << newOrder.getAllQuantities()[i] << ",";
                        file << newOrder.getAllProducts()[i].getName() << ",";
                    }
                    file << newOrder.getTotal();
                }
                catch(std::string msg)
                {
                    std::cout << "------------------------------------------" << std::endl;
                    std::cout << msg << std::endl;
                }
                
            }
//rewrite stock file
            void rewriteStock(Stock newStock,std::string& fileName)
            {
                try
                {
                    std::ofstream file;
                    file.open(fileName);
                    if(!file)
                    {
                        throw "The stock file could not be opened! (Fisierul de angajati nu a putut fi deschis)";
                    }
                    file << newStock.getAllProducts()[0].getId() << "," << newStock.getAllProducts()[0].getName() << ","
                    << newStock.getAllProducts()[0].getPrice() << "," << newStock.getAllProducts()[0].getProductionCost() << "," << newStock.getAllQuantities()[0];
                    for(int i = 1; i < newStock.getAllProducts().size(); i ++)
                    {
                        file << std::endl << newStock.getAllProducts()[i].getId() << "," << newStock.getAllProducts()[i].getName() << ","
                        << newStock.getAllProducts()[i].getPrice() << "," << newStock.getAllProducts()[i].getProductionCost() << "," << newStock.getAllQuantities()[i];
                    }
                    file.close();
                }
                catch(std::string msg)
                {
                    std::cout << "------------------------------------------" << std::endl;
                    std::cout << msg << std::endl;
                }
            }
//calculate total income from orders
            int orderIncome()
            {
                int income = 0;
                for(int i = 0; i < this->myOrders.size(); i ++)
                {
                    income += myOrders[i].getTotal();
                }
                return income;
            }
//calculate total sum of wages
            int allWages()
            {
                int sum = 0;
                sum += this->myManager.getWage();
                for(int i = 0; i < this->myBaristas.size(); i++)
                {
                    sum += this->myBaristas[i].getWage();
                }
                for(int i = 0; i < this->myWaiters.size(); i++)
                {
                    sum += this->myWaiters[i].getWage();
                }
                return sum;
            }
//calculate profits for the day
            int profits(int payDay)
            {
                int profit;
                profit = this->orderIncome() - this->myStock.calculateProductionCost();
                if(payDay == 1)
                {
                    profit -= this->allWages();
                }
                return profit;
            }
//daily report in English
            void dailyReportEnglish()
            {
                std::ofstream file("TodaysReport.txt");
                if(!file)
                {
                    std::cout << "The file could not be opened! Please try again" << std::endl;
                    return;
                }
                int i, profits = 0;
                file << "Today's Report: " << std::endl;
                file << "----------------------------------------------" << std::endl;
                file << "Costs: " << std::endl;
                file << "Production costs: " << this->myStock.calculateProductionCost() << " RON"<< std::endl;
                file << "----------------------------------------------" << std::endl;
                file << "Income: " << std::endl;
                file << "Total of all orders placed today is: " << this->orderIncome() << " RON"<< std::endl;
                file << "----------------------------------------------" << std::endl;
                file << "Wages: " << std::endl;
                file << "Manager: " << this->myManager.getWage() << std::endl;
                file << "Baristas: " << std::endl;
                for(int i = 0; i < this->myBaristas.size(); i ++)
                {
                    file << "Id: " << this->myBaristas[i].getId() << " - " << this->myBaristas[i].getWage() << std::endl;
                }
                file << "Waiters: " << std::endl;
                for(int i = 0; i < this->myWaiters.size(); i ++)
                {
                    file << "Id: " << this->myWaiters[i].getId() << " - " << this->myWaiters[i].getWage() << std::endl;
                }
                file << "----------------------------------------------" << std::endl;
                std::cout << "Is today a pay day? (1/0)" << std::endl;
                int payDay;
                std::cin >> payDay;
                while(payDay != 0 && payDay != 1)
                {
                    std::cout << "Wrong input! Choose 1 for YES and 0 for NO" << std::endl;
                    std::cout << "Is today a pay day? (1/0)" << std::endl;
                    std::cin >> payDay;
                }
                file << "Profits: " << this->profits(payDay) << " RON" << std::endl;
                file.close();
            }
//daily report in Romanian
            void dailyReportRomanian()
            {
                std::ofstream file("RaportZilnic.txt");
                if(!file)
                {
                    std::cout << "Fisierul nu a putut fi deschis! Incearca din nou" << std::endl;
                    return;
                }
                int i, profits = 0;
                file << "Raportul zilei de azi: " << std::endl;
                file << "----------------------------------------------" << std::endl;
                file << "Costuri: " << std::endl;
                file << "Costuri de productie: " << this->myStock.calculateProductionCost() << " RON"<< std::endl;
                file << "----------------------------------------------" << std::endl;
                file << "Venituri: " << std::endl;
                file << "Totalul tuturor comenzilor plasate azi: " << this->orderIncome() << " RON"<< std::endl;
                file << "----------------------------------------------" << std::endl;
                file << "Salarii: " << std::endl;
                file << "Manager: " << this->myManager.getWage() << std::endl;
                file << "Barista: " << std::endl;
                for(int i = 0; i < this->myBaristas.size(); i ++)
                {
                    file << "Id: " << this->myBaristas[i].getId() << " - " << this->myBaristas[i].getWage() << std::endl;
                }
                file << "Chelneri: " << std::endl;
                for(int i = 0; i < this->myWaiters.size(); i ++)
                {
                    file << "Id: " << this->myWaiters[i].getId() << " - " << this->myWaiters[i].getWage() << std::endl;
                }
                file << "----------------------------------------------" << std::endl;
                int payDay = 0;
                std::cout << "Este azi zi de plata? (1/0)" << std::endl;
                std::cin >> payDay;
                while(payDay != 0 && payDay != 1)
                {
                    std::cout << "Ai introdus gresit! Alege 1 pentru DA si 0 pentru NU" << std::endl;
                    std::cout << "Este azi zi de plata? (1/0)" << std::endl;
                    std::cin >> payDay;
                }
                file << "Profit: " << this->profits(payDay) << " RON" << std::endl;
                file.close();
            }
//special events

//read from order file
            void readOrder(std::string& fileName)
            {
                this->myOrders.clear();
                std::ifstream file(fileName);
                if(!file)
                {
                    std::cout << "The orders file could not be opened! (Fisierul de comenzi nu a putut fi deschis)" << std::endl;
                    return;
                }
                Order temp;
                Client auxClient;
                std::string line = "";
                int location, aux;
                while(getline(file, line))
                {
                    location = line.find(',');
                    temp.setId(stoi(line.substr(0, location)));
                    line = line.substr(location + 1, line.length());

                    location = line.find(',');
                    auxClient.setName(line.substr(0, location));
                    line = line.substr(location + 1, line.length());

                    location = line.find(',');
                    auxClient.setNOrders(stoi(line.substr(0, location)));
                    line = line.substr(location + 1, line.length());

                    temp.setClient(auxClient);
                    
                    location = line.find(',');
                    temp.setNrOfProducts(stoi(line.substr(0, location)));
                    line = line.substr(location + 1, line.length());

                    std::vector<Product> currentProducts = this->myStock.getAllProducts();
                    for(int i = 0; i < temp.getNrOfProducts(); i ++)
                    {
                        location = line.find(',');
                        temp.setOneQuantity(stoi(line.substr(0, location)));
                        line = line.substr(location + 1, line.length());
                        location = line.find(',');
                        for(int j = 0; j < currentProducts.size(); j ++)
                        {
                            if(currentProducts[j].getName() == line.substr(0, location))
                            {
                                temp.setOneProduct(currentProducts[j]);
                                line = line.substr(location + 1, line.length()); 
                                j = currentProducts.size();
                            }
                        }
                    }

                    location = line.find(',');
                    temp.setTotalValue(stoi(line.substr(0, location)));
                    line = line.substr(location + 1, line.length());  

                    this->myOrders.push_back(temp);    
                }
                file.close();
            }
//read from eployees file    
            void readEmployees(std::string& fileName)
            {
                this->myBaristas.clear();
                this->myWaiters.clear();
                std::ifstream file(fileName);
                if(!file)
                {
                    std::cout << "The orders file could not be opened! (Fisierul de comenzi nu a putut fi deschis)" << std::endl;
                    return;
                }
                std::string line = "";
                int location;
                int tempId, tempStart, tempEnd, tempWage;
                std::string tempName, tempJob;
                while(getline(file,line))
                {
                    location = line.find(',');
                    tempId = (stoi(line.substr(0, location)));
                    line = line.substr(location + 1, line.length());

                    location = line.find(',');
                    tempName = line.substr(0, location);
                    line = line.substr(location + 1, line.length());

                    location = line.find(',');
                    tempJob = line.substr(0, location);
                    line = line.substr(location + 1, line.length());

                    location = line.find(',');
                    tempStart = (stoi(line.substr(0, location)));
                    line = line.substr(location + 1, line.length());

                    location = line.find(',');
                    tempEnd = (stoi(line.substr(0, location)));
                    line = line.substr(location + 1, line.length());

                    location = line.find(',');
                    tempWage = (stoi(line.substr(0, location)));
                    line = line.substr(location + 1, line.length());

                    if(tempJob ==  "Manager")
                    {
                        this->myManager.setId(tempId);
                        this->myManager.setName(tempName);
                        this->myManager.setJob(tempJob);
                        this->myManager.setShiftStart(tempStart);
                        this->myManager.setShiftEnd(tempEnd);
                        this->myManager.setWage(tempWage);
                    }
                    else if(tempJob == "Barista")
                    {
                        Barista b;
                        b.setId(tempId);
                        b.setName(tempName);
                        b.setJob(tempJob);
                        b.setShiftStart(tempStart);
                        b.setShiftEnd(tempEnd);
                        b.setWage(tempWage);
                        this->myBaristas.push_back(b);
                    }
                    else
                    {
                        Waiter w;
                        w.setId(tempId);
                        w.setName(tempName);
                        w.setJob(tempJob);
                        w.setShiftStart(tempStart);
                        w.setShiftEnd(tempEnd);
                        w.setWage(tempWage);
                        this->myWaiters.push_back(w);
                    }
                }
                file.close();
            }
//read stock from file
            void readStock(std::string& fileName)
            {
                this->myStock.getAllProducts().clear();
                this->myStock.getAllQuantities().clear();
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

                    this->myStock.setOneProduct(temp); 

                    location = line.find(',');
                    this->myStock.setOneQuantity(stoi(line.substr(0, location)));
                    line = line.substr(location + 1, line.length());                 
                }
                file.close();
            }  
    };