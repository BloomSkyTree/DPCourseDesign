#ifndef CF_CATTLE_H_
#define CF_CATTLE_H_
#include "Mammals.h"

//*һ��ʵ���࣬���е��麯������ʵ�֡�
//*��ţ��
class Cattle final: public Mammals{
public:

	//*abs_list����Ҫע���subject�б�
	//*size���ö���Ĵ�С��
	//*max_age���ö����������䡣
	Cattle(vector<Abstract*>* abs_list, int size = 7, int max_age = 200):Mammals(abs_list,size,max_age){}

	~Cattle() {}

	//*��Ӧ������
	//*�����˶���������ʱ�������顣
	virtual void do_morning(){ run(); }

	//*��Ӧ������
	//*�����˶���������ʱ�������顣
	virtual void do_noon(){ produce_milk(); }

	//*��Ӧ������
	//*�����˶���������ʱ�������顣
	virtual void do_afternoon(){ drink(); }

	//*��Ӧ������
	//*�����˶���������ʱ�������顣
	virtual void do_night(){ sleep(); }

	//*��Ϊ������
	//*����
	void produce_milk(){ format_output("Mammals::produce_milk()", "is producing milk"); }

	//*����д�Ļ�ȡ�����ĺ���������"Cattle"
	virtual const char* get_class_name(){ return "Cattle"; }
};

#endif 
