// Type vecteur
#include "Vecteur.h"

// Constructeurs
vecteur::vecteur(void){
	taille = 0;
	tab = NULL;
}
vecteur::vecteur(int n):taille(n), tab(new int[n]){}
vecteur::vecteur(vecteur& v):taille(v.taille), tab(new int[v.taille])
{
	for (int i = 0; i < taille; i++)
	{
		tab[i] = v.tab[i];
	}
}

// Destructeur
vecteur::~vecteur()
{
	delete[] tab;
}

// Nombre d'elements
int vecteur::longueur(void)
{
	return this->taille;
}
 
// Acces aux elements
int& vecteur::operator[](int i)
{
	return tab[i];
}

// affectation : =(vecteur), =(int)
vecteur& vecteur::operator=(const vecteur& v)
{
	if (this != &v)
	{
		if(taille != 0){
			delete[] tab;
		}
		taille = v.taille;
		tab = new int[taille];
		for (int i = 0; i < taille; i++)
		{
			tab[i] = v.tab[i];
		}
	}
	return *this;
}

vecteur& vecteur::operator=(int n)
{
	for (int i = 0; i < taille; i++)
	{
		tab[i] = n;
	}
	return *this;
}

// incrementation/decr. : ++, ++(int), --
vecteur& vecteur::operator++(void)
{
	for (int i = 0; i < taille; i++)
	{
		tab[i]++;
	}
	return *this;
}

vecteur vecteur::operator++(int)
{
	vecteur v(*this);
	for (int i = 0; i < taille; i++)
	{
		tab[i]++;
	}
	return v;
}

vecteur& vecteur::operator--(void)
{
	for (int i = 0; i < taille; i++)
	{
		tab[i]--;
	}
	return *this;
}

// op. booleens : ==, <, >, <=, >=
int vecteur::operator==(vecteur& v)
{
	if (taille != v.taille)
	{
		return 0;
	}
	for (int i = 0; i < taille; i++)
	{
		if (tab[i] != v.tab[i])
		{
			return 0;
		}
	}
	return 1;
}

int vecteur::operator<(vecteur& v)
{
	if (taille != v.taille)
	{
		return 0;
	}
	for (int i = 0; i < taille; i++)
	{
		if (tab[i] >= v.tab[i])
		{
			return 0;
		}
	}
	return 1;
}

int vecteur::operator>(vecteur& v)
{
	if (taille != v.taille)
	{
		return 0;
	}
	for (int i = 0; i < taille; i++)
	{
		if (tab[i] <= v.tab[i])
		{
			return 0;
		}
	}
	return 1;
}

int vecteur::operator<=(vecteur& v)
{
	if (taille != v.taille)
	{
		return 0;
	}
	for (int i = 0; i < taille; i++)
	{
		if (tab[i] > v.tab[i])
		{
			return 0;
		}
	}
	return 1;
}

int vecteur::operator>=(vecteur& v)
{
	if (taille != v.taille)
	{
		return false;
	}
	for (int i = 0; i < taille; i++)
	{
		if (tab[i] < v.tab[i])
		{
			return 0;
		}
	}
	return 1;
}

// op. binaires : +, -

vecteur vecteur::operator+(const vecteur& v)
{
	vecteur v2(taille);
	for (int i = 0; i < taille; i++)
	{
		v2.tab[i] = tab[i] + v.tab[i];
	}
	return v2;
}

vecteur vecteur::operator-(const vecteur& v)
{
	vecteur v2(taille);
	for (int i = 0; i < taille; i++)
	{
		v2.tab[i] = tab[i] - v.tab[i];
	}
	return v2;
}


// produit scalaire : *

vecteur vecteur::operator*(vecteur& v)
{
	vecteur v2(taille);
	for (int i = 0; i < taille; i++)
	{
		v2.tab[i] = tab[i] * v.tab[i];
	}
	return v2;
}



// produit par un scalaire: n * v, v * n

vecteur vecteur::operator*(int n)
{
	vecteur v2(taille);
	for (int i = 0; i < taille; i++)
	{
		v2.tab[i] = n * tab[i];
	}
	return v2;
}

vecteur operator*(int n, vecteur& v)
{
	vecteur v2(v.taille);
	for (int i = 0; i < v.taille; i++)
	{
		v2.tab[i] = n * v.tab[i];
	}
	return v2;
}

// auto-adition : +=, -=

vecteur& vecteur::operator+=(vecteur& v)
{
	for (int i = 0; i < taille; i++)
	{
		tab[i] += v.tab[i];
	}
	return *this;
}

vecteur& vecteur::operator-=(vecteur& v)
{
	for (int i = 0; i < taille; i++)
	{
		tab[i] -= v.tab[i];
	}
	return *this;
}

// Operateurs d'entree/sortie: <<, >>
ostream& operator<< (ostream& o, vecteur& a)
{
	for (int i = 0; i < a.taille; i++)
	{
		o << a.tab[i] << " ";
	}
	return o;
}

istream& operator>> (istream& i, vecteur& a)
{
	for (int j = 0; j < a.taille; j++)
	{
		i >> a.tab[j];
	}
	return i;
}

