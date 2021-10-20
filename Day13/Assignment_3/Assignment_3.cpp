#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>


int main(){

    std::set<int> s;
    std::set<int>::iterator it1, it2; 
    int rNum = 0;
    for(int i=0; i<32; i++){
        rNum = rand() % 1000;
        s.insert(rNum);
    }
    int guess = 500;
    std::set<int> t = s;
    //std::cout << "middle: " << *s.find() << std::endl;
    /* std::set<int> itlow = s.lower_bound (30);                
    itup=s.upper_bound (60);  */
    /* 
    std::cout << guess << std::endl;
    s.erase(s.lower_bound(500), s.cend() ); */
    //it1 = t.begin(); 
    it2 = t.end();
    for(int i=0; i<16; i++){
        it2--;
    }
    t.erase(it2, t.cend() );
    std::cout << *--t.end() << std::endl;
    if(guess > *--t.end()){
        it2 = s.end();
        for(int i=0; i<16; i++){
        it2--;
    }
    }
    
    //std::cout << s.lower_bound() << std::endl;
    
    std::for_each(s.cbegin(), s.cend(), [](int x) {
    std::cout << x << std::endl;
    }); 
    std::cout << std::endl;
    std::for_each(t.cbegin(), t.cend(), [](int x) {
    std::cout << x << std::endl;
    }); 
    //std::cout << s.size() << std::endl;
    /* auto a = s.lower_bound(500);
    auto b = s.upper_bound(500);
    std::cout << *a << " : " << *b << std::endl; */ 
    return 0;
}