#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    //TASK 1

    string fullname;
    string idstudent ;
    double grade;

    cout<<"enter full name : ";
    getline(cin,fullname);

    cout<<"enter id student : ";
    cin>>idstudent;

    cout<<"enter grade : ";
    cin>>grade;

    ofstream myfile("student.txt");
    if(myfile.is_open())
    {
      myfile<<"full name : " <<fullname <<endl;
      myfile<<"id student : " << idstudent<<endl;
      myfile<<"grade : " <<grade <<endl;
      myfile.close();
    }
      else
      {
        cout<<"error";
      }


    return 0;
}
