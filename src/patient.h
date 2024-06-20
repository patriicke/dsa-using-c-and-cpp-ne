#include "iostream"

using namespace std;

// Structure for Patient
struct Patient
{
    int patient_id;
    string name;
    string dob;
    string gender;
    Patient *next;
};

// Linked List for Patients
Patient *patientsLL = nullptr;

bool isPatientExists(int patient_id)
{
    Patient *temp = patientsLL;
    while (temp != nullptr)
    {
        if (temp->patient_id == patient_id)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void registerPatient()
{
    int patient_id;
    string name, dob, gender;
    cout << "PATIENT REGISTRATION" << "\n________________________\n";
    cout << "ID: ";
    cin >> patient_id;
    if (isPatientExists(patient_id))
    {
        cout << "Patient with ID " << patient_id << " already exists!" << endl;
        return;
    }

    cout << "NAME: ";
    cin.ignore();
    getline(cin, name);

    cout << "DoB: ";
    getline(cin, dob);

    cout << "GENDER: ";
    getline(cin, gender);

    // Create new patient node
    Patient *newPatient = new Patient;
    newPatient->patient_id = patient_id;
    newPatient->name = name;
    newPatient->dob = dob;
    newPatient->gender = gender;
    newPatient->next = nullptr;

    // Add new patient to the linked list
    if (patientsLL == nullptr)
    {
        patientsLL = newPatient;
    }
    else
    {
        Patient *temp = patientsLL;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newPatient;
    }

    cout << "Patient registered successfully!" << endl;
}

void displayPatients()
{
    cout << "Patients:" << endl;
    Patient *temp = patientsLL;
    while (temp != nullptr)
    {
        cout << "ID: " << temp->patient_id << ", Name: " << temp->name << ", DOB: " << temp->dob << ", Gender: " << temp->gender << endl;
        temp = temp->next;
    }
}
