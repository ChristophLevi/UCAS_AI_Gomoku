#include "MainOperations.h"
void MainOperations::maingame()        // ��Ϸ��ѭ��
{
	GamePlayer *p1, *p2;
	p1 = new HumanityPlayer(black_chequer, board);
	p2 = new RobotPlayer(white_chequer, board);
	int status= 1;
	board_display();
    // p1
while (status>= 0)            
	{
	if (status == 1) {                    // ���״̬Ϊ1����һغϣ�
		Position p = p1->get_position();  // ��ȡ���λ��
		last_pos = p;                     // ��¼�ϴ�λ��
		if (steps.empty())                // �������Ϊ��
		{
			steps.push_back(Step(1, 1, p));                     // ��ӵ�һ��
		}
		else
		{
			steps.push_back(Step(1, steps.back().hand + 1, p));  // ��Ӻ�������
		}
		board_display();              // ��ʾ����
		int result = victory_sense(p);  // ����Ƿ��ʤ
		if (result == 1) {           // �����һ�ʤ
			cout << "�������˹�����..." << endl;                  // �����ʤ��Ϣ
			status = -1;             // ����״̬Ϊ-1����Ϸ������
		}
		else if (result == 2) {       // ���AI��ʤ
			cout << "�㱻�˹����ܴ����..." << endl;               // ���ʧ����Ϣ
			status = -2;             // ����״̬Ϊ-2����Ϸ������
		}
		else {
			status = 2;             // ����״̬Ϊ2��AI�غϣ�
			continue;               // ������һ��ѭ��
		}
	}
		if (status== 2) {
			Position p = p2->get_position();
			last_pos = p;
			if (steps.empty()) {
				steps.push_back(Step(1, 1, p));
			}
			else {
				steps.push_back(Step(1, steps.back().hand + 1, p));
			}
			board_display();
			int result = victory_sense(p);
			if (result == 1) {
				cout << "��                " << endl;
				cout << "  ��              " << endl;
				cout << "    ��            " << endl;
				cout << "      ��          " << endl;
				cout << "        ��        " << endl;
				cout << "          ��      " << endl;
				cout << "            ��    " << endl;
				cout << "              ��  " << endl;
				cout << "                ��" << endl;
				status= -1;
			}
			else if (result == 2) {
				cout << "��                " << endl;
				cout << "  ��              " << endl;
				cout << "    ��            " << endl;
				cout << "      ��          " << endl;
				cout << "        ��        "<< endl;
				cout << "          ��      " << endl;
				cout << "            ��    " << endl;
				cout << "              ��  " << endl;
				cout << "                ��" << endl;
				status= -2;
			}
			else status= 1;
			continue;
		}
	}
	save_steps();
	system("pause");
}
void MainOperations::board_display()
{
	system("cls");
	cout << "   ";
	for (int i = 0; i < Size; i++) 
	{
		cout << char('A' + i) << " ";  //����ΪABCD..����ĸ
	}
	cout << endl;
	for (int i = 0; i < Size; i++) 
	{
		for (int j = 0; j < Size; j++) 
		{
			if (j == 0) {
				printf("%*d", 3, 13 - i);
			}
			if (board[i][j]>0) 
			{
				if (board[i][j] == black_chequer) cout << "��";
				else if (board[i][j] == white_chequer) cout << "��";
				if (j == Size - 1)cout << endl;
			}
			else {
				if (i == 0 && j == 0)                   cout << "��-";
				else if (i == 0 && j == Size - 1)       cout << "��" << endl;
				else if (i == 0)                        cout << "��-";
				else if (i == Size - 1 && j == 0)       cout << "��-";
				else if (i == Size - 1 && j == Size - 1)cout << "��" << endl;
				else if (j == 0)                        cout << "��-";
				else if (i == Size - 1)                 cout << "��-";
				else if (j == Size - 1)                 cout << "��" << endl;
				else                                    cout << "��-";
			}
		}
	}
}
bool MainOperations::five_lian(Position p0, Position orientation) {
	// �������λ��
	Position p1 = p0 + orientation;
	Position p2 = p1 + orientation;
	Position p3 = p2 + orientation;
	Position p4 = p3 + orientation;
    // ��������λ���Ƿ��������ڣ��Լ��Ƿ������ͬ������
	if (is_in(p0) && is_in(p1) && is_in(p2) && is_in(p3) && is_in(p4) &&
		board[p1.r][p1.c] == board[p0.r][p0.c] && board[p2.r][p2.c] == board[p0.r][p0.c] &&
		board[p3.r][p3.c] == board[p0.r][p0.c] && board[p4.r][p4.c] == board[p0.r][p0.c]) {
		return true;  // ���������������������true
	}
	return false;      
}
bool MainOperations::six_lian(Position p0, Position orientation) {
	// ��������λ��
	Position p1 = p0 + orientation;
	Position p2 = p1 + orientation;
	Position p3 = p2 + orientation;
	Position p4 = p3 + orientation;
	Position p5 = p4 + orientation;
	// ���������λ���Ƿ��������ڣ��Լ��Ƿ������ͬ������
	if (is_in(p0) && is_in(p1) && is_in(p2) && is_in(p3) && is_in(p4) && is_in(p5) &&
		board[p1.r][p1.c] == board[p0.r][p0.c] && board[p2.r][p2.c] == board[p0.r][p0.c] &&
		board[p3.r][p3.c] == board[p0.r][p0.c] && board[p4.r][p4.c] == board[p0.r][p0.c] &&
		board[p5.r][p5.c] == board[p0.r][p0.c])
	{
		return true;  // ���������������������true
	}
	    return false;
}
Position MainOperations::find_edge(Position p0, Position orientation) {
	Position p1 = p0 + orientation;
	while (is_in(p1) && board[p1.r][p1.c] == board[p0.r][p0.c]) {
		p0 = p1;
		p1 = p1 + orientation;
	}
	return p0;
}
int MainOperations::victory_sense(Position p)
{
	// ��p��ʼ�ļ������
	char chequer = board[p.r][p.c];
	// �ҵ������ϡ����ϡ����¶�
	Position p_left = find_edge(p, Position(0, -1));
	Position p_up = find_edge(p, Position(-1, 0));
	Position p_upleft = find_edge(p, Position(-1, -1));
	Position p_downleft = find_edge(p, Position(1, -1));
	// pλ�õ�����ʤ����־	
	bool win_flag = five_lian(p_left, Position(0, 1)) || five_lian(p_up, Position(1, 0)) ||
		five_lian(p_upleft, Position(1, 1)) || five_lian(p_downleft, Position(-1, 1));
	if (chequer == this->black_chequer) {
		// ������1ʤ��������1
		if (win_flag) return 1;
	}
	else {
		// ������2ʤ��������2
		if (win_flag) return 2;
	}
	return 0;
}
void MainOperations::forward() 
{
}
string MainOperations::save_steps()
{
	return string();
}

