    #include <iostream>
    #include <string>

    class Employee
    {
        private:
            int id;
            std::string name;
            std::string job;
            int shiftStart;
            int shiftEnd;
            int wage;
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
            void setWage(int wage)
            {
                this->wage = wage;
            }
            void setJob(std::string job)
            {
                this->job = job;
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
            std::string getJob()
            {
                return this->job;
            }
            int getWage()
            {
                return this->wage;
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
//fire employee
            void fireEmployee()
            {
                this->setId(0);
                this->setName("");
                this->setShiftEnd(0);
                this->setShiftStart(0);
                this->wage = 0;
            }
    };

//AICI am folosit MOSTENIRE
    class Manager: public Employee
    {
        private:
            
        public:
            void info()
            {
                std::cout << "----------------------------------------------" << std::endl;
                std::cout << "------------- Manager Information ------------" << std::endl;
                std::cout << "Employee ID: " << getId() << std::endl;
                std::cout << "Name: " << getName() << std::endl;
                std::cout << "Shift: " << getShiftStart() << " - " << getShiftEnd() << std::endl;
            }
//AICI am folosit CONSTRUCTORI
            Manager(int id, std::string name, std::string job,int start, int end, int wage)
            {
                this->setId(id);
                this->setName(name);
                this->setJob(job);
                this->setShiftStart(start);
                this->setShiftEnd(end);
                this->setWage(wage);
            }
            Manager()
            {

            }
    };

    class Barista: public Employee
    {
        private:
            
        public:
            void info()
            {
                std::cout << "----------------------------------------------" << std::endl;
                std::cout << "------------- Barista Information ------------" << std::endl;
                std::cout << "Employee ID: " << getId() << std::endl;
                std::cout << "Name: " << getName() << std::endl;
                std::cout << "Shift: " << getShiftStart() << " - " << getShiftEnd() << std::endl;
            }
            Barista(int id, std::string name, std::string job,int start, int end, int wage)
            {
                this->setId(id);
                this->setName(name);
                this->setJob(job);
                this->setShiftStart(start);
                this->setShiftEnd(end);
                this->setWage(wage);
            }
            Barista(){}
    };

    class Waiter: public Employee
    {
        private:
            
        public:
            void info()
            {
                std::cout << "----------------------------------------------" << std::endl;
                std::cout << "------------- Waiter Information -------------" << std::endl;
                std::cout << "Employee ID: " << getId() << std::endl;
                std::cout << "Name: " << getName() << std::endl;
                std::cout << "Shift: " << getShiftStart() << " - " << getShiftEnd() << std::endl;
            }
            Waiter(int id, std::string name, std::string job,int start, int end, int wage)
            {
                this->setId(id);
                this->setName(name);
                this->setJob(job);
                this->setShiftStart(start);
                this->setShiftEnd(end);
                this->setWage(wage);
            }
            Waiter(){}
    };