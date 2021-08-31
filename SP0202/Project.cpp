// This is a Program for STUDENT DATA MANEGMENT for Institute , in which only Faculty has Rights to MANAGE (ADD , DELETE , MODIFY) the Student Details.
// While BOTH faculty and Student has Rights to DISPLAY the RESULT.
// HOPE you like it....
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <stdlib.h>

using namespace std;

// A STUDENT CLASS
class student
{
    int idnum; // Private Inbuilt
    int password;

    char name[50];
    int physics, chemistry, mathematics, english, comscience;
    double per;
    char grade;
    void calculate();

public:
    void getdata();
    void showdata() const;
    void show_tabular() const;
    int getIDNum() const;
    int getpassword() const;
};

// CALCULATING THE GRADES OF STUDENT USING MARKS IN RESPECTED SUBJECTS
void student::calculate()
{
    per = (physics + chemistry + mathematics + english + comscience) / 5.0;
    if (per >= 90)
        grade = 'O';
    else if (per >= 75)
        grade = 'A';
    else if (per >= 60)
        grade = 'B';
    else if (per >= 45)
        grade = 'C';
    else if (per >= 33)
        grade = 'D';
    else
        grade = 'F';
}

// HERE , FACULTY FILLS THE REQIRED DETAILS OF STUDENT (IDs , NAME , MARKS)
void student::getdata()
{
    cout << "\nEnter The ID number of the student: ";
    cin >> idnum;
    cout << "\nEnter The PASSWORD of the student(INT ONLY): ";
    cin >> password;
    cout << "\n\nEnter student's Name: ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\nEnter student's physics grade: ";
    cin >> physics;
    cout << "\nEnter student's chemistry grade: ";
    cin >> chemistry;
    cout << "\nEnter student's mathematics grade: ";
    cin >> mathematics;
    cout << "\nEnter student's english grade: ";
    cin >> english;
    cout << "\nEnter student's computer science grade: ";
    cin >> comscience;
    calculate();
}

// DISPLAY THE STUDENT DETAILS FILL BY THE FACULTY
void student::showdata() const
{
    cout << "\nID Number: " << idnum;
    cout << "\nName: " << name;
    cout << "\nPhysics: " << physics;
    cout << "\nChemistry: " << chemistry;
    cout << "\nMathematics: " << mathematics;
    cout << "\nEnglish: " << english;
    cout << "\nComputer Science: " << comscience;
    cout << "\nPercentage: " << per;
    cout << "\nLetter Grade: " << grade;
}

// ALIGN THE STUDENT RESULT IN TABULAR FORM USING SETW() FUNCTION
void student::show_tabular() const
{
    cout << idnum << setw(7) << " " << name << setw(12) << physics << setw(4) << chemistry << setw(4) << mathematics << setw(4)
         << english << setw(4) << comscience << setw(8) << per << setw(6) << grade << endl;
}

int student::getIDNum() const
{
    return idnum;
}

int student::getpassword() const
{
    return password;
}

void SaveStudent();
void displayAll();
void Searchdisplay(int);
void modifyStudent(int);
void deleteStudent(int);
void DisplayClassResult();
void DisplayResult();
void facultylogin();
void student_result();

// HERE , STUDENT DETAILS ARE FILLED IN STUDENT.DAT FILE
void write_student()
{
    student st;
    ofstream outFile;
    outFile.open("student.dat", ios::binary | ios::app);
    st.getdata();
    outFile.write(reinterpret_cast<char *>(&st), sizeof(student));
    outFile.close();
    cout << "\n\nStudent record Has Been Created ";
    cin.ignore();
    cin.get();
}

// DISPLAY ALL THE RESULT IN VERTICAL FORM BY OPENING OUR FILE AND USING SHOWDATA FUNCTION
void display_all()
{
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    while (inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
    {
        st.showdata();
        cout << "\n\n====================================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

//SEARCHING THE STUDENT RESULT IN OUR FILE BY FACULTY ONLY
void display_sp(int n)
{
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag = false;
    while (inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
    {
        if (st.getIDNum() == n)
        {
            st.showdata();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\nrecord not exist";
    cin.ignore();
    cin.get();
}

// STUDENT LOGIN
void print_sp(int n, int pass)
{
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag = false;
    while (inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
    {
        if (st.getIDNum() == n && st.getpassword() == pass)
        {
            st.showdata();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\nInvalid Password or Registration Number : ";
    cin.ignore();
    cin.get();
}

// MODIFYING THE STUDENT RESULT BY FACULTY ONLY
void modify_student(int n)
{
    bool found = false;
    student st;
    fstream File;
    File.open("student.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    while (!File.eof() && found == false)
    {

        File.read(reinterpret_cast<char *>(&st), sizeof(student));
        if (st.getIDNum() == n)
        {
            st.showdata();
            cout << "\n\nPlease Enter The New Details of student" << endl;
            st.getdata();
            int pos = (-1) * static_cast<int>(sizeof(st));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&st), sizeof(student));
            cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
    cin.ignore();
    cin.get();
}

// STUDENT RESULT IS DELETED BY THE FACULTY ONLY
void delete_student(int n)
{
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("Temp.dat", ios::out);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
    {
        if (st.getIDNum() != n)
        {
            outFile.write(reinterpret_cast<char *>(&st), sizeof(student));
        }
    }
    outFile.close();
    inFile.close();
    remove("student.dat");
    rename("Temp.dat", "student.dat");
    cout << "\n\n\tRecord Deleted ..";
    cin.ignore();
    cin.get();
}

// DISPLAY ALL THE RESULT IN TABULAR FORM BY OPENING OUR FILE AND USING SHOWDATA FUNCTION
void class_result()
{
    student st;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\t\tALL STUDENTS RESULT \n\n";
    cout << "==========================================================\n";
    cout << "R.No       Name        P   C   M   E   CS   %age   Grade" << endl;
    cout << "==========================================================\n";
    while (inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
    {
        st.show_tabular();
    }
    cin.ignore();
    cin.get();
    inFile.close();
}

// HERE FACULTY TO LOGIN BY THE PASSWORD (GIVEN BY INSTITUTE) AND FILL , MODIFY , DELETE , SEARCH , DISPLAY THE STUDENT RESULT
// AND PROVIDING THE STUDENTS THIER ID NUMBERS
void facultylogin()
{
    string pass = "";
    char ch;
    int num;
    cout << "Enter Faculty Password : ";
    ch = _getch();
    while (ch != 13)
    {
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if (pass == "12345")
    {
        do
        {
            system("cls");
            cout << "\t=================================================";
            cout << "\n\n\t1.CREATE STUDENT RECORD";
            cout << "\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
            cout << "\n\n\t3.SEARCH STUDENT RECORD ";
            cout << "\n\n\t4.MODIFY STUDENT RECORD";
            cout << "\n\n\t5.DELETE STUDENT RECORD";
            cout << "\n\n\t6. DISPLAY CLASS RESULT";
            cout << "\n\n\t7. EXIT";
            cout << "\n\n\t=================================================";
            cout << "\n\n\tPlease Enter Your Choice (1-7): ";
            cin >> ch;
            system("cls");
            switch (ch)
            {
            case '1':
                write_student();
                break;
            case '2':
                display_all();
                break;
            case '3':
                cout << "\n\n\tPlease Enter Student's ID number: ";
                cin >> num;
                display_sp(num);
                break;
            case '4':
                cout << "\n\n\tPlease Enter Student's ID number: ";
                cin >> num;
                modify_student(num);
                break;
            case '5':
                cout << "\n\n\tPlease Enter Student's ID number: ";
                cin >> num;
                delete_student(num);
                break;
            case '6':
                class_result();
                break;
            case '7':
                return;

            default:
                cout << "\a";
            }
        } while (ch != '7');
    }
    else
    {
        cout << "\n\t\t\aSORRY!! , INVAID PASSWORD\n"
                "\t\tContact Institute If You Forget The Password ...\n\n";
    }
}

// HERE , STUDENT CHECKS HIS RESULT AND NOTIFICATION LAUNCHED BY INSTITUTE
void student_result()
{
    int n, pass;
    int choice1;

    do
    {
        cout << "\n1.FOR NOTIFICATION"
                "\n2.FOR RESULT"
                "\n3.EXIT"
                "\nEnter your choice : ";
        cin >> choice1;

        switch (choice1)
        {
        case 1:
            cout << "\n\n\t1.FIRST SEM Result is updated on site on 28/08/2021.\n"
                    "\n\n\t2.Exam Form for SECOND SEM will be released soon.\n"
                    "\n\n\t3.REAP form for Admission are Launched by Rajsthan Govt.\n"
                    "\n\n\t4.Hostel Form for FIRST SEM are postponed due to COVID-19.\n"
                    "\n\n\t5.Form for DSC CLUB are released, Fill Fast! Limited seats.\n"
                    "\n\n\t6.Study pods 2.0 projects Winner is Declared. (SP202).\n\n\n";
            break;
        case 2:
            cout << "Enter your ID number : ";
            cin >> n;
            cout << "Enter Your Password : ";
            cin >> pass;
            system("cls");
            print_sp(n, pass);
            system("cls");
            break;

        case 3:
            system("cls");
            return;

        default:
            cout << "\t\t\aINVALID CHOICE!!\n\n";
            cout << "\a";
        }
    } while (choice1 != 3);
}

// MAIN FUNCTION
int main()
{
    string choice;
    char ch;
    cout.setf(ios::fixed | ios::showpoint);
    cout << setprecision(2);
    cout << "\n\t\t\t\t\t******************************************"
            "\n\t\t\t\t\tM.B.M ENGINEERING COLLEGE , JODHPUR 342001\n"
            "\t\t\t\t\t******************************************\n";

    cout << "\n------------------------------------ Hello!! , Welcome to the M.B.M Engineering  Portal --------------------------------\n\n";

    cout << "1. LOGIN AS FACULTY MEMBER \n"
            "2. LOGIN AS STUDENT MEMBER \n"
            "3. CLOSE THE APPLICATION "
            "\n\nNOTE - 1.ONLY THOSE STUDENT LOGIN WHOSE DATA IS SAVED BY FACULTY MEMBERS."
            "\n       2.IF YOU ARE NEW STUDENT KINDLY CONTACT YOUR SUBJECT FACULTY IMMEDIATELY.\n\n"
            "\nEnter your Choice : ";
    cin >> choice;
    if (choice == "1")
    {
        facultylogin();
        main();
    }
    else if (choice == "2")
    {
        student_result();
        main();
    }
    else if (choice == "3")
    {
        cout << "----------------------------------THANK YOU FOR USING THIS PORTAL ------------------------------\n ";
        exit(0);
    }
    else
    {
        cout << "\n\t\tINVALID CHOICE!!\n"
             << endl;
    }
    cout << "----------------------------------THANK YOU FOR USING THIS PORTAL ------------------------------\n ";

    return 0;
}
// THANK YOU
