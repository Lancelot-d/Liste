#include <Windows.h>
#include "Vue.h"
#include "stack.h"
using namespace std;

const int MENU_ADD = 1;
const int MENU_SHOWPILE = 2;
const int MENU_DELETE = 3;
const int MENU_QUIT = 4;
const int MENU_ADDINDEX = 5;
const int MENU_DELETEINDEX = 6;
const int MENU_SHOWPILEINDEX = 8;
const int MENU_SHOWLENGTHPILE = 7;

Element* tete= NULL;

bool isStackEmpty() {
	return tete == NULL;
}
bool IndexCorrectAddStack(Element* tete, int pos)
{
	Element* actuelle = tete;
	int compteur = 0;
	while (actuelle->next != NULL)
	{
		actuelle = actuelle->next;
		compteur++;
	}
	compteur += 1;// pour permettre l'insertion a la queue
	if (compteur < pos || pos < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool IndexCorrect(Element* tete, int pos)
{
	Element* actuelle = tete;
	int compteur = 0;
	while (actuelle->next != NULL)
	{
		actuelle = actuelle->next;
		compteur++;
	}
	if (compteur < pos || pos < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void addToStack(int value) {
	if (isStackEmpty()){
		tete = new Element;
		tete->value = value;
		tete->next = NULL;
	}
	else {
		Element * temp = new Element;
		temp->value = value;
		temp->next = tete;
		tete = temp;
	}
}
void supprimerTete(Element*& head)
{
	if (tete != NULL)
	{
		Element* elementAsupprimer = head;
		head = head->next;
		delete elementAsupprimer; 
	}
	
}
void addToStackAtIndex(int value, int pos)
{
	Element* precedent, * actuelle;
	Element* temp = new Element;
	temp->value = value;
	temp->next = NULL;
	precedent = NULL;
	actuelle = tete;
	int count = 0;
	
	if (pos == 0)
	{
		addToStack(value);
	}
	else if (pos !=0 && IndexCorrect(tete,pos)==true)
	{
		while (count != pos && tete !=NULL)
		{
			precedent = actuelle;
			actuelle = actuelle->next;
			count++;
		}
		if (count == pos)
		{
			precedent->next = temp;
			temp->next = actuelle;
		}
		else
		{
			return;
		}
	}
}
void SupprimerNoeudIndex(int pos)
{
	Element* precedent, * actuelle;
	precedent = NULL;
	actuelle = tete;
	int count = 0;
	if (pos == 0)
	{
		supprimerTete(tete);
	}
	else if (pos !=0 && IndexCorrect(tete, pos)== true)
	{
		while (count != pos)
		{
			precedent = actuelle;
			actuelle = actuelle->next;
			count++;
		}
		if (count == pos)
		{
			precedent->next = actuelle->next;
			delete actuelle;
		}
	}
}
void init() {
	
	addToStack(1);
	addToStack(2);
	addToStack(3);
	addToStack(4);

}
void main() 
{
	init();
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	int choice = 0;
	while (choice != MENU_QUIT) {
		choice = showMenu();
		switch (choice) {
		case MENU_ADD:
			addToStack(showAddElement());
			break;
		case MENU_DELETE:
			supprimerTete(tete);
			break;
		case MENU_SHOWPILE:
			showStack(tete);
			break;
		case MENU_ADDINDEX:
			addToStackAtIndex(showAddElement(), showIndexAdd());
			break;
		case MENU_DELETEINDEX:
			SupprimerNoeudIndex(showIndexSup());
			break;
		case MENU_SHOWPILEINDEX:
			showStackLength(tete);
			break;
		case MENU_SHOWLENGTHPILE:
			showStackAtIndex(tete, showAtIndex());
			break;
		}
	}
}