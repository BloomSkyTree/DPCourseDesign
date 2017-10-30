#ifndef CF_ABSTRACT_H
#define CF_ABSTRACT_H
#include "Object.h"
#include "Entity.h"
#include "AbstractType.h"
#include <vector>
#include <iterator>
class Entity;

typedef vector<Entity*> ObserverPool;

//*�������������࣬�̳���Object��
//*Subjetc���ǹ۲��߻����е�subject����Observer����Entity�Ĺ۲����
class Abstract :public Object{
public:
	Abstract(){ observer_pool_ = new vector<Entity*>(); }

	~Abstract(){ delete observer_pool_; }

	//*����һ�����е�ObserverPool�Դ���һ��Abstract
	//*���Դ���ӵ��ͬ��ע���б��Abstract
	Abstract(const ObserverPool* observer_pool){
		observer_pool_ = new ObserverPool((*observer_pool));
	}

	//*����observer pool�����㸴��ʹ�á�
	//*����iterator��ʹ�ã��˺����޷������ó�const��
	//*�뾡����Ҫ���л����obserber pool���ݱ䶯�Ĳ�����
	ObserverPool* get_observer_pool(){ return observer_pool_; }

	//*������observer pool�����observer
	void add_observer(Entity* ob){ 
		observer_pool_->push_back(ob);
	}

	//*��observer pool���Ƴ�ָ��ָ���Obserber��
	//*���ҵ���Ӧobserver���ɹ��Ƴ�������true��
	//*δ�ҵ���Ӧobserver���޷��Ƴ�������false��
	bool remove_observer(Entity *observer);

	//*����д�Ļ�ȡ�����ĺ���������"Abstract"
	virtual const char* get_class_name(){ return "Abstract"; }
protected:

	//*����أ����������ע���subject����Abstract��Observer��
	ObserverPool* observer_pool_;

	//*֪ͨ����������֪ͨ����observer
	virtual void notify();

};



#endif