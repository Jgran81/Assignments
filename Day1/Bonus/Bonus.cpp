//Write a program which can guess the number that user is thinking of –between 1-128 –you can ask anything you
//want up to 7 times.

#include <iostream>

int main(){

    unsigned int maxNum = 128;
    unsigned int minNum = 1;
    char reply = 'y';
    int guesses = 0;


    std::cout << "Think of a number between 1 and 128" << std::endl; 

    while(maxNum != minNum){
        std::cout << "Is you number bigger then " << (maxNum+minNum)/2 << " ? (y/n)" << std::endl;
        std::cin>>reply;
        if(reply=='y'){
            minNum = (maxNum+minNum)/2 - 1;
        }
        else{
            maxNum = (maxNum+minNum)/2;
        }
        guesses += 1;
        std::cout << "Guess number: " << guesses << std::endl;
        std::cout<<"Min number: " << minNum << std::endl;
        std::cout<<"Max number: " << maxNum << std::endl;
    }
    std::cout<<"Number of guesses: " << guesses << std::endl;
    std::cout << "Your number is: " << (maxNum) << std::endl;



}