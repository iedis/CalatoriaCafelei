    #include <iostream> 
    #include <fstream>
    #include <string>
    #include <vector>
    #include "employees.hpp"
    #include "products.hpp"
    #include "clients.hpp"
    #include "orders.hpp"
    #include "specialEvents.hpp"

    #define NPROD 20

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
            void setSeasonalMenu(std::vector<Product> seasonalProducts, int sDay, int sMonth, int sYear, int eDay, int eMonth, int eYear)
            {
                this->currentSeasonalMenu.setProducts(seasonalProducts);
                this->currentSeasonalMenu.setStartDate(sDay, sMonth, sYear);
                this->currentSeasonalMenu.setEndDate(eDay, eMonth, eYear);
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
//hire new empolyee
            template <typename T>
            void hireEmployee(T newEmployee)
            {
                try
                {
                    if(newEmployee.getJob() == "Manager")
                    {
                        myManager = newEmployee;
                    }
                    else if(newEmployee.getJob() == "Barista")
                    {
                        myBaristas.push_back(newEmployee);
                    }
                    else if(newEmployee.getJob() == "Waiter" || newEmployee.getJob() == "Chelner")
                    {
                        myWaiters.push_back(newEmployee);
                    }
                    throw "Wrong job title (Denumire job gresita). Try again (Reincearca).";
                }
                catch(std::string msg)
                {
                    cout << "------------------------------------------" << std::endl;
                    cout << msg << std::endl;
                }
            }
//fire employee
            template <typename T>
            void fireEmployee(T firedEmployee)
            {
                try
                {
                    if(firedEmployee.getJob() == "Manager")
                    {
                        this->myManager.fireEmployee();
                    }
                    else if(firedEmployee.getJob() == "Barista")
                    {
                        for(int i = 0; i < this->myBaristas.size(); i ++)
                        {
                            if(this->myBaristas[i].getId == firedEmployee.getId())
                            {
                                this->myBaristas.erase(find(this->myBaristas.begin(),this->myBaristas.end(), firedEmployee.getId()));
                                i = this->myBaristas.size();
                            }
                        }
                    }
                    else if(firedEmployee.getJob() == "Waiter" || firedEmployee.getJob() == "Chelner")
                    {
                        for(int i = 0; i < this->myWaiters.size(); i ++)
                        {
                            if(this->myWaiters[i].getId == firedEmployee.getId())
                            {
                                this->myWaiters.erase(find(this->myWaiters.begin(),this->myWaiters.end(), firedEmployee.getId()));
                                i = this->myWaiters.size();
                            }
                        }
                    }
                    throw "Wrong job title (Denumire job gresita). Try again (Reincearca).";
                }
                catch(std::string msg)
                {
                    cout << "------------------------------------------" << std::endl;
                    cout << msg << std::endl;
                }
            }
//calculate total income from orders
            int orderIncome()
            {
                int income = 0;
                for(int i = 0; i < this->myOrders.size(); i ++)
                {
                    income += this->myOrders[i].getTotal();
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
            void dailyReportEnglish(int payDay)
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
                int payDay = 0;
                std::cout << "Is today a pay day? (1/0)" << std::endl;
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
            void dailyReportRomanian(int payDay)
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

//read from stock file
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

                    this->myStock.setOneProduct(temp);

                    location = line.find(',');
                    this->myStock.setOneQuantity(stoi(line.substr(0, location)));
                    line = line.substr(location + 1, line.length());
                }
            }

    };