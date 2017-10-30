#ifndef CF_FARMLAND_H
#define CF_FARMLAND_H
#include <iostream>
#include <string>
#include<vector>
#include"Facility.h"
#include"Time.h"
#include"Atmosphere.h"
#include "AbstractType.h"
#include "Crop.h"

using namespace std;

#define PLOW_EFFECT 1.1

class Crop;

//*ʹ��Decorator����BaseFarmland����Ĺ��ܽ��а�װ��չ

//*BaseFarmLandΪcomponent�࣬�����ӿڹ淶׼�����ո������εĶ���
class BaseFarmLand :public Facility{
	friend class DecoratedFarmLand;
public:
	BaseFarmLand(vector<Abstract*>* abs = NULL, int size = 100, int duarability = 100)
		:Facility(abs, size, duarability){}

	virtual ~BaseFarmLand(){ }

	virtual const char* get_discription() = 0;

	virtual void set_discription(const char* str) = 0;

	virtual const float get_fertility() = 0;

	virtual void set_fertility(float fertility) = 0;

	virtual void plant_a_crop(Crop* crop){
		format_output("BaseFarmLand::plant_a_crop()", "a crop is planted.");
	}

	virtual void watering(){
		format_output("BaseFarmLand::watering()", "the land is watered.");
	}

	virtual const char* get_class_name(){ return "BaseFarmLand"; }

protected:

	virtual void when_atmosphere_changed() = 0;

	virtual void time_pass_by() = 0;
};

//*Farmland�Ǿ����Compontent�࣬�̳�BaseFarmLand�������˽�Ҫ���ո������εĶ���
class FarmLand :public BaseFarmLand {
public:
	FarmLand(vector<Abstract*>* abs = NULL, int size = 100, int duarability = 100, const char* desc = "", float fertility = 1) :BaseFarmLand(abs, size, duarability), fertility_(fertility){}

	~FarmLand() {}

	virtual const char* get_discription(){ return description_->c_str(); }

	virtual void set_discription(const char* str){ (*description_) = str; }

	virtual const float get_fertility(){ return fertility_; }

	virtual void set_fertility(float fertility){ fertility_ = fertility; }

	virtual void plant_a_crop(Crop* crop){
		format_output("FarmLand::plant_a_crop()", "a crop is planted.");
	}

	virtual void watering(){
		format_output("FarmLand::watering()", "the land is watered.");
	}

	virtual const char* get_class_name(){ return "FarmLand"; }
protected:
	virtual void when_atmosphere_changed(){}

	virtual void time_pass_by(){}

	string* description_;			//*�����ַ���

	float fertility_;				//*���ֶ�
};


//DecoratedLandΪDecorator�࣬�̳�BaseFarmLand���ṩ��װ�����Ľӿ�
//*���ڹ��������baseFarmLandָ�����ⲿ���벢�洢�ڴ����У����������н�����������delete
class DecoratedFarmLand:public BaseFarmLand{
public:
	DecoratedFarmLand(BaseFarmLand* baseFarmland) :base_farmland_(baseFarmland){}

	~DecoratedFarmLand(){}

	virtual void fix(int n = 1){ base_farmland_->fix(n); }

	virtual void loss(int n = 1){ base_farmland_->loss(n); }

	virtual void time_pass_by() { base_farmland_->time_pass_by(); }

	virtual void when_atmosphere_changed(){ this->base_farmland_->when_atmosphere_changed(); }

	int get_durability(){ return base_farmland_->get_durability(); }

	virtual const char* get_class_name(){ return "DecoratedFarmLand"; }

	virtual const char* get_discription(){ return base_farmland_->get_discription(); }

	virtual void set_discription(const char* str){ base_farmland_->set_discription(str); }

	virtual const float get_fertility(){ return base_farmland_->get_fertility(); }

	virtual void set_fertility(float fertility){ base_farmland_->set_fertility(fertility); }

	virtual void plant_a_crop(Crop* crop);

	virtual void watering(){
		base_farmland_->watering();
		format_output("DecoratedFarmLand::watering()", "the land is watered.");
	}

protected:
	BaseFarmLand* base_farmland_;
};


//*Concrete Decorator�࣬����װ����װ�ι���Concrete Compontent���������¹���
//*��ء���������ũ��ķ��ֶ�
//*�ɷ��ֶ�Ӱ����ֲ�������ֲ��Ľ�ʵ�ʵĹ���
class EffectFarmLand :public DecoratedFarmLand{
public:
	EffectFarmLand(BaseFarmLand* baseFarmland) :DecoratedFarmLand(baseFarmland){}

	~EffectFarmLand(){}

	//*��غ�������������ũ��ķ��ֶȣ�n��ʾ��صĴ�����Ĭ��n = 1
	void plow(int n = 1){
		format_output("EffectFarmLand::plow()", "the land is plowed.");
		for (int i = 0; i < n; i++)base_farmland_->set_fertility(base_farmland_->get_fertility() * PLOW_EFFECT); 
	}

	//*��ֲ�������������cropָ��ָ���ũ������ֲ�ڴ������ϣ�����Ӱ�����ʵ�ʡ�
	virtual void plant_a_crop(Crop* crop);

	virtual const char* get_class_name(){ return "EffectFarmLand"; }
};


#endif