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

	//*ȡ��ֲ�����ڰ���������ֵ
	const int get_energy() { return energy_; }

	//*ȡ��ֲ�����ڵĺ�ˮ��
	int get_water_content() { return water_content_; }

	//*����д�Ļ�ȡ�����ĺ���������"Plant"
	virtual const char* get_class_name(){ return "Plant"; }

protected:
	//*����ֵ
	int energy_;

	//*ˮ��
	int water_content_;

	//*��Ӧ��������ʱ������ʱ����update()���ô˺�����
	//*ע�⣺����
	virtual void time_pass_by() = 0;

	//*��Ӧ�������������仯ʱ����update()���ô˺�����
	//*ע�⣺����
	virtual void when_atmosphere_changed() = 0;
};


#endif