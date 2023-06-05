#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <map>

class backend {

    //Constructor
    public:
        backend() {
            //Initialize the array
            // for (int i = 0; i < 10; i++) {
            //     str[i] = "";
            // }
        }
        
    public:
        //Enum for menu options
        enum menu {DISPLAY = 1, ADD, REMOVE, QUIT};

        //MAP for item storage
        std::map<int, std::string> items;
        std::map<int, std::string>::iterator itr;

        //Main variables
        int choice = 0;
        int index = 0;
        std::string confirm = "";

        //Variables of items
        std::string word = "";
        std::string count = "";

        //Function prototypes
        void add(std::string word, std::string count);
        void remove(int index);
        void display();
        
    private:
        //...
};