#include "CashRegister.h"
#include <sstream>
#define MAX_ARRAY_SIZE 10
using namespace std;

int CashRegister::idCounter = 1000;
int CashRegister::numberOfIssuedReceipts = 0;

CashRegister::CashRegister() {
	receipts = new Receipt[MAX_ARRAY_SIZE];
}

CashRegister::~CashRegister() {
	delete[] receipts;
}

Receipt& CashRegister::issueReceipt(double sum, double vat) {
	if (CashRegister::numberOfIssuedReceipts >= MAX_ARRAY_SIZE)
	{
		throw exception("Too many receipts");
	}
	Receipt* receipt = new Receipt();
	receipt->setReceiptId(CashRegister::idCounter++);
	receipt->setSum(sum);
	receipt->setVat(vat);
	CashRegister::receipts[CashRegister::numberOfIssuedReceipts++] = *receipt;
	return *receipt;
}

Receipt& CashRegister::getReceiptFromId(int receiptId) {
	for (int i = 0; i < CashRegister::numberOfIssuedReceipts; i++) {
		if (CashRegister::receipts[i].getReceiptId() == receiptId) {
			return CashRegister::receipts[i];
		}
	}
	stringstream stringBuffer;
	stringBuffer << "Unknow id: " << receiptId;
	throw exception(stringBuffer.str().c_str());
}

double CashRegister::getSum() const {
	double sum = 0.0;
	for (int i = 0; i < CashRegister::numberOfIssuedReceipts; i++) {
		sum += CashRegister::receipts[i].getSum();
	}
	return sum;
}

double CashRegister::getSumWithVat() const {
	double sumWithVat = 0.0;
	double sum;
	for (int i = 0; i < CashRegister::numberOfIssuedReceipts; i++) {
		sum = CashRegister::receipts[i].getSum();
		sumWithVat += sum + (sum * (CashRegister::receipts[i].getVat() / 100));
	}
	return sumWithVat;
}
