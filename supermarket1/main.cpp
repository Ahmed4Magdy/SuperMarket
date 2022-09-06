#include<iostream>
using namespace std;
//functions
void user_page();
void manager_page();
void show_menu();
void buyproduct();
void buyproductbag();
void showthereciept();
void manager_page();
void create();
void login();
void manager_proces(string name);
void add();
void edit();
void name(int x);
void pricce(int x);
void both(int x);

//variables
int menu_size = 9;
string username="ahmed";
string password = "123";


//Arrays
string products[20] = { "rice","salat","potato",
		"tomato","carrots","onions","banana","apple","bottels" };
int price[20] = { 30,40,60,80,30,40,40,50,20 };

int main() {

	cout << "---------------supermarket-----------------" << endl;
	cout << endl;
	cout << " press to start the program" << endl;
	getchar();
	int choise_enter;
	do {
		cout << " choose the mood from the following :" << endl;
		cout << "1-user" << endl;
		cout << "2-manger" << endl;
		cout << "3-exit" << endl;



		cout << "enter number from access number " << endl;
		cin >> choise_enter;
		cout << endl;



		switch (choise_enter) {
		case 1:
			user_page();
			break;

		case 2:
				manager_page();
			break;
		}
	} while (choise_enter != 3);

}




void user_page() {
	string user_name;
	int choise_userdoing;
	cout << "please,enter your name :" << endl;
	cin >> user_name;

	cout << "---------------" << " welcome " <<  user_name << "--------------" << endl;

	do {
					cout << "please,what you can do :" << endl;
					cout << "1-show the menu" << endl;
					cout << "2-buy a product" << endl;
					cout << "3-exit" << endl;


					cout << "enter number from access number" << endl;
					cin >> choise_userdoing;
					switch (choise_userdoing) {

					case 1:
						show_menu();
						break;
					case 2:
						buyproduct();
						break;
					}

	} while (choise_userdoing!=3);
}

void show_menu() {
	for (int i = 0;i < menu_size;i++) {
		cout << i + 1 << " - " << products[i] << "        " << price[i] << "lE" <<endl;
	}
}

void buyproduct() {

	int products_bag[15];
	int num_products;
	int choise_product;

	do {
		cout << "please, choose the process : " << endl;
		cout << endl;

		cout << "1-buy products " << endl;
		cout << "2-show the reciept" << endl;
		cout << "3-return to main page" << endl;
		
		cout << endl;
		
		cout << " enter  choise number from access number" << endl;
		cin >> choise_product;

		switch (choise_product) {
		case 1:
			buyproductbag();
			break;

		case 2:

			showthereciept();
			break;


		}
	}
	while (choise_product!=3);
	return ;
}

	void buyproductbag(){

		int products_bag[15];
		int num_products;

		cout << "enter number the product " << endl;
		cin >> num_products;

		for (int i = 0;i < num_products;i++) {
			cout << "enter number the products " << endl;
			cin >> products_bag[i];
		}

		cout << " order Done " << endl;
	}


void showthereciept() {

	int sum = 0;
	int products_bag[15];
	int num_products;
	cout << "--------------- your reciept -----------------" << endl;

	cout << "enter number the products" << endl;
	cin >> num_products;
	for (int j = 0;j < num_products;j++) {

		cout << "enter number the products" << endl;
		cin >> products_bag[j];

		sum += price[products_bag[j] - 1];
		cout << products[products_bag[j] - 1] << "   " << price[products_bag[j] - 1] << endl;

	}
	cout << endl;
	cout << " total cost : " << sum << endl;

}

void manager_page() {
	int choise_manager;
	do {
		cout << endl;
		cout << " choose the mood of the following" << endl;
		cout << "1-create a new email" << endl;
		cout << "2-login" << endl;
		cout << "3-return to main page" << endl;


		cin >> choise_manager;

		switch (choise_manager)
		{
		case 1:
			create();
			break;
		case 2:
			login();
			break;
		case 3:
			break;

		}
	} while (choise_manager != 3);
}

	void create() {
		string user_name;
		string rename;
		string password;
		string repassword;

		cout << "enter your useer name" << endl;
		cin >> user_name;
		cout << endl;
		cout << "enter your password" << endl;
		cin >> password;
		cout << endl;

		cout << "now login to open the program" << endl;
		cout << endl;
		cout << "ReEnter your name" << endl;
		cin >> rename;
		cout << endl;

		cout << "ReEnter your password" << endl;
		cin >> repassword;
		cout << endl;

		if (user_name == rename && password == repassword) {
			manager_proces(rename);
		}
		else {
			cout << "wrong input, try once again for access" << endl;
			cout << endl;

				create();
		}
	}

	void login() {
		string name,passwordd;
		cout << "please,enter your name" << endl;
		cin >> name;
		cout << "please,enter your password" << endl;
		cin >> passwordd;

		if (name == username  && passwordd == password) {
			manager_proces(username);
		}
		else {
			login();
		}

	}


	void manager_proces(string name) {
		cout << " welcome sir " << name << endl;
		cout << endl;
		int choise_process;
		do {
					cout << "choose the mood of the following" << endl;
					cout << endl;
					cout << "1-add element to the menu" << endl;
					cout << "2-edit an element in the menu" << endl;
					cout << "return back" << endl;

					cin >> choise_process;

					switch (choise_process) {
					case 1:
						add();
						break;
					case 2:
						edit();
						break;
					case 3:
						break;
					}

		} while (choise_process !=3);
		
}

	void add()
	{


		cout << "now the menu has 9 element" << endl;
		cout << "enter the new size you want" << endl;
		cin >> menu_size;


		if (menu_size > 9) {


				for (int i = 0;i < menu_size - 9;i++) {
					cout << "enter the new product name" << endl;
					cin >> products[i + 9];

					cout << "enter the new product price" << endl;
					cin >> price[i + 9];
				}

				cout << " done " << endl;
				cout << " Do you want show to the menu?(yes/no)" << endl;
				string check;
				cin >> check;

				if (check == "yes") {
					show_menu();
				}
				else if (check == "no") {
					manager_proces("sir");
				}




		}

		else if (menu_size < 9 && menu_size>0) {
			cout << " done " << endl;
			cout << " Do you want show to the menu?(yes/no)" << endl;
			string check;
			cin >> check;

			if (check == "yes") {
				show_menu();
			}
			else if (check=="no") {
				manager_proces("sir");
			}

		}
		
	}

	int x;
	void edit()
	{
		int num_products, products_num;
		
		cout << "how many the number of product to edit" << endl;
		cin >> num_products;
		cin >> x;
		for (int i = 0;i < num_products;i++) {
			cout << "enetr the number of the product to edit" << endl;
			cin >> products_num;

			cout << "want  to edit name or price" << endl;
			cout << "1-name" << endl;
			cout << "2-price" << endl;
			cout << "3-both" << endl;

			int choise_edit;
			cin >> choise_edit;
			switch (choise_edit) {
			case 1:
				name(products_num);
				break;
			case 2:
				pricce(products_num);
				break;
			case 3:
				both(products_num);
				break;

			}



		}
	}

	void name( int products_num) {
		string newname;
		cout << "enter the new product name" << endl;
		cin >> newname;
		products[products_num - 1] = newname;

		cout << "do ypu want show the menu?(yes/no)" << endl;
		string check;
		cin >> check;
		if (check == "yes") {
			show_menu();
		}
		else if (check == "no") {
			manager_proces("sir");
		}
	}


	void pricce(int products_num){
		int newpricce;

		cout << "enter the new product pricce" << endl;
		cin >> newpricce;
		products[products_num - 1] = newpricce;

		cout << "do ypu want show the menu?(yes/no)" << endl;
		string check;
		cin >> check;
		if (check == "yes") {
			show_menu();
		}
		else if (check == "no") {
			manager_proces("sir");
		}
	}


	void both(int products_num) {
		
		 name(products_num);
		 pricce(products_num);

		cout << "do ypu want show the menu?(yes/no)" << endl;
		string check;
		cin >> check;
		if (check == "yes") {
			show_menu();
		}
		else if (check == "no") {
			manager_proces("sir");
		}
	}