#ifndef CF_FACILITY_H
#define CF_FACILITY_H
#include "Entity.h"

//*��ʩ�ࡣ��������ĳЩ���õ�ũ����Ʒ���乲�������Ǿ����;öȣ���ʹ��ʱ�ᱻ���ġ�
//*���ڼ̳���Entity����Ҳ��Observer��������û������Ŀǰ��û�н�����ص�ʵ�֣���غ���Ϊ�ա�
class Facility :public Entity{
public:
	//*abs_list����Ҫע���subject�б�
	//*size������ʩ�Ĵ�С��
	//*init_durability����ʼ�;öȡ�
	Facility(vector<Abstract*>* abs_list = NULL, int size = 0, int init_durability = 100);

	virtual ~Facility(){}

	//*��������
	//*����n��ʾ����ָ����;ö���
	virtual void fix(int n = 1){ durability_ += n; }

	//*ĥ������
	//*����n��ʾĥ����;ö���
	virtual void loss(int n = 1){ if (durability_ >= n)durability_ -= n; }

	//*ȡ���;öȵĺ�����
	//*const�����޷��ɴ˺����ı亯����Ա��ֵ��
	const int get_durability(){ return durability_; }

	//*����д�Ļ�ȡ�����ĺ���������"Facility"
	virtual const char* get_class_name(){ return "Facility"; }
protected:
	//*�;ö�
	int durability_;

	//*��ʱ��仯�ķ�Ӧ����������û����Ҫ�����ÿ�
	virtual void time_pass_by(){}

	//*�������仯�ķ�Ӧ����������û����Ҫ�����ÿ�
	virtual void when_atmosphere_changed(){}
};


#endif