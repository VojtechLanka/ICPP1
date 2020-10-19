#include <iostream>
#include "CashRegister.h"
#include "Receipt.h"

using namespace std;

int main() {
	try
	{
		CashRegister* cashRegister = new CashRegister();

		cout << "Adding receipt" << endl << "Sum: 259.50" << endl << "Vat: 21" << endl;
		Receipt receiptOne = cashRegister->issueReceipt(259.50, 21);
		cout << "Added receipt with Id: " << receiptOne.getReceiptId() << endl;
		cout << "Sum: " << receiptOne.getSum() << endl;
		cout << "Vat: " << receiptOne.getVat() << endl;

		cout << "Adding receipt" << endl << "Sum: 19.99" << endl << "Vat: 21" << endl;
		Receipt receiptTwo = cashRegister->issueReceipt(19.99, 21);
		cout << "Added receipt with Id: " << receiptTwo.getReceiptId() << endl;

		cout << "Adding receipt" << endl << "Sum: 500.20" << endl << "Vat: 18" << endl;		
		Receipt receiptThree = cashRegister->issueReceipt(500.20, 18);
		cout << "Added receipt with Id: " << receiptThree.getReceiptId() << endl;

		cout << "Trying to find receipt with id 1001: " << endl;
		Receipt receipt = cashRegister->getReceiptFromId(1001);
		cout << "Found receipt with id 1001:" << endl;
		cout << "Sum: " << receipt.getSum() << endl;
		cout << "Vat: " << receipt.getVat() << endl;

		// This should throw exception
		// receipt = cashRegister->getReceiptFromId(9999);

		cout << "Total sum: " << cashRegister->getSum() << endl;
		cout << "Total sum with VAT: " << cashRegister->getSumWithVat() << endl;
	}
	catch (const std::exception& ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}
	return 0;
}