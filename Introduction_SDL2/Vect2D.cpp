#include "Vect2D.h"

//BUT:Constructeur sans paramètre
//ENTREE:
//SORTIE:2 float
cVect2D::cVect2D()
{
	this->mf_x = 0.0f;
	this->mf_y = 0.0f;
}

//BUT:Constructeur avec un paramètre
//ENTREE:un pointeur de vecteur
//SORTIE:2 float initialisé par ceux d'un vecteur
cVect2D::cVect2D(cVect2D *v)
{
	this->mf_x = v->mf_x;
	this->mf_y = v->mf_y;
}

//BUT:Constructeur avec plusieurs paramètres et un paramètre par défault
//ENTREE: 2 float
//SORTIE: 2 float
cVect2D::cVect2D(float f_x, float f_y)
{
	this->mf_x = f_x;
	this->mf_y = f_y;
}

//BUT:Récupère la valeur de X d'un vecteur
//ENTREE:
//SORTIE:1 float
float cVect2D::GetVectX() const
{
	return this->mf_x;
}

//BUT:Récupère la valeur de Y d'un vecteur
//ENTREE:
//SORTIE:1 float
float cVect2D::GetVectY() const
{
	return this->mf_y;
}

//BUT:Initialise la valeur de X d'un vecteur
//ENTREE:1 float
//SORTIE:1 float
void cVect2D::SetVectX(float f_x)
{
	this->mf_x = f_x;
}

//BUT:Initialise la valeur de Y d'un vecteur
//ENTREE:1 float
//SORTIE:1 float
void cVect2D::SetVectY(float f_y)
{
	this->mf_y = f_y;
}

//BUT:Additionne deux vecteurs
//ENTREE:1 vecteur
//SORTIE:1 vecteur
void cVect2D::Add(cVect2D v)
{
	this->mf_x += v.mf_x;
	this->mf_y += v.mf_y;
}

//BUT:Soustrait deux vecteurs
//ENTREE:1 vecteur
//SORTIE:1 vecteur
void cVect2D::Sub(cVect2D v)
{
	this->mf_x -= v.mf_x;
	this->mf_y -= v.mf_y;
}

//BUT:Multiplie deux vecteurs
//ENTREE:1 vecteur
//SORTIE:1 vecteur
void cVect2D::Multi(cVect2D v)
{
	this->mf_x *= v.mf_x;
	this->mf_y *= v.mf_y;
}

//BUT:Multiplie un vecteur par un float
//ENTREE:1 vecteur
//SORTIE:1 vecteur
void cVect2D::Multi(float f_x)
{
	this->mf_x *= f_x;
	this->mf_y *= f_x;
}

//BUT:Produit scalaire de deux vecteurs
//ENTREE:1 vecteur
//SORTIE:1 float
float cVect2D::ScalarProduct(cVect2D v)
{
	return this->mf_x * v.mf_x + this->mf_y * v.mf_y;
}

/*
//BUT:Norme de deux vecteurs
//ENTREE:1 vecteur
//SORTIE:1 float
*/
float cVect2D::NormProduct(cVect2D v)
{
	const int nPow = 2;
	return sqrt(pow((v.mf_x - this->mf_x), nPow) + pow((v.mf_y - this->mf_y), nPow));
}

//BUT: Verifie si 2 vecteur sont égaux
//ENTREE: 1 vecteur
//SORTIE: un bool
bool cVect2D::isSame(cVect2D position)
{
	if(mf_x != position.mf_x || mf_y != position.mf_y)
		return false;

	return true;
}

//BUT:Fonction d'affichage d'un vecteur
//ENTREE:
//SORTIE:1 string
std::string cVect2D::ToString()const
{
	return ("x = " + std::to_string(mf_x) + " y = " + std::to_string(mf_y));
}

