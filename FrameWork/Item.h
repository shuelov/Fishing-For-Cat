
class Item
{


public:




	typedef struct tem
	{ 
		int code;  //아이템 코드(인벤토리에서 쓸것)
 		float x; //그려질 x좌표 
		float y; // 그려질 y 좌표
		int sell_price;  // 판매가격 (플레이어가 상점에 팔 때 가격)
		int buy_price; // 살때 가격 (플레이어가 상점에서 살 때 가격)
		int howmany;  //고양이가 갖고있는 갯수
		int where; //나오는 스테이지 0 =상점용, 1=계곡,2호수,3바다,4everywhere
		int u_x; // 얼마나 크게 그려질것인가 1이 디폴트
		int u_y;
		char name[200];//이름
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

	Sprite bing;   //물고기들
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

	Sprite bait;   //아이템들
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
	void SellItem(int _itemcode, int _howmany); // 팔고난후 내 돈 처리 (아이템 처리는 따로해야됌)
	void ShowSellPrice(int _itemcode, int _x,int _y);
	void ShowBuyPrice(int _itemcode, int _x, int _y);

};

extern Item item;