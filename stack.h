#pragma once

struct Element {
	int value;
	Element * next;
};

bool IndexCorrect(Element* tete, int pos);
