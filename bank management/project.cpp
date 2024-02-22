#include<iostream>
#include<fstream>
#include<cstdlib>
#include<time.h>
using namespace std;

class bank{
    int accNo;
    char name[25];
    char Fname[25];
    char aadhar[25];
    char P_no[25];
    char email[25];
    float amount;
    int newAmount;
    fstream file,file1;

    public:
    int search;

    
    void createAccount(void);
    void depositAmount(void);
    void withdrawAmount(void);
    void checkInfo(void);

};



int main(){
    bank b;
    char choice;

    cout<<" ..........XYZ BANK.........."<<endl;
    cout<<"......Press 1 to Log In......"<<endl;
    cout<<"..Press 2 to Create Account.."<<endl;
    cout<<".......Press 0 to Exit......."<<endl;

    cin>>choice;


    switch(choice){
        case '1':
         cout<<"Enter your Account No. : ";
         cin>>b.search;
         while(1){

            cout<<" .............XYZ BANK............."<<endl;
            cout<<"....Press 1 to Deposite Amount.... "<<endl;
            cout<<"....Press 2 to Withdraw Amount...."<<endl;
            cout<<".......Press 3 to check Info......."<<endl;
            cout<<" .......Press 0 to Exit Menu......."<<endl;
            cin>>choice;

            switch (choice)
            {
             case '1':
                b.depositAmount();
             break;
            
             case '2':
                b.withdrawAmount();
             break;

             case '3':
                b.checkInfo();
             break;

             case '0':
                return 0;
             break;
            
             default:
             cout<<"Invalid Choice...!";
             break;
            }
            system("pause");
            system("cls");
        }
        break;
        case '2':
            b.createAccount();
        break;
        
        case '0':
            system("exit");
        break;
        
        default :
            cout<<endl<<" Invalid choice...! ";
        break;    
    }
    return 0;
}

void bank :: createAccount(){

    srand(time(0));
    accNo=rand()*rand()+rand()*rand();

    cout<<"Enter your Name : ";
    cin>>name;

    cout<<"Enter your father's Name : ";
    cin>>Fname;

    cout<<"Enter your aadhar no: ";
    cin>>aadhar;
    cout<<"Enter Your phone no. :: ";
	cin>>P_no;
    cout<<"Enter your Email Id : ";
    cin>>email;

    cout<<"Enter Your amount : ";
    cin>>amount;
    cout<<endl<<accNo<<" This is your Account Number..."<<endl;
    cout<<"Please save it"<<endl;

    file.open("data.txt",ios::out|ios::app);
    file<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<aadhar<<"\t"<<P_no<<"\t"<<amount<<endl;
    file.close();

}


void bank :: depositAmount(){
    cout<<"Enter your deposite amount : ";
    cin>>newAmount;
    
    file.open("data.txt",ios::in);
    file1.open("data1.txt",ios::out|ios::app);
    file>>accNo>>name>>Fname>>aadhar>>P_no>>email>>amount;

    while(!file.eof()){
        if(accNo==search){
            cout<<endl<<"Current Amount : "<<amount<<endl;
            amount=amount+newAmount;
            cout<<"updated amount : "<<amount<<endl;
            file1<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<aadhar<<"\t"<<P_no<<"\t"<<email<<"\t"<<amount<<endl;
        }
        else{
			file1<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<aadhar<<"\t"<<P_no<<"\t"<<email<<"\t"<<amount<<endl;
		}
		file>>accNo>>name>>Fname>>aadhar>>P_no>>email>>amount;
    }
    file.close();
    file1.close();
    remove("data.txt");
    rename("data1.txt","data.txt");
}


void bank :: withdrawAmount(){
    cout<<"Enter amount to withdraw : ";
    cin>>newAmount;
    file.open("data.txt",ios::in);
    file1.open("data1.txt",ios::out|ios::app);
    file>>accNo>>name>>Fname>>aadhar>>P_no>>email>>amount;
	
	 while(!file.eof()){
        if(accNo==search){
            cout<<endl<<"Current Amount : "<<amount<<endl;
            amount=amount-newAmount;
            cout<<"updated amount : "<<amount<<endl;
            file1<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<aadhar<<"\t"<<P_no<<"\t"<<email<<"\t"<<amount<<endl;
        }
        else{
			file1<<accNo<<"\t"<<name<<"\t"<<Fname<<"\t"<<aadhar<<"\t"<<P_no<<"\t"<<email<<"\t"<<amount<<endl;
		}
		file>>accNo>>name>>Fname>>aadhar>>P_no>>email>>amount;
    }
    file.close();
    file1.close();
    remove("data.txt");
    rename("data1.txt","data.txt");
}

void bank :: checkInfo(){
    fstream file;
    file.open("data.txt",ios::in);
    if(!file) cout<<" File opening error...!";

    file>>accNo>>name>>Fname>>aadhar>>P_no>>email>>amount;
    while(!file.eof()){
        if(accNo==search){
            cout<<"......XYZ BANK......"<<endl;
            cout<<"Account No. "<<accNo<<endl;
            cout<<"Name : "<<name<<endl;
            cout<<"Father's Name : "<<Fname<<endl;
            cout<<"Aadhar No. : "<<aadhar<<endl;
            cout<<"Phone No : "<<P_no<<endl;
            cout<<"Email Id: "<<email<<endl;
            cout<<"current amount : "<<amount<<endl;
            cout<<"             ****************                  ";
        }
        file>>accNo>>name>>Fname>>aadhar>>P_no>>email>>amount;
    }
    file.close();
}