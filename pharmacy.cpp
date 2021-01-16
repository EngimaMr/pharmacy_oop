#include<iostream>
#include<string>
using namespace std;
//class parent name
class person
{
	// Encapsulation
protected:
	string name;
	string address;
	string sex;
	int phone;
	string email;
public:
	//Default constructor
	person() {
		cout << "WELCAME TO YOU IN PHARMACY MANAGMANT SYSTEM " << endl;
		cout << "Please Enter YOUR INFORMATION " << endl;
		cout << " YOUR NAME IS : "; cin >> name;
		cout << " YOUR ADDress IS : "; cin >> address;
		cout << " YOUR SEX IS : "; cin >> sex;
		cout << " YOUR Phone Number IS : "; cin >> phone;
		cout << " YOUR E-mail address IS : "; cin >> email;
	}
	//Parameterized constructor
	//fuction ovreloading
	person(string n, string ad, string x, int ph, string eml)
	{
		name = n;
		address = ad;
		sex = x;
		phone = ph;
		email = eml;
	}
	//pure virtual function
	virtual float total_salary() = 0;//abstrcation
	//function overridingvirtual void print
	virtual void print()
	{
		cout << " Name is = " << name << "\t" << " Address is = " << address << "\t" << "Sex is = " << sex << endl;
		cout << "Phone Number = " << phone << "\t" << " E-mail address = " << email << endl;
	}
};
//Inheritance
//class child
class employee :public person
{
	// Encapsulation
private:
	float salary;
	int overtime_hours;
	float overtime_hour_rate;
public:
	//Parameterized constructor
	employee(string n, string ad, string x, int ph, string eml, float s, int ovh, float ovhr) :person(n, ad, x, ph, eml)
	{
		salary = s;
		overtime_hours = ovh;
		overtime_hour_rate = ovhr;
	}
	//Default constructor
	//fuction ovreloading
	employee()
	{
		cout << " your salary is : "; cin >> salary;
		cout << " YOUR overtime_hours IS : "; cin >> overtime_hours;
		cout << " YOUR overtime_houre_rate IS : "; cin >> overtime_hour_rate;
	}
	float total_salary() //fuction
	{
		return salary + (overtime_hours * overtime_hour_rate);
	}
	void print()//function overriding
	{
		person::print();
		cout << "YOUR salary := " << salary << "\t" << " overtime_hours = " << overtime_hours << "\t" << " overtime_hours = " << overtime_hours << endl;
	}
};

//class shild
//Inheritance
class client :public person
{
	// Encapsulation
private:
	float money;
	float Discount;
public:
	//Parameterized constructor
	client(string n, string ad, string x, int ph, string eml, float mo, float dis) :person(n, ad, x, ph, eml)
	{
		money = mo;
		Discount = dis;
	}
	//Default constructor
	//fuction ovreloading
	client() {
		cout << " YOUR MONEY IS :"; cin >> money;
		cout << " YOUR Discount from pharmacy :"; cin >> Discount;
	}
	float total_salary()//function
	{
		return (money - Discount);
	}
	void print()//function overriding
	{
		person::print();
		cout << " MONEY IS : = " << money << endl;
		cout << " YOU have Discount in this prodution : " << Discount << endl;
	}
};
//class parent name
class medicin
{
	// Encapsulation
protected:
	string company;
	string medicine;
	int ID;
	int price;
	int Date;
	string quality;
public:
	//Parameterized constructor
	medicin(string co, string med, int i, int prc, int dt, string qt)
	{
		company = co;
		medicine = med;
		ID = i;
		price = prc;
		Date = dt;
		quality = qt;
	}
	//Default constructor
	//fuction ovreloading
	medicin()
	{
		cout << " ENTER information of medicine please " << endl;
		cout << " company production of medicin : "; cin >> company;
		cout << " NAME OF medicine : "; cin >> medicine;
		cout << " ID number of medicin : "; cin >> ID;
		cout << " PRICE OF MEDIcin : "; cin >> price;
		cout << " Production Date Medicince : "; cin >> Date;
	}
	//pure virtaul functin
	virtual string qulite() = 0;
	//virtual function
	virtual void showData()
	{
		cout << "company production : " << company << "\t" << " NAME medicine : " << medicine << "\t" << " ID number : " << ID << endl;
		cout << "PRICE IS = " << price << "\t" << "Production Date :" << Date << endl;
	}
};
//Inheritance
//class child
class tablet :public medicin
{
	// Encapsulation
private:
	string type;
public:
	//Parameterized constructor
	tablet(string co, string med, int i, int prc, int dt, string qt, string typ) :medicin(co, med, i, prc, dt, qt)
	{
		type = typ;
	}
	//Default constructor
	//fuction ovreloading
	tablet()
	{
		cout << "Enter THe TYPE of medicine tablets :"; cin >> type;
	}
	//function overriding
	string qulite()
	{
		return quality;
	}
	void showData()//function overriding
	{
		medicin::showData();
		cout << "name of medicine tablets is : " << type << endl;
	}
};//Inheritance
//class child
class liquid :public medicin
{
	// Encapsulation
private:
	string type;
public:
	//Parameterized constructor
	liquid(string co, string med, int i, int prc, int dt, string qt, string typ) :medicin(co, med, i, prc, dt, qt)
	{
		type = typ;
	}
	//Default constructor
	//fuction ovreloading
	liquid()
	{
		cout << "Enter THe TYPE of medicine liquid :"; cin >> type;
	}
	string qulite()//function overriding
	{
		return quality;
	}
	void showData()//function overriding
	{
		medicin::showData();
		cout << " name of medicine liquid is : " << type << endl;
	}
};
int main()
{
	int n;
	cout << "WELCOME \n";
	cout << " menu of pharmacy management system " << endl;
	cout << " to Managing staff and doctors press number 1:" << endl; cout << " To manage drug files and tablet types press numer 2:" << endl;
	cout << " To manage drug files and liquid types press numer 3:" << endl;
	cout << " To manage customer files press number 4: " << endl;
	cin >> n;
	if (n == 1) {
		person* ptr;//using pointer
		employee m;
		ptr = &m;
		ptr->print();// Polymorphism
		ptr->total_salary();// Polymorphism
	}
	else if (n == 2) {
		medicin* ntr;//using pointer
		tablet ta;
		ntr = &ta;
		ntr->showData();// Polymorphism
		ntr->qulite();// Polymorphism
	}
	else if (n == 3)
	{
		medicin* ntr;//using pointer
		liquid li;
		ntr = &li;
		ntr->showData();// Polymorphism
		ntr->qulite();// Polymorphism
	}
	else if (n == 4) {
		person* ptr;//using pointer
		client c;
		ptr = &c;
		ptr->print();// Polymorphism
		ptr->total_salary();// Polymorphism
	}
	else
	{
		cout << "Invalid number plese enter any number" << endl;
		cin >> n;
	}
	return 0;
}