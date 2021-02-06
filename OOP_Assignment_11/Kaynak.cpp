#include<iostream>
using namespace std;

template <class P>
class Polynomial {

public:

	P  degree;
	P* coefArr;
	Polynomial() {

	}
	Polynomial(int d) {		//Constructor that creates a dynamic coef array

		degree = d;
		coefArr = new int(degree + 1);
	}

	Polynomial operator=(Polynomial& a) {   //Assingment Operator Overloading

		Polynomial ret;

		ret.degree = a.degree;
		ret.coefArr = a.coefArr;

		return ret;
	}


	friend std::istream& operator>> <P>(istream& in, Polynomial& a) {		 //>> Operator Overloading


		for (int i = a.degree; i >= 0; i--) {		//Getting the coefficets for each degree from the user

			cout << "x" << i << " coefficent: ";
			in >> a.coefArr[i];
		}


		return in;
	}

	friend std::ostream& operator<< <P>(ostream& out, Polynomial& a) {		 //<< Operator Overloading

		int i = 0;
		for (i = a.degree; i >= 0; i--) {		//Checking degree for output

			if (a.coefArr[i] != 0 && i == 1) {

				out << a.coefArr[i] << "x^" << i;
				break;
			}
			if (a.coefArr[i] != 0) {

				out << a.coefArr[i] << "x^" << i << "+";
			}

		}
		i--;

		if (a.coefArr[0] != 0 && i == 0) {

			out << "+" << a.coefArr[0];
		}

		return out;
	}

};


int main() {


	int size;

	cout << "Degree of polynomial: ";
	cin >> size;

	Polynomial<int> p1(size);


	cin >> p1;

	cout << "Degree of polynomial: ";
	cin >> size;
	Polynomial<int> p2(size);

	cin >> p2;

	cout << p1 << endl << endl;
	cout << p2 << endl << endl;

	p2 = p1;

	cout << "After the appointment " << endl << endl;

	cout << p2;



	return 0;
}