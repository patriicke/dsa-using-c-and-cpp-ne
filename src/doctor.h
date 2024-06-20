#include "iostream"

using namespace std;

// Structure for Doctor
struct Doctor
{
    int doctor_id;
    string name;
    string specialization;
    Doctor *next;
};

// Doctors Linked List
Doctor *doctorsLL = nullptr;

bool isDoctorExists(int doctor_id)
{
    Doctor *temp = doctorsLL;
    while (temp != nullptr)
    {
        if (temp->doctor_id == doctor_id)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void registerDoctor()
{
    int doctor_id;
    string name, specialization;
    cout << "DOCTOR REGISTRATION" << "\n________________________\n";

    cout << "ID: ";
    cin >> doctor_id;

    if (isDoctorExists(doctor_id))
    {
        cout << "Doctor with ID " << doctor_id << " already exists!" << endl;
        return;
    }

    cout << "NAME: ";
    cin.ignore();
    getline(cin, name);
    if (isEmpty(name))
    {
        cout << "NAME can't be empty" << endl;
        return;
    }

    cout << "SPECIALIZATION: ";
    getline(cin, specialization);
    if (isEmpty(specialization))
    {
        cout << "SPECIALIZATION can't be empty" << endl;
        return;
    }

    // Create new doctor node
    Doctor *newDoctor = new Doctor;
    newDoctor->doctor_id = doctor_id;
    newDoctor->name = name;
    newDoctor->specialization = specialization;
    newDoctor->next = nullptr;

    // Add new doctor to the linked list
    if (doctorsLL == nullptr)
    {
        doctorsLL = newDoctor;
    }
    else
    {
        Doctor *temp = doctorsLL;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newDoctor;
    }

    cout << "Doctor registered successfully!" << endl;
}

void displayDoctors()
{
    cout << "Doctors:" << endl;
    Doctor *temp = doctorsLL;
    while (temp != nullptr)
    {
        cout << "ID: " << temp->doctor_id << ", Name: " << temp->name << ", Specialization: " << temp->specialization << endl;
        temp = temp->next;
    }
}
