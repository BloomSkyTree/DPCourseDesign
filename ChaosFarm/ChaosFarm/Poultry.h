#ifndef CF_POULTRY_H_
#define CF_POULTRY_H_
#include "Animal.h"
#include "Time.h"

//*�������ݶ�����ࡣ�̳���Animal�����Ҳ��Observer
class Poultry :public Animal {
public:

	//*abs_list����Ҫע���subject�б�
	//*size���ö���Ĵ�С��
	//*max_age���ö����������䡣
	Poultry(vector<Abstract*>* abs_list, int size, int max_age) :Animal(abs_list, size, max_age) {}

	~Poultry() {}

	//*���麯����ʵ�֡�
	//*����ʱ�����ŵĳ��ȣ���������
	//*����ﵽ���ֵʱ������������
	virtual void grow(){
		age_ += Time::instance()->get_d_hour();
		if (age_ >= max_age_)die();
	}

	//*��Ӧ��������ʱ������ʱ����update()���ô˺�����
	//*���ж϶�����Ȼ���ŵ�ʱ�򣬻����Ŀǰ������ʱ�����һЩ���顣
	virtual void time_pass_by(){ if (alive_){ Time::instance()->do_something(this); grow(); } }

	//*��Ӧ�������������仯ʱ����update()���ô˺�����
	//*���ж϶�����Ȼ���ŵ�ʱ�򣬻���ݱ仯�������������һЩ���顣
	virtual void when_atmosphere_changed(){
		Atmosphere* atm = Atmosphere::getInstance();
		switch (atm->get_weather_type()){
		case SUNNY:format_output("Poultry::when_atmosphere_changed()", "is enjoying the sunshine"); break;
		case WINDY:format_output("Poultry::when_atmosphere_changed()", "is feeling the wind"); break;
		case RAINY:format_output("Poultry::when_atmosphere_changed()", "try to take a shelter from rain"); break;
		case CLOUDY:format_output("Poultry::when_atmosphere_changed()", "is not happy"); break;
		default:break;
		}
	}

	
	//*��Ϊ������
	//*������ȥ
	void fly(){ cout << "Poultry:" << id_ << ":fly(): A poultry is flying." << endl; }


	virtual void lay_egg(){
		format_output("Poultry::lay_egg()", "is laying eggs.");
	}

	//*��Ϊ������
	//*����
	virtual void incubate(){
		format_output("Poultry::incubate()", "is incubating.");
	}
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

	//*����д�Ļ�ȡ�����ĺ���������"Poultry"
	virtual const char* get_class_name(){ return "Poultry"; }



};
#endif 

