    #include <iostream>
    #include <string>
    #include <vector>

    class Client
    {
        private:
            std::string name;
            int nOrders;
        public:
//getters and setters
            void setName(std::string name)
            {
                this->name = name;
            }
            void setNOrders(int no)
            {
                this->nOrders = no;
            }
            int getNOrders()
            {
                return this->nOrders;
            }
            std::string getName()
            {
                return this->name;
            }
    };