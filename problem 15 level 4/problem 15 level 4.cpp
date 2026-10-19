#include <iostream>

using namespace std;

struct SDate
{
    short Year;
    short Month;
    short Day;
};

bool IsLeapYear(short Year)
{

    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);

}

short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;


    int NumberOfDays[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

}

bool IsLastDayInMonth(SDate Date)
{
    return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
 
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

short ReadDay()
{
    short Day;
    cout << "\n Please Enter a Day ?";
    cin >> Day;
    return Day;
}

short ReadMonth()
{
    short Month;
    cout << "\n Please Enter a Month ?";
    cin >> Month;
    return Month;
}

short ReadYear()
{
    short Year;
    cout << "\n Please Enter a Year ?";
    cin >> Year;
    return Year;
}

SDate ReadFullDate()
{
    SDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}


int main()
{
    SDate Date = ReadFullDate();

    if (IsLastDayInMonth(Date))
        cout << "\n Yes, Day is Last Day in Month. ";
    else
        cout << "\n No, Day is NOT Last Day in Month. ";

    if(IsLastMonthInYear(Date.Month))
        cout << "\n Yes, Month is Last Month in Year. ";
    else
        cout << "\n No, Month is NOT Last Month in Year. ";

    return 0;

}

  