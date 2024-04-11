#include <iostream>
using namespace std;
const string days=" mon  tue  wed  thu  fri  sat sun";
const string months[12]={"January","February","March","April","May","June","July","August","September","October","November","Decmeber"};
const int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
class calendar{
    int day;
    int year;
    int month_number;
    string month_name;
    int f_day;
    int day_number;
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
    void disp(){
        cout<<"---------------"<<month_name<<"---------------"<<endl;
        cout<<days;
    }

    
};

int main() {
    calendar c(7,2,2024);
    c.disp();

    return 0;
}
