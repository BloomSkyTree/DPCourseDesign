#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "Chicken.h"
#include "Atmosphere.h"
#include "AbstractType.h"
#include "Time.h"

Chicken::Chicken(vector<Abstract*>* abs_list, int size, int max_age) :Poultry(abs_list, size, max_age) 
{

}


void Chicken::when_atmosphere_changed()
{
	cout << "Atmosphere has changed." << endl;
}

void Chicken::die()
{
	cout << "A chicken is dead." << endl;
}


void Chicken::grow()
{
	age_ += 1;
}


void Chicken::cry()
{
	cout << "A chicken is crying." << endl;
}

bool Chicken::drink() 
{
	if (thirsty_ <= 0) 
	{
		cout << "I am not thirsty, and don't want to drink." << endl;
		return false;
	}
	cout << "I have drunk some water." << endl;
	thirsty_--;
	return true;
}

void Chicken::lay_egg()
{
	cout << "I have laid an egg." << endl;
	return;
}

void Chicken::incubate()
{
	cout << "I am incubating the eggs." << endl;
	return;
}

void Chicken::do_morning(){
	//cout << "Chicken:"
}


void Chicken::do_noon(){

}


void Chicken::do_afternoon(){

}


void Chicken::do_night(){

}