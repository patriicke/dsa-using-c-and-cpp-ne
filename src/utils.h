#include "iostream"

using namespace std;

string checkGender(string gender)
{
    if (
        gender == "MALE" || gender == "Male" || gender == "male" || gender == "M" || gender == "m")
        return "Male";
    else if (gender == "FEMALE" || gender == "Female" || gender == "female" || gender == "F" || gender == "f")
        return "Female";
    else
        return "";
}

bool isEmpty(string content)
{
    if (content.length() == 0)
        return true;
    return false;
}

// bool isValidDate(string date)
// {
//     if (date.length() != 10 || date[2] != '/' || date[5] != '/')
//         return false;

//     int day = stoi(date.substr(0, 2));
//     int month = stoi(date.substr(3, 2));
//     int year = stoi(date.substr(6, 4));

//     if (day < 1 || day > 31)
//         return false;

//     if (month < 1 || month > 12)
//         return false;

//     if (year < 1900 || year > 9999)
//         return false;

//     int daysInMonth;
//     if (month == 2)
//     {
//         if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//             daysInMonth = 29;
//         else
//             daysInMonth = 28;
//     }
//     else if (month == 4 || month == 6 || month == 9 || month == 11)
//     {
//         daysInMonth = 30;
//     }
//     else
//     {
//         daysInMonth = 31;
//     }

//     if (day > daysInMonth)
//         return false;

//     return true;
// }