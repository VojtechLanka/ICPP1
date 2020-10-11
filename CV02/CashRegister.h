#ifndef CASH_REGISTER_H
#define CASH_REGISTER_H

#include "Receipt.h"

class CashRegister {
public:
	CashRegister();
	~CashRegister();

	Receipt& issueReceipt(double sum, double vat);
	Receipt& getReceiptFromId(int receiptId);
	double getSum() const;
	double getSumWithVat() const;
private:
	Receipt* receipts;
	static int numberOfIssuedReceipts;
	static int idCounter;
};

#endif // CASH_REGISTER_H