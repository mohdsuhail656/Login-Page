#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class book{
    public: 
    int id,quantity;
    string author,title;
    void input(){ 
        cout<<"Enter Book ID     : ";cin>>id;cin.ignore();
        cout<<"Enter Book Title  : ";getline(cin,title);
        cout<<"Enter book Author : ";getline(cin,author);
        cout<<"Enter Quantity    : ";cin>>quantity;cin.ignore();
    }
    void display(){
        cout<<"Book ID  : "<<id<<"\n  Title    : "<<title<<"\n  Author   : "<<author<<"\n  Quantity : "<<quantity<<endl;
    }
};
class Library{
    private:
    book b;
    public:
    void addbook(){
        //system("cls");//for clear privious doing operation 
        cout<<"===========================\n";
        cout<<"      ADD NEW BOOK\n";
        cout<<"===========================\n";
        b.input();
        ofstream file("library.txt",ios::app);
        file<<b.id<<"*"<<b.title<<"*"<<b.author<<"*"<<b.quantity<<endl;
        cout<<"----------------------------\n";
        cout<<"  BOOK ADDED SUCCESSFULLY\n";
        cout<<"----------------------------\n";
        file.close();
    }
    void viewallbook(){
     ifstream file("library.txt");
     system("cls");
    if(file.peek()==EOF){
        cout<<"=============\n";
        cout<<"   NO BOOKS \n";
        cout<<"=============\n";
    }
    else{
        int i=1;
        cout<<"=====================\n";
        cout<<"     ALL BOOKS\n";
        cout<<"=====================\n";
        while(file>>b.id && 
        file.ignore() && 
        getline(file,b.title,'*')&& 
        getline(file,b.author,'*') &&
        file>>b.quantity &&
        file.ignore()){
            cout<<i<<".";
                b.display();
                i++;
                cout<<"---------------------------\n";
        }
        file.close();
    }
    }
    void searchbook(){
        int getid;string title;
        cout<<"==========================\n";
        cout<<"       SEARCH BOOK \n";
        cout<<"==========================\n";
        cout<<"Enter BOOK ID : ";cin>>getid;cin.ignore();
        cout<<"Enter Title   : ";getline(cin,title);
        bool found =false;
        ifstream file("library.txt");
        while(file>>b.id &&
        file.ignore() && 
        getline(file,b.title,'*') &&
        getline(file,b.author,'*')&&
        file>>b.quantity && 
        file.ignore()){
            if(getid==b.id && title==b.title){
                found=true;
                cout<<"---------------------\n";
                cout<<"     BOOK FOUND \n";
                cout<<"---------------------\n";
                b.display();
                cout<<"---------------------\n";
            }
        }
        if(!found){
            cout<<"---------------------------\n";
            cout<<"     BOOK NOT FOUND \n";
            cout<<"---------------------------\n";
        }
        file.close();
    }
    void deletebook(){
        int getid;
        cout<<"=========================\n";
        cout<<"      DELETE BOOK \n";
        cout<<"=========================\n";
        cout<<"Enter BOOK ID : ";cin>>getid;
        bool found =false;
        ifstream file("library.txt");
        ofstream temp("temp.txt");
        while(file>>b.id && 
        file.ignore() &&
        getline(file,b.title,'*')&&
        getline(file,b.author,'*')&& 
        file>>b.quantity &&
        file.ignore()){
            if(getid==b.id){
                found =true;
                cout<<"-------------------------------\n";
                cout<<"   BOOK DELETED SUCCESSFULLY \n";
                cout<<"-------------------------------\n";
            }
            else{
                temp<<b.id<<"*"<<b.title<<"*"<<b.author<<"*"<<b.quantity<<endl;
            }
        }
        if(!found){
            cout<<"-----------------------\n";
            cout<<"    BOOK NOT FOUND\n";
            cout<<"-----------------------\n";
        }
        file.close();
        temp.close();
        remove("library.txt");
        rename("temp.txt","library.txt");
    }
    void issuebook(){
        string title;
        cout<<"======================\n";
        cout<<"     ISSUE BOOK \n";
        cout<<"======================\n";
        cout<<"Enter Title : ";getline(cin,title);
        bool found=false;
        ifstream file("library.txt");
        ofstream temp("temp.txt");
        while(file>>b.id && 
            file.ignore() &&
        getline(file,b.title,'*')&&
        getline(file,b.author,'*')&&
        file>>b.quantity &&
        file.ignore()){
            if(b.title==title && b.quantity>=1){
                found=true;
                cout<<"--------------------------------\n";
                cout<<"   BOOK ISSUE SUCCESSFULLY\n";
                cout<<"--------------------------------\n";
                b.quantity--;
            }
            temp<<b.id<<"*"<<b.title<<"*"<<b.author<<"*"<<b.quantity<<endl;
        }
        if(!found){
            cout<<"----------------------------------\n";
            cout<<" BOOK NOT FOUND OR NOT AVILABLE\n";
            cout<<"----------------------------------\n";
        }
        file.close();
        temp.close();
        remove("library.txt");
        rename("temp.txt","library.txt");
    }
    void returnbook(){
        string gettitle;
        cout<<"===========================\n";
        cout<<"       RETURN BOOK \n";
        cout<<"==========================\n";
        cout<<"Enter title : ";getline(cin,gettitle);
        bool found=false;
        ifstream file("library.txt");
        ofstream temp("temp.txt");
        while(file>>b.id &&
        file.ignore() &&
        getline(file,b.title,'*')&&
        getline(file,b.author,'*')&&
        file>>b.quantity && 
        file.ignore()){
            if(b.title==gettitle){
                found=true;
                b.quantity++;
                cout<<"---------------------------------\n";
                cout<<"    BOOK RETURN SUCCESSFULLY\n";
                cout<<"---------------------------------\n";
            }
            temp<<b.id<<"*"<<b.title<<"*"<<b.author<<"*"<<b.quantity<<endl;
        }
        if(!found){
            cout<<"------------------------\n";
            cout<<"    BOOK NOT FOUND\n";
            cout<<"------------------------\n";
        }
        file.close();
        temp.close();
        remove("library.txt");
        rename("temp.txt","library.txt");
    }
};
int main(){
    int ch;
    Library l;
    cout<<"==================================\n";
    cout<<"     LIBRARY MANAGEMENT SYSTEM\n";
    cout<<"==================================\n";
    do{
        cout<<"1.ADD BOOK\n2.VIEW ALL BOOK\n3.Search Book\n4.ISSUE BOOK\n5.RETURN BOOK\n6.DELETE BOOK\n7.EXIT\n";
        cout<<"Enter your choice : ";cin>>ch;cin.ignore();
        switch(ch){
            case 1:l.addbook();
            break;
            case 2:l.viewallbook();
            break;
            case 3:l.searchbook();
            break;
            case 4:l.issuebook();
            break;
            case 5:l.returnbook();
            break;
            case 6:l.deletebook();
            break;
            case 7: cout<<"Exit\n";
            break;
            default: cout<<"INvailed Choice ! Try Again\n";
        }
    }while(ch!=7);
    return 0;
}