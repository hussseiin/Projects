#include "Contact.h"

int Contact::counter = 0;

int Contact::Aliascounter = 0;

Contact::Contact(int s) : size (s){

    user = new User[size];
}

Contact::~Contact(){

    delete [] user;
}

void Contact::add_user(){

    if(counter == size){
        cout<<"  FULL DATA BASE\n";
        return;
    }

    char key;   int id;

    for(int i = counter ; i < size ; i++){

        cout<<"  ID : ";  cin>>id;   user[i].set_id(id);   cin.ignore();
        cout<<"  FIRST NAME : "; getline(cin,input);    user[i].set_fname(input);
        cout<<"  LAST NAME : ";  getline(cin,input);    user[i].set_lname(input);
        cout<<"  GENDER : ";     getline(cin,input);    user[i].set_gender(input);
        cout<<"  CITY : ";       getline(cin,input);    user[i].set_city(input);
        cout<<"  ADDED DATE : "; getline(cin,input);    user[i].set_addedDate(input);
        user[i].add_phone();
        user[i].add_email();
        user[i].add_address();

        counter ++;
        Aliascounter ++;

        cout<<"  ANOTHER USER ? Y/N : ";    cin>>key;

        if(key == 'y' || key == 'Y')
            continue;
        else
            break;
    }
}

void Contact::edit(){

    if(counter == 0){
        cout<<"  NO USERS INSERTED\n";
        return;
    }

    string input;
    int c;  cout<<"  ID : ";    cin>>c;

    for(int i = 0 ; i < counter ; i++){
        if(user[i].get_id() == c){

            cout<<"  1-EDIT USER INFO\n";
            cout<<"  2-EDIT PHONE INFO\n";
            cout<<"  3-EDIT EMAIL INFO\n";
            cout<<"  4-EDIT ADDRESS INFO\n";
            cout<<"  CHOICE : ";    cin>>c;

            switch(c){

                case 1 : {
                    cout<<"  NEW ID : ";     cin>>c;                user[i].set_id(c);      cin.ignore();
                    cout<<"  FNAME : ";      getline(cin,input);    user[i].set_fname(input);
                    cout<<"  LNAME : ";      getline(cin,input);    user[i].set_lname(input);
                    cout<<"  CITY : ";       getline(cin,input);    user[i].set_city(input);
                    cout<<"  GENDER : ";     getline(cin,input);    user[i].set_gender(input);
                    cout<<"  ADDED DATE : "; getline(cin,input);    user[i].set_addedDate(input);
                    break;
                }
                case 2 :
                    cin.ignore();
                    user[i].edit_phone();
                    break;
                case 3 :
                    cin.ignore();
                    user[i].edit_email();
                    break;
                case 4 :
                    cin.ignore();
                    user[i].edit_address();
                    break;
            }
        }
        else if(i == counter -1){
            cout<<"  NO MATCHING ID\n";
            return;
        }
    }





}

bool Contact::search(){
    if(counter == 0){
        cout<<"  NO USERS INSERTED\n";
        return false;
    }

    int c;

    cout<<"  1-ID SEARCH\n";
    cout<<"  2-PHONE SEARCH\n";
    cout<<"  3-EMAIL SESARCH\n";
    cout<<"  4-ADDRESS SEARCH\n\n";

    cout<<"  CHOICE : ";    cin>>c;

    switch(c){
    case 1 :{

        cout<<"  ID TO SEARCH : ";   cin>>c;

        for (int i = 0 ; i < counter ; i ++){
            if(user[i].get_id() == c)
                return true;

            else if(i == counter-1){
                cout<<"  NO MATCHING ID\n";
                return false;
            }
        }
    }
    case 2 :{

        cout<<"  ID TO SEARCH : ";   cin>>c;

        for (int i = 0 ; i < counter ; i ++){
            if(user[i].get_id() == c){
                cin.ignore();
                return user[i].search_Phone();

            }

            else if(i == counter-1){
                cout<<"  NO MATCHING ID\n";
                return false;
            }
        }
    }
    case 3 :{

        cout<<"  ID TO SEARCH : ";   cin>>c;

        for (int i = 0 ; i < counter ; i ++){
            if(user[i].get_id() == c){
                cin.ignore();
                return user[i].search_email();
            }

            else if(i == counter-1){
                cout<<"  NO MATCHING ID\n";
                return false;
            }
        }
    }
    case 4 :{

        cout<<"  ID TO SEARCH : ";   cin>>c;

        for (int i = 0 ; i < counter ; i ++){
            if(user[i].get_id() == c){
                cin.ignore();
                return user[i].search_address();
            }

            else if(i == counter-1){
                cout<<"  NO MATCHING ID\n";
                return false;
            }
        }
    }
}
}

void Contact::number(){

    cout<<"  NUMBER OF USER IS : "<<Aliascounter<<"\n";
}

void Contact::show_all(){

    if(Aliascounter == 0){
        cout<<"  NO USERS INSERTED\n";
        return;
    }

    for(int i = 0 ; i < counter  ; i++){
        user[i].show();
    }
}

void Contact::delete_user(){

    if(counter == 0){
        cout<<"  NO USERS INSERTED\n";
        return;
    }

    cout<<"  ALL IDs : ";

    for(int i = 0 ; i < counter ; i ++){
        if(user[i].get_id() == -1)
            continue;

        cout<<user[i].get_id()<<" - ";
    }

    int c;  cout<<"\n  ID TO BE DELETED : ";  cin>>c;

    for(int i = 0 ; i < counter ; i++ ){
        if(user[i].get_id() == c){
            user[i] = {};
            Aliascounter--;
        }
        else if (i == counter-1)
            cout<<"  INVALID ID\n";
    }

}
