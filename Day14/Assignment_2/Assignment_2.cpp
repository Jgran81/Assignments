#include <iostream>
#include <bitset>
#include <bit>



std::bitset<16> decode(int setValues[]){
    int div[5] = {20,150, 150, 150, 150};
    int pos[5] = {12, 9, 6, 3, 0};
    
    std::bitset<16> data(0);
    
    for(int i=0; i<5; i++){
        std::bitset<16> set((setValues[i]/div[i]) << pos[i]);
        data = data | set;
       
    }
    return data;
}
    //1011101001011011
int main(){

    int speed = 220;
    int frontDist = 750;
    int rearDist = 150;
    int rightDist = 450;
    int leftDist = 450;

    int *setValues[5] = {&speed, &frontDist ,&rearDist, &rightDist, &leftDist};
    std::cout << decode(*setValues) << std::endl;
    

    return 0;
}