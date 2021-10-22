#include <iostream>
#include <fstream>
#include <map>

//Write a program which receives the name of two text files as input argument. 
//The program shall count the number of occurrences of the words of the first 
//file, in the second file, and then print the result at the end of the
//secondfile.

//ofstream  -   Stream class to write to file
//ifstream  -   Stream class to read from file
//fstream   -   Stream class to read/write from/to file

//argv shall take two files as input
int main(int argc, char* argv[]){
    //1. Read information from one file, word by word   -- Done!
    //2. Add the word to map    -- Done!
    //3. Read info from second file, word by word and add them to list -- Done!
    //4. Print list to second file -- Done!
    //5. Open files from command line. Done!
    
    //input word to add to wordList of map type
    std::string word;
    std::map<std::string,int> wordList;
    
    //Input classes
    std::ifstream input1;   //Reading first file
    std::ifstream input2;   //Reading second file
    std::ofstream output;   //Writing to second file

    input1.open(argv[1]);   //Open first file
    if (!input1.is_open()){
        std::cout << "Input file is not open." << std::endl;
        return 0;
    }
    while (input1 >> word){     //Looping through words in file
        wordList[word]+=1;      //Add word as key and add to value in map
    }
   
    //std::cout << wordList.size() << std::endl;
    
    input1.close();     //Close first file

    input2.open(argv[2]);  //Open second file as read
    if (!input2.is_open()){
        std::cout << "Input file is not open." << std::endl;
        return 0;
    }
    
    while (input2 >> word){     //Looping through words in file
        wordList[word]+=1;      //Add word as key and add to value in map
    }
    input2.close();             //Close second file
    output.open(argv[2], std::ios_base::app);  //Open second file as write in append mode
    if (!output.is_open()){
        std::cout << "Output file is not open." << std::endl;
        return 0;
    }
    output << std::endl;    //Adding new line to file

    for (auto& x: wordList) {   //Looping the map list and print the key and value
        output << x.first << ": " << x.second << std::endl;
    }
    output.close();     //Close second file
    

    return 0;
}