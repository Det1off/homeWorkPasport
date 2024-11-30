#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Visa {
private:
    string country;      
    string issueDate;    
    string expiryDate;   
    string visaType;     

public:
    Visa(const string& country, const string& issueDate, const string& expiryDate, const string& visaType)
        : country(country), issueDate(issueDate), expiryDate(expiryDate), visaType(visaType) {
    }

    void ShowVisa() const {
        cout << "Страна: " << country << ", Тип визы: " << visaType
            << ", Выдана: " << issueDate << ", Действует до: " << expiryDate << "\n";
    }
};


class Passport {
private:
    string firstName;
    string lastName;
    string passportNumber;
    string nationality;
    string dateOfBirth;
    string placeOfIssue;

public:
    Passport(const string& firstName, const string& lastName, const string& passportNumber,
        const string& nationality, const string& dateOfBirth, const string& placeOfIssue)
        : firstName(firstName), lastName(lastName), passportNumber(passportNumber),
        nationality(nationality), dateOfBirth(dateOfBirth), placeOfIssue(placeOfIssue) {
    }

    virtual void ShowInfo() const {
        cout << "Имя: " << firstName << ", Фамилия: " << lastName
            << ", Номер паспорта: " << passportNumber << ", Гражданство: " << nationality
            << ", Дата рождения: " << dateOfBirth << ", Место выдачи: " << placeOfIssue << "\n";
    }
};


class ForeignPassport : public Passport {
private:
    vector<Visa> visas;

public:
    ForeignPassport(const string& firstName, const string& lastName, const string& passportNumber,
        const string& nationality, const string& dateOfBirth, const string& placeOfIssue)
        : Passport(firstName, lastName, passportNumber, nationality, dateOfBirth, placeOfIssue) {
    }


    void AddVisa(const Visa& visa) {
        visas.push_back(visa);
    }


    void ShowVisas() const {
        if (visas.empty()) {
            cout << "Нет виз.\n";
        }
        else {
            cout << "Список виз: \n";
            for (const auto& visa : visas) {
                visa.ShowVisa();
            }
        }
    }


    void ShowInfo() const override {
        Passport::ShowInfo();
        ShowVisas();
    }
};

int main() {

    ForeignPassport myPassport("Иван", "Иванов", "AB1234567", "Украина", "01.01.1990", "Киев");


    myPassport.AddVisa(Visa("США", "01.06.2023", "01.12.2023", "Туристическая"));
    myPassport.AddVisa(Visa("Канада", "15.07.2023", "15.07.2025", "Рабочая"));
    myPassport.ShowInfo();


}
