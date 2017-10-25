#ifndef CF_LIVING_H
#define CF_LIVING_H
#include "Entity.h"
#include "Atmosphere.h"
#include<string>
using namespace std;

enum SEX{
	NON = 0,
	MALE = 1,
	FEMALE = 2,
	HERMAPHRODITISM = 3,		//����ͬ��

};

class Living :public Entity{
public:
	Living(vector<Abstract*>* abs_list, int size, int max_age, string* name, SEX sex);

	~Living(){ delete name_; }

	virtual void die(){														//����ʱ�����á�
		cout << name_ << " died just now." << endl;
	}																

	virtual Living* mate_with(Living* another) = 0;								 //���亯��������һ��������н��䣬���������Ӵ������ָ��

	virtual void breath(Atmosphere* atm) = 0;										 //�������������øı�atm������̼������Ũ�ȵĺ���

	virtual void grow() = 0;															//������������ʱ����������

	string* get_name(){ return name_; }									//���ش�����ֵ��ַ���

	void set_name(string* new_name);											 //������������

	virtual void time_pass_by() = 0;

	virtual void when_atmosphere_changed() = 0;

	virtual void update(Abstract* abs, AbstractType type) = 0;


protected:
	int age_;
	int max_age_;
	float grow_speed_;						//�ɿ�����ζŨ��Ӱ�죬��һ��ϵ������grow()�б�ʹ��
	float health_gradient_;					//����ֵ�仯�ʣ��ɿ���΢����Ũ��Ӱ�죬��һ��ϵ������time_pass_by()�б�ʹ�ã�Ӱ�콡���ȱ仯
	int health_;							 //��0��������
	string* name_;
	SEX sex_;
};


#endif // !CF_ENTITY_H



