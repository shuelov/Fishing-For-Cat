
class Item
{


public:




	typedef struct tem
	{ 
		int code;  //������ �ڵ�(�κ��丮���� ����)
 		float x; //�׷��� x��ǥ 
		float y; // �׷��� y ��ǥ
		int sell_price;  // �ǸŰ��� (�÷��̾ ������ �� �� ����)
		int buy_price; // �춧 ���� (�÷��̾ �������� �� �� ����)
		int howmany;  //����̰� �����ִ� ����
		int where; //������ �������� 0 =������, 1=���,2ȣ��,3�ٴ�,4everywhere
		int u_x; // �󸶳� ũ�� �׷������ΰ� 1�� ����Ʈ
		int u_y;
		char name[200];//�̸�
	};
	tem item_bing;
	tem item_cruciancarp;
	tem item_frog;
	tem item_ing;
	tem item_jang;
	tem item_lobster;
	tem item_octopus;
	tem item_shark;
	tem item_sora;
	tem item_trash;
	tem item_tuna;
	tem item_turtle;
	tem item_yeon;
	tem item_bait;
	tem item_fishingrod;
	tem item_goodfishingrod;
	tem item_ricecake;
	tem item_shirimp;

	Sprite bing;   //������
	Sprite cruciancarp;
	Sprite frog;
	Sprite ing;
	Sprite jang;
	Sprite lobster;
	Sprite octopus;
	Sprite shark;
	Sprite sora;
	Sprite trash;
	Sprite tuna;
	Sprite turtle;
	Sprite yeon;

	Sprite bait;   //�����۵�
	Sprite fishingrod;
	Sprite goodfishingrod;
	Sprite ricecake;
	Sprite shirimp;


	RECT q_rc;
	char str[100];

	RECT q_rc1;
	char str1[100];


	RECT q_rc2;
	char str2[100];

	
	Item(void);
	~Item(void);
	void Init();
	void Update();
	void Draw();
	void DrawItem(int _itemcode, float _x, float _y, int _u_x, int _u_y);
	void GetItem(int _itemcode, int _howmany);
	void OutItem(int _itemcode, int _howmany);
	void Showname(int _itemcode, int _x, int _y);
	void Showhowmany(int _itemcode, int _x, int _y);
	void SellItem(int _itemcode, int _howmany); // �Ȱ��� �� �� ó�� (������ ó���� �����ؾ߉�)
	void ShowSellPrice(int _itemcode, int _x,int _y);
	void ShowBuyPrice(int _itemcode, int _x, int _y);

};

extern Item item;