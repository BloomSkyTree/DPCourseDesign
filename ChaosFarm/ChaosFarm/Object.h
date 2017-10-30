#ifndef CF_OBJECT_H
#define CF_OBJECT_H
#include<iostream>
#include<string>

using namespace std;


//*�����࣬���е��඼�̳��Դ���
class Object{
public:
	//*���캯�����ڴ�Ϊ�������һ�޶���ID
	Object(){ id_ = counter_++; }

	virtual ~Object(){}

	//*���ô˺����Ի�ȡ�����ID
	//const�����޷����ɴ˺����ı�����ID��
	const int get_id(){ return id_; }

	//*ȡ�ö���������������
	//*ÿ�����඼Ӧ����д�˺������Է�����ȷ������
	virtual const char* get_class_name(){ return "Object"; }

	//*��׼���������������������д��
	//*���� ������ID�� ����::��Ա������()��������� �ĸ�ʽ���������
	//*�������messageĬ��Ϊ���ַ���������Ҫʱ���и��衣
	virtual const void format_output(const char* class_function_name, const char* message = ""){
		cout << get_class_name() << " : " << id_ << " : " << class_function_name << " : " << message << endl;
	}

protected:
	int id_;						//*�����ID��ÿ�������ڴ���ʱ���ᱻ����Ψһ��ID��

	static int counter_;			//*�����������Ը������Ψһ��ID���ڸ�����Լӣ��ȴ���һ�����󱻴���
};



#endif