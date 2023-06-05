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

//Instance for class "backend"
backend bcknd;

//Class for main
class derived : public backend
{
    private:
        /* data */
    public:
        void display(){
            if (!items.empty())
            {
                //Display the items
                std::cout << "Items:" << std::endl;
                for (itr = items.begin(); itr != items.end(); ++itr)
                {
                    //Display the item
                    std::cout << itr->first << " - " << itr->second << std::endl;
                }
            }else{
                std::cout << "No items!" << std::endl;
            }
            
        }
        void add(std::string word, std::string count){
            //Add the word & count to the array
            int index = items.size() + 1;
            word += " > " + count;
            items.insert(std::pair<int, std::string>(index, word));
        }
        void remove(int index){
            //Remove the word from the array
            items.erase(index);

            //Shift the items
            int range = items.size();
            for (int i = index; i <= range; i++)
            {
                items[i] = items[i + 1];
            }
            items.erase(range + 1);
        }
};

//Instance for class "backend"
derived logic;

//Array of numbers, list of menu options
int nums[4] = {logic.DISPLAY, logic.ADD, logic.REMOVE, logic.QUIT};

void displayMenu() {
    //Display the menu
    std::cout << logic.DISPLAY << ". Display the list" << std::endl;
    std::cout << logic.ADD << ". Add an item" << std::endl;
    std::cout << logic.REMOVE << ". Remove an item" << std::endl;
    std::cout << logic.QUIT << ". Quit" << std::endl;
    std::cout << "Enter your choice: ";
}

void getChoice() {
    //Get the user's choice
    std::cin >> logic.choice;
}

void addWord() {
    //Clear the screen
    system("cls");

    //Add the word
    logic.add(logic.word, logic.count);
    
    //Display a success message
    std::cout << "Item added!" << std::endl;
    //Pause the program
    system("pause");
}

void removeWord() {
    //Get the word to remove
    std::cout << "Enter the index of the item to remove: ";
    std::cin >> logic.index;
    if(logic.items.empty()){
        std::cout << "No items!" << std::endl;
        system("pause");
    }else{
        //Remove the word
        logic.remove(logic.index);
        //Display a success message
        std::cout << "Item removed!" << std::endl;
        //Pause the program
        system("pause");
    }
}

void confirmItem() {
    system("cls");
    //Confirm the item
    std::cout << "Item: " << logic.word << std::endl;
    std::cout << "Count: " << logic.count << std::endl;
    std::cout << "Is this correct? (y/n): ";
    std::cin >> logic.confirm;
    //If the user says no
    if (logic.confirm == "n") {
        //Get the word to add
        std::cout << "Enter a word to add: ";
        std::cin >> logic.word;
        std::cout << "Enter how many of the item: ";
        std::cin >> logic.count;
        //Add the word
        addWord();
    }
    //If the user says yes
    else if (logic.confirm == "y") {
        //Add the word
        addWord();
    }
    //If the user enters an invalid choice
    else {
        //Display an error message
        std::cout << "Invalid choice!" << std::endl;
        //Pause the program
        system("pause");
    }
}

void runOption(){
    //Switch statement for the user's choice
    switch (logic.choice) {
        //Display the list
        case logic.DISPLAY:

            //Display the list
            system("cls");

            //Display the items
            logic.display();
            
            //Pause the program
            system("pause");

            break;
        //Add a word
        case logic.ADD:

            //Clear the screen
            system("cls");

            //Get the word to add
            std::cout << "Enter a word to add: ";
            std::cin >> logic.word;
            std::cout << "Enter how many of the item: ";
            std::cin >> logic.count;

            //Add the word
            confirmItem();

            break;
        //Remove a word
        case logic.REMOVE:

            //Clear the screen
            system("cls");

            //Get the list of items
            logic.display();

            //Remove the word
            removeWord();

            break;
        //Quit
        case logic.QUIT:

            //Quit
            std::cout << "Goodbye!" << std::endl;

            //Pause the program
            system("pause");

            //Exit the program
            exit(0);

            break;
        //Invalid choice
        default:

            //Display an error message
            std::cout << "Invalid choice!" << std::endl;

            //Pause the program
            system("pause");
            
            break;
    }
}

//Main function
int main() {

    //Clear the screen
    system("cls");
    
    //Display the menu
    displayMenu();

    //Get the user's choice
    getChoice();

    //Run the user's choice
    runOption();
    main();

    //Return 0
    return EXIT_SUCCESS;
}