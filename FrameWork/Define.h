#define SCREEN_WITH 1280		// ȭ�� ���� �ȼ�ũ��
#define SCREEN_HEIGHT 768	// ȭ�� ���� �ȼ�ũ��

#define FRAME 1000
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
// ����Ÿ ���̽�
#define DB_HOST "@localhost"
#define DB_USER "@shuelov"
#define DB_PASS "@mikeng1114"
#define DB_NAME "@save"
#define CHOP(x) x[strlen(x) - 1] = ' '
enum gamechap
{
	LOGO = 0,
	MENU = 1,
	NEWGAME = 2,
	OVER = 3,
	STORY = 4,
	TOWN = 5,
	OPTION = 6,
	TOTALCHAP
};

enum alphabet
{	
	A_, B_, C_, D_, E_, F_, G_, H_, I_, J_, K_, L_
};
enum gamework
{
	INIT = 0,
	WORK = 1,
	DRAW = 2
};