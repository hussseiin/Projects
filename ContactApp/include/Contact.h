#ifndef CONTACT_H
#define CONTACT_H
#include <User.h>
#include <Phone.h>
#include <Address.h>
#include <Email.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Contact
{
    public:

        void add_user();
        void edit();
        bool search();
        void number();
        void show_all();
        void delete_user();

            //default
        Contact(int);
        virtual ~Contact();

    protected:

    private:

        User* user;

        int size;


        static int Aliascounter;

        static int counter;

        string input;

};

#endif // CONTACT_H
