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

class incident_category {
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

class tickets {
    private:
       string name;
       int ticket_number;
       incident_category user_input;
       bool solved;
};

class user {                                                                        //class that will store user information and all related inf
private:
    
    string name;
    string password;
    vector<tickets> tickets;

public:
    
};

int main()
{
    

    return 0;
}


