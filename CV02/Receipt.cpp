#include "Receipt.h"

int Receipt::getReceiptId() {
	return this->id;
}
double Receipt::getSum() {
	return this->sum;
}
double Receipt::getVat() {
	return this->vat;
}
void Receipt::setReceiptId(int receiptId) {
	this->id = receiptId;
}
void Receipt::setSum(double sum) {
	this->sum = sum;
}
void Receipt::setVat(double vat) {
	this->vat = vat;
}
