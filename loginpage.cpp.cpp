#include<iostream>
#include<vector>
#include<string>
using namespace std;
class login{
    public:
    string name,password,gmail;
    void input(){
    cout<<"Enter UserName: ";getline(cin,name);
    cout<<"Enter Email Adress: ";getline(cin,gmail);
    cout<<"Set Password: ";getline(cin,password);
    }
    void userlist(){
        cout<<"Name: "<<name<<endl<<"Email Adress: "<<gmail<<"\nPassword: "<<password<<endl;
    }
    void forget(){
        cout<<"--------------------------\n";
        cout<<"Your Password:: "<<password<<endl;
        cout<<"-------------------------\n";
    }
};
int main(){
    vector<login>v;
    login s;
    int choice;
    do{
        cout<<"------- REGISTRATION -------\n";
        cout<<"1.New User\n2.Login\n3.Forget\n4.Delete User\n5.User List\n6.Exit\n";
        cout<<"Enter your choice: ";cin>>choice;
        cin.ignore();
        switch(choice){
            case 1:{
                cout<<"--- SIGN IN ---\n";
            s.input();
            v.push_back(s);
            cout<<"Account Created Successfully...\n";
            break;
            }
            case 2: {
                cout<<"--- LOGIN ---\n";
            string nam;
            string pass;
            cout<<"Enter UserName: ";getline(cin,nam);
            cout<<"Enter Password: ";getline(cin,pass);
            bool found=false;
            for(auto &s:v){
                if(s.name==nam && s.password==pass){
                    cout<<"Login Successfully...\n";
                    found=true;
                    break;
                }
            }
            if(!found){ cout<<"Invailed username or password\n";
            }
            break;
        }
        case 3:{
            string user,mail;
            cout<<"Enter Username: ";getline(cin,user);
            cout<<"Enter Email Adress: ";getline(cin,mail);
            bool found=false;
            for(auto &s:v){
                if(s.name==user || s.gmail==mail){
                    s.forget();
                    found=true;
                    break;
                }
            }
             if(!found){
                    cout<<"--Username or Password Incorrect--\n";
                }
            break;
        }
        case 4:{
            string getusername,getpass;
            cout<<"Enter Username: ";getline(cin,getusername);
            cout<<"Password: ";getline(cin,getpass);
            bool found=false;
            for(auto it=v.begin(); it!=v.end(); ++it){
                if(it->name==getusername && it->password==getpass){
                    v.erase(it);
                    cout<<"Account Deleted Successfully...\n";
                    found=true;
                    break;
                }
            }
            if(!found){
                cout<<"Incorrect Uername or Password!!\n";
            }
            break;
        }
        case 5:{
            cout<<"---- User List ----\n";
            for(auto &s: v){
            s.userlist();
            }
            break;
        }
        case 6:cout<<"Exiting..\n";
        break;
        default: cout<<"Invailed Choice\n";
        break;
        }
    }while(choice!=6);
    return 0;
}