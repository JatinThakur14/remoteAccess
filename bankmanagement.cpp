#include <iostream>
#include <string>
#include <time.h>
#include <chrono>
#include <vector>
#include <ctime>
#define endl '\n'
class bank
{
    std::string name;
    unsigned long long accno, balance;
    std::vector<std::string> logs;

public:
    void getAccDetail()
    {
        std::cout << "Enter Name: ";
        std::cin >> name;
        std::cout << "Enter Account No.";
        std::cin >> accno;
        std::cout << "Enter Balance: ";
        std::cin >> balance;
    }
    void accDetail()
    {
        std::cout << "\n\n************************\n"
                  << "Holder Name: " << name << endl
                  << "Account No: " << accno << endl
                  << "Available Balance: " << balance << endl
                  << "************************\n\n";
    }
    void deposit()
    {
        unsigned long int bal;
        std::time_t end_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::string a = ctime(&end_time);
        std::cout << "Enter How much money you want to take: ";
        std::cin >> bal;
        balance -= bal;
        logs.push_back(std::to_string(bal) + " Have been deducted at "+a);
    }
    void credit()
    {
        unsigned long int bal;
        std::time_t end_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::string a = ctime(&end_time);
        std::cout << "Enter How much money you want to Add: ";
        std::cin >> bal;
        balance += bal;
        logs.push_back(std::to_string(bal) + " Have been added at "+a);
    }
    void checkLogs()
    {
        std::cout << "\n\n**************\n";
        for (auto i : logs)
        {
            std::cout << i << endl;
        }
        std::cout << "**************\n\n";
    }
    void interest()
    {
        //FIXME:Work in Progress
        int inter = balance * 0.014;
        auto start_time = std::chrono::high_resolution_clock::now();
        auto current_time = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count();
        std::time_t end_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::string a = ctime(&end_time);
        while (time == 10)
        {
            balance += balance * 0.014;
            logs.push_back("Interest of " + std::to_string(inter) + "  have been added in you account at " + a);
        }
    }
};

int main()
{
    bank user;
    int x = 0;
    user.getAccDetail();
    while (x != 5)
    {
        std::cout << "1.Account Detail\n2.Add Money\n3.Take Money\n4.Check Transaction History\n5.Quit\nInput: ";
        std::cin >> x;
        if (x == 1)
        {
            user.interest();
            user.accDetail();
        }
        else if (x == 2)
        {
            user.credit();
        }
        else if (x == 3)
        {
            user.deposit();
        }
        else if (x == 4)
        {
            user.checkLogs();
        }
        else if (x == 5)
        {
            break;
        }
        else
        {
            std::cout << "\nEnter Valid Input\n";
        }
    }

    return 0;
}