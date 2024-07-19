#pragma once
class GameCondition {
public:
	int win6 = 0;		// ����
	int win5 = 0;	    // 5����
	int live4 = 0;	    // ��4
	int dead4 = 0;		// ��4
	int jump4 = 0;
	int live3 = 0;		// ��3
	int jump3 = 0;		// ��3
	int dead3 = 0;		// ��3
	int live2 = 0;		// ��2	
	int dead2 = 0;		// ��2
	int jump2 = 0;
	GameCondition operator + (const GameCondition s1) const {
		GameCondition s2;
		s2.win6 = win6 + s1.win6;
		s2.win5 = win5 + s1.win5;
		s2.live4 = live4 + s1.live4;
		s2.dead4 = dead4 + s1.dead4;
		s2.live3 = live3 + s1.live3;
		s2.jump3 = jump3 + s1.jump3;
		s2.dead3 = dead3 + s1.dead3;
		s2.live2 = live2 + s1.live2;
		s2.dead2 = dead2 + s1.dead2;
		s2.jump2 = jump2 + s1.jump2;
		return s2;
	}
};