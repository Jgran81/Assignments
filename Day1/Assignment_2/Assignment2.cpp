#include <iostream>

int key = 19;
std::string chiper = "VKRIMHZKTIAR";


int main(){

    for(char c: chiper){
        char a = c - key;
        //std::cout << a;
    
        if(a>='A'){
            std::cout << a ;
        }
        else{
            char aa = a + ('Z' - 'A' + 1);
                       
            std::cout << aa;
        }
        
    }
    std::cout<<std::endl;

    


}