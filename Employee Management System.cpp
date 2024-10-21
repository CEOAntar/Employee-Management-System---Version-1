#include<iostream>
using namespace std;
int main()
{
const int max_array_size = 100;
string name[max_array_size];
int age[max_array_size];
double salary[max_array_size];
char gender[max_array_size];
int employee = 0;


    for(;;)
    {
        int choice;
        cout<<"Enter Your Choice: "<<endl;
        cout<<"1) Add New Employee"<<endl;
        cout<<"2) Print All Employees"<<endl;
        cout<<"3) Delete By Age"<<endl;
        cout<<"4) Update Salary By Name"<<endl;
        cout<<"5) cancel"<<endl;
        cin>>choice;
        if(choice == 1)
        {
            //enter new employee in the system
            if(employee < max_array_size)
            {
                cout<<"Enter name : "; cin>>name[employee];
                cout<<"Enter age: "; cin>>age[employee];
                cout<<"Enter salary: "; cin>>salary[employee];
                cout<<"Enter gender (m/f): "; cin>>gender[employee];
                cout<<"\n";
                employee++;
            }
            else{cout<<"Maximum number of employees reached!";}
        }
        //print out all the employees
        else if(choice == 2)
        {
            cout<<"***************************************"<<endl;
            for(int i = 0 ; i < employee ; ++i)
            {
                cout<<name[i]<<" "<<age[i]<<" "<<salary[i]<<" "<<gender[i]<<endl;
            }
            cout<<"***************************************"<<endl;
        }
        //delete by age
        else if(choice == 3)
        {
            int start_age , end_age;
            cout<<"Enter the start age: "; cin>>start_age;
            cout<<"Enter the end age: "; cin>>end_age;
            for(int i = 0 ; i < employee ; ++i)
            {
                //find the user that his age between 20 and 30
                if(start_age <= age[i] && age[i] <= end_age)
                {
                    //another loop to shift the elements
                    for(int j = i ; j < employee -1 ; ++j)
                    {
                        name[j] = name[j+1];
                        age[j] = age[j+1];
                        salary[j] = salary[j+1];
                        gender[j] = gender[j+1];
                    }
                    employee--;
                    i--;
                }
            }
        }
        //update salary by name
        else if(choice == 4)
        {
            string Name;
            double Salary;
            cout<<"Enter the name and salary: ";
            cin>>Name>>Salary;
            for(int i = 0 ; i < employee ; ++i)
            {
                //find the employee
                if(name[i] == Name)
                {
                    salary[i] = Salary;
                }
                else{cout<<"there is no user called "<<Name<<endl;}
            }
        }
        else{break;}
    }
    return 0;
}
