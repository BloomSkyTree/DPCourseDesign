#ifndef CF_ANIMAL_H
#define CF_ANIMAL_H
#include "Living.h"

class Animal :public	Living{
public:
	Animal(vector<Abstract*>* abs_list, int size, int max_age, const char* name, SEX sex);

	~Animal(){}

	virtual bool eat(Entity* food);

	virtual void cry(){ cout << name_ << "is crying." << endl; }

	virtual bool drink();

	virtual void time_pass_by() = 0;

	virtual void when_atmosphere_changed() = 0;

	virtual void update(Abstract* abs, AbstractType type) = 0;

	virtual void die(){														//����ʱ�����á�
		cout << name_ << " died just now." << endl;
	}

	virtual Living* mate_with(Living* another) = 0;								 //���亯��������һ��������н��䣬���������Ӵ������ָ��

	virtual void breath(Atmosphere* atm) = 0;										 //�������������øı�atm������̼������Ũ�ȵĺ���

	virtual void grow() = 0;															//������������ʱ����������

protected:
	int hunger_;				//������
	int thirsty_;
};


#endif