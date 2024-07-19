#ifndef _MAINOPERATIONS
#define _MAINOPERATIONS
#include"SustainFunctions.h"
#include"HumanityPlayer.h" 
#include"RobotPlayer.h" 
#include"GameCondition.h" 
#include"GameScore.h" 

class MainOperations {
public:
	int board[Size][Size];            
	static const int black_chequer = 1;  // ����Ϊ1
	static const int white_chequer = 2;  // ����Ϊ2
	static const int nothing = 0;        // �ո�Ϊ0
	MainOperations() {memset(this->board, 0, sizeof(this->board));}       // ��ʼ����������Ϊ0
	vector<Step> steps;    
	Position last_pos;         
	void maingame();      
	void board_display(); 
	bool five_lian(Position p0, Position orientation);      // �жϴ�p0λ�ÿ�ʼ������orientation�����Ƿ��γ�5��
	bool six_lian(Position p0, Position orientation);      // �жϴ�p0λ�ÿ�ʼ������orientation�����Ƿ��γ�6��
	Position find_edge(Position p0, Position orientation);  // ��p0λ�ÿ�ʼ������orientation�����ҵ��߽�λ��
	int victory_sense(Position p);                         // ��pλ�ü���Ƿ��γ�5����6����������ʤ����������ұ�ţ����򷵻�0
	void forward();                                        // ǰ��
	string save_steps();            
};
#endif 