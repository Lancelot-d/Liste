#include "Vue.h"
#include <conio.h>
#include <iostream>
#include <string>
#include "cvm.h"
#include "stack.h"
using namespace std;
int showAddElement()
{
	int value;
	cout << endl << endl << "Quelle est la valeur ? : ";
	cin >> value;
	clrscr();
	return value;
}
int showIndexAdd()
{
	int index;
	cout << endl << endl << "Quelle est la position de l'element a inserer ? : ";
	cin >> index;
	clrscr();
	return index;
}
int showIndexSup()
{
	int index;
	cout << endl << endl << "Quelle est la position de l'element a supprimer ? : ";
	cin >> index;
	clrscr();
	return index;
}
int showAtIndex()
{
	int index;
	cout << endl << endl << "Quelle est la position de l'element a afficher ? : ";
	cin >> index;
	clrscr();
	return index;
}

int showMenu() {
	int choice;
	cout << endl << endl <<
		"Que voulez-vous faire?" << endl << endl <<
		"1 Ajouter un element a la pile?" << endl <<
		"2 afficher la pile?" << endl <<
		"3 Supprimer un element de la pile?" << endl <<
		"4 Quitter?" << endl <<
		"5 Ajouter un element a une position donnee" << endl <<
		"6 Supprimer un element a une position donnee" << endl <<
		"7 Afficher un element a une position donnee" << endl<<
		"8 Afficher le nombre d'element dans la pile" << endl <<endl
		<< "Votre choix : ";
	cin >> choice;
	clrscr();
	return choice;
}
void showStack(Element * tete) 
{
	if (tete == NULL)
	{
		cout << "Pile vide";
		return;
	}
	else if (tete->next != NULL)
	{
		showStack(tete->next);
	}
	cout << tete->value << ' ';
}
void showStackLength(Element* tete)
{
	Element * actuelle = tete;
	int compteur = 0;
	if (actuelle == NULL)
	{
		cout << compteur;
		return;
	}
	while (actuelle->next != NULL)
	{
		actuelle = actuelle->next;
		compteur++;
	}
	cout <<"taille de la pile : "<< compteur+1;
}
void showStackAtIndex(Element* tete, int pos)
{
	Element * actuelle=tete;
	int compteur = 0;
	if (IndexCorrect(tete,pos))
	{
		while (compteur != pos)
		{
			actuelle = actuelle->next;
			compteur++;
		}
		if (compteur == pos)
		{
			cout << actuelle->value;
		}
	}
}