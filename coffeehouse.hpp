    #include <iostream> 
    #include <string>
    #include <vector>
    #include "employees.hpp"
    #include "products.hpp"
    #include "clients.hpp"
    #include "orders.hpp"

    class CoffeeHouse
    {
        private:
            Manager myManager;
            std::vector<Barista> myBaristas;
            std::vector<Waiter> myWaiters;
            std::vector<int> myWages;
            Stock myStock;
            std::vector<Order> myOrders;
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
                    else if(newEmployee.getJob() == "Waiter")
                    {
                        myWaiters.push_back(newEmployee);
                    }
                    throw "Wrong job title. Try again";
                }
                catch(std::string msg)
                {
                    cout << "------------------------------------------" << std::endl;
                    cout << msg << std::endl;
                }
            }
//fire employee

//daily raport

//special events
        
    };