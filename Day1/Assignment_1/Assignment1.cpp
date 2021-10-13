/*Write a program which takes a positive number from user, and then fill in a 3-dimensional array of size [8,9,11]
with random positive numbers smaller than the one user has provided –pretty print the array.
Modify your first assignment from yesterday to receive the dimensions of the arrays from the user.*/

#include <iostream>

// unsigned int numArray[8][9][11];
unsigned int userInput = 0;
unsigned int randomValue = 0;
int main(){

    int arraySize_1D = 8;
    int arraySize_2D = 9;
    int arraySize_3D = 11;

    int ***numArray = new int **[arraySize_1D];

    for(size_t i = 0; i < arraySize_1D ; i++){
        numArray[i] = new int*[arraySize_2D];

        for(size_t j = 0; j < arraySize_2D; j++){
            numArray[i][j] = new int[arraySize_3D];
            
        }
    }
       
    
    std::cout<< "Enter a number: " <<std::endl;
    std::cin>>userInput;
    for(int i = 0; i<8 ; i++){
        for(int j = 0; j < 9; j++){
            for(int k = 0; k < 11; k++){
                randomValue = rand() % userInput;
                numArray[i][j][k] = randomValue;
                if(k<1){
                    std::cout<<"[ ";
                }
                std::cout << numArray[i][j][k] << "\t";
            }
            std::cout<<"]" << std::endl;
            
        }
        std::cout << std::endl;
    } 
    for(int i = 0; i < arraySize_1D; i++){
        for(int j = 0; j < arraySize_2D; j++){
            delete[] numArray[i][j];
        }
        delete[] numArray[i];
    }
    delete[] numArray;

    return 0;
    
}