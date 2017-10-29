#ifndef CF_MAMMALS_H_
#define CF_MAMMALS_H_
#include "Animal.h"
#include "Time.h"

//*�������鶯����ࡣ�̳���Animal�����Ҳ��Observer
class Mammals :public Animal {
public:

	//*abs_list����Ҫע���subject�б�
	//*size���ö���Ĵ�С��
	//*max_age���ö����������䡣
	Mammals(vector<Abstract*>* abs_list = NULL, int size = 10, int max_age = 200) :Animal(abs_list, size, max_age) {}

	~Mammals() {}

	//*���麯����ʵ�֡�
	//*����ʱ�����ŵĳ��ȣ���������
	//*����ﵽ���ֵʱ������������
	virtual void grow(){
		age_ += Time::instance()->get_d_hour();
		if (age_ >= max_age_)die();
	}

	//*��Ӧ��������ʱ������ʱ����update()���ô˺�����
	//*���ж϶�����Ȼ���ŵ�ʱ�򣬻����Ŀǰ������ʱ�����һЩ���顣
	virtual void time_pass_by(){ if (alive_) { Time::instance()->do_something(this); grow(); } }

	//*��Ӧ�������������仯ʱ����update()���ô˺�����
	//*���ж϶�����Ȼ���ŵ�ʱ�򣬻���ݱ仯�������������һЩ���顣
	virtual void when_atmosphere_changed(){
		if (alive_){
			Atmosphere* atm = Atmosphere::get_instance();
			switch (atm->get_weather_type()){
			case SUNNY:format_output("Mammals::when_atmosphere_changed()", "is enjoying the sunshine"); break;
			case WINDY:format_output("Mammals::when_atmosphere_changed()", "is walking briefly."); break;
			case RAINY:format_output("Mammals::when_atmosphere_changed()", "try to take a shelter from rain"); break;
			case CLOUDY:format_output("Mammals::when_atmosphere_changed()", "seems unhappy"); break;
			default:break;
			}
		}
	}

	//*��Ϊ����
	//*����
	void run(){
		format_output("Mammals::run()", "is running");
	}

	//*��Ϊ������
	//*����
	virtual void produce_milk(){
		format_output("Mammals::produce_milk()", "is producing milk");
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

	//*����д�Ļ�ȡ�����ĺ���������"Mammals"
	virtual const char* get_class_name(){ return "Mammals"; }
};
#endif 

