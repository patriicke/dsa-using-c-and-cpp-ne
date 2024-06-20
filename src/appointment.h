#include "iostream"

using namespace std;

// Appointment Structure
struct Appointment
{
    int appointment_id;
    int patient_id;
    int doctor_id;
    string appointment_date;
    Appointment *next;
};

// Appointments Linked List
Appointment *appointmentsLL = nullptr;

void registerAppointment()
{
    int appointment_id, patient_id, doctor_id;
    string appointment_date;
    cout << "APPOINTMENT REGISTRATION" << "\n________________________\n";

    cout << "ID: ";
    cin >> appointment_id;

    cout << "P_ID: ";
    cin >> patient_id;

    if (!isPatientExists(patient_id))
    {
        cout << "Patient with ID " << patient_id << " does not exist!" << endl;
        return;
    }

    cout << "D_ID: ";
    cin >> doctor_id;

    if (!isDoctorExists(doctor_id))
    {
        cout << "Doctor with ID " << doctor_id << " does not exist!" << endl;
        return;
    }

    cout << "DATE: ";
    cin.ignore();
    getline(cin, appointment_date);

    // Create new appointment node
    Appointment *newAppointment = new Appointment;
    newAppointment->appointment_id = appointment_id;
    newAppointment->patient_id = patient_id;
    newAppointment->doctor_id = doctor_id;
    newAppointment->appointment_date = appointment_date;
    newAppointment->next = nullptr;

    // Add new appointment to the linked list
    if (appointmentsLL == nullptr)
    {
        appointmentsLL = newAppointment;
    }
    else
    {
        Appointment *temp = appointmentsLL;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newAppointment;
    }

    cout << "Appointment registered successfully!" << endl;
}

void displayAppointments()
{
    cout << "Appointments:" << endl;
    Appointment *temp = appointmentsLL;
    while (temp != nullptr)
    {
        cout << "ID: " << temp->appointment_id << ", Patient ID: " << temp->patient_id << ", Doctor ID: " << temp->doctor_id << ", Date: " << temp->appointment_date << endl;
        temp = temp->next;
    }
}
