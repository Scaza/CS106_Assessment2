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
            device_part = user_inputted_device_part;
            
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

public:
    Ticket(string tName, int tNum, incident_category inc, bool isSolved)
        : name(tName), ticket_number(tNum), user_input(inc), solved(isSolved) {}

    string getName() const { return name; }
    int getNumber() const { return ticket_number; }
    bool isSolved() const { return solved; }
        // Initialized all the member variables in constructor
    
};

class User {                                                                        //class that will store user information and all related inf
protected:

    string name;
    string password;
    vector<Ticket> tickets;

public:

    User(string userName, string userPassword)
        :name(userName), password(userPassword)
    {
        cout << "User Created: " << name << endl;
    }

    string getUsername() {
        return name;
    }

    string getPassword() {
        return password;
    }

    void addTicket(Ticket ticket) {
        tickets.push_back(ticket);
        cout << "Ticket Added: " << ticket.getName() << " to user: " << name << endl;
    }
   virtual void showTickets() {                                                                                            //method of displaying all 
        cout << "Displaying Tickets for user: " << name << endl;

        for (Ticket ticket : tickets) {
            cout << "Ticket Name: " << ticket.getName()
                << ", Ticket Number: " << ticket.getNumber()
                << ", Ticket Status: " << (ticket.isSolved() ? "Solved" : "Unsolved")
                << endl;
        }

    }
   

};

class HelpDeskOperator : public User {
public:
    HelpDeskOperator(string name, string password) : User(name, password) {
        cout << "HelpDesk Operator Created: " << getUsername() << endl;
    }

    
};

class SupportTechnician : public User {
public:
    SupportTechnician(string name, string password) : User(name, password) {
        cout << "Support Technician Created: " << getUsername() << endl;
    }

    
};





int main()
{

    vector<User*> Users;                     //Intialising a vector of user class so that accounts can be stored with their information and edited as required
    bool run = true;
    int user_input;
    bool isLoggedIn = true;

    while (run) {                                                                                                                                           //Outer most while loop that will control the number of iterations that the program runs for.

        cout << "Welcome to the phone repair helpdesk!" << endl;
        cout << "In order to get started please select an account to log into or create an account to use! " << endl;
        cout << "***************************************************************************************** " << '\n' << endl;

        cout << "Would you like to: " << '\n' << endl;
        cout << "1.Create an account" << endl;
        cout << "2.Log into an existing account" << endl;
        cout << "3.Exit" << '\n' << endl;


        while (!(cin >> user_input) || user_input != 1 && user_input != 2 && user_input != 3) {
            cin.clear();
            cin.ignore(123, '\n');
            cout << "Please input a valid input from the options selection! " << '\n' << endl;
        }

        if (user_input == 1) {

            //create an account

            // get username and password from user
            string userName, password;
            cout << "\nEnter username:";
            cin >> userName;
            cout << "Enter Password : ";
            cin >> password;

            // Ask for role of the user
            cout << "Enter your role (1 for User, 2 for HelpDesk Operator, 3 for Support Technician): ";
            int role;
            cin >> role;

            //create a new user and add to the Users vector base on their role
            User* newUser = nullptr;
            if (role == 1) {
                newUser = new User(userName, password);
            }
            else if (role == 2) {
                newUser = new HelpDeskOperator(userName, password);
            }
            else if (role == 3) {
                newUser = new SupportTechnician(userName, password);
            }

            if (newUser != nullptr) {
                Users.push_back(newUser);
                cout << "Account created successfully!\n";
            }
        }
    
        else if (user_input == 2) {
            // Log in an Existing Account

            //get userdane and password from user
            string userName, password;
            cout << "\nEnter username:";
            cin >> userName;
            cout << " Enter password:";
            cin >> password;

            // Find the user in User vector
            bool userFound = false;
            User* currentUser = nullptr;
            for (User* user : Users) {
                if (user->getUsername() == userName) {
                    userFound = true;
                    // If user is found, then check the password

                    if (user->getPassword() == password) {
                        cout << "User logged in successfully!\n";
                        currentUser= user;
                        break;
                        // user is logged in now and can perform other operations 
                        //such as creating,cosing or viewing tickets.

                    }
                    else {
                        cout << "Incorrect password!\n";
                    }
                    break;
                }
            }
            if (!userFound) {
                cout << "User not found!\n";
                continue;
            }
            // User logged in, provide a functionality menu
            

            while (isLoggedIn) {
                cout << "\n======= MENU =======";
                cout << "\n1. Show my Tickets";
                cout << "\n2. Add a Ticket";
                cout << "\n3. Logout";
                cout << "\n====================";
                cout << "\nEnter your choice: ";
                cin >> user_input;

                switch (user_input) {
                case 1:
                    currentUser->showTickets();
                    break;
                case 2:
                {
                    //add a ticket.
                    string ticketName;
                    int ticketNum;
                    int categoryNum;
                    bool solved;

                    cout << "Enter ticket name: ";
                    cin >> ticketName;
                    cout << "Enter ticket number: ";
                    cin >> ticketNum;
                    cout << "Choose incident category: 1 for SOFTWARE, 2 for HARDWARE, 3 for BOTH: ";
                    cin >> categoryNum;
                    cout << "Is it solved? 0 for No, 1 for Yes: ";
                    cin >> solved;

                    Damaged category = static_cast<Damaged>(categoryNum - 1);
                    currentUser->addTicket(Ticket(ticketName, ticketNum, incident_category("Broken Screen", category), solved));
                    break;
                }
                case 3:
                    // Logout
                    cout << "Logged out successfully!\n";
                    isLoggedIn = false;
                    break;
                default:
                    cout << "Invalid choice!\n";
                    break;
                }
        }
            //Exit
            run = false;
        }
    }

    for (User* user : Users) {
        delete user;
    }
    Users.clear();

    return 0;
    
}


