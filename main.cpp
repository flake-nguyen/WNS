#include "linked_list.h"
#include "goods.h"

int main() {
	goods* head = NULL;
	int x, y, q, z, t, e;
	string a, b, c;
	
	while (1) {
		cout << endl << "----------------------------------------------------" << endl;
		cout << "######   Warehouse Management System - WMS    ######" << endl;
		cout << "_______________________ MENU _______________________" << endl;
		cout << "1. Print a list of goods in the warehouse" << endl;
		cout << "2. Add a goods to the warehouse" << endl;
		cout << "3. Find a goods from the warehouse" << endl;
		cout << "4. Delete a goods from the warehouse" << endl;
		cout << "5. Edit a goods from the warehouse" << endl;
		cout << "Enter the action you want to perform (1-5): ";
		cin >> q;
		if (q == 1) {
			cout << "List of data goods:" << endl;
			print_data(head);
		}
		else if (q == 2) {
			cout << "Enter name of goods: "; cin >> a;
			cout << "Enter id of goods: "; cin >> x;
			cout << "Enter quantity of goods: "; cin >> y;
			cout << "Enter entry date (dd/mm/yyyy): "; cin >> b;
			cout << "Enter expired date (dd/mm/yyyy): "; cin >> c;
			pushTop(head, x, y, a, b, c);
		}
		else if (q == 3) {
			cout << "Enter id of goods you want to find: "; cin >> z;
			find(head, z);
		}
		else if (q == 4) {
			cout << "Enter serial of goods you want to delete: "; cin >> t;
			popMid(head, t);
		}
		else if (q == 5) {
			cout << "Enter serial of goods you want to edit: "; cin >> e;
			edit(head, e);
		}
		else {
			cout << "Syntax error!" << endl;
			break;
		}
	}
	return 0;
}