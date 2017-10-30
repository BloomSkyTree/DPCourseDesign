#ifndef CF_ANIMAL_H
#define CF_ANIMAL_H
#include "Living.h"


//*����������࣬�̳���Living�����Ҳ��Observer��
//*���ʱ��Subject����Time��ǰ��������Ӧ����������ʱ��β�ͬ�����ϡ����硢���硢���ϣ���������ͬ�Ķ�����
class Animal :public Living{
public:
	//*abs_list����Ҫע���subject�б�
	//*size���ö���Ĵ�С��
	//*max_age���ö����������䡣
	Animal(vector<Abstract*>* abs_list = NULL, int size = 0, int max_age = 100);

	virtual ~Animal(){}

	//*��Ӧ������
	//*�����˶������糿ʱ�������顣
	virtual void do_morning() = 0;

	//*��Ӧ������
	//*�����˶���������ʱ�������顣
	virtual void do_noon() = 0;

	//*��Ӧ������
	//*�����˶���������ʱ�������顣
	virtual void do_afternoon() = 0;

	//*��Ӧ������
	//*�����˶���������ʱ�������顣
	virtual void do_night() = 0;

	//*��Ϊ������
	//*˯��
	virtual void sleep(){ format_output("Animal::sleep()", "zzz..."); }

	//*��Ϊ������
	//*���С�
	virtual void cry(){
		format_output("Animal::cry()", "is crying");
	}

	//*��Ϊ������
	//*��ˮ��
	virtual void drink(){
		format_output("Animal::drink()", "is driking");
	}

	//*��Ӧ��������ʱ������ʱ����update()���ô˺�����
	//*ע�⣺����
	virtual void time_pass_by() = 0;

	//*��Ӧ�������������仯ʱ����update()���ô˺�����
	//*ע�⣺����
	virtual void when_atmosphere_changed() = 0;		

	//*����д�Ļ�ȡ�����ĺ���������"Animal"
	virtual const char* get_class_name(){ return "Living"; }
};


#endif