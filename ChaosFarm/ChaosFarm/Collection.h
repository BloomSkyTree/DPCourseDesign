#pragma once
#include "Object.h"

/*����*/
class Collection :public Object
{
public:
	Collection(){}
	virtual ~Collection(){}
	class FarmIterator :public Object
	{
	public:
		FarmIterator(){}
		virtual ~FarmIterator(){}
		friend class Collection;
		//*��ȡ�ýڵ��ֵ
		virtual Object* value() = 0;
		//*ָ����һ�ڵ�
		virtual void turn_next() = 0;
		//*ָ����һ�ڵ�
		virtual void turn_previous() = 0;
		//*ָ���׽ڵ�
		virtual void turn_first() = 0;
		//*ָ��β�ڵ�
		virtual void turn_last() = 0;
		//*�ж��Ƿ�����һ�ڵ�
		virtual bool has_next() = 0;
		//*�ж��Ƿ�����һ�ڵ�
		virtual bool has_previous() = 0;
		//*����д�Ļ�ȡ�����ĺ���������"FarmIterator"
		virtual const char* get_class_name(){ return "FarmIterator"; }
	protected:
		Object* current_node_;
	};
	//*��ȡ��С
	virtual int size() = 0;
	//*�����Ԫ��
	virtual void add(Object* new_element) = 0;
	//*�Ƴ�iteratorָ���Ԫ��
	virtual void remove(FarmIterator& iterator) = 0;
	//*�ж��Ƿ�Ϊ��
	virtual bool is_empty() = 0;
	//*��iteratorָ��ʼ��
	virtual void begin(FarmIterator& iterator) = 0;
	//*��iteratorָ�������
	virtual void end(FarmIterator& iterator) = 0;
};