#include"SustainFunctions.h" 
#include"GamePlayer.h" 
#include"GameCondition.h" 
#include"GameScore.h" 

class HumanityPlayer : public GamePlayer {
public:
	HumanityPlayer() {}                                                                // Ĭ�Ϲ��캯��
	HumanityPlayer(int c, int _board[Size][Size]) { chequer = c; board = _board; }      // �������Ĺ��캯�������ڳ�ʼ�����Ӻ�����
	virtual Position get_position();         // ��д������麯������ȡ��������λ��
	void print_error(string message);
	void put_chess(int r, int c);
};