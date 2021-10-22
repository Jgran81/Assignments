#include <iostream>
#include <bitset>
#include <bit>
#include <cstring>

struct field{
    unsigned lights:3;
    unsigned doors:4;
    unsigned windows:4;
    unsigned seatbelts:5;
};

void maskFunc(uint16_t data, uint16_t mask[], int arr[]){
    std::cout << "Seat belts: " << std::bitset<5>((data & mask[0]) >> arr[0]) << std::endl;
    std::cout << "Windows: " << std::bitset<4>((data & mask[1]) >> arr[1]) << std::endl;
    std::cout << "Doors: " << std::bitset<4>((data & mask[2]) >> arr[2] ) << std::endl;
    std::cout << "Lights: " << std::bitset<3>(data & mask[3]) << std::endl;
}


int main(){
    int array[4] = {11, 7, 3, 0};
    uint16_t Data = {0b1011101001011011};
    uint16_t MASK[4] = {0b1111100000000000, 0b0000011110000000, 0b0000000001111000, 0b0000000000000111};
    maskFunc(Data, MASK, array);

    field a;// = *(reinterpret_cast<field*>(&Data));
    memcpy(&a,&Data,sizeof(field));
    std::cout << "Seatbelts: " << std::bitset<5>(a.seatbelts) << '\n';
    std::cout << "Windows: " << std::bitset<4>(a.windows) << '\n';
    std::cout << "Doors: " << std::bitset<4>(a.doors) << '\n';
    std::cout << "Lights: " << std::bitset<3>(a.lights) << '\n';    

    return 0;
}