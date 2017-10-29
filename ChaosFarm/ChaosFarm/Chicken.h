#ifndef CF_CHICKEN_H_
#define CF_CHICKEN_H_
#include "Poultry.h"

//*һ��ʵ���࣬���е��麯������ʵ�֡�
//*��
class Chicken final: public Poultry{
public:

	//*abs_list����Ҫע���subject�б�
	//*size���ö���Ĵ�С��
	//*max_age���ö����������䡣
	Chicken(vector<Abstract*>* abs_list = NULL, int size = 3, int max_age = 100);

	~Chicken() {}

	//*����д�Ļ�ȡ�����ĺ���������"Chicken"
	virtual const char* get_class_name(){ return "Chicken"; }

	//*��Ӧ������
	//*�����˶���������ʱ�������顣
	virtual void do_morning();

	//*��Ӧ������
	//*�����˶���������ʱ�������顣
	virtual void do_noon();

	//*��Ӧ������
	//*�����˶���������ʱ�������顣
	virtual void do_afternoon();

	//*��Ӧ������
	//*�����˶���������ʱ�������顣
	virtual void do_night();
};

#endif 
