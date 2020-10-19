#ifndef RECEIPT_H
#define RECEIPT_H

class Receipt {
public:
	int getReceiptId();
	double getSum();
	double getVat();
	void setReceiptId(int receiptId);
	void setSum(double sum);
	void setVat(double vat);
private:
	int id;
	double sum;
	double vat;
};

#endif // RECEIPT_H
