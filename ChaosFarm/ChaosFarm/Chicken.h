#ifndef CF_CHICKEN_H_
#define CF_CHICKEN_H_
#include "Poultry.h"

class Chicken final: public Poultry{
public:

	Chicken(vector<Abstract*>* abs_list = NULL, int size = 3, int max_age = 100);

	~Chicken() {}
    
	virtual void time_pass_by(){ Time::instance()->do_something(this); }

	virtual void when_atmosphere_changed();

	virtual void die();

	virtual void grow();

	virtual void cry();

	virtual void drink();

	void lay_egg();

	void incubate();

	virtual void do_morning();

	virtual void do_noon();

	virtual void do_afternoon();

	virtual void do_night();
};

#endif 
