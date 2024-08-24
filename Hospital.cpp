#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

//Forward Declaration
class Person;
class Patient;
class Nurse;
class Doctor;
class Managment_System;
  

/*Classes*/

class Person
{
protected:
          string Name;
          char Gender;
          int Age;
          int ID;

public:
        void setName(string n) { Name = n; }
        void setGender(char G) { Gender = G; }
        void setAge(int a) { Age = a; }
        void setId(int i) { ID = i; }

        string getName() const { return Name; }
        char getGender() const { return Gender; }
        int getAge() const { return Age; }
        int getId() const { return ID; }

};

class Patient : public Person
{

private:
          int Condition; //A patient has 5 conditions
          string Register_date;
          string Discharge_date;
public:
          Patient() {}
          //setter
          Patient(string name , char gender , int age , string ad , int con)
          {
                    if(con < 1 || con > 3)
                    {
                              cout<<"Enter a Valid Condition(1/2/3)"<<endl;
                              ID = -1;
                    }
                    else if((gender != 'm' && gender != 'M') && (gender != 'f' && gender != 'F'))
                    {
                              cout<<"Enter a valid Gender"<<endl;
                              ID = -1;
                    }
                    else
                    {
                              Name = name;
                              Gender = gender;
                              Age = age;
                              Register_date = ad;
                              Condition = con;
                              ID = 1;
                    }

          }
          //getter
          void Display_info()
          {
                    cout<<"Name: "<<Name<<endl;
                    cout<<"Gender: "<<Gender<<endl;
                    cout<<"Age: "<<Age<<endl;
                    cout<<"ID: "<<ID<<endl;
                    cout<<"Admission_data: "<<Register_date<<endl;
                    cout<<"Discharge_date: "<<Discharge_date<<endl;
          }

          int Patient_condition()
          {
                    return Condition;
          }
          string Patient_register_date()
          {
                    return Register_date;
          }
          string Patient_discharge_date()
          {
                    return Discharge_date;
          }

};

class Nurse : public Person 
{
private:
    int Medical_license;
    string Departement ;
public:
    Nurse(){} //Empty Contructor
    Nurse(string n, char g, int a, int m, string Dep){

        


        if((g != 'm' && g != 'M') && (g != 'f' && g != 'F'))
        {
                  cout<<"Enter a valid Gender"<<endl;
                  Medical_license = -1;
        }
        else
        {
            Name=n ;
            Gender=g ;
            Age=a;
            Medical_license=m ;
            Departement=Dep ;
        }

    }

    void setMedicalLicense(int m){
        Medical_license=m ;
    }
    void setDepartment(string Dep){
        Departement=Dep ;
    }

    int getMedicalLicense() const { return Medical_license; }
    string getDepartement() const { return Departement; }

};

class Doctor : public Person
{
private:
          int Medical_license;
          int Speciality;//Doctor has 5 Specialties

public:
        Doctor(){}
          //setter
          Doctor(string name , char gender , int age ,int me , int s)
          {
                    Medical_license = -1;

                    if(s > 3 || s < 1)
                    {
                              cout<<"Enter a valid Speciality(1/2/3)"<<endl;
                    }
                    else if((gender != 'm' && gender != 'M') && (gender != 'f' && gender != 'F'))
                    {
                              cout<<"Enter a valid Gender"<<endl;
                    }
                    else
                    {
                              Name = name;
                              Gender = gender;
                              Age = age;
                              Medical_license = me;
                              Speciality = s;
                    }

          }

          //getters
          void Display_Doctor_info()
          {
                    cout<<"Name: "<<Name<<endl;
                    cout<<"Gender: "<<Gender<<endl;
                    cout<<"Age: "<<Age<<endl;
                    cout<<"ID: "<<ID<<endl;
                    cout<<"Medical_license: "<<Medical_license<<endl;
                    cout<<"Speciality: "<<Speciality<<endl;
          }
            int Doctor_license() const
            {
                return Medical_license;
            }

            int Doctor_speciality() const
            {
                return Speciality;
            }


};

class Managment_System
{
          private:
                    //patients
                    static const int Patient_Size = 50;
                    static Patient Patients[Patient_Size];
                    static int front;
                    static int rear;


                    //doctor
                    static const int Doctor_Size = 20;
                    static vector <Doctor> Doctors;

                    //nurses
                    static vector<Nurse> Nurses;

          public:
                    //Doctors Functions
                    void Add_Doctor(Doctor d)
                    {
                              if(d.Doctor_license() == -1)
                              {
                                        cout<<"Process Failed"<<endl;
                              }
                              else
                              {
                                        Doctors.push_back(d);
                                        Doctors.back().setId(Doctors.size()-1);
                                        cout<<"Doctor Added Successfuly"<<endl;
                              }
                    }

                    void Display_Doctors()
                    {
                              for(int i = 0 ; i < Doctors.size() ; i++)
                              {
                                        Doctors[i].Display_Doctor_info();
                              }
                    }

                    void Delete_Doctor(int id)
                    {
                        auto it = find_if(Doctors.begin(), Doctors.end(), [id](const Doctor& d) { return d.getId() == id; });
                        if (it != Doctors.end()) {
                            cout << "Doctor with ID " << id << " deleted successfully." << endl;
                            Doctors.erase(it);
                        } else {
                            cout << "Doctor with ID " << id << " not found." << endl;
                        }
                    }

                    //Nurse Functions
                    public:
                            void Add_Nurse(Nurse n) {
                                if(n.getMedicalLicense() == -1)
                                {
                                    cout<<"Proccess Failed"<<endl;
                                }
                                else
                                {
                                    Nurses.push_back(n);
                                    Nurses.back().setId(Nurses.size()-1);
                                    cout << "Nurse " << n.getName() << " added successfully." << endl;
                                }

                            }

                            void Display_Nurses() const {
                                for (const auto& nurse : Nurses) {
                                    cout << "Name: " << nurse.getName() << endl
                                        << "Gender: " << nurse.getGender() << endl
                                        << "Age: " << nurse.getAge() << endl
                                        << "ID: " << nurse.getId() << endl
                                        << "Medical License: " << nurse.getMedicalLicense() << endl
                                        << "Department: " << nurse.getDepartement() << endl << endl;
                                }
                            }

                            void Delete_Nurse(int id) {
                                auto it = find_if(Nurses.begin(), Nurses.end(), [id](const Nurse& n) { return n.getId() == id; });
                                if (it != Nurses.end()) {
                                    cout << "Nurse with ID " << id << " deleted successfully." << endl;
                                    Nurses.erase(it);
                                } else {
                                    cout << "Nurse with ID " << id << " not found." << endl;
                                }
                            }




                    //Patient Functions
                    void Register_Patient(Patient p)
                    {
                              if(p.getId() == -1)
                              {
                                        cout<<"Register Failed"<<endl;
                              }
                              //Queue is Full
                              else if((rear == Patient_Size - 1 && front == 0) || (front == rear + 1))
                              {
                                        cout<<"Patient Queue is Full \n";
                                        return;
                              }
                              //Queue is empty
                              else if(front == -1 && rear == -1)
                              {
                                        front = rear = 0;
                                        Patients[rear] = p;
                                        Patients[rear].setId(rear);
                                        cout<<"Patient "<<p.getName()<<" Registered Successfuly"<<endl;
                                        return;
                              }
                              //Not full nor empty
                              else if(rear == Patient_Size - 1 && front != 0)
                              {
                                        rear = 0 ;
                                        Patients[rear] = p;
                                        Patients[rear].setId(rear);
                                        cout<<"Patient "<<p.getName()<<" Registered Successfuly"<<endl;
                                        return;
                              }
                              else
                              {
                              rear++;
                              Patients[rear] = p;
                              Patients[rear].setId(rear);
                              cout<<"Patient "<<p.getName()<<" Registered Successfuly"<<endl;
                              return; 
                              }
                    }

                    void Discharge_Patient()
                    {
                    //queue is empty
                    if(front == -1 && rear == -1)
                    {
                    cout<<"Patients Queue is empty \n";
                    return;
                    }
                    //else
                    else if(front == Patient_Size-1 && front > rear)
                    {
                    cout << "Patient " << Patients[front].getName() << " Discharged Successfully" << flush << endl;
                    front = 0;
                    return;
                    }
                    else if(front == rear)
                    {
                    cout << "Patient " << Patients[front].getName() << " Discharged Successfully" << flush << endl;
                    rear = front = -1;
                    return;
                    }
                    else
                    {
                    cout << "Patient " << Patients[front].getName() << " Discharged Successfully" << flush << endl;
                    front++;
                    return;
                    }
                    }

                    void Check_Patient_Turn()
                    {
                              if(front == -1 && rear == -1)
                              {
                                        cout<<"Patients Queue is empty"<<endl;
                                        return;
                              }
                              else
                              {
                                        Patients[front].Display_info();
                              }
                    }

                    void Display_Patients()
                    {
                              if(front == -1 && rear == -1)
                              {
                                        cout<<"Patients Queue is empty"<<endl;
                                        return;
                              }
                              else if(front <= rear)
                              {
                                        for(int i = front ; i <= rear ; i++)
                                        {
                                                  Patients[i].Display_info();
                                        }
                                        return;
                              }
                              else if(front > rear)
                              {
                                        for(int i = front ; i < Patient_Size ; i++)
                                        {
                                                  Patients[i].Display_info();     
                                        }
                                        for(int i = 0 ; i <= rear ; i++)
                                        {
                                                  Patients[i].Display_info();
                                        }
                                        return;
                              }
                    }


};



//Static Variables Declaration
int Managment_System::front = -1;
int Managment_System::rear = -1;
Patient Managment_System::Patients[Managment_System::Patient_Size];
vector<Doctor> Managment_System::Doctors;
vector<Nurse> Managment_System::Nurses;

int main()
{
    Managment_System Hospital_system;

    while(true)
    {
        cout<<"Enter: (P) for Patients , (D) for Doctor , (N) for nurses: ";
        char Choice; cin>>Choice;
        if(Choice == 'P' || Choice == 'p')
        {
            bool Repeat = true;
            while(Repeat == true)
            {
                cout<<"\t \t \t \t \t  Patient Operations"<<endl;
                cout<<"1-Register Patient \t 2-Discharge Patient \t 3-Check Patient Turn \t 4-Display Patients"<<endl;    
                int Choice2; cin>>Choice2;
                if(Choice2 == 1)
                {
                    cout<<"Enter Patient Name: ";
                    string name; cin>>name;
                    cout<<"Enter Patient Age: ";
                    int age; cin>>age;
                    cout<<"Enter Patient Gender (M / F): ";
                    char gender; cin>>gender;
                    cout<<"Enter Patient Condition(1/2/3): ";
                    int condition; cin>>condition;
                    cout<<"Enter Patient Register date: ";
                    string registerdate; cin>> registerdate;
                    Hospital_system.Register_Patient(Patient(name, gender, age ,registerdate,condition));
                }
                else if(Choice2 == 2)
                {
                    Hospital_system.Discharge_Patient();
                }
                else if(Choice2 == 3)
                {
                    Hospital_system.Check_Patient_Turn();
                }
                else if(Choice2 == 4)
                {
                    Hospital_system.Display_Patients();
                }
                else
                {
                    cout<<"Invalid Number"<<endl;
                }

                cout<<"Do you want to choose another Patient operation ? (Y) (N): ";
                char r; cin>>r;
                if(r == 'Y' || r == 'y'){Repeat = true;}
                else if(r == 'N'|| r =='n'){Repeat = false;}
                else{cout<<"invalid input"<<endl;Repeat = false;}  
            }
        }
        else if(Choice == 'D' || Choice == 'd')
        {
            bool Repeat = true;
            while(Repeat == true)
            {
                cout<<"\t \t \t \t \t Doctors Operations"<<endl;
                cout<<"1-Add Doctor \t 2-Display Doctor \t 3-Delete Doctor"<<endl;
                int Choice2; cin>>Choice2;
                if(Choice2 == 1)
                {
                    cout<<"Enter Doctor Name: ";
                    string name; cin>>name;
                    cout<<"Enter Doctor Age: ";
                    int age; cin>>age;
                    cout<<"Enter Doctor Gender (M / F): ";
                    char gender; cin>>gender;
                    cout<<"Enter Doctor Speciality(1/2/3): ";
                    int speciality; cin>>speciality;
                    cout<<"Enter Doctor Medical license: ";
                    int medical_license; cin>> medical_license;

                    Hospital_system.Add_Doctor(Doctor(name,gender,age,medical_license,speciality));
                }
                else if(Choice2 == 2)
                {
                    Hospital_system.Display_Doctors();
                }
                else if(Choice2 == 3)
                {
                    cout<<"Enter Doctor Id: ";
                    int id; cin>>id;
                    Hospital_system.Delete_Doctor(id);
                }
                else
                {
                    cout<<"Enter a Valid number"<<endl;
                }

                cout<<"Do you want to choose another Doctor operation ? (Y) (N): ";
                char r; cin>>r;
                if(r == 'Y' || r == 'y'){Repeat = true;}
                else if(r == 'N'|| r =='n'){Repeat = false;}
                else{cout<<"invalid input"<<endl;Repeat = false;}
            }
        }
        else if(Choice == 'N' || Choice == 'n')
        {
            bool Repeat = true;
            while(Repeat == true)
            {
                cout<<"\t \t \t \t \t Nurse Operations"<<endl;
                cout<<"1-Add Nurse \t 2-Display Nurses \t 3-Delete Nurse"<<endl;
                int Choice2; cin>>Choice2;
                if(Choice2 == 1)
                {
                    cout<<"Enter Nurse Name: ";
                    string name; cin>>name;
                    cout<<"Enter Nurse Age: ";
                    int age; cin>>age;
                    cout<<"Enter Nurse Gender (M / F): ";
                    char gender; cin>>gender;
                    cout<<"Enter Nurse Department: ";
                    string department; cin>>department;
                    cout<<"Enter Nurse Medical license: ";
                    int medical_license; cin>> medical_license;

                    Hospital_system.Add_Nurse(Nurse(name,gender,age,medical_license,department));
                }
                else if(Choice2 == 2)
                {
                    Hospital_system.Display_Nurses();
                }
                else if(Choice2 == 3)
                {
                    cout<<"Enter Nurse Id: ";
                    int id; cin>>id;
                    Hospital_system.Delete_Nurse(id);
                }
                else
                {
                    cout<<"Enter a Valid number"<<endl;
                }

                cout<<"Do you want to choose another Nurse operation ? (Y) (N): ";
                char r; cin>>r;
                if(r == 'Y' || r == 'y'){Repeat = true;}
                else if(r == 'N'|| r =='n'){Repeat = false;} 
                else{cout<<"invalid input"<<endl;Repeat = false;}
            }
        }
        else
        {
            cout<<"Enter a Valid option"<<endl;
        }
    }
}






