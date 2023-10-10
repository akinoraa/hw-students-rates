#include <iostream>
using namespace std;

/// <summary>
/// 
/// </summary>
class DateTime
{
    int day;
    int month;
    int year;

public:
    /// <summary>
    /// method to set day of birth
    /// </summary>
    /// <param name="day"></param>
    void SetDay(int day)
    {
        if (day > 0 && day <= 31) 
        {
            this->day = day;
        }
        else
        {
            cout << "Invalid value!" << endl;
            throw "ERROR!\n";
        }
    }

    /// <summary>
    /// method to get the day of birth
    /// </summary>
    /// <returns>day</returns>
    int GetDay() const
    {
        return day;
    }

    /// <summary>
    /// method to set month of birth
    /// </summary>
    /// <param name="month"></param>
    void SetMonth(int month)
    {
        if (month >= 1 && month <= 12)
        {
            this->month = month;
        }
        else
        {
            cout << "Invalid value!" << endl;
            throw "ERROR!\n";
        }
    }
    /// <summary>
   /// method to get the month of birth
   /// </summary>
   /// <returns>month</returns>
    int GetMonth() const
    {
        return month;
    }
    /// <summary>
   /// method to set year of birth
   /// </summary>
   /// <param name="year"></param>
    void SetYear(int year)
    {
        this->year = year;
    }
    /// <summary>
   /// method to get the year of birth
   /// </summary>
   /// <returns>year</returns>
    int GetYear() const
    {
        return year;
    }

    DateTime() : DateTime(23, 3, 2005) {}

    DateTime(int day, int month) : DateTime(day, month, 2004) {}

    DateTime(int day, int month, int year)
    {
        SetDay(day);
        SetMonth(month);
        SetYear(year);
    }

    void Print() const
    {
        cout << "Date: " << day << "." << month << "." << year << endl;
    }
};

//////////////////////////////////////////////////////

class Student
{
    string name;
    string surname;
    string patronymic;
    string adress;
    string phone_number;
    DateTime birthday;
    DateTime study_start; 
  

    int* hometask_rates = nullptr;
    int hometask_rates_count = 0;

    int* practice_rates = nullptr;
    int practice_rates_count = 0;

    int* exam_rates = nullptr;
    int exam_rates_count = 0;

public:

    Student():Student("Max","Smith", "Antonovych", "Bunina", "0978463746", { 9, 10, 2000 }, {1, 9, 2022}) {}

    Student(string name, string surname):Student("Max", "Smith", "Antonovych", "Bunina", "0978463746", { 9, 10, 2000 }, { 1, 9, 2022 }) {}

    Student(string name, string surname, string patronymic, string adress, string phone_number, DateTime birthday, DateTime study_start)
    {
        SetSurname(name);
        SetName(surname);
        SetPatronymic(patronymic);
        SetAdress(adress);
        SetPhoneNumber(phone_number);
        SetBirthday({ 18, 7, 2003 });
        SetStudyStart({ 9, 10, 2023 });
    }

    // TO DO: constructors overloading !!!

    // TO DO: make copy c-tor

    /// <summary>
    /// 
    /// </summary>
    ~Student()
    {
        if (hometask_rates != nullptr)
        {
            delete[] hometask_rates;
            hometask_rates = nullptr;
        }
        if (practice_rates != nullptr)
        {
            delete[] practice_rates;
            practice_rates = nullptr;
        }
        if (exam_rates != nullptr)
        {
            delete[] exam_rates;
            exam_rates = nullptr;
        }
    }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="name"></param>
    void SetName(string name)
    {
        this->name = name;
    }

    string GetName() const
    {
        return name;
    }

private:
    void SetBirthday(const DateTime& birthday)
    {
        this->birthday = birthday;
    }

public:
    DateTime GetBirthday() const
    {
        return birthday;
    }

    void SetStudyStart(const DateTime& study_start)
    {
        this->study_start = study_start;
    }

    DateTime GetStudyStart() const
    {
        return study_start;
    }

    /// <summary>
    /// à method that allows you to change a student's last name
    /// </summary>
    /// <param name="surname">some new value for student surname</param>
    void SetSurname(string surname)
    {
        this->surname = surname;
    }

    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    string GetSurname() const
    {
        return surname;
    }


    void SetPatronymic(string patronymic)
    {
        this->patronymic = patronymic;
    }

    string GetPatronymic() const
    {
        return patronymic;
    }

    void SetAdress(string adress)
    {
        this->adress = adress;
    }

    string GetAdress() const
    {
        return adress;
    }

    void SetPhoneNumber(string phone_number)
    {
        if (phone_number.length() > 11 && phone_number.length() < 9)
        {
            cout << "Incorrect value for parameter rate. Value must be from 10" << endl;
            throw "ERROR!";
        }
        else
            this->phone_number = phone_number;
    }

    string GetPhoneNumber() const
    {
        return phone_number;
    }

    /// <summary>
    /// This method involves adding a grade to the student's homework grade list, and the grade should be between 1 and 12 points 
    /// </summary>
    /// <param name="rate">value from 1 to 12</param>
    void AddHometaskRate(unsigned int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter rate. Value must be from 1 to 12\n";
            throw "ERROR!";
        }

        if (hometask_rates_count == 0)
        {
            hometask_rates = new int[1];
            hometask_rates[0] = rate;
        }
        else
        {
            int* temp = new int[hometask_rates_count + 1];
            for (int i = 0; i < hometask_rates_count; i++)
                temp[i] = hometask_rates[i];
            temp[hometask_rates_count] = rate;
            delete[] hometask_rates;
            hometask_rates = temp;
        }
        hometask_rates_count++;
    }

    void PrintHometaskRates() const
    {
        cout << "Hometasks rates: ";
        for (int i = 0; i < hometask_rates_count; i++)
        {
            cout << hometask_rates[i] << ", ";
        }
        cout << "\n";
    }

    int GetHometaskRateByIndex(unsigned int index)
    {
        if (index >= hometask_rates_count)
        {
            cout << "Incorrect index when accessing the evaluation array\n";
            throw "ERROR!";
        }
        return hometask_rates[index];
    }

    int GetHometasksRatesCount() const
    {
        return hometask_rates_count;
    }

    void AddPracticRate(int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter rate. Value must be from 1 to 12" << endl;
            throw "ERROR!";
        }

        if (practice_rates_count == 0)
        {
            cout << "Add first rate!" << endl;
            practice_rates = new int[1];
            practice_rates[0] = rate;
        }
        else
        {
            cout << "Add yet another rate" << endl;
            int* temp = new int[practice_rates_count + 1];
            for (int i = 0; i < practice_rates_count; i++)
            {
                temp[i] = practice_rates[i];
                temp[i + 1] = rate;
            }
            delete[] practice_rates;
            practice_rates = temp;
        }

        practice_rates_count++;
    }

    int GetPracticetasksRatesCount() const
    {
        return practice_rates_count;
    }

    void AddExamRate(int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter rate. Value must be from 1 to 12" << endl;
            throw "ERROR!";
        }

        if (exam_rates_count == 0)
        {
            cout << "Add first rate!" << endl;
            exam_rates = new int[1];
            exam_rates[0] = rate;
        }
        else
        {
            cout << "Add yet another rate" << endl;
            int* temp = new int[exam_rates_count + 1];
            for (int i = 0; i < exam_rates_count; i++)
            {
                temp[i] = exam_rates[i];
                temp[i + 1] = rate;
            }
            delete[] exam_rates;
            exam_rates = temp;
        }

        exam_rates_count++;
    }


    int GetExamtasksRatesCount() const
    {
        return exam_rates_count;
    }

    // There should not be a setter for the number of grades in a class, because there is a special way to add a grade, and there is no other way to influence this process.

    // TO DO: show what can happen if return pointer to array
    /* int* GetHometaskRates() const
    {
        int* copy = new int[hometask_rates_count];
        for (int i = 0; i < hometask_rates_count; i++)
        {
            copy[i] = hometask_rates[i];
        }
        return copy;
    }*/

    // TO DO: a lot of work here...

void PrintHomeTaskRates() const
{
    for (int i = 0; i < hometask_rates_count; i++)
    {
        cout << i + 1 << ")" << hometask_rates[i] << endl;
    }
}
void PrintPracticeTaskRates() const
{
    for (int i = 0; i < practice_rates_count; i++)
    {
        cout << practice_rates_count << ")" << practice_rates[i] << endl;
    }
}
void PrintExamTaskRates() const
{
    for (int i = 0; i < exam_rates_count; i++)
    {
        cout << exam_rates_count << ")" << exam_rates[i] << endl;
    }
}

void Print() const
{
    cout << "Surname: " << surname << endl;
    cout << "Nane: " << name << endl;
    cout << "Patronymic: " << patronymic << endl;
    cout << "Adress: " << adress << endl;
    cout << "Phone number: " << phone_number << endl;
}

};

int main()
{
    Student s1;
    DateTime d1;
    DateTime d2(2, 5);
    DateTime d3(18, 7, 2003);

    s1.Print();
    cout << "Birthday: ";
    s1.GetBirthday().Print();
    cout << "Study day: ";
    s1.GetStudyStart().Print();

    cout << "Rates for home tasks: " << endl;
    s1.AddHometaskRate(10);
    s1.PrintHomeTaskRates();
    s1.AddHometaskRate(11);
    s1.PrintHomeTaskRates();
    s1.AddHometaskRate(12);
    s1.PrintHomeTaskRates();
    cout << endl;

    cout << "Rates for practice tasks: " << endl;
    s1.AddPracticRate(11);
    s1.PrintPracticeTaskRates();
    s1.AddPracticRate(11);
    s1.PrintPracticeTaskRates();
    s1.AddPracticRate(12);
    s1.PrintPracticeTaskRates();
    cout << endl;

    cout << "Rates for exam tasks: " << endl;
    s1.AddExamRate(10);
    s1.PrintExamTaskRates();
    s1.AddExamRate(11);
    s1.PrintExamTaskRates();
    cout << endl;

}