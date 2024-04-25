#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

const string days="Mon  Tue  Wed  Thu  Fri  Sat Sun";
const string months[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
const int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
class calendar{
    int n;
    int year;
    int month_number;
    string month_name;
    int f_day;
    int day_number;
    int event_dates[31];
    int unsorted_event_dates[31];
    string event_names[31];
public:
calendar(int m,int y){
    month_number=m;
    month_name=months[month_number-1];
    year=y;
    int ytemp=year;
    ytemp-=month_number<3;
    f_day=( ytemp + ytemp/4 - ytemp/100 + ytemp/400 + t[month_number-1] + 1) % 7;
    switch(month_number-1){
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
    if(month_number-1==1)
    {
        if((year%4==0 && year%100!=0)  || year%400==0)
            day_number=29;
        else
            day_number=28;

    }

}
    void set_rem(){
        cout<<"Enter number of events to be added in the current month: "<<endl;cin>>n;
        cout<<"Enter the details: "<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter date of event "<<(i+1)<<": "<<endl;
            cin>>event_dates[i];
            cout<<"Enter the name of event: "<<(i+1)<<": "<<endl;
            cin>>event_names[i];
        }
        copy (event_dates, event_dates+n, unsorted_event_dates);
        sort(event_dates,event_dates + n);
    }
    void disp()
    {
        cout<<"---------------"<<month_name<<"---------------"<<endl;
        cout<<days<<endl;
        if (f_day-1==-1){f_day=7;}
        for(int i=0;i<f_day-1;i++)
        {
            cout<<"     ";
        }
        f_day=f_day-1;
        int event_no=0;
        for(int i=1;i<=day_number;i++)
        {
            if (i==event_dates[event_no])
                {
                   cout<<"R    ";
                   event_no++;
                }
            else
            {
            cout<<i;
            string spacing = (i/10==0) ? "    " : "   ";
            cout<<spacing;
            }
            f_day++;
            if (f_day==7){cout<<endl;f_day=0;}
        }
    }
    void event_disp()
    {
        int pos[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(event_dates[i]==unsorted_event_dates[j])
                {
                   pos[i]=j;
                }
            }
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<"Event "<<(i+1)<<" Name: "<<event_names[pos[i]]<<endl;
            cout<<"Event "<<(i+1)<<" Date: "<<event_dates[i]<<endl;
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

int main()
{
    UserLogin user;
    if(user.Login()==1)
    {
        int m,y;
        cout<<"Enter Year and Month required: "<<endl;cin>>y>>m;
        calendar c(m,y);
        c.set_rem();
        c.disp();
        c.event_disp();
    }
    return 0;
}
