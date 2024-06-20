#include <iostream>
#include <string>
#include "./src/patient.h"
#include "./src/doctor.h"
#include "./src/appointment.h"

using namespace std;

int main()
{
    int choice;
    do
    {
        cout << "Menu: " << endl;
        cout << "1. Register a Patient" << endl;
        cout << "2. Register a Doctor" << endl;
        cout << "3. Register an Appointment" << endl;
        cout << "4. Display Patients" << endl;
        cout << "5. Display Doctors" << endl;
        cout << "6. Display Appointments" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            registerPatient();
            break;
        case 2:
            registerDoctor();
            break;
        case 3:
            registerAppointment();
            break;
        case 4:
            displayPatients();
            break;
        case 5:
            displayDoctors();
            break;
        case 6:
            displayAppointments();
            break;
        case 7:
            cout << "Thank you for using our Ruhengeli Referral Hospital System." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }

        cout << endl;
    } while (choice != 7);

    return 0;
}
