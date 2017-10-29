#ifndef CF_PLANT_H
#define CF_PLANT_H
#include "Living.h"
#include "Atmosphere.h"


class Plant : public Living
{
public:


	Plant(vector<Abstract*>* abs_list, int size, int max_age);
	~Plant(){}

	//*��Ϊ����������
	virtual void bloom() = 0;

	//*��Ϊ�������������
	virtual void photosynthesis() = 0;

	//*��Ϊ����������
	virtual void breath() = 0;

	virtual void update(AbstractType type) = 0;


	int get_energy() { return energy_; }


	int get_water_content() { return water_content_; }


	virtual const char* get_class_name(){ return "Plant"; }
protected:
	int energy_;
	int water_content_;

	virtual void time_pass_by() = 0;
	virtual void when_atmosphere_changed() = 0;
};


#endif