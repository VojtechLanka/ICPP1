#include <iostream>
using namespace std;

struct Triangle
{
	int a, b, c;

	Triangle() : a(), b(), c() {}

	Triangle(int a, int b, int c) : a(a), b(b), c(c) {}

	bool canBeConstructed(Triangle t) {
		return t.a + t.b > t.c && t.a + t.c > t.b && t.b + t.c > t.a;
	}

	bool canBeConstructed(Triangle* t) {
		return t->a + t->b > t->c && t->a + t->c > t->b && t->b + t->c > t->a;
	}
};


int main()
{
	int n;
	cout << "Number of triangles: ";
	cin >> n;
	Triangle* t = new Triangle[n];
	for (size_t i = 0; i < n; i++) {
		cout << "Triangle " << i + 1 << endl;
		cout << "a: ";
		cin >> t[i].a;
		cout << "b: ";
		cin >> t[i].b;
		cout << "c: ";
		cin >> t[i].c;
		if (t->canBeConstructed(t[i]))
		{
			cout << "Contents: " << t->a + t->b + t->c << endl;
		}
		else {
			cout << "The triangle cannot be constructed." << endl;
		}
	}
	delete[] t;
}