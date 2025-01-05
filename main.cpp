    #include <iostream> 
    #include <fstream>
    #include <string>
    #include <vector>
    #include "coffeehouse.hpp"
    using namespace std;

//template function to find employee from a given id
    template <typename T>
    int findById(std::vector<T> employees, int id)
    {
        int index, i;
        for(i = 0; i < employees.size(); i ++)
            {
                if(employees[i].getId() == id)
                {
                    index = i;
                    i = employees.size();
                }
            }
        return index;
    }

    int main()
    {
        CoffeeHouse location;
        string employeesFile, ordersFile, stockFile;
        int city = 0, option = 0, i, index;
        int tempId, tempStart, tempEnd, tempWage;
        string tempName, tempJob;
        vector<Waiter> auxWaiters;
        vector<Barista> auxBaristas;
        cout << "----------------------------------------------" << endl;
        cout << "Welcome! (Bine ai venit!)" << endl;
        while(city < 1 || city > 5)
        {
            cout << "Please pick you location: (Te rog alege cafeneaua ta:)" << endl;
            cout << "----------------------------------------------" << endl;
            cout << "1. Bucuresti" << endl;
            cout << "2. Brasov" << endl;
            cout << "3. Cluj" << endl;
            cout << "4. Iasi" << endl;
            cout << "5. Timisoara" << endl;
            cout << "----------------------------------------------" << endl;
            cin >> city;
            if(city < 1 || city > 5)
            {
                cout << "Wrong option. Try again! (Optiune gresita. Te rog reincearca!)" << endl;
            }
        }

//choose name of each file, based on location of caffe
        switch (city)
        {
        case 1:
            employeesFile = "csv/angajati/angajatiBucuresti.csv";
            ordersFile = "csv/comenzi/comenziBucuresti.csv";
            stockFile = "csv/stockuri/stockBucuresti.csv";
            break;
        case 2:
            employeesFile = "csv/angajati/angajatiBrasov.csv";
            ordersFile = "csv/comenzi/comenziBrasov.csv";
            stockFile = "csv/stockuri/stockBrasov.csv";
            break;
        case 3:
            employeesFile = "csv/angajati/angajatiCluj.csv";
            ordersFile = "csv/comenzi/comenziCluj.csv";
            stockFile = "csv/stockuri/stockCluj.csv";
            break;
        case 4:
            employeesFile = "csv/angajati/angajatiIasi.csv";
            ordersFile = "csv/comenzi/comenziIasi.csv";
            stockFile = "csv/stockuri/stockIasi.csv";
            break;
        case 5:
            employeesFile = "csv/angajati/angajatiTimisoaar.csv";
            ordersFile = "csv/comenzi/comenziTimisoara.csv";
            stockFile = "csv/stockuri/stockTimisoara.csv";
            break;
        default:
            break;
        }
//read from files for chose location
        location.readEmployees(employeesFile);
        location.readOrder(ordersFile);
        location.getStock().readStock(stockFile);
//implement user menu
        cout << "----------------------------------------------" << endl;
        while(option < 1 || option > 8)
        {
            cout << "What do you want to do? (Ce doriti sa faceti?)" << endl;
            cout << "Choose the respective number. (Alegeti numarul corespunzator):" << endl;
            cout << "----------------------------------------------" << endl;
            cout << "1. Hire new employee (Angajati o persoana)" << endl;
            cout << "2. Fire an employee (Concediati un angajat)" << endl;
            cout << "3. Change an employees schedule (Schimbati programul unui angajat)" << endl;
            cout << "4. New order (Introduceti o noua comanda)" << endl;
            cout << "5. Change stock information (Schimbati informatiile legate de stoc)" << endl;
            cout << "6. Create seasonal menu (Creati meniu de sezon)" << endl;
            cout << "7. Daily report (Raport zilnic)" << endl;
            cout << "8. Quit (Iesiti)" << endl;
            cout << "----------------------------------------------" << endl;
            cin >> option;
            if(option < 1 || option > 8)
            {
                cout << "Please choose a number between 1 and 8 (Introduceti o cifra intre 1 si 8)" << endl;
            }
            switch (option)
            {
                case 1:
                    cout << "----------------------------------------------" << endl;
                    cout << "You chose: Hire employee (Ati ales: Angajeaza o persoana)" << endl;
                    cout << "Please complete the form below (Completati formularul de angajare)" << endl;
                    cout << "Id: " << endl;
                    cin >> tempId;
                    cout << "Name: (Nume:) " << endl;
                    cin >> tempName;
                    cout << "Job title: (Denumire job:)" << endl;
                    cin >> tempJob;
                    cout << "Start of shift: (Inceutul turei)" << endl;
                    cin >> tempStart;
                    cout << "End of shift: (Finalul turei)" << endl;
                    cin >> tempEnd;
                    cout << "Wage: (Salariu)" << endl;
                    cin >> tempWage;
                    if(tempJob ==  "Manager")
                    {
                        Manager aux(tempId,tempName,tempJob,tempStart,tempEnd,tempWage);
                        location.setManager(aux); 
                        location.hireEmployee(aux,employeesFile);
                    }
                    else if (tempJob == "Barista")
                    {
                        Barista aux(tempId,tempName,tempJob,tempStart,tempEnd,tempWage);
                        location.setOneBarista(aux);
                        location.hireEmployee(aux,employeesFile);
                    }
                    else if(tempJob == "Waiter" || tempJob == "Chelner")
                    {
                        Waiter aux(tempId,tempName,tempJob,tempStart,tempEnd,tempWage);
                        location.setOneWaiter(aux);
                        location.hireEmployee(aux,employeesFile);
                    }
                    else {
                        cout << "Wrong input! Try again (Denumire job gresita! Reincercati)" << endl;
                    }
                    break;
                case 2:
                    cout << "----------------------------------------------" << endl;
                    cout << "You chose: Fire employee (Ati ales: Concediaza angajat)" << endl;
                    cout << "What is the job title of the employee you want to fire? (Ce slujba are angajatul?)" << endl;
                    cin >> tempJob;
                    cout << "Enter the Id of the employee you want to fire (Introduceti Id-ul angajatului pe care doriti sa il concediati)" << endl;
                    cin >> tempId;
                    auxWaiters = location.getWaiters();
                    auxBaristas = location.getBaristas();
                    if(tempJob ==  "Manager")
                    {
                        location.getManager().fireEmployee();
                    }
                    else if(tempJob ==  "Barista")
                    {
                        index = findById(auxBaristas,tempId);
                        auxBaristas.erase(auxBaristas.begin() + index);
                    }
                    else if(tempJob ==  "Waiter" || tempJob == "Chelner")
                    {
                        index = findById(auxWaiters,tempId);
                        auxWaiters.erase(auxWaiters.begin() + index);
                    }
                    else {
                        cout << "Wrong input! Try again (Denumire job gresita! Reincercati)" << endl;
                        break;
                    }
                    location.rewriteEmployee(location.getManager(),auxWaiters,auxBaristas,employeesFile);
                    location.readEmployees(employeesFile);
                    break;
                case 3:
                    int newStart, newEnd;
                    cout << "----------------------------------------------" << endl;
                    cout << "You chose: Change an employees schedule (Schimbati programul unui angajat)" << endl;
                    cout << "What is the job title of the employee you want to fire? (Ce slujba are angajatul?)" << endl;
                    cin >> tempJob;
                    cout << "Enter the Id of the employee you want to fire (Introduceti Id-ul angajatului pe care doriti sa il concediati)" << endl;
                    cin >> tempId;
                    cout << "What is the new start time? (Care este noua ora de incepere?)" << endl;
                    cin >> newStart;
                    cout << "What is the new end time? (Care este noua ora de final?)" << endl;
                    cin >> newEnd;
                    auxWaiters = location.getWaiters();
                    auxBaristas = location.getBaristas();
                    if(tempJob == "Manager")
                    {
                        location.getManager().changeShift(newStart,newEnd);
                    }
                    else if(tempJob == "Barista")
                    {
                        index = findById(auxBaristas,tempId);
                        auxBaristas[index].changeShift(newStart,newEnd);
                    }
                    else if(tempJob == "Waiter" || tempJob == "Chelner")
                    {
                        index = findById(auxWaiters,tempId);
                        auxWaiters[index].changeShift(newStart,newEnd);
                    }
                    else {
                        cout << "Wrong input! Try again (Denumire job gresita! Reincercati)" << endl;
                        break;
                    }
                    location.rewriteEmployee(location.getManager(),auxWaiters,auxBaristas,employeesFile);
                    location.readEmployees(employeesFile);
                    break;
                case 4:

                    break;
                case 5:
                    
                    break;
                case 6:

                    break;
                case 7:
                    
                    break;
                case 8:
                    cout << "Goodbye! (La revedere!)" << endl;
                    return 0;
                    break;
                default:
                    break;
            }
            cout << "----------------------------------------------" << endl;
            cout << "Do you want to do something else? (1/0) (Doriti sa faceti alta actiune? (1/0))" << endl;
            cin >> option;
            if(option == 1)
            {
                option = 0;
            }
            else if(option == 0)
            {
                cout << "Goodbye! (La revedere!)" << endl;
                return 0;
            }
            else
            {
                cout << "Wrong option. Exiting. (Optiune gresita. Iesire)" << endl;
            }
        }



        return 0;
    }