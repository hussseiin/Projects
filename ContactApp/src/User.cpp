#include "User.h"
        //constructor
User::User(){
    id = -1;
    fname = "";
    lname = "";
    gender = "";
    city  = "";
    addedDate = "";
    phone = new Phone [5];
    email = new Email[5];
    address = new Address[5];
}

        //destructor
User::~User(){
    delete [] phone;
    delete [] email;
    delete [] address;
}

        //add  phone
void User::add_phone(){

    char c;

    for(int i = 0 ; i < 5 ; i ++){


        cout<<"  PHONE : "; getline(cin,input);     phone[i].set_phone(input);
        cout<<"  TYPE : ";  getline(cin,input);     phone[i].set_type(input);
        cout<<"  DESCRIPTION : ";   getline(cin,input); phone[i].set_desc(input);

        cout<<"  ANOTHER PHONE ? Y/N : ";   cin>>c;

        if(c == 'y' || c == 'Y'){
            cin.ignore();
            continue;
        }
        else
            break;
    }
    cin.ignore();
}

        //add email
void User::add_email(){

    char c;

    for(int i = 0 ; i < 5 ; i ++){

        cout<<"  EMAIL : "; getline(cin,input);     email[i].set_email(input);
        cout<<"  TYPE : ";  getline(cin,input);     email[i].set_type(input);
        cout<<"  DESCRIPTION : ";   getline(cin,input); email[i].set_desc(input);

        cout<<"  ANOTHER PHONE ? Y/N : ";   cin>>c;

        if(c == 'y' || c == 'Y'){
            cin.ignore();
            continue;
        }
        else
            break;
    }
    cin.ignore();
}

        //add address
void User::add_address(){

    char c;


    for(int i = 0 ; i < 5 ; i ++){


        cout<<"  ADDRESS : "; getline(cin,input);     address[i].set_place(input);
        cout<<"  TYPE : ";  getline(cin,input);     address[i].set_type(input);
        cout<<"  DESCRIPTION : ";   getline(cin,input); address[i].set_desc(input);

        cout<<"  ANOTHER ADDRESS ? Y/N : ";   cin>>c;

        if(c == 'y' || c == 'Y'){
            cin.ignore();
            continue;
        }
        else
            break;
    }
}

        //edit phone
void User::edit_phone(){
    if (phone[0].get_phone() == "")
        cout<<"  NO PHONE INSERTED\n";

    cout<<"  PHONE TO BE EDITED : "; cin>>input;
    cin.ignore();

    for(int i = 0 ; i < 5 ; i++){
        if(phone[i].get_phone() == input){
            cout<<"  NEW PHONE : "; getline(cin,input);  phone[i].set_phone(input);
            cout<<"  TYPE : ";  getline(cin,input);     phone[i].set_type(input);
            cout<<"  DESCRIPTION : ";   getline(cin,input); phone[i].set_desc(input);
            break;
        }

        else if(i == 4)
            cout<<"  NO MATCHING PHONE\n";
    }
}

        //edit email
void User::edit_email(){
    if (email[0].get_email() == "")
        cout<<"  NO PHONE INSERTED\n";


    cout<<"  EMAIL TO BE EDITED : "; cin>>input;
    cin.ignore();

    for(int i = 0 ; i < 5 ; i++){
        if(email[i].get_email() == input){
            cout<<"  NEW EMAIL : "; getline(cin,input);  email[i].set_email(input);
            cout<<"  TYPE : ";  getline(cin,input);     email[i].set_type(input);
            cout<<"  DESCRIPTION : ";   getline(cin,input); email[i].set_desc(input);
            break;
        }

        else if(i == 4)
            cout<<"  NO MATCHING EMAIL\n";
    }
}

        //edit address
void User::edit_address(){
    if (address[0].get_place() == "")
        cout<<"  NO ADDRESS INSERTED\n";


    cout<<"  ADDRESS TO BE EDITED : "; cin>>input;
    cin.ignore();

    for(int i = 0 ; i < 5 ; i++){
        if(address[i].get_place() == input){
            cout<<"  NEW PHONE : "; getline(cin,input);  address[i].set_place(input);
            cout<<"  TYPE : ";  getline(cin,input);     address[i].set_type(input);
            cout<<"  DESCRIPTION : ";   getline(cin,input); address[i].set_desc(input);
            break;
        }

        else if(i == 4)
            cout<<"  NO MATCHING PHONE\n";
    }
}

        // delete phone
void User::delete_phone(){

    if(phone[0].get_phone() == ""){
        cout<<"  NO PHONE INSERTED\n";
        return;
    }

    cout<<"  PHONE TO BE DELETED : "; getline(cin,input);

    for(int i = 0 ; i < 5 ; i++){
        if(!input.compare(phone[i].get_phone())){
            phone[i] = {};
            return;
        }

        else if(i == 4)
            cout<<"  NO MATCHING PHONE\n";
    }

}

        //delete email
void User::delete_email(){

    if(email[0].get_email() == ""){
        cout<<"  NO PHONE INSERTED\n";
        return;
    }

    cout<<"  EMAIL TO BE DELETED : "; getline(cin,input);

    for(int i = 0 ; i < 5 ; i++){
        if(!input.compare(email[i].get_email())){
            email[i] = {};
            return;
        }

        else if(i == 4)
            cout<<"  NO MATCHING EMAIL\n";
    }

}

        //delete address
void User::delete_address(){

    if(address[0].get_place() == ""){
        cout<<"  NO PHONE INSERTED\n";
        return;
    }

    cout<<"  ADDRESS TO BE DELETED : "; getline(cin,input);

    for(int i = 0 ; i < 5 ; i++){
        if(!input.compare(address[i].get_place())){
            phone[i] = {};
            return;
        }

        else if(i == 4)
            cout<<"  NO MATCHING ADDRESS\n";
    }

}

        //phone search
bool User::search_Phone(){

    if(phone[0].get_phone() == ""){
        cout<<"  NO PHONE INSERTED\n";
        return false;
    }


    cout<<"  PHONE TO SEARCH : "; getline(cin,input);

    for(int i = 0 ; i < 5 ; i++){
        if(!input.compare(phone[i].get_phone()))
            return true;
    }
    return false;
}

        //email search
bool User::search_email(){

    if(email[0].get_email() == ""){
        cout<<"  NO EMAIL INSERTED\n";
        return false;
    }

    cout<<"  EMAIL TO SEARCH : "; getline(cin,input);

    for(int i = 0 ; i < 5 ; i++){
        if(!input.compare(email[i].get_email()))
            return true;
    }
    return false;
}

        //address search
bool User::search_address(){

    if(address[0].get_place() == ""){
        cout<<"  NO ADDRESS INSERTED\n";
        return false;
    }


    cout<<"  ADDRESS TO SEARCH : "; getline(cin,input);

    for(int i = 0 ; i < 5 ; i++){
        if(!input.compare(address[i].get_place()))
            return true;
    }
    return false;
}

        //show
void User::show(){

    if (id == -1)
        return;

    cout<<"  ID : "<<id<<"\t\tFNAME : "<<fname<<"\t\tLNAME : "<<lname
        <<"\n  GENDER : "<<gender<<"\t\tCITY : "<<city<<"\t\tADDED DTAE : "<<addedDate<<"\n";


    if(!(phone[0].get_phone() == "")){
        for(int i = 0 ; i < 5 && phone[i].get_phone() != "" ; i++){
                cout<<"  PHONE : "<<phone[i].get_phone()<<"\t\tTYPE : "<<phone[i].get_type()<<"\t\tDESCRIPTION : "<<phone[i].get_desc()<<"\n";
        }
    }

    if(!(email[0].get_email() == "")){
        for(int i = 0 ; i < 5 && email[i].get_email() != "" ; i++){
                cout<<"  EMAIL : "<<email[i].get_email()<<"\t\tTYPE : "<<email[i].get_type()<<"\t\tDESCRIPTION : "<<email[i].get_desc()<<"\n";
        }
    }

    if(!(address[0].get_place() == "")){
        for(int i = 0 ; i < 5 && address[i].get_place() != "" ; i++){
                cout<<"  ADDRESS : "<<address[i].get_place()<<"\t\tTYPE : "<<address[i].get_type()<<"\t\tDESCRIPTION : "<<address[i].get_desc()<<"\n";
        }
        cout<<"\n";
    }
}

void User::set_id(int i){
    id = i;
}

void User::set_fname(string f){
    fname = f;
}

void User::set_lname(string l){
    lname = l;
}

void User::set_gender(string g){
    gender = g;
}

void User::set_city(string c){
    city = c;
}

void User::set_addedDate(string a){
    addedDate = a;
}

int User::get_id(){
    return id;
}

string User::get_fname(){
    return fname;
}

string User::get_lname(){
    return lname;
}

string User::get_city(){
    return city;
}

string User::get_gender(){
    return gender;
}

string User::get_addedDate(){
    return addedDate;
}




























