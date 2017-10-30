#ifndef CF_ENTITY_H
#define CF_ENTITY_H
#include "Object.h"
#include "Abstract.h"
#include "AbstractType.h"
#include<vector>
#include<iterator>
class Abstract;


//*ʵ���ࡣ�̳��Ե�����Object��������ʵ�д��ڵ�����
//*Observer�����༰������Ķ��󶼿��Գ�Ϊsubject����Abstract��Observer
class Entity :public Object{
public:
	//*���캯����
	//*����abs_listΪָ�����˶���Ҫ���ĵ�subject����Abstract�༰����������ָ���vector���ڴ˹��캯���У�����ɶ��ġ�
	Entity(vector<Abstract*>* abs_list = NULL, int size = 0);

	virtual ~Entity(){}

	//*���º��������յ���Դ�ڶ��ĵ�subject����Abstract��֪ͨʱ������ݵ�������Abstract�����ͣ����ò�ͬ�ķ�Ӧ������
	//*AbstractType: ���enum AbtractType
	virtual void update(AbstractType type){
		switch (type)
		{
		case ERROR:
			break;
		case TIME:time_pass_by();
			break;
		case ATMOSPHERE:when_atmosphere_changed();
			break;
		default:
			break;
		}
	}


	//*��Ӧ��������ʱ������ʱ����update()���ô˺�����
	virtual void time_pass_by(){}

	//*��Ӧ�������������仯ʱ����update()���ô˺�����
	virtual void when_atmosphere_changed(){}

	//*ȡ�ô�ʵ��Ĵ�С
	int get_size(){ return size_; }

	//*�����ʵ��Ĵ�С
	void set_size(int new_size){ size_ = new_size; }

	//*����д�Ļ�ȡ�����ĺ���������"Entity"
	virtual const char* get_class_name(){ return "Entity"; }

protected:

	//*��С������ʵ��Ĵ�С�ı�����
	int size_;
};



#endif