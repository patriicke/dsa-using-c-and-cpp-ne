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

string isInvalidDate(string date, int startYear, int endYear)
{
    // Check if the date has the correct format (DD/MM/YYYY)
    if (date.length() != 10 || date[2] != '/' || date[5] != '/')
        return "Invalid date format! Please use the format DD/MM/YYYY.";

    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));

    if (day < 1 || day > 31)
        return "Invalid day! Please enter a day between 1 and 31.";

    if (month < 1 || month > 12)
        return "Invalid month! Please enter a month between 1 and 12.";

    if (year < startYear || year > endYear)
        return "Invalid year! Please enter a year between " + to_string(startYear) + " and " + to_string(endYear) + ".";

    int daysInMonth;
    if (month == 2)
    {
        // Check for leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            daysInMonth = 29;
        else
            daysInMonth = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        daysInMonth = 30;
    }
    else
    {
        daysInMonth = 31;
    }

    if (day > daysInMonth)
        return "Invalid day! The month " + to_string(month) + " has only " + to_string(daysInMonth) + " days.";

    return "";
}