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

    string getName() {                                                                                      //Get name
        return name;
    }

    int getNumber() {                                                                                        //Get number
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
    bool run = true;

    while (run) {
    
        cout << "Welcome to the phone repair helpdesk!"
    
    
    }
    

    return 0;
}


