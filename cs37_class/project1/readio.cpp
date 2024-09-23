#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

const int MAX_USERS = 30;

// struct to hold the use informatons
struct UserAccount {
    std::string username;
    std::string country;
    int age;
    double accountBalance;
};

int main() {
    UserAccount users[MAX_USERS];
    int userCount = 0;

    // this just displaying the instructions
    std::cout << "Please enter information to database in the format of <username> <country> <age> <accountBalance>, separated each user by a newline:" << std::endl;
    std::cout << "Type ***Ctrl + D*** to exit the input phase :) (I had to google this I did not this was a thing thats cool)" << std::endl;

    // this read the input by the uyser
    while (userCount < MAX_USERS && std::cin >> users[userCount].username >> users[userCount].country >> users[userCount].age >> users[userCount].accountBalance) {
        userCount++;
    }

    // proccesses user info
    double highestBalance = std::numeric_limits<double>::min();
    double totalBalance = 0;
    int haitians = 0;
    bool youngerThan21 = false;

    for (int i = 0; i < userCount; i++) {
        // highest account balance
        if (users[i].accountBalance > highestBalance) {
            highestBalance = users[i].accountBalance;
        }

        // sum of account balances
        totalBalance += users[i].accountBalance;

        // haitian users
        if (users[i].country == "Haiti") {
            haitians++;
        }

        // people who can't drink in USA yet lol
        if (users[i].age < 21) {
            youngerThan21 = true;
        }
    }

    // all the output!
    std::cout << std::fixed;
    std::cout << "Q: What is the highest account balance among all users?" << std::endl;
    std::cout << "A: $" << std::setprecision(1) << highestBalance << std::endl;

    std::cout << "Q: What's the sum of account balance of all users?" << std::endl;
    std::cout << "A: $" << std::setprecision(2) << totalBalance << std::endl;

    std::cout << "Q: How many users come from Haiti?" << std::endl;
    std::cout << "A: " << haitians << std::endl;

    std::cout << "Q: Do we have any user younger than 21?" << std::endl;
    std::cout << "A: " << (youngerThan21 ? "Yes" : "No") << std::endl;

    return 0;

    //c++ is so fun yay! (I cried 3 times writing this)
}
