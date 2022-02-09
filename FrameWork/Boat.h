
class Boat
{


public:
	float x, y; // 배의 위치

	int movingboat; // 배가 조금씩 움직이게 만드려고
	bool plusorminus;  //움직이게 할때 +와 - 계산 바뀌는용 

	DWORD KeyTime; // 시간관리용
	
	Sprite ship;
	Sprite boat;

	Boat(void);
	~Boat(void);
	void Init();
	void Update();
	void Draw();


};

extern Boat boat;