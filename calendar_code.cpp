// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

const string days="mon  tue  wed  thu  fri  sat sun";
const string months[12]={"January","February","March","April","May","June","July","August","September","October","November","Decmeber"};
const int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
class calendar{
    int day;
    int year;
    int month_number;
    string month_name;
    int f_day;
    int day_number;
    int reminder;
public:
calendar(int d,int m,int y){
    day=d;
    month_number=m;
    month_name=months[month_number-1];
    year=y;
    int ytemp=year;
    ytemp-=month_number<3;
    f_day=( ytemp + ytemp/4 - ytemp/100 + ytemp/400 + t[month_number-1] + 1) % 7;
    switch(month_number){
        case 0:
        case 2:
        case 4:
        case 6:
        case 7:
        case 9:
        case 11: day_number=31; break;
        case 3:
        case 5:
        case 10:
        case 8: day_number=30; break;
    }

}
    void set_rem(){cout<<"enter reminder date for current month"<<endl;cin>>reminder;}
    void disp(){
        cout<<"---------------"<<month_name<<"---------------"<<endl;
        cout<<days<<endl;
        for(int i=0;i<f_day-1;i++){
            cout<<"     ";
        }
        f_day=f_day-1;
        for(int i=1;i<=day_number;i++){
            if (i==reminder){
                cout<<"R    ";
            }
            else{
            cout<<i;
            string spacing = (i/10==0) ? "    " : "   ";
            cout<<spacing;
            }
            f_day++;
            if (f_day==7){cout<<endl;f_day=0;}
        }
    }

    
};

class UserLogin
{
private:
    string userName;
    string userPassword;
public:
    UserLogin()
    {
        userName="User";
        userPassword="Password";
    }
    int Login()
    {
        int loginAttempt = 0;
        while (loginAttempt<3)
        {
           cout << "Please enter your user name: ";
           cin >> userName;
           cout << "Please enter your user password: ";
           cin >> userPassword;
           if (userName == "User" && userPassword == "Password")
           {
            cout << "Welcome back User!"<<endl;
            return 1;
            break;
           }
           else
           {
            cout << "Invalid login attempt. Please try again.\n" << endl;
            loginAttempt++;
           }
        }
        if (loginAttempt == 3)
        {
            cout << "Too many login attempts! Please try again after sometime or reset your user name and password.";
            exit(0);
        }
    }
};

int main() {
    UserLogin user;
    if(user.Login()==1)
    {
        //here the rest of the code begins.
        calendar c(4,4,2024);
        c.set_rem();
        c.disp();
    }

    return 0;
}
