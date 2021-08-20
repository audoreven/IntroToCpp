#include <iostream>
#include <string>
#include <array>

using namespace std;

/*******************************/
//	       Parent Class
/*******************************/
class Product
{
public:
	Product(void);
	Product(string desc, float p, float w, float x, float y, float z);

	string description;
	void set_price(float p);
	void set_weight(float w);
	void set_shippingDimensions(float x, float y, float z);
	float get_price();
	float get_weight();
	float* get_shippingDimensions();
	void displayInfo();
private:
	float price;
	float weight;
	float shipping_dimensions[3];
};

/*******************************/
//		Children Classes
/*******************************/
class Food : Product
{
public:
	Food(void);
	Food(string expr, string cat);

	void set_expr_date(string expr_date);
	void set_cat(string cat);
	string get_expr_date();
	string get_cat();
	void display_info();
private:
	string expiration_date;
	string category;
};

class Toy : Product
{
public:
	Toy(void);
	Toy(string age, string safety);

	void set_age(string age_grp);
	void set_safety_info(string safe);
	string get_age();
	string get_safety_info();
	void display_info();
private:
	string age_group;
	string safety_info;
};


/****************************************/
//				   main()
/****************************************/

int main() 
{
	// creating classes
	Food food1;
	Food food2("06/24/2021", "Fruits");

	Toy toy1;
	Toy toy2("5+", "Keep away from very young children. Risk of choking.");

	// displaying info for the objects
	cout << "Display info for food 1: " << endl;
	food1.display_info(); 
	cout << "Display info for food 2: " << endl;
	food2.display_info();
	cout << "Display info for toy 1: " << endl;
	toy1.display_info();
	cout << "Display info for toy 2: " << endl;
	toy2.display_info();
	cout << endl << endl;

	// testing getters and setters
	cout << "Testing getters and setters" << endl;
	food1.set_expr_date("06/24/21");
	food1.set_cat("Vegetables");
	cout << "Food 1 new expr date: " << food1.get_expr_date() << endl;
	cout << "Food 1 new category: "<< food1.get_cat() << endl;
	cout << endl;

	toy1.set_age("13+");
	toy1.set_safety_info("Keep away from young children. Material on cards may be inappropriate for children.");
	cout << "Toy 1 new age group: " << toy1.get_age() << endl;
	cout << "Toy 1 new safety info: " << toy1.get_safety_info() << endl;

	return 0;
}

/****************************************/
//		    Function Definitions
/****************************************/

/***********************/
//	  Constructors
/***********************/

// base
Product::Product(void) {
	description = "";
	price = 0;
	weight = 0;
	shipping_dimensions[0] = shipping_dimensions[1] = shipping_dimensions[2] = 0.0;
}

Product::Product(string desc, float p, float w, float x, float y, float z) {
	description = desc;
	price = p;
	weight = w;
	shipping_dimensions[0] = x;
	shipping_dimensions[1] = y;
	shipping_dimensions[2] = z;
}


// derived
Food::Food(void) {
	expiration_date = "";
	category = "";
}

Food::Food(string expr, string cat) {
	expiration_date = expr;
	category = cat;
}

Toy::Toy(void) {
	age_group = "";
	safety_info = "";
}

Toy::Toy(string age, string safety) {
	age_group = age;
	safety_info = safety;
}
	

/***********************/
//  getters and setters
/***********************/

// base
void Product::set_price(float p) 
{
	price = p;
}
void Product::set_weight(float w) 
{
	weight = w;
}
void Product::set_shippingDimensions(float x, float y, float z) 
{
	shipping_dimensions[0] = x;
	shipping_dimensions[1] = y;
	shipping_dimensions[2] = z;
}
float Product::get_price() 
{
	return price;
}
float Product::get_weight() 
{
	return weight;
}
float* Product::get_shippingDimensions() 
{
	return shipping_dimensions;
}


//derived
void Food::set_expr_date(string expr_date) 
{
	expiration_date = expr_date;
}

void Food::set_cat(string cat) 
{
	category = cat;
}

string Food::get_expr_date() 
{
	return expiration_date;
}

string Food::get_cat() 
{
	return category;
}


void Toy::set_age(string age_grp)
{
	age_group = age_grp;
}
void Toy::set_safety_info(string safe)
{
	safety_info = safe;
}
string Toy::get_age()
{
	return age_group;
}
string Toy::get_safety_info()
{
	return safety_info;
}

/***********************/
//	    get infos
/***********************/

// base
void Product::displayInfo() {
	cout << description << endl
		<< "Price: " << price << endl
		<< "Weight: " << weight << endl
		<< "Shipping Dimensions: " << shipping_dimensions[0]
		<< "x" << shipping_dimensions[1]
		<< "x" << shipping_dimensions[2] << endl;
}


// derived 
void Food::display_info() {
	Product::displayInfo();
	cout << endl << "Expiration Date: " << expiration_date
		<< endl << "Category: " << category << endl;
}

void Toy::display_info() {
	Product::displayInfo();
	cout << endl << "Age Group: " << age_group
		<< endl << "Safety Info: " << safety_info << endl;

}