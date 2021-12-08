#include <iostream>
#include <map>
#include <algorithm>



int main()
{
    //1. Insert rand numbers in vector
    //2. Move values to multimap
    std::map<int,int> list;

    unsigned int rNum = 0;
    for(int i=0; i<10000; i++){
        rNum = rand() % 33;
        list[rNum]+=1;
    }
    //std::sort(begin(list), end(list), comp);
    
    for(int i=0; i<33; i++){
        std::cout << "Number: " << i << " is called: " << list.at(i) << " times"<< std::endl;;
    }
   
    return 0;
}