    #include <iostream>
    #include <string>

    class Employee
    {
        private:
            int id;
            std::string name;
            int shiftStart;
            int shiftEnd;
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
            void setShiftStart(int start)
            {
                this->shiftStart = start;
            }
            void setShiftEnd(int end)
            {
                this->shiftEnd = end;
            }
            int getId()
            {
                return this->id;
            }
            std::string getName()
            {
                return this->name;
            }
            int getShiftStart()
            {
                return this->shiftStart;
            }
            int getShiftEnd()
        {
            return this->shiftEnd;
        }
//display information
    //AICI am folosit ABSTRACTIZARE
            virtual void info() = 0;
//change shift times
            void changeShift(int newStart, int newEnd)
            {
                this->shiftStart = newStart;
                this->shiftEnd = newEnd;
            }
    };

//AICI am folosit MOSTENIRE
    class Manager: public Employee
    {
        public:
            void info()
            {
                std::cout << "----------------------------------------------" << std::endl;
                std::cout << "------------- Manager Information ------------" << std::endl;
                std::cout << "Employee ID: " << getId() << std::endl;
                std::cout << "Name: " << getName() << std::endl;
                std::cout << "Shift: " << getShiftStart() << " - " << getShiftEnd() << std::endl;
            }
    };

    class Barista: public Employee
    {
        public:
            void info()
            {
                std::cout << "----------------------------------------------" << std::endl;
                std::cout << "------------- Barista Information ------------" << std::endl;
                std::cout << "Employee ID: " << getId() << std::endl;
                std::cout << "Name: " << getName() << std::endl;
                std::cout << "Shift: " << getShiftStart() << " - " << getShiftEnd() << std::endl;
            }
    };

    class Waiter: public Employee
    {
        public:
            void info()
            {
                std::cout << "----------------------------------------------" << std::endl;
                std::cout << "------------- Waiter Information -------------" << std::endl;
                std::cout << "Employee ID: " << getId() << std::endl;
                std::cout << "Name: " << getName() << std::endl;
                std::cout << "Shift: " << getShiftStart() << " - " << getShiftEnd() << std::endl;
            }
    };