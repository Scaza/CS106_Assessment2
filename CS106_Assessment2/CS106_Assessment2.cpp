// CS106_Assessment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Damaged {                                                                       //Simple enum that allows the user to indicate whether or not the damage is software/Hardware related

    SOFTWARE,
    HARDWARE,
    BOTH
};

class incident_category {                                                                                           //Inceident category to describe broken features of the iphone
    private:
        string details;
        Damaged device_part;
    public:
    
        incident_category(string categoryName, Damaged user_inputted_device_part) {
            details = categoryName;
            
        }
    
        const string getName (){
            return details;
        }
};

class Ticket{                                                                                               //Ticket with appropriate asssociated details as specified within the brief
private:
    string name;
    int ticket_number;
    incident_category user_input;
        bool solved;
public:

    string getName() {                                                                                      //method to access the name from outside of the function 
        return name;
    }

    int getNumber() {                                                                                       
        return ticket_number;
    }

    bool isSolved() {
        return solved;
    }


};

class User {                                                                        //class that will store user information and all related inf
private:

    string name;
    string password;
    vector<Ticket> tickets;

public:
    User(string userName, string userPassword)
        :name(userName), password(userPassword)
    {
        cout << "User Created: " << name << endl;
    }
    void addTicket(Ticket ticket) {
        tickets.push_back(ticket);
        cout << "Ticket Added: " << ticket.getName() << " to user: " << name << endl;
    }
    void showTickets() {                                                                                            //method of displaying all 
        cout << "Displaying Tickets for user: " << name << endl;

        for (Ticket ticket : tickets) {
            cout << "Ticket Name: " << ticket.getName()
                << ", Ticket Number: " << ticket.getNumber()
                << ", Ticket Status: " << (ticket.isSolved() ? "Solved" : "Unsolved")
                << endl;
        }

    }



    int main()
    {

        vector<User> Users;                                                                                                          //Intialising a vector of user class so that accounts can be stored with their information and edited as required
        bool run = true;

        while (run) {                                                                                                                                           //Outer most while loop that will control the number of iterations that the program runs for.

            cout << "Welcome to the phone repair helpdesk!" << endl;
            cout << "In order to get started please select an account to log into or create an account to use! " << endl;
            cout << "***************************************************************************************** " << '\n' << endl;

            cout << "Would you like to: " << '\n' << endl;
            cout << "1.Create an account" << endl;
            cout << "2.Log into an existing account" << endl;
            cout << "3.Exit" << '\n' << endl;

            int user_input;

            while (!(cin >> user_input) || user_input != 1 && user_input != 2 && user_input != 3) {
                cin.clear();
                cin.ignore(123, '\n');
                cout << "Please input a valid input from the options selection! " << '\n' << endl;
            }

            if (user_input == 1) {

            }
            else if (user_input == 2) {

            }
            else if (user_input == 3) {

            }



        }

        return 0;
    }


