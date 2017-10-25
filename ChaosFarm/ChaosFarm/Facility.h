#ifndef CF_FACILITY_H
#define CF_FACILITY_H
#include "Entity.h"

class Facility :public Entity{
public:
	Facility(vector<Abstract*>* abs_list, int size, int init_durability = 100);

	~Facility(){}

	virtual void fix(int n = 1){ durability_ += n; }

	virtual void loss(int n = 1){ if (durability_ >= n)durability_ -= n; }

	virtual void time_pass_by() = 0;

	virtual void when_atmosphere_changed() = 0;

	virtual void update(Abstract* abs, AbstractType type) = 0;


protected:
	int durability_;
};


#endif