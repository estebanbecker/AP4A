// Include de l'application
#include "Vecteur.h"

int
main(int argc, char **argv)
{

	cout << "PROGRAMME DE TEST" << endl;
 
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
}

