
class Boat
{


public:
	float x, y; // ���� ��ġ

	int movingboat; // �谡 ���ݾ� �����̰� �������
	bool plusorminus;  //�����̰� �Ҷ� +�� - ��� �ٲ�¿� 

	DWORD KeyTime; // �ð�������
	
	Sprite ship;
	Sprite boat;

	Boat(void);
	~Boat(void);
	void Init();
	void Update();
	void Draw();


};

extern Boat boat;