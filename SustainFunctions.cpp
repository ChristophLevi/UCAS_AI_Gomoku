#include"SustainFunctions.h"
#include"GameCondition.h" 

// ��ת��ɫ
int change_player(int role) {
	if (role == 1)
		return 2;
	return 1;
}
// ���λ���Ƿ���������
bool is_in(Position p) {
	if (p.r >= 0 && p.r < Size && p.c >= 0 && p.c < Size)
		return true;
	else return false;
}
// ��λ��ת��Ϊ�ַ�����ʾ
string position_trans(Position p) {
	string s = "";
	s = "(" + to_string(13 - p.r) + ", " + char(p.c + 'A') + ")";  // ���кź��к�ת��Ϊ�ַ���
	return s;
}
// ��ӡ����
void print_board(int board[][Size])
{
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			cout << board[i][j] << " ";  // ���������ÿ��λ�õ�ֵ
		}
		cout << endl; 
	}
}
