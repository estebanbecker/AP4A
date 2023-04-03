// Include de l'application
#include "Vecteur.h"
#include <string>

#define TEST1 0 //1 pour tester, 0 pour ne pas tester
#define TEST2 0 //1 pour tester, 0 pour ne pas tester
#define TEST3 1 //1 pour tester, 0 pour ne pas tester


int
main(int argc, char **argv)
{

	#if TEST1 //test classique
	cout << "PROGRAMME DE TEST1" << endl;
 
	// Constructeurs
	vecteur v1(3);
	vecteur v2 = v1;
	vecteur v3;	
	v1[0] = 2;
	v1[1] = 4;
	v1[2] = 6;
	cout << "v1 :	" << v1 << endl;

	v2 = v1;
	cout << "v2 = v1 :	" << v2 << endl;	
	v2++;
	cout << "v2++ :	" << v2 << endl;

	v3 = v1 + v2;
	cout << "v3 = v1 + v2 :	" << v3 << endl;

	v3 = v1 - v2;
	cout << "v3 = v1 - v2 :	" << v3 << endl;

	v3 = v1 * v2;
	cout << "v3 = v1 * v2 :	" << v3 << endl;

	v3 = v1 * 2;
	cout << "v3 = v1 * 2 :	" << v3 << endl;

	v3 = 2 * v1;
	cout << "v3 = 2 * v1 :	" << v3 << endl;

	v3 = v1;
	cout << "v3 = v1 :	" << v3 << endl;

	v3 = 2;
	cout << "v3 = 2 :	" << v3 << endl;

	cout << "v1 == v2 :	" << (v1 == v2) << endl;
	cout << "v1 < v2 :	" << (v1 < v2) << endl;
	cout << "v1 > v2 :	" << (v1 > v2) << endl;
	cout << "v1 <= v2 :	" << (v1 <= v2) << endl;
	cout << "v1 >= v2 :	" << (v1 >= v2) << endl;
	cout << "v1 == v3 :	" << (v1 == v3) << endl;

	// Erreur de compilation
	//v3 = v1 + 2;

	cout << "FIN DU PROGRAMME DE TEST" << endl;

	return 0;

	#endif

	#if TEST2 //même test en notation fonctionnelle
	cout << "PROGRAMME DE TEST2" << endl;

	vecteur v1(3);
	vecteur v2=v1;
	vecteur v3;

	v1.operator[](0)=2;
	v1.operator[](1)=4;
	v1.operator[](2)=6;

	cout << "PROGRAMME DE TEST2" << endl;

	//use operator<<() with notation functionnelle to print v1
	operator<<(operator<<(operator<<(cout,"v1 :	"),v1),"\n");


	v2.operator=(v1);
	operator<<(operator<<(operator<<(cout,"v2 = v1 :	"),v2),"\n");
	v2.operator++();
	operator<<(operator<<(operator<<(cout,"v2++ :	"),v2),"\n");

	
	v3.operator=(v1.operator+(v2));
	operator<<(operator<<(operator<<(cout,"v3 = v1 + v2 :	"),v3),"\n");

	v3.operator=(v1.operator-(v2));
	operator<<(operator<<(operator<<(cout,"v3 = v1 - v2 :	"),v3),"\n");

	v3.operator=(v1.operator*(v2));
	operator<<(operator<<(operator<<(cout,"v3 = v1 * v2 :	"),v3),"\n");

	v3.operator=(v1.operator*(2));
	operator<<(operator<<(operator<<(cout,"v3 = v1 * 2 :	"),v3),"\n");

	v3.operator=(2*v1);
	operator<<(operator<<(operator<<(cout,"v3 = 2 * v1 :	"),v3),"\n");

	v3.operator=(v1);
	operator<<(operator<<(operator<<(cout,"v3 = v1 :	"),v3),"\n");

	v3.operator=(2);
	operator<<(operator<<(operator<<(cout,"v3 = 2 :	"),v3),"\n");

	//convert a boolean to a string
	if(v1.operator==(v2))
		operator<<(operator<<(cout,"v1 == v2 :	"),"true");
	else
		operator<<(operator<<(cout,"v1 == v2 :	"),"false");

	operator<<(cout,"\n");

	if(v1.operator<(v2))
		operator<<(operator<<(cout,"v1 < v2 :	"),"true");
	else
		operator<<(operator<<(cout,"v1 < v2 :	"),"false");

	operator<<(cout,"\n");

	if(v1.operator>(v2))
		operator<<(operator<<(cout,"v1 > v2 :	"),"true");
	else
		operator<<(operator<<(cout,"v1 > v2 :	"),"false");

	operator<<(cout,"\n");

	if(v1.operator<=(v2))
		operator<<(operator<<(cout,"v1 <= v2 :	"),"true");
	else
		operator<<(operator<<(cout,"v1 <= v2 :	"),"false");

	operator<<(cout,"\n");

	if(v1.operator>=(v2))
		operator<<(operator<<(cout,"v1 >= v2 :	"),"true");
	else
		operator<<(operator<<(cout,"v1 >= v2 :	"),"false");

	operator<<(cout,"\n");

	if(v1.operator==(v3))
		operator<<(operator<<(cout,"v1 == v3 :	"),"true");
	else
		operator<<(operator<<(cout,"v1 == v3 :	"),"false");

	operator<<(cout,"\n");

	cout << "FIN DU PROGRAMME DE TEST2" << endl;

	#endif
	#if TEST3 //test de la classe Vecteur avec des pointeurs

	vecteur* v1;
	v1 = new vecteur(3);
	vecteur* v2;
	v2 = new vecteur(*v1);
	vecteur* v3;
	v3 = new vecteur(3);

	v1->operator[](0)=2;
	v1->operator[](1)=4;
	v1->operator[](2)=6;

	cout << "v1 :   " << *v1 << endl;
	*v2 = *v1;
	cout << "v1 = v2 :	" << *v2 << endl;
	v2->operator++();
	cout << "v2++ :	" << *v2 << endl;

	v3->operator=(v1->operator+(*v2));
	cout << "v3 = v1 + v2 :	" << *v3 << endl;

	*v3 = *v1 - *v2;
	cout << "v3 = v1 - v2 :	" << *v3 << endl;

	*v3 = *v1 * *v2;
	cout << "*v3 = *v1 * *v2 :	" << *v3 << endl;

	*v3 = *v1 * 2;
	cout << "*v3 = *v1 * 2 :	" << *v3 << endl;

	*v3 = 2 * *v1;
	cout << "*v3 = 2 * *v1 :	" << *v3 << endl;

	*v3 = *v1;
	cout << "*v3 = *v1 :	" << *v3 << endl;

	*v3 = 2;
	cout << "*v3 = 2 :	" << *v3 << endl;

	cout << "*v1 == *v2 :	" << (*v1 == *v2) << endl;
	cout << "*v1 < *v2 :	" << (*v1 < *v2) << endl;
	cout << "*v1 > *v2 :	" << (*v1 > *v2) << endl;
	cout << "*v1 <= *v2 :	" << (*v1 <= *v2) << endl;
	cout << "*v1 >= *v2 :	" << (*v1 >= *v2) << endl;
	cout << "*v1 == *v3 :	" << (*v1 == *v3) << endl;

	#endif





}

