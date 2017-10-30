#ifndef CF_ATMOSPHERE_H
#define CF_ATMOSPHERE_H
#include "Abstract.h"
using namespace::std;

#define GOOD_LUX 1.0;
#define BAD_LUX 0.5;


enum WEATHER_TYPE { 
	SUNNY,					//*���졣ֲ����Թ�Ϲ����ã���ǿ��ѡ�
	RAINY,					//*���졣��ǿ����
	WINDY,					//*��硣
	CLOUDY					//*���졣��ǿ���͡�
};

//*���ڼ̳���Abstratc����Ҳ��observer��
//*Singleton������ģʽ
//*������������ǰ��������ͬ������ӵ�в�ͬ�Ĺ�ǿϵ��
class Atmosphere :public Abstract {

public:
	//*ȡ�õ�ǰ���������͡�
	WEATHER_TYPE get_weather_type(){ return weather_; }

	//*�������õ�ǰ������
	void change_weathertype(WEATHER_TYPE new_weather);

	//*ȡ��singletonʵ����
	static Atmosphere* get_instance();

	//*ȡ�õ�ǰ�����µĹ�ǿϵ����
	float get_lux(){ return lux_; }

	//*����д�Ļ�ȡ�����ĺ���������"Atmosphere"
	virtual const char* get_class_name(){ return "Atmosphere"; }
protected:
	Atmosphere();
	~Atmosphere();

	float lux_;								//��ǿϵ����Ӱ��ֲ��������һ��ȡ�õ�energy��

	WEATHER_TYPE weather_;					//��ǰ��������

	static Atmosphere* instance_;			//singleton��staticʵ��

	virtual void notify();

	//*����Ψһ��������������������ɾ��Atmosphere��ʵ��
	//*��̬�������Ķ�����ڳ������ʱ�����տռ䣬����������������
	//*����ͷ�stateӰ������˷�����time_instance_�Ŀռ�
	class AtmosphereReleaser
	{
	public:
		~AtmosphereReleaser()
		{
			if (Atmosphere::instance_)

				delete Atmosphere::instance_;
		}
		static AtmosphereReleaser garbo;
	};

};



#endif