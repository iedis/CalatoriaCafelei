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