
/*                          Project                          */


#include<iostream>
using namespace std;


 // ------------------  Person Class  -------------------
class Person {
protected:
    static int id;
    string name;
    string password;
public:
     //constructor
    Person() {
        id++;
        name = " ";
        password = " ";
    }

    // parametrised
    Person(string n, string p) {
        name = n;
        password = p;
    }

     //Setter
    void set_name(string n) {
        name = n;
    }

    void set_password(string p) {
        password = p;
    }

     //Getter
    int get_id() {
        return id;
    }
    string get_name() {
        return name;
    }
    string get_password() {
        return password;
    }

     // Methods
    bool isName(string testNameSize) {
        if (testNameSize.length() >= 5 && testNameSize.length() <= 20) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isPass(string testPassSize) {
        if (testPassSize.length() >= 8 && testPassSize.length() <= 20) {
            return true;
        }
        else {
            return false;
        }
    }

    void Display() {
        cout << "--------------------------" << endl;
        cout << ".......... So .........." << endl;
        cout << "--------------------------" << endl;
        cout << "Your id : " << id << endl;
        cout << "Your name : " << name << endl;
        cout << "Your Password is : ";
        for(int i = 1; i <= password.length(); i++){
            cout << "*";
        }
        cout << endl;
        
    }
    

     // distruction
    ~Person() {

    }
};
int Person :: id = 0;

 //------------------  Client Class  -------------------

class Client : public Person {
private:
    double balance;

public:
   //  Constructor
    Client() {
        balance = 1500;
    }

     //Parametrised
    Client(string n, string p, double b) : Person(n, p) {
        balance = b;
    }

     //Setter
    void set_balance(double b) {
        balance = b;
    }

     //Getter
    double get_balance() {
        return balance;
    }

     //Methods

    double deposit(double amount) {
        balance += amount;
        return balance;
    }

    double withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        }
        else {
             cout << "amount exceeded" << endl;
        }
        return balance;
    }

    double transferTo(Client& a, double amount) {
        if (amount <= balance) {
            a.deposit(amount);
            balance -= amount;
        }
        else {
            cout << "amount exceeded" << endl;
        }
        return balance;
    }

    double checkBalance() {
        return balance;
    }


    void Display() {
        Person::Display();
        cout << "Your balance is : " << balance << endl;
        cout << "Thank You ..." << endl;
    }

     // Distructor
    ~Client() {

    }
};

 // ------------------  Employee Class  -------------------

class Employee : public Person {
private:
    double empSalary;

public:
    // constructor
    Employee() {
        empSalary = 5000;
    }

    // parametrised
    Employee(string n, string p, double amount) : Person(n, p) {
        empSalary = amount;
    }

    // Setter
    void set_empSalary(double amount) {
        empSalary = amount;
    }

    // Getter
    double get_empSalary() {
        return empSalary;
    }

    // Methods
    void Display() {
        Person::Display();
        cout << "Your balance is : " << empSalary << endl;
        cout << "Thank You ..." << endl;
    }
};

// ------------------  Admin Class  -------------------

class Admin : public Employee {
private:
    double adminSalary;

public:
    // constructor
    Admin() {
        adminSalary = 5000;
    }

    // parametrised
    Admin(string n, string p, double amount, double salary) : Employee(n, p, amount) {
        adminSalary = salary;
    }

    // Setter
    void set_adminSalary(double salary) {
        adminSalary = salary;
    }

    // Getter
    double get_adminSalary() {
        return adminSalary;
    }

    // Methods
    void Display() {
        Person::Display();
        cout << "Your balance is : " << adminSalary<< endl;
        cout << "Thank You ..." << endl;
    }
};


// ------------------  Main Class  -------------------

int main() {
    
    Client c, c2;
    Employee e, e2;
    Admin a1;
    
    //
    string n; // for name
    string p; // for password
    
    /// start
    cout << "                   Hello Dear ...." << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "1 - Client " << endl;
    cout << "2 - Employee " << endl;
    cout << "3 - Admin " << endl;
    cout << "Please Choose from one to three : ";
    
    int x;
    cin >> x;
    
    //  //      Option 1
    if (x == 1) {
        cout << "--------------------------" << endl;
        cout << "...... Hello Client ......" << endl;
        cout << "--------------------------" << endl;
        cout << "Your id is : " << c.get_id() << endl;

        cout << "Create your name : ";
        cin >> n;

        if(c.isName(n) == 1){
            c.set_name(n);
        } else{
            cout << "error ...  please enter name between 5 to 20 : ";
            cin >> n;
            c.set_name(n);
        }

        cout << "Create your password : ";
        cin >> p;
        if(c.isPass(p) == 1){
            c.set_password(p);
        } else {
            cout << "error ...  please enter password between 5 to 20 : ";
            cin >> p;
            c.set_password(p);
        }

        
        cout << "Write your amount to deposit : ";
        double a;
        cin >> a;
        c.deposit(a);
        
        cout << "Do you want to withdraw ? y/n : ";
        char y_or_n;
        char y_or_n2;
        cin >> y_or_n;
        if(y_or_n == 'y'){
            cout << "Write your amount to withdraw : ";
            double w;
            cin >> w;
            c.withdraw(w);
        } else{
            cout << "So you want to transfer ? y/n : ";
            cin >> y_or_n2;
            if(y_or_n2 == 'y'){
                cout << "Write your amount to transfer : ";
                double t;
                cin >> t;
                c.transferTo(c2, t);
            } else{
                cout << "--- Okay dear ." << endl;
            }
        }
        c.Display();

    }
    //  //      Option 2
    else if (x == 2) {
        cout << "--------------------------" << endl;
        cout << "...... Hello Employee ......" << endl;
        cout << "--------------------------" << endl;
        cout << "Your id is : " << Employee().get_id() << endl;

        cout << "Create your name : ";
        cin >> n;
        if(e.isName(n) == 1){
            e.set_name(n);
        } else {
            cout << "error ...  please enter name between 5 to 20 : ";
            cin >> n;
            e.set_name(n);
        }

        cout << "Create your password : ";
        cin >> p;
        if(e.isPass(p) == 1){
            e.set_password(p);
        } else {
            cout << "error ...  please enter password between 5 to 20 : ";
            cin >> p;
            e.set_password(p);
        }
        
        cout << "Do yo want to add client account ? y/n : ";
        char y_or_n3;
        char y_or_n4;
        cin >> y_or_n3;
        string c_name;
        string c_pass;
        double c_bal;
        string c_search;
        
        if(y_or_n3 == 'y'){
            cout << "Please create her name : ";
            cin >> c_name;
            c2.set_name(c_name);
            
            cout << "Please create her password : ";
            cin >> c_pass;
            c2.set_password(c_pass);
            
            cout << "Please create her balance : ";
            cin >> c_bal;
            c2.set_balance(c_bal);
        } else if (y_or_n3 == 'n'){
            cout << "So do you want searching a client ? y/n : ";
            cin >> y_or_n4;
            if(y_or_n4 == 'y'){
                cout << "Please enter her name : ";
                cin >> c_search;
                if (c_search.length() == c.get_name().length()){
                    cout << "-- Yes Found --" << endl;
                } else{
                    cout << "-- Not Found --" << endl;
                }
            } else{
                cout << "Okay dear .. " << endl;
            }
        }
        
        e.Display();
        cout << "--------------------------" << endl;
        cout << "New client name is : " << c2.get_name() << endl;
        cout << "New client password is : ";
        for(int i = 1; i <= c2.get_password().length(); i++){
            cout << "*";
        }
        cout << endl;
        cout << "New client balane is : " << c2.get_balance() << endl;
        cout << "Thank You ..." << endl;
    }
    
//  //      Option 3
    else if (x == 3) {
        cout << "--------------------------" << endl;
        cout << "...... Hello Admin ......" << endl;
        cout << "--------------------------" << endl;
        cout << "Your id is : " << a1.get_id() << endl;

        cout << "Create your name : ";
        cin >> n;
        if(a1.isName(n) == 1){
            a1.set_name(n);
        } else {
            cout << "Error ...  please enter name between 5 to 20 : ";
            cin >> n;
            a1.set_name(n);
        }

        cout << "Create your password : ";
        cin >> p;
        if(a1.isPass(p) == 1){
            a1.set_password(p);
        } else {
            cout << "Error ...  please enter password between 5 to 20 : ";
            cin >> p;
            a1.set_password(p);
        }
        
        cout << "Do yo want to add employee account ? y/n : ";
        char y_or_n5;
        char y_or_n6;
        cin >> y_or_n5;
        string e_name;
        string e_pass;
        double e_bal;
        string e_search;
        
        if(y_or_n5 == 'y'){
            cout << "Please create her name : ";
            cin >> e_name;
            e2.set_name(e_name);
            
            cout << "Please create her password : ";
            cin >> e_pass;
            e2.set_password(e_pass);
            
            cout << "Please create her balance : ";
            cin >> e_bal;
            e2.set_empSalary(e_bal);
            
        } else if (y_or_n5 == 'n'){
            cout << "So do you want searching an employee ? y/n : ";
            cin >> y_or_n6;
            if(y_or_n6 == 'y'){
                cout << "Please enter her name : ";
                cin >> e_search;
                if (e_search.length() == e.get_name().length()){
                    cout << "-- Yes Found --" << endl;
                } else{
                    cout << "-- Not Found --" << endl;
                }
            } else{
                cout << "-- Okay dear .. " << endl;
            }
        }
        
        a1.Display();
        cout << "--------------------------" << endl;
        cout << "New employee name is : " << e2.get_name() << endl;
        cout << "New employee password is : ";
        for(int i = 1; i <= e2.get_password().length(); i++){
            cout << "*";
        }
        cout << endl;
        cout << "New client balane is : " << e2.get_empSalary() << endl;
        cout << "Thank You ..." << endl;
    }
    else {
        cout << "Please enter just between 1 to 3 " << endl;
    }

}
