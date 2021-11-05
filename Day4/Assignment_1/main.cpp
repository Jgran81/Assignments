#include <iostream>
#include <vector>

//A car service shop needs to keep track of the records of services 
//they provide to their customer. Create a system for them so they 
//could keep ATLEAST the below records:
// x Date the customer visited
// x Services performed (at least 2 different services)
// x Parts changed (at least 2 different parts)
// x Payment (method & amount)


//Sorry for the 1-file setup, I'm lazy

class service{
    public:
    int cost;
    unsigned int date;
    std::string service_name;

};
class oilChange : public service{
    private:
    std::string name = "Oil change";
    const int price = 2199;
    public:
    oilChange(const unsigned int d){
        service_name = name;
        cost = price;
        date = d;
    }

};
class changeAirFilter : public service{
    private:
    std::string name = "Change brake pads";
    const int price = 3989;
    public:
    changeAirFilter(const unsigned int d){
        service_name = name;
        cost = price;
        date = d;
    }

};
//-------------------------
class partsChanged{
    public:
    int cost;
    std::string part_changed;
    unsigned int date;
};
class replaceMuffler : public partsChanged{
    private:
    std::string name = "Replace muffler";
    const int price = 1599;
    public:
    replaceMuffler(const unsigned int d){
        part_changed = name;
        cost = price;
        date = d;

    }
};
class replaceTires : public partsChanged{
    private:
    std::string name = "Replace tires";
    const int price = 5499;
    public:
    replaceTires(const unsigned int d){
        part_changed = name;
        cost = price;
        date = d;
    }
};
//-------------------------
class paymentMethod{
    public:
    std::string paymentType;
};
class cardPayment : public paymentMethod{
    private:
    std::string card = "Card";
    public:
    cardPayment(){
        paymentType = card;
    }
};
class cashPayment : public paymentMethod{
    private:
    std::string cash = "Cash";
    public:
    cashPayment(){
        paymentType = cash;
    }
};

//-------------------------

class customer{
    public:
    std::string name;
    std::vector<std::string> service;
    std::vector<std::string> partsChanged;
    std::string payWith;
    int paymentDue;
    unsigned int lastVisit;

};

//How to connect different services to the customer? done
//How to connect different repairs for the customer? done
//How to connect different paymentDue options for the customer?
class carServiceShop{
public:
    int n_customers = 0;
    std::vector<customer*> customer_list;

    carServiceShop(){}

    void new_cust(std::string n){
        customer *n_cust = new customer;
        n_cust->name = n;
        n_customers++;
        customer_list.push_back(n_cust);
    }
    void payment(const int n){

    }
    //printing name, paymentDue due, what services has been done
    void print(){
        std::cout << "Number of customers: " << n_customers << std::endl;
        for(auto i=0; i<customer_list.size(); i++){
            std::cout <<"Customer name: " << customer_list[i]->name << ", Payment due: " << customer_list[i]->paymentDue << ", Last visit: " << customer_list[i]->lastVisit << std::endl;
            for(auto j=0; j<customer_list[i]->service.size(); j++){
                if (j == 0){
                    std::cout << "~~~|| Services done: ||~~~" << std::endl;
                }
                std::cout << customer_list[i]->service[j] << std::endl;
            }
            //std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            for(auto j=0; j<customer_list[i]->partsChanged.size(); j++){
                if (j == 0){
                    std::cout << "~~~|| Parts changed: ||~~~" << std::endl;
                }
                std::cout << customer_list[i]->partsChanged[j] << std::endl;
            }
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                
        }
    }
    
    
    ~carServiceShop(){
        for (auto i = 0; i < customer_list.size(); ++i) {
            delete customer_list[i];
        }
        customer_list.clear();
    };
};

void newCustomer(carServiceShop &shop){
    std::string newCustomerName;
    std::cout << "What is the name of the customer? :" << std::endl;
    std::cin.ignore();
    getline(std::cin, newCustomerName);
    
    std::cout << newCustomerName << std::endl;
    shop.new_cust(newCustomerName);
} 

//ToDo: Change the choices to get info from obj
void newService(carServiceShop &shop){
    unsigned int date = 0;
    unsigned int choice;
    unsigned int choice_2;

    std::cin.ignore();
    std::cout << "Please choose customer: " << std::endl;
    for (auto i=0; i<shop.customer_list.size(); i++){
        std::cout << i+1 << ". " << shop.customer_list[i]->name << std::endl;
    }
    std::cin >> choice;
    std::cout << "What type of service? " << std::endl;
    std::cout << "1. Oil change \n2. Air filter change" << std::endl;
    std::cin >> choice_2;
    std::cout << "Please type in date of service (YYMMDD): " << std::endl;
    std::cin >> date;
    if (choice_2 == 1){
        oilChange oil(date);
        shop.customer_list[choice-1]->service.push_back(oil.service_name);
        shop.customer_list[choice-1]->paymentDue += oil.cost;
        shop.customer_list[choice-1]->lastVisit = oil.date;
    }
    else if (choice_2 == 2){
        changeAirFilter filter(date);
        shop.customer_list[choice-1]->service.push_back(filter.service_name);
        shop.customer_list[choice-1]->paymentDue += filter.cost;
        shop.customer_list[choice-1]->lastVisit = filter.date;
    }
    
    //std::cout << shop.customer_list[choice-1]->name << std::endl;

}
//ToDo: Change the choices to get info from obj
void partChange(carServiceShop &shop){
    unsigned int date = 0;
    unsigned int choice;
    unsigned int choice_2;

    std::cin.ignore();
    std::cout << "Please choose customer: " << std::endl;
    for (auto i=0; i<shop.customer_list.size(); i++){
        std::cout << i+1 << ". " << shop.customer_list[i]->name << std::endl;
    }
    std::cin >> choice;
    std::cout << "What type of part to change? " << std::endl;
    std::cout << "1. Muffler \n2. Tires" << std::endl;
    std::cin >> choice_2;
    std::cout << "Please type in date of part change (YYMMDD): " << std::endl;
    std::cin >> date;
    if (choice_2 == 1){
        replaceMuffler muffler(date);
        shop.customer_list[choice-1]->partsChanged.push_back(muffler.part_changed);
        shop.customer_list[choice-1]->paymentDue += muffler.cost;
        shop.customer_list[choice-1]->lastVisit = muffler.date;
    }
    else if (choice_2 == 2){
        replaceTires tires(date);
        shop.customer_list[choice-1]->partsChanged.push_back(tires.part_changed);
        shop.customer_list[choice-1]->paymentDue += tires.cost;
        shop.customer_list[choice-1]->lastVisit = tires.date;
    }
}
//ToDo: Change the choices to get info from obj
void payment(carServiceShop &shop){
    unsigned int date = 0;
    unsigned int choice;
    unsigned int choice_2;
    int amount;

    std::cin.ignore();
    std::cout << "Please choose customer: " << std::endl;
    for (auto i=0; i<shop.customer_list.size(); i++){
        std::cout << i+1 << ". " << shop.customer_list[i]->name << std::endl;
    }
    std::cin >> choice;
    std::cout << shop.customer_list[choice-1]->name << " have: " << shop.customer_list[choice-1]->paymentDue << " left to pay." <<std::endl;
    std::cout << "Payment method? " << std::endl;
    std::cout << "1. Card \n2. Cash" << std::endl;
    std::cin >> choice_2;
    std::cout << "Enter amount to pay: " << std::endl;
    std::cin >> amount;
    
    std::string pMethod;
    if (choice_2 == 1){
        cardPayment card;
        shop.customer_list[choice-1]->paymentDue -= amount;
        pMethod = shop.customer_list[choice-1]->payWith = card.paymentType;
    }
    else if (choice_2 == 2){
        cashPayment cash;
        shop.customer_list[choice-1]->paymentDue -= amount;
        pMethod = shop.customer_list[choice-1]->payWith = cash.paymentType;
    }
    std::cout << "Customer: " << shop.customer_list[choice-1]->name << " Payed: " << amount << ", Using: " << pMethod << std::endl;
    std::cout << "Left to pay: " << shop.customer_list[choice-1]->paymentDue << std::endl;
}

int main(){

    //Create a menue of choices, then there must be new stuff

    carServiceShop shop;

    unsigned int choice = 1;
    
    while (choice)
    {
        std::cout << "What do you want to do?" << std::endl;
        std::cout << "1. New customer \n2. New service \n3. Part change \n4. Payment \n0. Exit" << std::endl;
        std::cin >> choice;
        //std::cout << choice << std::endl;
        if (choice == 1){
            newCustomer(shop);
        }
        else if (choice == 2){
            newService(shop);
        }
        else if (choice == 3){
            partChange(shop);
        }
        else if (choice == 4){
            payment(shop);

        }
    }
    shop.print();

    return 0;
}