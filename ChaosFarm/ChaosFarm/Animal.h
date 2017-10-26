#ifndef CF_ANIMAL_H
#define CF_ANIMAL_H
#include "Living.h"

class Animal :public	Living{
public:
	Animal(vector<Abstract*>* abs_list, int size, int max_age, SEX sex);

	~Animal(){}

	virtual bool eat(Entity* food);

	virtual void cry() = 0;

	virtual bool drink();

	virtual void time_pass_by() = 0;

	virtual void when_atmosphere_changed() = 0;

	virtual void update(AbstractType type){
		switch (type)
		{
		case ERROR:
			break;
		case TIME:time_pass_by();
			break;
		case ATMOSPHERE:when_atmosphere_changed();
			break;
		default:
			break;
		}
	}

	virtual void die() = 0;

	virtual Living* mate_with(vector<Abstract*>* abs_list, Living* another) = 0;								 //���亯��������һ��������н��䣬���������Ӵ������ָ��

	virtual void breath(Atmosphere* atm) = 0;										 //�������������øı�atm������̼������Ũ�ȵĺ���

	virtual void grow() = 0;															//������������ʱ����������

protected:
	int hunger_;				//������
	int thirsty_;
};


#endif