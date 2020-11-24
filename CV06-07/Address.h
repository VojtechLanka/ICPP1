#ifndef ADDRESS_H
#define ADDRESS_H

struct Address {
private:
	std::string street;
	std::string town;
	int zipCode;
public:
	Address();
	Address(std::string street, std::string town, int psc);
	~Address();
	std::string getStreet();
	std::string getTown();
	friend std::ostream& operator<<(std::ostream& os, const Address& address);
	friend std::istream& operator>>(std::istream& is, Address& address);
};

#endif // ADDRESS_H