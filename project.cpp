#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int acc = 0;
int regoption, paisay;
string senderaccount, no, user;
string setTpass, Setacc, setuser;
string filename;

int reset();
int login();
string mainmenu();
void accounts();
int Tpassset(string);
int continution();
int sendmoney();
int Transactionpass();
void transactionpayment(int r, string id, string filename);
void transactioncurrency(string cn, int am, string filename);
int registermenu();
string changeContactInfo(string file, string arr[], int to);

string updateAccountDetails();
int changeSecurityInfo(string arr[]);
void clearTransactionHistory();

string updateAccountDetails()
{
    string choice;

    cout << "\nSelect what you want to update:" << endl;
    cout << "1) Name" << endl;
    cout << "2) Password" << endl;
    cout << "3) Transaction Password" << endl;
    cout << "4) Contact Information" << endl;
    cout << "5) Security Question and Answer" << endl;
    cout << "6) Clear Transaction History" << endl;
    cout << "0) Exit" << endl;
    cout<<"select choice ( 1-6/0 ) : ";
    cin >> ws;
    getline(cin, choice);
    if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" && choice != "0")
    {
        cout << "Error : Invalid choice " << endl;
        return "0";
    }
    int choice1 = stoi(choice);
    ifstream read("account.txt");
    string arr[100];
    int check = 1;
    for (int i = 0; !read.eof(); i++)
    {
        read >> arr[i];
        check++;
        if (i >= 100)
        {
            break;
        }
    }
    string file, word;
    int to;
    system("cls");

    switch (choice1)
    {
    case 1:
        cout << "Enter new name: ";
        file = "name.txt";
        to = 1;
        changeContactInfo(file, arr, to);
        break;
    case 2:
        cout << "Enter new password: ";
        file = "pass.txt";
        to = 2;
        changeContactInfo(file, arr, to);
        break;
    case 3:
        setTpass = "0";
        word = "new";
        Tpassset(word);
        break;
    case 4:
        cout << "Enter new contact: ";
        file = "contact.txt";
        to = 3;
        changeContactInfo(file, arr, to);
        break;
    case 5:
       
        changeSecurityInfo(arr);
        break;
    case 6:
        clearTransactionHistory();
        break;
    case 0:
        cout << "Exiting update menu." << endl;
        break;
    default:
        cout << "Invalid choice. Please select again." << endl;
        break;
    }

    return "0";
}

string changeContactInfo(string file, string arr[], int to)
{
    string neww;
    cin >> ws;
    getline(cin, neww);
    cout<<"Enter -99 at any point to exit"<<endl;
    switch (to)
    {
    case 1:
        if (neww == "-99")
        {
            system("cls");

            return "0";
        }
        else if (!isalpha(neww[0]) && !isdigit(neww[0]) || (isdigit(neww[0])))
        {
            cout << "First letter must be alphabet" << endl;

            return "0";
        }
        else if (neww.length() < 5)
        {
            cout << "Enter atleast Five Character." << endl;

            return "0";
        }
        cout << "Name updated successfully." << endl;

        break;
    case 2:
        if (neww == "-99")
        {
            system("cls");

            return "0";
        }

        if (neww.length() < 8)
        {
            cout << "Password must contains eigth characters ." << endl;

            return "0";
        }
        cout << "Password updated successfully." << endl;
        break;
    case 3:
        if (neww == "-99")
        {
            system("cls");
            return "0";
        }
        if (neww.length() < 11 || neww.length() > 11)
        {
            cout << "Contact contains 11 numbers. " << endl;
            return "0";
        }
        for (int i = 0; i < neww.length() - 1; i++)
        {
            if (!isdigit(neww[i]))
            {
                cout << "Contact include only  numbers";

                return "0";
            }
        }
        if (neww[0] != '0' || neww[1] != '3')
        {
            cout << "Invalid Formate (03---)" << endl;

            return "0";
        }
        cout << "Contact updated successfully." << endl;
        break;
    }

    ifstream read2(file);
    string arr1[100];
    int check = 1;
    for (int i = 0; !read2.eof(); i++)
    {
        read2 >> arr1[i];
        check++;

        if (i >= 100)
        {
            break;
        }
    }
    read2.close();
    for (int i = 0; i < check; i++)
    {
        if (Setacc == arr[i])
        {
            arr1[i] = neww;
            break;
        }
    }
    ofstream nam(file);

    for (int i = 0; i < check; i++)
    {
        nam << arr1[i] << endl;
    }
    nam.close();

    return "0";
}

int changeSecurityInfo(string arr[])
{
    cout << "Enter -99 at any point to exit " << endl;
    cout << "Enter new security question: ";
    string newQuestion;
    cin >> ws;
    getline(cin, newQuestion);
    if (newQuestion == "-99")
    {
        system("cls");

        return 0;
    }
    if (newQuestion.length() > 100)
    {
        cout << "You reached the limit of 100 words " << endl;

        return 0;
    }
    cout << "Enter new answer to the security question: ";
    string newAnswer;
    getline(cin, newAnswer);
    if (newAnswer == "-99")
    {
        system("cls");
        return 0;

    }
    if (newAnswer.length() > 100)
    {
        cout << "You reached the limit of 100 words " << endl;
        return 0;
    }
    ifstream read("security.txt");
    ifstream read1("answer.txt");

    string arr1[100], arr2[100];
    int check = 1;
    for (int i = 0; !read.eof(); i++)
    {
        read >> arr1[i];
        read1 >> arr2[i];
        check++;
        if (i >= 100)
        {
            break;
        }
    }

    for (int i = 0; i < check; i++)
    {
        if (Setacc == arr[i])
        {

            arr1[i] = newQuestion;
            arr2[i] = newAnswer;
            break;
        }
    }
    ofstream nam("security.txt");
    ofstream nam1("answer.txt");
    for (int i = 0; i < check; i++)
    {
        nam << arr1[i];
        nam1 << arr2[i];
        cout << "Security question and answer updated successfully." << endl;
        nam.close();
        nam1.close();
        break;
    }

    return 0;
}

void clearTransactionHistory()
{
    ofstream clearFile("text_" + Setacc + ".txt", ofstream::trunc);
    clearFile.close();

    cout << "Transaction history cleared successfully." << endl;
}

void currencywallet()
{
    ifstream read("currencycash_" + Setacc + ".txt");
    double arr[6];
    for (int i = 0; i < 6; i++)
    {
        read >> arr[i];
        if (i >= 6)
        {
            break;
        }
    }
    read.close();
    cout << "You have " << arr[0] << " USD " << endl;
    cout << "You have " << arr[1] << " CAD " << endl;
    cout << "You have " << arr[2] << " EUR " << endl;
    cout << "You have " << arr[3] << " JPY " << endl;
    cout << "You have " << arr[4] << " TRY " << endl;
    cout << "You have " << arr[5] << " SAR " << endl;
}
int Tpassset(string word)
{
    if (setTpass == "0")
    {
        cout<<"Enter -99 to exit at any point to point "<<endl;
        ifstream read("account.txt"), read1("T-pass.txt");
        cout << "Enter the " << word << " transaction pass of atleast 5 charactors for " << Setacc << " : ";
        string T_pass;
        cin >> ws;
        getline(cin, T_pass);
        if(T_pass=="-99"){
            system("cls");
            return 0;
        }
        if (T_pass.length() < 5)
        {
            cout << "Password must be at least five letters : " << endl;
            cout << "Do you want to enter again (1/0) : ";
            string opt;
            getline(cin, opt);
            if (opt == "1")
            {
                Tpassset(word);
            }
            else
            {
                return 0;
            }
        }
        else
        {
            string arr[100], arr1[100];
            int check = 1;
            for (int i = 0; !read.eof(); i++)
            {
                read >> arr1[i];
                read1 >> arr[i];
                check++;
                if(i>=100){
                    break;
                }
            }
            for (int i = 0; i < check; i++)
            {
                if (Setacc == arr1[i])
                {
                    arr[i] = T_pass;
                    break;
                }
            }
            read.close(), read1.close();
            ofstream pss("T-pass.txt");
            for (int i = 0; i < check; i++)
            {
                pss << arr[i] << endl;
            }
            pss.close();
            cout << "Your " << word << " transaction password for account " << Setacc << " has been set" << endl;
            setTpass = T_pass;
            return 1;
        }
    }
    else
    {
        cout << "You are not allowed " << endl;
    }
    return 0;
}

int paym(string x, int r, string id)
{
    ifstream read("pass.txt");
    ifstream read1("account.txt");
    ifstream read2("cash_" + Setacc + ".txt");
    ifstream read3("payment_" + Setacc + ".txt");
    int cash;
    read2 >> cash;
    read2.close();
    int py;
    read3 >> py;
    read3.close();
    int   check = 1;
    string arr1[100];
    for (int i = 0; !read1.eof(); i++)
    {

        read1 >> arr1[i];
        check++;
        if(i>=100){
            break;
        }
    }
    read1.close();
    cout << "Enter the Transaction password : ";
    string pass;
    cin >> ws;
    getline(cin, pass);
    for (int i = 0; i < check; i++)
    {
        if (Setacc == arr1[i])
        {

            if (r <= cash)
            {
                if (pass == setTpass)
                {
                    cout << x << " of " << r << " has been paid." << endl;
                    cash -= r;

                    ofstream readd("cash_" + Setacc + ".txt",ios::trunc);
                    ofstream rr("payment_" + Setacc + ".txt", ios::trunc);

                    readd << cash ;
                    readd.close();

                    rr << py + 5;
                    rr.close();

                    transactionpayment(r, id, filename);
                    ifstream read("record_" + Setacc + ".txt");
                    int a;
                    read >> a;
                    read.close();
                    a += r;
                    ofstream cord("record_" + Setacc + ".txt");
                    cord << a;
                    cord.close();
                    return 1;
                }
                else
                {
                    cout << "Transaction password does not match." << endl;
                }
            }
            else
            {
                cout << "Not enough money in the account." << endl;
            }
        }
    }
    return 0;
}

int Transactionpass()
{
    if (setTpass == "0")
    {
        cout << "You have to set the Transaction password" << endl;
        return 0;
    }
    else
    {
        cout << "Enter the transaction password : ";
        string Tpass;
        cin >> ws;
        getline(cin, Tpass);
        ifstream read("account.txt");
        string arr11[100], a[100];
        int chh = 1;
        for (int i = 0; !read.eof(); i++)
        {
            read >> arr11[i];
            chh++;
            if (i >= 100)
            {
                break;
            }
        }
        read.close();
        int check = 0;
        for (int i = 0; i < chh; i++)
        {
            if (Setacc == arr11[i])
            {
                check++;
                if (Tpass == setTpass)
                {
                    return 1;
                }
                else if (Tpass != a[i])
                {
                    cout << "Transaction Password not matched " << endl;
                    break;
                }
            }
        }

        if (check == 0)
        {
            cout << "sender not matched ." << endl;
        }
    }
    return 0;
}

void customersupport()
{
    cout << "------- WELCOME TO CUSTOMER SUPPORT------" << endl
         << endl;
    cout << "If you have any issue you can contact customer support." << endl
         << endl;
    cout << "CUSTOMER SUPPORT NUMBER : 0328-9454860" << endl;
    cout << "CUSTOMER SUPPORT NUMBER : 0324-5053783" << endl;
    cout << "CUSTOMER SUPPORT NUMBER : 0323-8510411" << endl
         << endl;
    cout << "---Thank You!---" << endl;
}
int loan()
{
    ifstream read("validation.txt", ios::app);
    int a;
    read >> a;
    read.close();
    if (a != 1)
    {
        ifstream read("record_" + Setacc + ".txt"), read1("cash_" + Setacc + ".txt");
        int a, b;
        read >> a;
        read1 >> b;
        read.close();
        read1.close();
        cout << "According to your prvious record ." << endl;
        cout << "You are eligible for loan upto : " << (a + b) * 2 << endl
             << endl;
        cout << " Enter -99 to exit " << endl;
        cout << "Enter the amount : ";
        string cff1;
        getline(cin, cff1);
        if (cff1 == "-99")
        {
            system("cls");
            return 1;
        }
        for (int i = 0; i < cff1.length(); i++)
        {
            if (!isdigit(cff1[i]))
            {
                cout << "Error : Only numbers " << endl;
                return 1;
            }
        }
        int cff = stoi(cff1);
        if (cff <= (a + b) * 2)
        {
            cout << "Your loan amount of " << cff << " has been credited to your account ." << endl;
            b = b + cff;
            ofstream cah("cash_" + Setacc + ".txt");
            cah << b;
            cah.close();
            ofstream check("validation.txt");
            check << 1;
            check.close();
            ofstream loanammount("loan remaning_" + Setacc + ".txt");
            loanammount << cff;
            loanammount.close();
            int Toption = continution();
            if (Toption == 1)
            {
                return 7;
            }
        }
        else if (cff > (a + b) * 2)
        {
            cout << "You are not eligible for this amount ." << endl;
        }

        return 1;
    }
    else
    {
        cout << "   Beek mangya You have already taken loan ,Pay back it first." << endl;

        return 1;
    }
}
int loanpayback()
{
    ifstream read("cash_" + Setacc + ".txt"), read1("loan remaning_" + Setacc + ".txt");
    int a, b;
    read >> a;
    read1 >> b;
    read.close();
    read1.close();
    cout << "Amount to be paid : " << b << endl;
    if (b == 0)
    {
        return 0;
    }
    cout << "Enter 1 to pay : ";
    string choice1;
    getline(cin, choice1);
    if (choice1 != "1")
    {
        return 1;
    }
    int choice = stoi(choice1);

    if (choice == 1)
    {
        if (b != 0)
        {
            if (a >= b)
            {
                a -= b;
                ofstream cas("cash_" + Setacc + ".txt"), val("validation.txt"), loan("loan remaning_" + Setacc + ".txt");
                val << 0;
                cas << a;
                cas.close();
                val.close();
                cout << "Loan Paid." << endl;
                b = 0;
                loan << b;
                loan.close();
                return 0;
            }
            else if (a < b)
            {
                cout << "You do not have enough money.";
                return 0;
            }
        }
        else if (b == 0)
        {
            cout << "No remaining loan amount.";
        }
    }
    return 0;
}

int resetmenu()

{
    ifstream read("validation 4.txt");
    int a;
    read >> a;
    read.close();
    cout << "You have " << 3 - a << " attempts left" << endl;

    if (a != 3)
    {
        ifstream read("cnic.txt");
        ifstream read1("date_of_birth.txt");
        ifstream read2("name.txt");
        ifstream read3("security.txt");
        ifstream read4("us.txt");
        ifstream read5("answer.txt");
        string c, d, n, s, u, na;
        cout << "Enter -99 anytime to exit" << endl;
        cout << "Enter your usename :";
        cin >> ws;
        getline(cin, user);
        if (user == "-99")
        {
            system("cls");
            return 0;
        }

        cout << "Enter the onwer name :";
        string name;
        getline(cin, name);
        if (name == "-99")
        {
            system("cls");
            return 0;
        }
        cout << "Enter your CNIC: ";
        string cnic;
        getline(cin, cnic);
        if (cnic == "-99")
        {
            system("cls");
            return 0;
        }
        cout << "Enter date of birth : ";
        string date;
        getline(cin, date);
        if (date == "-99")
        {
            system("cls");
            return 0;
        }
        string arr[100], arr1[100];

        for (int i = 0; !read.eof(); i++)
        {
            getline(read5, arr[i]);
            getline(read3, arr1[i]);
            if (i >= 100)
            {
                break;
            }
        }

        for (int i = 0; getline(read, c) && getline(read1, d) && getline(read2, na) && getline(read4, u); i++)
        {
            if (cnic == c && date == d && user == u && name == na)
            {
                setuser = u;
                cout << arr1[i] ;
                cout << "Answer the question: ";
                string ans;
                getline(cin, ans);
                if (ans == "-99")
                {
                    system("cls");
                    return 0;
                }
                if (ans == arr[i])
                {
                    cout << "You can now reset." << endl;
                    ofstream va("validation 4.txt");
                    va << 0;
                    va.close();
                    read.close();
                    read1.close();
                    read2.close();
                    read3.close();
                    read4.close();
                    read5.close();

                    return 1;
                }
                if (i >= 100)
                {
                    break;
                }
            }
        }
        cout << "Incorrect information, try again.\n";
        ofstream va("validation 4.txt");
        a++;
        va << a;
        va.close();
        read.close();
        read1.close();
        read2.close();
        read3.close();
        read4.close();
        int option = continution();
        if (option == 1)
        {
            return 4;
        }
    }
    else if (a == 3)
    {
        cout << "You have reached your limit you must contact customer support." << endl;
        return 4;
    }

    return 0;
}

int reset()
{
    string arr[100];
    string arr1[100];

    ifstream read3("us.txt");
    ifstream read2("pass.txt");
    int count3 = 1;
    for (int i = 0; !read3.eof(); i++)
    {
        getline(read2, arr1[i]);
        getline(read3, arr[i]);
        count3++;
        if (i >= 100)
        {
            break;
        }
    }

    read2.close();
    read3.close();

    for (int b = 0; b < count3; b++)
    {
        if (setuser == arr[b])
        {
            cout << "Enter -99 to exit without resetting." << endl;
            cout << "Enter the reset password (except -99) : ";
            string p;
            cin >> ws;
            getline(cin, p);
            if (p == "-99")
            {
                return 0;
            }
            if (p.length() < 8)
            {
                cout << "Password must contains eigth characters ." << endl;

                return reset();
            }
            arr1[b] = p;
            ofstream pasw("pass.txt");

            for (int i = 0; i < count3; i++)
            {
                pasw << arr1[i] << endl;
            }

            pasw.close();
            cout << "Password has been reseted." << endl;
            ofstream val("validation 3.txt");
            val << 0;
            val.close();
            return 1;
            break;
        }
    }
    cout << "Password has not been reseted" << endl;

    return 0;
}

int currency()
{
    ifstream read("cash_" + Setacc + ".txt");
    int A;
    read>>A;
    read.close();
    ifstream read1("account.txt");
    int count = 1;
    string arr1[100];
    for(int i=0;!read1.eof();i++){
        read1>>arr1[i];
        count++;
        if(i>=100){
            break;
        }
    }
    read1.close();
    cout << "Enter -99 at any point to exit " << endl;
    cout << "Enter the amount to convert: ";
    string am1;
    getline(cin, am1);
    if (am1 == "-99")
    {
        system("cls");
        return 1;
    }
    for (int i = 0; i < am1.length(); i++)
    {
        if (!isdigit(am1[i]))
        {
            cout << "Error : Only Numbers" << endl;
            return 1;
        }
    }

    int am = stoi(am1);

    int check = -1;
    for (int i = 0; i < count; i++)
    {
        if (Setacc == arr1[i])
        {
            check = i;
            break;
        }
    }

    if (check == -1)
    {
        cout << "Account not matched" << endl;
        return 0;
    }

    if (am > A)
    {
        cout << "Not enough money" << endl;
        return 1;
    }

    cout << "1. US DOLLARS (USD)" << endl
         << "2. CANADIAN DOLLARS (CAD)" << endl
         << "3. EURO (EUR)" << endl
         << "4. JAPANESE YEN (JPY)" << endl
         << "5. TURKISH LIRA (TRY)" << endl
         << "6. SAUDI RIYAL (SAR)" << endl
         << "7. Exit " << endl;
    cout << "Select choice (1-7): ";
    string choice1;
    cin >> ws;
    getline(cin, choice1);
    if (choice1 != "1" && choice1 != "2" && choice1 != "3" && choice1 != "4" && choice1 != "5" && choice1 != "6" && choice1 != "7")
    {
        cout << "Invalid choice!" << endl;
        return 1;
    }
    if (choice1 == "7")
    {
        return 7;
    }
    system("cls");
    int choice = stoi(choice1);
    double val[] = {1.0, 1.3, 0.85, 110.0, 8.5, 3.75};
    string currencyNames[] = {"USD", "CAD", "EUR", "JPY", "TRY", "SAR"};
    ofstream c("cash_" + Setacc + ".txt");
    if (choice < 1 || choice > 6)
    {
        cout << "Invalid choice. Please select a number between 1 and 6." << endl;
        return 0;
    }

    double tax = 0.07;
    double convertedAmount = am / val[choice - 1] * (1 - tax);
    A -= am;
    string cn = currencyNames[choice - 1];

    cout << "You selected " << cn << endl;
    cout << "Currency value: " << val[choice - 1] << " " << cn << endl;
    cout << "The " << am << " PKR converted into " << convertedAmount << " " << currencyNames[choice - 1] << " after 7% tax" << endl;
    cout << "Remaining amount in account: " <<  A << endl;
    transactioncurrency(cn, am, filename);
    ofstream write("cash_" + Setacc + ".txt");
        write <<  A;
    write.close();
    ifstream read3("record_" + Setacc + ".txt");
    int a;
    read >> a;
    read3.close();
    a += am;
    ofstream reco("record_" + Setacc + ".txt");
    reco << a;
    reco.close();
    ifstream read4("currencycash_" + Setacc + ".txt");
    double arr2[6];
    for (int i = 0; i < 6; i++)
    {
        read4 >> arr2[i];
    }
    read4.close();
    arr2[choice - 1] = convertedAmount;
    ofstream curcash("currencycash_" + Setacc + ".txt");
    for (int i = 0; i < 6; i++)
    {
        curcash << arr2[i] << endl;
    }
    curcash.close();
    return 1;
}

string menu()
{
    string option;
    cout << " 1. Accounts " << endl
         << " 2. Money Transfer " << endl
         << " 3. Payments " << endl
         << " 4. Currency Exchange " << endl
         << " 5. Loan " << endl
         << " 7. Settings " << endl;
    cout << "Select the option: ";
    cin >> ws;
    getline(cin, option);
    return option;
}

int login()

{
    ifstream read("validation 3.txt");
    int a;
    read >> a;
    read.close();
    cout << "You have " << 3 - a << " attempts left" << endl;
    if (a != 3)
    {
        ifstream read1("us.txt");
        ifstream read("pass.txt");
        ifstream read2("account.txt");
        ifstream read3("T-pass.txt");
        cout << "  Enter -99 On both options to exit anytime " << endl;
        cout << "Enter your username: ";
        string user;
        cin >> ws;
        getline(cin, user);
        if (user == "-99")
        {
            system("cls");
            return 0;
        }

        cout << "Enter your password: ";
        string pass;
        cin >> ws;
        getline(cin, pass);

        if (pass == "-99")
        {
            system("cls");

            return 0;
        }
        string u;
        string f;

        while (getline(read1, u) && getline(read, f) && getline(read2, Setacc) && getline(read3, setTpass))
        {
            filename = "text_" + Setacc + ".txt";
            if (user == u)
            {
                if (f == pass)
                {
                    ofstream va("validation 3.txt"), re("validation 4.txt");
                    va << 0;
                    re << 0;
                    re.close();
                    va.close();
                    read.close();
                    read1.close();
                    system("cls");
                    return 1;
                }
            }
        }
        read.close();
        read1.close();

        cout << "You have entered wrong credentials.\n";
        ofstream val("validation 3.txt");
        a++;
        val << a;
        val.close();
        cout << "Do you want to enter again (1 for yes , 2 for No) : ";
        string opt;
        cin >> ws;
        getline(cin, opt);
        if (opt != "1" && opt != "2")
        {
            cout << "Invalid choice !" << endl;
            int option = continution();
            if (option == 1)
            {
                system("cls");
                return 0;
            }
        }
        system("cls");

        if (opt == "1")
        {

            if (a <= 3)
            {
                return login();
            }
            else
            {
                system("cls");
                return 0;
            }
        }

        else if (opt == "2")
        {

            return 0;
        }
    }
    else if (a == 3)
    {
        cout << "You have reached your limit you must reset orr contact customer support." << endl;
    }

    return 0;
}

int registermenu()

{
    string reg, regpass, cni, contact, date, name, ac, TPass;
     int acc;
    ifstream read("accountcheck.txt");
    string a;
    read >> a;
    read.close();
  if (a.empty()) {
        acc = 0;
    } else {
        acc = stoi(a);
    }
   

    cout << "Enter -99 at any point to exit the registration." << endl
         << endl;
    cout << "Enter your 5 character username (First letter must be alphabet ) : ";
    cin >> ws;
    getline(cin, reg);
    if (reg == "-99")
    {
        system("cls");

        return 2;
    }
    if (!isalpha(reg[0]) && !isdigit(reg[0]) || (isdigit(reg[0])))
    {
        cout << "First letter must be alphabet" << endl;

        return 0;
    }
    if (reg.length() < 5)
    {
        cout << "Enter atleast Five Character." << endl;

        return 0;
    }
    ifstream readUsers("us.txt");

    string u;
    while (getline(readUsers, u))
    {
        if (u == reg)
        {
            cout << "Username already exists." << endl;

            return 1;
        }
    }

    readUsers.close();

    cout << "Enter your 8 digit password (execpt -99): ";
    cin >> ws;
    getline(cin, regpass);

    if (regpass == "-99")
    {
        system("cls");

        return 2;
    }

    if (regpass.length() < 8)
    {
        cout << "Password must contains eigth characters ." << endl;

        return 0;
    }
    system("cls");
    cout << "      Please enter additional details." << endl;
    cout << "Enter -99 at any point to exit the registration." << endl
         << endl;

    cout << "Enter your full name (Only alphabets) : ";
    getline(cin, name);

    if (name == "-99")
    {
        system("cls");

        return 2;
    }

    for (int i = 0; i < name.length(); i++)
    {
        if (!isalpha(name[i]) && name[i] != ' ')
        {
            cout << "Full Name include only has letters";
            return 0;
        }
    }
    cout << "Enter your 13 digit CNIC (3************): ";

    getline(cin, cni);
    if (cni == "-99")
    {
        system("cls");

        return 2;
    }
    if (cni.length() < 13 || cni.length() > 13)
    {
        cout << "Error :CNIC must contains 13 numbers. " << endl;
        return 0;
    }
    for (int i = 0; i < cni.length(); i++)
    {
        if (!isdigit(cni[i]))
        {
            cout << "CNIC include only has numbers";
            return 0;
        }
    }
    if (cni[0] != '3')
    {
        cout << "Invalid Formate ( 3---)" << endl;
        return 0;
    }
    ifstream readCNIC("cnic.txt");

    string c;
    while (getline(readCNIC, c))
    {
        if (c == cni)
        {
            cout << "CNIC already registered." << endl;

            return 1;
        }
    }
    readCNIC.close();
    cout << "Enter your date of birth (DD-MM-YYYY): ";
    getline(cin, date);
    if (date == "-99")
    {
        system("cls");

        return 2;
    }

    
    if (!isdigit(date[0]) && !isdigit(date[1]) && !isdigit(date[3]) && !isdigit(date[4]) && !isdigit(date[6]) && !isdigit(date[7]) && !isdigit(date[8]) && !isdigit(date[9]))
    {
        cout << "Days / Month / Year Must contains numbers." << endl;
        return 0;
    }
 
    if(date[0]=='3'){
        if (date[1]!='0'&&date[1]!='1'){
            cout<<"Invalid Formate!"<<endl;
            return 0;
        }
    }
        if(date[3]=='1'){
        if (date[4]!='2'&&date[1]!='1'){
            cout<<"Invalid Formate!"<<endl;
            return 0;
        }
    }

    if(date[0]=='0'){
        if(date[1]=='0'){
            cout<<"Invalid Formate!"<<endl;
            return 0;
        }
    }if(date[3]=='0'){
        if(date[4]=='0'){
            cout<<"Invalid Formate!"<<endl;
            return 0;
        }}
    if (date.length() != 10)
    {
        cout << "Invalid Formate." << endl;
        return 0;
    }
    if ((date[2] != '-') || (date[5] != '-'))
    {
        cout << "Invalid Formate !" << endl;
        return 0;
    }
    
    if (date[6] == '2')
    {
        if (date[7] == '0')
        {
            if (date[8] == '0')
            {
                if (date[9] == '8' || date[9] == '9')
                {
                    cout << "Below age (minimum age is 18)" << endl;
                    return 2;
                }
            }
            else if ((date[8] == '1') || (date[8] == '2'))
            {
                cout << "Below age (minimum age is 18)" << endl;
                return 2;
            }
            else
            {
                cout << "Invalid age input!" << endl;
                return 0;
            }
        }
        else
        {
            cout << "Invalid age input!";
            return 0;
        }
    }

    else if (date[6] == '1')
    {
        if (date[7] == '9')
        {
            if (date[8] == '2' || date[8] == '1')
            {
                cout << "You are not allowed because  you are 90+ " << endl;
                return 2;
            }
            if (date[8] == '3')
            {
                if ((date[9] == '0') || (date[9] == '1') || (date[9] == '2') || (date[9] == '3'))
                {
                    cout << "You are not allowed because  you are 90+ " << endl;
                    return 2;
                }
            }
        }
        else
        {
            cout << "Invalid age !" << endl;
            return 0;
        }
    }
    else
    {
        cout << "Invalid age !" << endl;
        return 0;
    }

    cout << "Enter your 11 digit contact number (03*********): ";
    getline(cin, contact);
    if (reg == "-99")
    {
        system("cls");
        return 2;
    }
    if (contact.length() < 11 || contact.length() > 11)
    {
        cout << "Contact contains 11 numbers. " << endl;
        return 0;
    }
    for (int i = 0; i < contact.length() - 1; i++)
    {
        if (!isdigit(contact[i]))
        {
            cout << "Contact include only  numbers";

            return 0;
        }
    }
    if (contact[0] != '0' || contact[1] != '3')
    {
        cout << "Invalid Formate (03---)" << endl;

        return 0;
    }

    ifstream readContact("contact.txt");

    string co;
    while (getline(readCNIC, c) && getline(readContact, co))
    {

        if (co == contact)
        {
            cout << "Contact number already registered." << endl;

            return 1;
        }
    }
    readContact.close();

    system("cls");
    cout << "Enter -99 at any point to exit " << endl;
    cout << "   Almost registered." << endl;
    cout << "Enter your security question (maximun 100 words):";
    string question;
    getline(cin, question);

    if (question == "-99")
    {
        system("cls");

        return 2;
    }
    if (question.length() > 100)
    {
        cout << "You reached the limit of 100 words " << endl;

        return 0;
    }

    cout << "Enter the answer of security question (Maximum 100 words) :";
    string answer;
    getline(cin, answer);
    if (answer == "-99")
    {
        system("cls");

        return 2;
    }
    if (answer.length() > 100)
    {
        cout << "You reached the limit of 100 words " << endl;

        return 0;
    }
    ofstream ques;
    ques.open("security.txt", ios::app);
    ques << question << endl;
    ques.close();
    ofstream answ;
    answ.open("answer.txt", ios::app);
    answ << answer << endl;
    answ.close();
    ac = to_string(acc);
    ofstream acs("account.txt", ios::app);
    ofstream usr("us.txt", ios::app);
    ofstream pas("pass.txt", ios::app);
    ofstream Tpss("T-pass.txt", ios::app);
    Tpss << "0" << endl;
    usr << reg << endl;
    pas << regpass << endl;
    acs << acc << endl;
    acs.close();
    usr.close();
    pas.close();
    acs.close();  

    ofstream na("name.txt", ios::app);
    ofstream cnic("cnic.txt", ios::app);
    ofstream birth("date_of_birth.txt", ios::app);
    ofstream con("contact.txt", ios::app);
    ofstream pay("payment_" + ac + ".txt", ios::app);
    ofstream rec("record_" + ac + ".txt", ios::app);
    ofstream cur("currencycash_" + ac + ".txt", ios::app);
    ofstream cas("cash_" + ac + ".txt");
    ofstream loan("loan remaning_" + ac + ".txt");
    loan << 0;
    cas << 20000;
    pay << 1000;
    rec << 0;

    ofstream actt("accountcheck.txt");
    acc += 1;
    actt << acc;
    actt.close();

    for (int i = 0; i < 6; i++)
    {
        cur << 0 << endl;
    }

    na << name << endl;
    cnic << cni << endl;
    birth << date << endl;
    con << contact << endl;
    cas.close();
    rec.close();
    cur.close();
    na.close();
    cnic.close();
    birth.close();
    con.close();
    pay.close();

    usr.close();
    pas.close();
    acs.close();
    Tpss.close();
    ofstream val1("validation 3.txt"), val2("validation 4.txt");
    val1 << 0;
    val2 << 0;
    val2.close();
    val1.close();
    cout << "Thank you!" << endl;
    system("cls");
    cout << "Thank you for registration!" << endl;
    int Toption = continution();
    if (Toption == 1)
    {
        return 2;
    }
    return 2;
}

int askregister()
{
    cout << "Do you want to enter again? (1 for yes, 2 for exit): ";
    cin >> regoption;
    system("cls");

    return regoption;
}

string mainmenu()
{
    string option;
    cout << "1 ) LOGIN " << endl
         << "2 ) REGISTER" << endl
         << "3 ) RESET PASSWORD" << endl
         << "4 ) CUSTOMER SUPPORT" << endl
         << "5 ) END THE PROGRAM" << endl
         << endl;
    cout << "SELECT OPTION ( 1-5 ) : ";
    getline(cin, option);
    return option;
}

void accounts()
{
    string arr1[100], arr2[100], arr3[100], arr4[100], arr5[100], A;
    ifstream read("name.txt");
    ifstream read1("cnic.txt");
    ifstream read2("date_of_birth.txt");
    ifstream read3("contact.txt");
    ifstream read4("account.txt");
    ifstream read5("cash_" + Setacc + ".txt");
    read5 >> A;
    read5.close();
    int count5 = 1;
    for (int i = 0; !read.eof(); i++)
    {
        getline(read, arr1[i]);
        getline(read1, arr2[i]);
        getline(read2, arr3[i]);
        getline(read3, arr4[i]);
        getline(read4, arr5[i]);
        count5++;
        if (i >= 100)
        {
            break;
        }
    }
    read.close();
    read1.close();
    read2.close();
    read3.close();
    read4.close();

    for (int i = 0; i < count5; i++)
    {
        if (Setacc == arr5[i])
        {
            cout << "Account number : " << arr5[i] << endl;
            cout << "Account Balance :" << A << endl;
            cout << "Owner name :" << arr1[i] << endl;
            cout << "Onwer CNIC:" << arr2[i] << endl;
            cout << "Owner date of birth :" << arr3[i] << endl;
            cout << "Owner contact : " << arr4[i] << endl;
            break;
        }
    }
}
void transactioncurrency(string cn, int am, string filename)
{
    ofstream os;
    os.open(filename, ios::app);
    os << " Account is : " << Setacc << " Converted to  : " << cn << " amount is : " << am << endl;
    os.close();
}

void transaction(int paisay, string no, string filename)
{
    ofstream os;
    os.open(filename, ios::app);
    os << "sender account is : " << Setacc << " receiver is : " << no << " amount is : " << paisay << endl;
    os.close();
}

void transactionpayment(int r, string id, string filename)
{
    ofstream os;
    os.open(filename, ios::app);
    os << "sender account is : " << Setacc << " Payment id is : " << id << " amount is : " << r << endl;
    os.close();
}

int sendmoney()
{
    string arr1[100];
    int count6 = 1;
    ifstream read("cash_" + Setacc + ".txt", ios::app), read1("account.txt", ios::app);
    int A;
    read>>A;
    read.close();
    for (int i = 0; !read1.eof(); i++)
    {
        read1 >> arr1[i];
        count6++;
        if (i >= 100)
        {
            break;
        }
    }

    read.close();
    read1.close();
    cout << "Enter -99 to exit at any point." << endl;
    cout << "Enter the receiver 5 dijit account number: ";
    string no;
    cin >> ws;
    getline(cin, no);
    if (no == "-99")
    {
        system("cls");
        return 1;
    }
    if (no.length() != 5)
    {
        cout << "Only 5 digit Account Number is allowed." << endl;
        return 1;
    }
    for (int i = 0; i < no.length() - 1; i++)
    {
        if (!isdigit(no[i]))
        {
            cout << "Error : Only Numbers" << endl;
            return 1;
        }
    }

    cout << "Enter the amount: ";
    string paisay1;
    cin >> ws;
    getline(cin, paisay1);
    if (paisay1 == "-99")
    {
        system("cls");
        return 1;
    }
    for (int i = 0; i < paisay1.length() ; i++)
    {
        if (!isdigit(paisay1[i]))
        {
            cout << "Error : Only Numbers" << endl;
            return 1;
        }
    }
    int paisay = stoi(paisay1);

    if (paisay < 0)
    {
        cout << "Invalid Transaction !" << endl;
        cout << "Do you want to enter again ? (1/0) : ";
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            sendmoney();
        }
        else
        {
            return 1;
        }
    }

    int check = 0;

    for (int b = 0; b < count6; b++)
    {
        if (Setacc == arr1[b])
        {
            check++;
            int o = Transactionpass();
            if (o == 1)
            {

                if (paisay <= A)
                {
                    A -= paisay;
                    cout << "Amount has been transferred from " << Setacc << " to " << no << endl;
                    ifstream read("record_" + Setacc + ".txt");
                    int a;
                    read >> a;
                    read.close();
                    a += paisay;
                    ofstream recor("record_" + Setacc + ".txt");
                    recor << a;
                    recor.close();
                    cout << "Remaining amount is: " << A << endl;
                    transaction(paisay, no, filename);
                    ofstream amount1("cash_" + Setacc + ".txt");
                        amount1 << A ;
                    amount1.close();
                    return 1;
                }
                else if (paisay > A)
                {
                    cout << "Not enough money in the sender account.\n";
                    break;
                }
            }
            else if (o == 0)
            {
                break;
                return 1;
            }
        }
    }

    if (check == 0)
    {
        cout << "Sender account not found.\n";
    }

    return 1;
}

string paymentmenu()
{

    cout << "1.Bill Payment" << endl
         << "2.Fee Payment" << endl
         << "3.Mobile Balance Transfer " << endl
         << "4.Shopping" << endl
         << "5.Government Payemnts " << endl
         << "6.Exit" << endl;
    cout << "Select Option (1-6) : ";
    string choice;
    getline(cin, choice);
    if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6")
    {
        cout << "Invalid option! " << endl;
        return "0";
    }
    system("cls");
    return choice;
}
void Transactiongistory()
{

    ifstream Read("text_" + Setacc + ".txt");
    string show;
    int check = 1;

    while (getline(Read, show))
    {

        cout << show << endl;
        check++;
    }
    if (check == 1)
    {
        cout << "No Transaction history available ." << endl;
    }
    Read.close();
}
int continution()
{
    cout << "Press any Number/Character to exit : ";
    string continueoption;
    getline(cin, continueoption);
    system("cls");
    return 1;
}
string setting()
{
    cout << endl;
    cout << "1.Logout" << endl
         << "2.Transaction password set." << endl
         << "3.Updation" << endl
         << "4.Customer support." << endl;
    cout << "Select (1-4) : ";
    string optio;
    cin >> ws;
    getline(cin, optio);
    if (optio == "1" || optio == "2" || optio == "3" || optio == "4")
    {
        system("cls");
        return optio;
    }
    else
    {
        cout << "Invalid choice !" << endl;
        int option = continution();
        if (option == 1)
        {
            return "0";
        }
    }
    return "0";
}
int main()
{
    system("cls");
    cout << "                                                      ----------------------------------" << endl;
    cout << "                                                      ---------------------------------- " << endl;
    cout << "                                                       WELCOME TO BANK MANAGMENT SYSTEM " << endl;
    cout << "                                                            (End-User Interface)" << endl;
    cout << "                                                             ------EDITH------" << endl;
    cout << "                                                      ----------------------------------" << endl;
    cout << "                                                      ----------------------------------" << endl
         << endl;
    while (true)
    {
        string option = mainmenu();
        system("cls");
        if (option != "3" && option != "2" && option != "1" && option != "4" && option != "5")
        {
            cout << "Invalid option" << endl;
            int Toption = continution();

            if (Toption == 1)
            {
                continue;
                ;
            }
        }
        if (option == "5")
        {
            system("cls");
            break;
        }
        system("cls");
        if (option == "1")
        {
            int option1 = login();
            if (option1 == 1)
            {
                while (true)
                {
                    string menuoption = menu();
                    system("cls");
                    if (menuoption != "1" && menuoption != "2" && menuoption != "3" && menuoption != "4" && menuoption != "5" && menuoption != "6" && menuoption != "7")
                    {
                        cout << "Invalid option" << endl;

                        cout << "Select any character to go back to Mainmenu : ";
                        string sel;
                        cin >> ws;
                        getline(cin, sel);
                        system("cls");

                        continue;
                    }
                    if (menuoption == "1")
                    {
                        cout << "1.Account Detail" << endl
                             << "2.Transaction History" << endl
                             << "3.Exit" << endl;
                        cout << "Select 1-3 : ";
                        cin >> ws;
                        string accountoption;
                        getline(cin, accountoption);
                        if (accountoption != "1" && accountoption != "2" && accountoption != "3")
                        {
                            cout << "Invalid option !" << endl;
                            cout << "Select any character to go back to Mainmenu : ";
                            string sel;
                            cin >> sel;
                            system("cls");
                            continue;
                        }
                        system("cls");

                        if (accountoption == "1")
                        {
                            accounts();
                            int option = continution();
                            if (option == 1)
                            {
                                continue;
                            }
                        }
                        else if (accountoption == "2")
                        {
                            Transactiongistory();
                            int option = continution();
                            if (option == 1)
                            {
                                continue;
                            }
                        }
                        else if (accountoption == "3")
                        {
                            continue;
                        }
                    }
                    else if (menuoption == "2")
                    {
                        int sendoption = sendmoney();
                        if (sendoption == 1)
                        {
                            int option = continution();
                            if (option == 1)
                            {
                                continue;
                            }
                        }
                    }
                    else if (menuoption == "3")
                    {
                        string opt = paymentmenu();
                        if (opt == "0")
                        {
                            int Toption = continution();
                            if (Toption == 1)
                            {
                                system("cls");
                                continue;
                            }
                        }
                        string a = Setacc;
                        ifstream read, read11("bil_numbers" + a + ".txt"), read22("fee_pay" + a + ".txt"), read44("shopping" + a + ".txt"), read55("govt." + a + ".txt");
                        read.open("payment_" + a + ".txt");
                        int r1;
                        read >> r1;
                        read.close();

                        string arrr[100], arr11[100], arr33[100], arr44[100];
                        int check = 0;

                        for (int i = 0; !read11.eof() && !read22.eof() && !read44.eof() && !read55.eof(); i++)
                        {
                            read11 >> arrr[i];
                            read22 >> arr11[i];
                            read44 >> arr33[i];
                            read55 >> arr44[i];
                            check++;
                            if (i >= 100)
                            {
                                break;
                            }
                        }
                        read11.close();
                        read22.close();
                        read44.close();
                        read55.close();
                        cout << "Enter -99 at any point to exit" << endl;
                        if (opt == "1")
                        {
                            cout << "Enter the Bill ID : ";
                            string id;
                            cin >> ws;
                            getline(cin, id);
                            if (id == "-99")
                            {
                                system("cls");
                                continue;
                            }
                            if (id.length() < 5 || id.length() > 10)
                            {
                                cout << "Invalid Format (must be at least 5 to 10 characters)" << endl;
                                int Toption = continution();
                                if (Toption == 1)
                                {
                                    continue;
                                }
                            }

                            for (int i = 0; i < id.length(); i++)
                            {
                                if (!isdigit(id[i]) && !isalpha(id[i]) || (id[i] == ' '))
                                {
                                    cout << "Error special characters are not allowed " << endl;
                                    int Toption = continution();
                                    if (Toption == 1)
                                    {
                                        continue;
                                    }
                                }
                            }
                            int flg = 1;
                            for (int i = 0; i <= check; i++)
                            {
                                if (id == arrr[i])
                                {
                                    cout << "This bill is already paid.";
                                    int Toption = continution();
                                    if (Toption == 1)
                                    {
                                        system("cls");
                                        break;
                                    }
                                    read11.close();
                                    flg++;
                                    break;
                                }
                                if (i >= 100)
                                {
                                    break;
                                }
                            }
                            if (flg == 1)
                            {

                                string x = "Bill ";
                                cout << "The Bill is : " << r1 << " rupees." << endl;
                                int pa = paym(x, r1, id);
                                if (pa == 1)
                                {
                                    ofstream b("bil_numbers" + a + ".txt", ios::app);
                                    b << id << endl;
                                    b.close();
                                }
                                read11.close();
                                int Toption = continution();
                                if (Toption == 1)
                                {
                                    continue;
                                }
                            }
                        }

                        else if (opt == "2")
                        {
                            cout << "Enter the fee slip No: ";
                            string id;
                            cin >> id;
                            if (id == "-99")
                            {
                                system("cls");
                                continue;
                            }
                            if (id.length() < 5 || id.length() > 10)
                            {
                                cout << "Invalid Format (must be at least 5 to 10 characters)" << endl;
                                int Toption = continution();
                                if (Toption == 1)
                                {
                                    continue;
                                }
                            }

                            for (int i = 0; i < id.length(); i++)
                            {
                                if (!isdigit(id[i]) && !isalpha(id[i]) || (id[i] == ' '))
                                {
                                    int Toption = continution();
                                    if (Toption == 1)
                                    {
                                        continue;
                                    }
                                }
                            }
                  
                            int flg = 1;

                            for (int i = 0; i < check; i++)
                            {
                                if (id == arr11[i])
                                {
                                    cout << "This Fee is already paid.";
                                    read22.close();
                                    flg++;
                                    break;
                                }
                                if (i >= 100)
                                {
                                    break;
                                }
                            }
                            if (flg == 1)
                            {

                                string x = "Fee ";
                                int r = r1 * 2;
                                cout << "The Fee is : " << r << " rupees." << endl;
                                int pa = paym(x, r1, id);

                                if (pa == 1)
                                {
                                    ofstream f("fee_pay" + a + ".txt", ios::app);
                                    f << id << endl;
                                    f.close();
                                }
                                read22.close();
                                int Toption = continution();
                                if (Toption == 1)
                                {
                                    continue;
                                }
                            }
                        }

                        else if (opt == "3")
                        {
                            cout << "Enter the Mobile No : ";
                            string id;
                            cin >> id;
                            if (id == "-99")
                            {
                                system("cls");
                                continue;
                            }
                            if (id.length() < 11 || id.length() > 11)
                            {
                                cout << "Contact contains 11 numbers. " << endl;
                                int Toption = continution();
                                if (Toption == 1)
                                {
                                    continue;
                                }
                            }
                            for (int i = 0; i < id.length(); i++)
                            {
                                if (!isdigit(id[i]))
                                {
                                    cout << "Contact include only  numbers";
                                    int Toption = continution();
                                    if (Toption == 1)
                                    {
                                        continue;
                                    }
                                }
                            }
                            if (id[0] != '0' || id[1] != '3')
                            {
                                cout << "Invalid Formate (03---)" << endl;
                                int Toption = continution();
                                if (Toption == 1)
                                {
                                    continue;
                                }
                            }

                            string x = "Load ";
                            cout << "Enter the load amount :";
                            string r1;
                            cin >> ws;
                            getline(cin, r1);
                            for (int i = 0; i < r1.length(); i++)
                            {
                                if (!isdigit(r1[i]))
                                {
                                    cout << "Contact include only  numbers";
                                    int Toption = continution();
                                    if (Toption == 1)
                                    {
                                        continue;
                                    }
                                }
                            }
                            int r = stoi(r1);
                            int pa = paym(x, r, id);

                            int Toption = continution();
                            if (Toption == 1)
                            {
                                continue;
                            }
                        }

                        else if (opt == "4")
                        {
                            cout << "Enter the Receipt No. : ";
                            string id;
                            cin >> id;
                            int flg = 1;
                            if (id == "-99")
                            {
                                system("cls");
                                continue;
                            }
                            if (id.length() < 5 || id.length() > 10)
                            {
                                cout << "Invalid Format (must be at least 5 to 10 characters)" << endl;
                                int Toption = continution();
                                if (Toption == 1)
                                {
                                    continue;
                                }
                            }

                            for (int i = 0; i < id.length(); i++)
                            {
                                if (!isdigit(id[i]) && !isalpha(id[i]) || (id[i] == ' '))
                                {
                                    cout << "Error special characters are not allowed " << endl;
                                    int Toption = continution();
                                    if (Toption == 1)
                                    {
                                        continue;
                                    }
                                }
                            }

                            for (int i = 0; i < check; i++)
                            {
                                if (id == arr33[i])
                                {
                                    cout << "This Bill of this Receipt no. is already paid.";
                                    read44.close();
                                    flg++;
                                    break;
                                }
                                if (i >= 100)
                                {
                                    break;
                                }
                            }
                            if (flg == 1)
                            {

                                string x = "Shopping bill ";
                                int r = r1 * 3;
                                cout << "The bill is : " << r << " rupees." << endl;
                                int pa = paym(x, r1, id);

                                if (pa == 1)
                                {
                                    ofstream s("shopping" + a + ".txt", ios::app);
                                    s << id << endl;
                                    s.close();
                                }
                            }
                            read44.close();
                            int Toption = continution();
                            if (Toption == 1)
                            {
                                continue;
                            }
                        }

                        else if (opt == "5")
                        {
                            cout << "Enter the PSID : ";
                            string id;
                            cin >> id;
                            if (id == "-99")
                            {
                                system("cls");
                                continue;
                            }
                            if (id.length() < 5 || id.length() > 10)
                            {
                                cout << "Invalid Format (must be at least 5 to 10 characters)" << endl;
                                int Toption = continution();
                                if (Toption == 1)
                                {
                                    continue;
                                }
                            }

                            for (int i = 0; i < id.length(); i++)
                            {
                                if (!isdigit(id[i]) && !isalpha(id[i]) || (id[i] == ' '))
                                {
                                    cout << "Error special characters are not allowed " << endl;
                                    int Toption = continution();
                                    if (Toption == 1)
                                    {
                                        continue;
                                    }
                                }
                            }
                            int flg = 1;

                            for (int i = 0; i < check; i++)
                            {
                                if (id == arr44[i])
                                {
                                    cout << "This PSID is already paid.";
                                    read55.close();
                                    flg++;
                                    break;
                                }
                                if (i >= 100)
                                {
                                    break;
                                }
                            }

                            if (flg == 1)
                            {
                                string x = "PSID fee ";
                                int r = r1 * 3;
                                cout << "The fee is : " << r << " rupees." << endl;
                                int pa = paym(x, r1, id);
                                if (pa == 1)
                                {
                                    ofstream s("govt." + a + ".txt", ios::app);
                                    s << id << endl;
                                    s.close();
                                }
                                read55.close();
                                int Toption = continution();
                                if (Toption == 1)
                                {
                                    continue;
                                }
                            }
                        }
                        else if (opt == "6")
                        {
                            system("cls");
                            continue;
                        }
                    }
                    else if (menuoption == "7")
                    {

                        string opt = setting();
                        system("cls");
                        if (opt == "1")
                        {
                            break;
                        }
                        else if (opt == "2")
                        {
                            string wd;
                            Tpassset(wd);
                            int Toption = continution();
                            if (Toption == 1)
                            {
                                continue;
                            }
                        }

                        else if (opt == "3")
                        {
                            updateAccountDetails();
                            int Toption = continution();
                            if (Toption == 1)
                            {
                                continue;
                            }
                        }
                        else if (opt == "4")
                        {
                            customersupport();
                            int Toption = continution();
                            if (Toption == 1)
                            {
                                continue;
                            }
                        }
                    }
                    else if (menuoption == "4")
                    {
                        cout << "1.Currency excange" << endl
                             << "2.Currency wallet" << endl
                             << "3.Exit" << endl;
                        cout << "select ( 1-3 ) ; ";
                        string choice;
                        cin >> ws;
                        getline(cin, choice);
                        if (choice != "1" && choice != "2" && choice != "3")
                        {
                            cout << "Error : Invalid choice " << endl;
                            int Toption = continution();
                            if (Toption == 1)
                            {
                                continue;
                            }
                        }
                        system("cls");
                        if (choice == "1")

                        {
                            while (true)
                            {
                                int opt = currency();
                                {
                                    if (opt == 0)
                                    {
                                        cout << "Do you want to enter again (1 for yes and 0 for no): ";
                                        int op;
                                        cin >> op;
                                        if (op == 1)
                                        {
                                            continue;
                                        }
                                        else if (op == 0)
                                        {
                                            break;
                                        }
                                    }
                                    else if (opt == 1)
                                    {
                                        int Toption = continution();
                                        if (Toption == 1)
                                        {
                                            break;
                                        }
                                    }
                                    else if (opt == 7)
                                    {
                                        system("cls");
                                        break;
                                    }
                                }
                            }
                        }
                        else if (choice == "2")
                        {
                            currencywallet();
                            int Toption = continution();
                            if (Toption == 1)
                            {
                                continue;
                            }

                            break;
                        }
                        else if (choice == "3")
                        {
                            continue;
                        }
                    }
                    else if (menuoption == "5")
                    {
                        while (true)
                        {
                            cout << "1.Get Loan " << endl
                                 << "2.Loan Pay Back." << endl
                                 << "3.Exit" << endl;
                            cout << "Select (1-3) : ";
                            string select;
                            cin >> ws;
                            getline(cin, select);
                            if (select != "1" && select != "2" && select != "3")
                            {
                                cout << "Invalid option!" << endl;
                                int Toption = continution();

                                if (Toption == 1)
                                {
                                    break;
                                }
                            }
                            system("cls");
                            if (select == "1")
                            {
                                int opt = loan();
                                if (opt == 1)
                                {

                                    int Toption = continution();

                                    if (Toption == 1)
                                    {
                                        break;
                                    }
                                }

                                else if (opt == 0)
                                {
                                    int Toption = continution();

                                    if (Toption == 1)
                                    {
                                        continue;
                                        ;
                                    }
                                }
                            }
                            else if (select == "2")
                            {
                                int opt = loanpayback();
                                if (opt == 0)
                                {
                                    int Toption = continution();

                                    if (Toption == 1)
                                    {
                                        break;
                                    }
                                }
                            }
                            else if (select == "3")
                            {
                                break;
                            }
                        }
                        continue;
                    }
                }
                continue;
            }
        }

        else if (option == "2")

        {
            while (true)
            {
                int option6 = registermenu();
                if (option6 == 1)
                {
                    int option7 = askregister();
                    if (option7 == 1)
                    {
                        continue;
                    }
                    else if (option7 == 2)
                    {
                        break;
                    }
                }
                else if (option6 == 2)
                {

                    break;
                }
            }

            continue;
        }

        else if (option == "3")
        {
            {
                int option4 = resetmenu();
                if (option4 == 1)
                {
                    int option5 = reset();
                    if (option5 == 1)
                    {
                        int opt = continution();
                        if (opt == 1)
                        {
                            system("cls");
                            continue;
                        }
                    }
                    else if (option5 == 0)
                    {
                        break;
                    }
                }
                else if (option4 == 4)
                {
                    continue;
                     int opt = continution();
                        if (opt == 1)
                        {
                            system("cls");
                            continue;
                        }
                }
            }
            continue;
        }
        else if (option == "4")
        {
            customersupport();
            int Toption = continution();

            if (Toption == 1)
            {
                continue;
                
            }
        }
    }

    return 0;
}