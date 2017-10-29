#ifndef CF_LIVING_H
#define CF_LIVING_H
#include "Entity.h"
#include "Atmosphere.h"
#include<string>
using namespace std;

//*����������࣬�̳���Entity�����Ҳ��Observer
//*����������趨������ʱ�����Ŷ��ɳ��������������ʱ������ȥ�����Ҳ��ٶ�Subject�ı仯������Ӧ��
//*ע�⣺������趨���䵥λΪСʱ��
//*��Ҫ������˵���飬����ĵ�λΪСʱ��
//*�������Ѿ����÷��ˣ����Ҿ����б�Ҫ��˵һ�飬����ĵ�λΪСʱ��
class Living :public Entity{
public:
	//*abs_list����Ҫע���subject�б�
	//*size��������Ĵ�С��
	//*max_age���������������䡣
	Living(vector<Abstract*>* abs_list = NULL, int size = 0, int max_age = 100);

	~Living(){}

	//*����������
	//*�����ú󣬸����ｫ�����������ٶ�Subject�ı仯������Ӧ��
	//*��Ȼ������ܶ����ˣ���ʹ����ȥ�����new���Ŀռ�Ҳ�����Զ������գ����벻Ҫ����delete��
	virtual void die(){
		alive_ = false;
		format_output("Living::die()", "is dead");
	}

	//*�ɳ�����
	//*ע�⣺����
	//*����Time���ʵ���漰Animal�ࣨ��������࣬���Ըú����޷�����һ�����ʵ�֡�
	//*Animal���������ʵ�ִ˺�����
	virtual void grow() = 0;

	//*���Ի�ȡ����ĺ���
	//*const�����޷�ͨ���˺����޸Ķ�������䡣
	const int get_age() { return age_; }

	//*����д�Ļ�ȡ�����ĺ���������"Living"
	virtual const char* get_class_name(){ return "Living"; }

	//*���ر����Ƿ���Ȼ���ŵ�boolֵ��
	bool is_alive(){ return alive_; }
protected:
	//*����
	int age_;
	//*�������
	int max_age_;
	//*������
	int health_;
	//*�����Ƿ���Ȼ����
	bool alive_;

	//*��Ӧ��������ʱ������ʱ����update()���ô˺�����
	//*ע�⣺����
	virtual void time_pass_by() = 0;

	//*��Ӧ�������������仯ʱ����update()���ô˺�����
	//*ע�⣺����
	virtual void when_atmosphere_changed() = 0;
};


#endif // !CF_ENTITY_H



