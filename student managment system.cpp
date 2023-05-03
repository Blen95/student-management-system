 #include <iostream>
#include<fstream>
#include<conio.h>
#include <iomanip>
using namespace std;
struct Stud_info{
int Stud_id;
char Name[20];
int age;
char gender;
int year;
int semester;
};
void Register();
void Update(int ID);
void payement();
void Delete(int ID);
void Search(int ID);
void Paylist();

int main()
{
int choice_1,choice_2,ID;
char ch;
string pass;
cout<<"\n\n\n"<<setw(60)<<"STUDENT MANAGMENT SYSTEM"<<endl<<endl<<endl<<endl;
  cout<<setw(50)<<"Login"<<endl<<endl;
    cout<<setw(45)<<"sign in as: "<<endl<<endl<<endl;
    cout<<setw(45)<<"1.Student\n\n"<<setw(42)<<"2.Admin"<<endl;
    cin>>choice_1;
   M: switch(choice_1){
case 1:
 system("CLS");
    cout<<"1. Register"<<endl;
    cout<<"2. Update info"<<endl;
    cout<<"3. Make payment"<<endl;
    cin>>choice_2;
    switch(choice_2)
    {
    case 1:
        system("CLS");
    Register();
        break;
    case 2:
        system("CLS");
        cout<<"enter your id"<<endl;
        cin>>ID;
        Update(ID);
    break;

    case 3:
    system("CLS");
   payement();
   break;
    }
    break;
case 2:
     system("CLS");
     cout<<"Password "<<endl;
       ch=getch();

   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch=getch();
   }
   if(pass == "1234"){
        system("CLS");
     cout<<"\n 1. Delete Student\n 2. See student info \n 3. List of students who payed"<<endl;
     cin>>choice_2;
     system("CLS");
 switch(choice_2)
{
 case 1:
      system("CLS");
     cout<<"Enter ID to be deleted"<<endl;
     cin>>ID;
    Delete(ID);
    break;
 case 2:
      system("CLS");
     cout<<"Enter the ID of the student"<<endl;
     cin>>ID;
   Search(ID);
   break;
 case 3:
      system("CLS");
    Paylist();
   break;
     }
     }
   else
      cout << "\n\n\n"<<setw(60)<<"Access Aborted.Please Try Again"<<endl;
    break;
   }
   int check;
   cout <<"Enter 1 to go back to main menu"<<endl;
   cin>>check;
   if (check==1)
   {
       goto M;
   }
    return 0;
}

void Register(){
    fstream Register;
    Stud_info Student;
    int year, semester;
    string process;
    cout<<"Id: ";
    cin>>Student.Stud_id;
    cout<<"Name: ";
    cin>>Student.Name;
    cout<<"Age: ";
    cin>>Student.age;
    cout<<"Gender: ";
    cin>>Student.gender;
    cout<<"Please enter the year you want to register for"<<endl;
cout<<"1.Year1"<<"\n"<<"2.Year 2"<<"\n"<<"3. Year 3"<<"\n"<<"4. Year 4"<<endl;
cin>>Student.year;
cout<<"select the semester you want to register for"<<endl;
cout<<"1.semester 1"<<"\n"<<"2. semester 2"<<endl;
cin>>Student.semester;
Register.open("students.txt",ios::app);
if (Register.fail())
{
    cout<<"error";
}

Register.write((char*)&Student,sizeof(Student));
 system("CLS");


cout<<"successfully registered to year "<<Student.year<<" Semester "<<Student.semester<<endl;

}
void Update(int ID)
{
    int flag=0;
    fstream update("students.txt",ios::in);
    Stud_info S;
    update.read((char*)&S,sizeof(S));
    while (!update.eof())
    {
        if(ID==S.Stud_id)
        {
            flag=1;
            break;
        }
        update.read((char*)&S,sizeof(S));
    }
    int pos=sizeof(S);
    update.seekp(-pos,ios::cur);
cout<<"ID: "<<endl;
    cin>>S.Stud_id;
cout<<"Name: "<<endl;
    cin>>S.Name;
cout<<"Age: "<<endl;
    cin>>S.age;
cout<<"Gender: "<<endl;
    cin>>S.gender;
cout<<"year: "<<endl;
    cin>>S.year;
cout<<"Semester: "<<endl;
    cin>>S.semester;
cout<<"update successful"<<endl;
}
void payement()
{
int cash,acc,ch,ID;
string pin;
    cout<<"ID: "<<endl;
    cin>>ID;
    cout<<"Amount: ";
    cin>>cash;
    cout<<"Account number: "<<endl;
    cin>>acc;
    cout<<"Pin"<<endl;
    ch=getch();
    while(ch!=13){
        pin.push_back(ch);
        cout<<"*";
        ch=getch();
    }
    fstream file("students.txt",ios::in);
    fstream file2("Payments.txt",ios::app);
    Stud_info S;
    if (file2.fail())
        {
        cout<<"error";
        }
    file.read((char*)&S,sizeof(S));
    while(!file.eof()){

        if(ID==S.Stud_id)
        {
            file2.write((char*)&S,sizeof(S));

        }
        file.read((char*)&S,sizeof(S));
    }
    cout<<"payment successful"<<endl;
}
void Delete(int ID)
{
    fstream file1("students.txt",ios::in);
    fstream file2("temp.txt",ios::out);
    Stud_info S;
    file1.read((char*)&S,sizeof(S));
    while(!file1.eof())
          {
              if(ID!=S.Stud_id)
            {
                file2.write((char*)&S,sizeof(S));
            }
            file1.read((char*)&S,sizeof(S));
          }
          remove ("students.txt");
          rename("temp.txt","student.txt");
}
void Search(int ID)
{
    fstream file("students.txt",ios::in);
    Stud_info S;
    int flag=0;
    file.read((char*)&S,sizeof(S));
    while (!file.eof())
    {
        if(ID=S.Stud_id)
        {
            flag=1;
            break;
        }
        file.read((char*)&S,sizeof(S));
    }
    if(flag==1)
    {
        cout<<S.Stud_id<<"\n NAME:"<<S.Name<<"\n"<<"AGE: "<<S.age<<"\n"<<"GENDER:"<<S.gender<<"\n"<<"YEAR:"<<S.year<<"\n"<<"SEMESTER:"<<S.semester<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
}
void Paylist()
{
    fstream view("Payments.txt",ios::in);
    Stud_info S;
    view.read((char*)&S,sizeof(S));
    while(!view.eof())
    {
        cout<<"Student_id"<<setw(20)<<"NAME"<<setw(20)<<"AGE"<<setw(20)<<"GENDER"<<setw(20)<<"YEAR"<<setw(20)<<"Semester"<<endl;
        cout<<S.Stud_id<<setw(27)<<S.Name<<setw(19)<<S.age<<setw(20)<<S.gender<<setw(18)<<S.year<<setw(18)<<S.semester<<endl;
        view.read((char*)&S,sizeof(S));
    }

}
