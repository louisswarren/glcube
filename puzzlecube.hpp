#ifndef PUZZLECUBE_H
#define PUZZLECUBE_H

class Puzzlecube
{
protected:
	int edges[12][2], corners[8][2], centers[6];

public:
	enum {
		MOVE_UP, MOVE_UP_I,
		MOVE_LEFT, MOVE_LEFT_I,
		MOVE_FRONT, MOVE_FRONT_I,
		MOVE_RIGHT, MOVE_RIGHT_I,
		MOVE_BACK, MOVE_BACK_I,
		MOVE_DOWN, MOVE_DOWN_I,
	};

	Puzzlecube();

};


#endif
