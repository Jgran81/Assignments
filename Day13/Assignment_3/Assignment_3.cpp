#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

//Check guess agains the middle number, larger or smaller. 512
//Move checker up or down 256, 128, 64, 32, 16, 4, 2


int main(){

    //Set s and iterator it1
    std::set<int> s;
    std::set<int>::iterator it1; 
    int rNum = 0;

    //Populating the set:
    for(int i=0; i<1024; i++){
        rNum = rand();
        s.insert(rNum);
    }
    //Random number:
    int guess = rand();
    //Setting the iterator for number above the guess number
    it1 = s.lower_bound(guess);
    
    //For printing number in list:
    /* std::for_each(s.cbegin(), s.cend(), [](int x) {
    std::cout << x << std::endl;
    }); 
    std::cout << std::endl; */

    std::cout << "Random number: " << guess << std::endl;
    std::cout << "Number above: " << *it1 << std::endl;
    //Setting the iterator for number bellow guess:
    it1--;
    std::cout << "Number bellow: " << *it1 << std::endl;
    
    return 0;
}

/* Random number: 386839851
Number above: 387346491
Number bellow: 384370888 */