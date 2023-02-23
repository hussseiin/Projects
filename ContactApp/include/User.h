#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
#include "Phone.h"
#include "Email.h"
#include "Address.h"
using namespace std;

class User
{
    public:

            //setters
        void set_id(int);
        void set_fname(string);
        void set_lname(string);
        void set_gender(string);
        void set_city(string);
        void set_addedDate(string);

            //getters
        int get_id();
        string get_fname();
        string get_lname();
        string get_gender();
        string get_city();
        string get_addedDate();

            //phone manipulation
        void add_phone();
        void edit_phone();
        void delete_phone();
        bool search_Phone();

            //email manipulation
        void add_email();
        void edit_email();
        void delete_email();
        bool search_email();

            //address manipulation
        void add_address();
        void edit_address();
        void delete_address();
        bool search_address();

        void show();

            //defalut
        User();
        virtual ~User();

    protected:

    private:
        int id;
        string fname;
        string lname;
        string gender;
        string city;
        string addedDate;
        Phone* phone;
        Email* email;
        Address* address;

        string input; // for function
};

#endif // USER_H
