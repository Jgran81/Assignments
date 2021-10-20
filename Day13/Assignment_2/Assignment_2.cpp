#include <iostream>
#include <map>



int main()
{
    std::map<int,int> list;

    unsigned int rNum = 0;
    for(int i=0; i<10000; i++){
        rNum = rand() % 33;
        list[rNum]+=1;
    }
    
    for(int i=0; i<33; i++){
        std::cout << "Number: " << i << " is called: " << list.at(i) << " times"<< std::endl;;
    }
   
    return 0;
}