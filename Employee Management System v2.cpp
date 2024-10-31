#include<iostream>
using namespace std;
//global variables
const int maxx = 1000;
string name[maxx];
int age[maxx];
double salary[maxx];
char gender[maxx];
int employee = 0;
//menu function
int menu()
{
    int choice = -1;
    while(choice == -1)
    {
        cout<<"Enter your choice: "<<"\n";
        cout<<"1) Enter new employee"<<"\n";
        cout<<"2) print all employees"<<"\n";
        cout<<"3) Delete by age"<<"\n";
        cout<<"4) update salary by name"<<"\n";
        cout<<"5) Exit"<<"\n";
        cin>>choice;

        if(!(1<=choice && choice <= 5))
        {
            cout<<"Invalid choice. Try again\n";
            choice = -1;
        }
    }
    return choice;
}
//enter new employee function
void enter_new_employee()
{
    cout<<"Enter the employee name: "; cin>>name[employee];
    cout<<"Enter the age: "; cin>>age[employee];
    cout<<"Enter the salary: "; cin>>salary[employee];
    cout<<"Enter the gender (m/f): "; cin>>gender[employee];
    employee++;
}
void print_all_employees()
{
    cout<<"*************************************"<<"\n";
    for(int i = 0 ; i < employee ; ++i)
    {
        cout<<name[i]<<" "<<age[i]<<" "<<salary[i]<<" "<<gender[i]<<"\n";
    }
    cout<<"*************************************"<<"\n";
}
//delete be age function
void delete_by_age()
{
    int start_age , end_age;

    cout<<"Start age: "; cin>>start_age;
    cout<<"end age: "; cin>>end_age;

    for(int i = 0 ; i < employee ; ++i)
    {
        if(start_age <= age[i] && age[i] <= end_age)
        {
            for(int j = 0 ; j < employee ; j++)
            {
                name[i] = name[j + 1];
                age[i] = age[j + 1];
                salary[i] = salary[j + 1];
                gender[i] = gender[j + 1];
            }
            employee--;
            i--;
        }
    }
}
//update salary by name
void update_salary()
{
    string Name;
    int Salary;
    cout<<"Enter the name and salary: ";
    cin>>Name>>Salary;
    for(int i = 0 ; i < employee ; ++i)
    {
        if(Name == name[i])
        {
            salary[i] = Salary;
        }
        else{cout<<"there is no employee called "<<Name;}
    }
}
int main()
{
    while(true)
    {
        int choice = menu();

        if(choice == 1)
            enter_new_employee();
        else if(choice == 2)
            print_all_employees();
        else if(choice == 3)
            delete_by_age();
        else if(choice == 4)
            update_salary();
        else{break;}
    }
}


