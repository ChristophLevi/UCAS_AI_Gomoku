#pragma once
#include"SustainFunctions.h" 
#include"GameCondition.h" 
#include"GameScore.h" 

class GamePlayer {
public:	
	int chequer;                                       // ���ӱ�ʶ
	int(*board)[Size];                                // ָ�����������ָ��
	virtual Position get_position() = 0;              // ���麯�� ��������д
	void change_chequer(int _chequer);                // �ı���ҵ����ӱ�ʶ


};
