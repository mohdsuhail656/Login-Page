#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class login{
    public:
    string name,Email;
    string password;
    void input(){
        cout<<"Enter Username: ";getline(cin,name);
        cout<<"Enter Email Address : ";getline(cin,Email);
        cout<<"Set Password : ";getline(cin,password);
    }
    void display(){
        cout<<"UserName: "<<name<<", Email: "<<Email<<endl;
    }
};
int main(){
    int choice;
    ofstream file;
    login l;
    do{
        cout<<" ----------- LOGIN PAGE ----------- \n";
        cout<<"1.SIGN IN\n2.Login \n3.Forget\n4.User list\n5.Delete User\n6.Update Password\n7.Exit\n";
        cout<<"Enter your choice: ";cin>>choice;cin.ignore();
        switch(choice){
            case 1:{
                cout<<"  ----- SIGN IN ----- \n";
                l.input();
                file.open("logindata.txt",ios::app);
                file<<l.name<<"*"<<l.Email<<"*"<<l.password<<endl;
                file.close();
                cout<<"-------------------------------------\n";
                cout<<"     Account Created Successfully\n";
                cout<<"-------------------------------------\n";
                break; 
            }
            case 2:{
                string getpass,getusername;
                cout<<"Username: ";getline(cin,getusername);
                cout<<"Password: ";getline(cin,getpass);
                ifstream file("logindata.txt",ios:: in);
                bool found=false;
                bool founduser=false;
                while(getline(file,l.name,'*')&&
                getline(file,l.Email,'*')&&
                getline(file,l.password)){
                    if(getusername==l.name){
                        founduser=true;
                    if(getpass==l.password){
                        found=true;
                        cout<<"--------------------------------\n";
                        cout<<"       Login Successfully       \n";
                        cout<<"--------------------------------\n";
                        cout<<"UserName: "<<l.name<<", Email: "<<l.Email<<endl;
                        file.close();
                    }
                }
                }
                if(!founduser){
                    cout<<"------------------------\n";
                    cout<<"    USER NOT FOUND \n";
                    cout<<"------------------------\n";
                }
                else if(!found){
                    cout<<"-----------------------\n";
                    cout<<" INCORRECT PASSWORD \n";
                    cout<<"-----------------------\n";
                }
                break;
            }
            case 3:{
                string getuser,email;
                cout<<"userName: ";getline(cin,getuser);
                cout<<"Email: ";getline(cin,email);
                ifstream file("logindata.txt");
                bool found=false;
                while(getline(file,l.name,'*')){
                getline(file,l.Email,'*');
                getline(file,l.password);
                    if(l.name==getuser){
                        if(l.Email==email){
                            cout<<"      - Account Found -        \n";
                            cout<<"-----------------------------\n";
                            cout<<"Password:: "<<l.password<<endl;
                            cout<<"-----------------------------\n";
                            found=true;
                            break;
                        }
                    }
                }
                if(!found){
                    cout<<"----------------------\n";
                    cout<<"   Account Not Found \n";
                    cout<<"----------------------\n";
                }
                file.close();
                break;
            }
            case 4: {
                ifstream file("logindata.txt");
                if(file.peek()==EOF){
                    cout<<"-----------------------\n";
                    cout<<"    NO USER FOUND  \n";
                    cout<<"-----------------------\n";
                }
                else{
                int i=1;
                cout<<"------------ User List ----------\n";
                while(getline(file,l.name,'*')&&
                    getline(file,l.Email,'*')&&
                    getline(file,l.password)){
                    cout<<i++<<". "<<l.name<<" | "<<l.Email<<endl;
                }
                file.close();
                cout<<"----------------------------------\n";
            }
                break;
            }
            case 5:{
                string getuser,getpass;
                cout<<"Username: ";getline(cin,getuser);
                cout<<"Password: ";getline(cin,getpass);
                ifstream file("logindata.txt");
                ofstream temp("temp.txt");
                bool found=false;
                while(getline(file,l.name,'*') &&
                getline(file,l.Email,'*') &&
                getline(file,l.password)){
                    if(getuser==l.name && getpass==l.password){
                        found=true;
                        cout<<"----------------------------\n";
                        cout<<"  User Deleted Successfully   \n";
                        cout<<"-----------------------------\n";
                    }
                    else{
                        temp<<l.name<<"*"<<l.Email<<"*"<<l.password<<endl;
                    }
                }
                if(!found){
                cout<<"-------------------\n";
                cout<<"   User Not Found \n";
                cout<<"-------------------\n";
                }
                file.close();
                temp.close();
                remove("logindata.txt");
                rename("temp.txt","logindata.txt");
                break;
            }
            case 6:{
                string getusername,getpass;
                cout<<"Username: ";getline(cin,getusername);
                cout<<"Old Password: ";getline(cin,getpass);
                ifstream file("logindata.txt");
                ofstream temp("temp.txt");
                bool founduname=false;
                bool foundpass=false;
                while(getline(file,l.name,'*')&&
                getline(file,l.Email,'*')&&
                getline(file,l.password)){
                    if(getusername==l.name){
                        founduname=true;
                    if(getpass==l.password){
                        foundpass=true;
                        cout<<"------------------------------------\n";
                        cout<<"Enter New Password: ";
                        getline(cin,l.password);
                        cout<<"------------------------------------\n";
                        cout<<"-------------------------------\n";
                        cout<<"  Password Updated Successfully \n";
                        cout<<"-------------------------------\n";
                    }
                }
                temp<<l.name<<"*"<<l.Email<<"*"<<l.password<<endl;
                }
                if(!founduname){
                    cout<<"-------------------\n";
                    cout<<"  User Not Found \n";
                    cout<<"-------------------\n";
                }
                else if(!foundpass){
                    cout<<"------------------------\n";
                    cout<<"  Incorrect Password\n";
                    cout<<"------------------------\n";
                }
                file.close();
                temp.close();
                remove("logindata.txt");
                rename("temp.txt","logindata.txt");
                break;
            }
            case 7:cout<<"Exit\n";
            break;
            default:cout<<"Invailed choice\n";
        }
    }while(choice!=7);
    return 0;
}
