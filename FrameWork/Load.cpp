#include "Include.h"

Load load;
static DWORD ALPHATime = GetTickCount();

Load::Load(void)
{

	// ������ ���̽� ����
	sql.mysql_Success = false;

	//// ������ ���̽� �׽�Ʈ ����
	//count = 0;

}

Load::~Load(void)
{
}

void Load::Init()
{

	//// ����Ÿ ���̽�//////////////////////////////////////////////////////////////////////////////////////////////////////
	// 1 �ܰ� �׽�Ʈ ���� Ȯ��////////////////////////////////////////////////////////////////////

	// MYSQL ����ü ���� ���� (��ü���� ����Ÿ ���̽��� ��Ʈ�� ���ش�)
	////MYSQL mysql;
	//// mysql ����ü ���� �ʱ�ȭ
	//mysql_init(&sql.mysql);
	//// mysql ����Ÿ ���̽��� ���� (���⼱ �׳� ���Ӹ� Ȯ��)
	//if(!mysql_real_connect(&sql.mysql, NULL/*host�ּ�(ip)*/, "root", "Glfhglfh00!", NULL/*DB�̸�*/, 3306, NULL, 0) )
	//	sql.mysql_Success = false;
	//else sql.mysql_Success = true;
	//// mysql  ���� ����
	//mysql_close(&sql.mysql);

	//////////////////////////////////////////////////////////////////////////////////////////////
	// 2 �ܰ� ���� Ȯ��

	// ����ü ����
	/*
	MYSQL *mysql_real_connect(

	MYSQL *mysql,				// MYSQL ������ ��巹��

	const char *host,			// ȣ��Ʈ �̸� �Ǵ� IP ��巹�� (default = localhost)

	const char *user,			// MySQL Login ID (default = ���� �α��� �̸�)

	const char *passwd,			// �н����� (default = none)

	const char *db,				// �����ͺ��̽� �̸� (default = none)

	unsigned int port,			// TCP/IP ���� ��Ʈ (use default)

	const char *unix_socket,    // ���� (use default)

	unsigned long client_flag)  // flag (none)

	*/

	// mysql ����ü ���� �ʱ�ȭ
	mysql_init(&sql.conn);

	// ip, ���� id , pass, ����Ÿ ���̽���, ��Ʈ��ȣ ������ ����
	sql.connection = mysql_real_connect(&sql.conn, DB_HOST,
		DB_USER, DB_PASS,
		DB_NAME, 3306,
		(char *)NULL, 0);

	// ���� ���ӿ� �����ϸ� ���� ����
	if (sql.connection == NULL)
	{
		sprintf_s(sql.state, "Mysql connection error : %s", mysql_error(&sql.conn));
		sql.mysql_Success = false;
	}
	else // �ƴϸ�...
	{
		sql.mysql_Success = true;
	}

}


void Load::load()
{
	if (!sql.mysql_Success)return;

	// ���� mysql_query() �Լ��� MYSQL ����ü�� ���� ������ ����
	sql.query_start = mysql_query(sql.connection, "select * from save where saveslot=4");
	if (sql.query_start != 0) // ���� ���н�
	{
		sprintf_s(sql.state, "Mysql query error : %s", mysql_error(&sql.conn));
	}
	else // ������
	{
		sql.mysql_Success = true;
	}

	// mysql_store_result �Լ��� �Ѿ�� ����Ÿ ���̽� �� ����
	sql.sql_result = mysql_store_result(sql.connection);

	// ID, ��й�ȣ �������� 
	// select * from login where ?? ��� ��������... �� ���ڵ� �� ��ŭ �Ѿ��(�� ��ŭ ������ ����)
	while ((sql.sql_row = mysql_fetch_row(sql.sql_result)) != NULL)
	{
		// ���� ����� ������ ���ڵ� ���� ����������... where id = ? ? ������ Ư�� ����� ���� ����������...
		// ��ü ����Ÿ�� �ʿ��� ���� �迭�� ������ ó������....
		// sql.sql_row[0] �ε����� �ش� Į��(��,�ʵ�)�� ������
		sprintf_s(sql.result, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",
			sql.sql_row[1], sql.sql_row[2], sql.sql_row[3], sql.sql_row[4], sql.sql_row[5],
			sql.sql_row[6], sql.sql_row[7], sql.sql_row[8], sql.sql_row[9], sql.sql_row[10],
			sql.sql_row[11], sql.sql_row[12], sql.sql_row[13], sql.sql_row[14], sql.sql_row[15],
			sql.sql_row[16], sql.sql_row[17], sql.sql_row[18], sql.sql_row[19], sql.sql_row[20]);

		inventory.money = atoi(sql.sql_row[1]);
		item.item_cruciancarp.howmany = atoi(sql.sql_row[2]);
		item.item_jang.howmany = atoi(sql.sql_row[3]);
		item.item_lobster.howmany = atoi(sql.sql_row[4]);
		item.item_bing.howmany = atoi(sql.sql_row[5]);
		item.item_frog.howmany = atoi(sql.sql_row[6]);
		item.item_ing.howmany = atoi(sql.sql_row[7]);
		item.item_octopus.howmany = atoi(sql.sql_row[8]);
		item.item_shark.howmany = atoi(sql.sql_row[9]);
		item.item_trash.howmany = atoi(sql.sql_row[10]);
		item.item_tuna.howmany = atoi(sql.sql_row[11]);
		item.item_yeon.howmany = atoi(sql.sql_row[12]);
		item.item_bait.howmany = atoi(sql.sql_row[13]);
		item.item_ricecake.howmany = atoi(sql.sql_row[14]);
		item.item_shirimp.howmany = atoi(sql.sql_row[15]);
		item.item_fishingrod.howmany = atoi(sql.sql_row[16]);
		item.item_goodfishingrod.howmany = atoi(sql.sql_row[17]);
		quest.num_mission = atoi(sql.sql_row[18]);
		inventory.usingfishrodcode = atoi(sql.sql_row[19]);
		inventory.usingbaitcode = atoi(sql.sql_row[20]);


		// �̷������� ���ڿ��� ������ ��ȯ
		//int a = atoi(sql.sql_row[1]);
		// �������� ���ڿ��� ��ȯ �Լ� ����� #define _CRT_NONSTDC_NO_DEPRECATE ���ϸ� ���� �߻�
		//itoa(a, pw, 10);	// 10 ������ ������

		// ���ڵ� ����ŭ ����... 
		//count += 1;
	}
	// �������� ���ڿ��� ��ȯ �Լ� ����� #define _CRT_NONSTDC_NO_DEPRECATE ���ϸ� ���� �߻�
	//itoa(count, cnt, 10);	// 10 ������ ������

	// sql.sql_result �� ����
	mysql_free_result(sql.sql_result);
	///////////////////////////////////////////////////////////////////////////////////////////////
}

void Load::load1()
{
	if (!sql.mysql_Success)return;

	// ���� mysql_query() �Լ��� MYSQL ����ü�� ���� ������ ����
	sql.query_start = mysql_query(sql.connection, "select * from save where saveslot=1");
	if (sql.query_start != 0) // ���� ���н�
	{
		sprintf_s(sql.state, "Mysql query error : %s", mysql_error(&sql.conn));
	}
	else // ������
	{
		sql.mysql_Success = true;
	}

	// mysql_store_result �Լ��� �Ѿ�� ����Ÿ ���̽� �� ����
	sql.sql_result = mysql_store_result(sql.connection);

	// ID, ��й�ȣ �������� 
	// select * from login where ?? ��� ��������... �� ���ڵ� �� ��ŭ �Ѿ��(�� ��ŭ ������ ����)
	while ((sql.sql_row = mysql_fetch_row(sql.sql_result)) != NULL)
	{
		// ���� ����� ������ ���ڵ� ���� ����������... where id = ? ? ������ Ư�� ����� ���� ����������...
		// ��ü ����Ÿ�� �ʿ��� ���� �迭�� ������ ó������....
		// sql.sql_row[0] �ε����� �ش� Į��(��,�ʵ�)�� ������
		sprintf_s(sql.result, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",
			sql.sql_row[1], sql.sql_row[2], sql.sql_row[3], sql.sql_row[4], sql.sql_row[5],
			sql.sql_row[6], sql.sql_row[7], sql.sql_row[8], sql.sql_row[9], sql.sql_row[10],
			sql.sql_row[11], sql.sql_row[12], sql.sql_row[13], sql.sql_row[14], sql.sql_row[15],
			sql.sql_row[16], sql.sql_row[17], sql.sql_row[18], sql.sql_row[19], sql.sql_row[20]);

		inventory.money = atoi(sql.sql_row[1]);
		item.item_cruciancarp.howmany = atoi(sql.sql_row[2]);
		item.item_jang.howmany = atoi(sql.sql_row[3]);
		item.item_lobster.howmany = atoi(sql.sql_row[4]);
		item.item_bing.howmany = atoi(sql.sql_row[5]);
		item.item_frog.howmany = atoi(sql.sql_row[6]);
		item.item_ing.howmany = atoi(sql.sql_row[7]);
		item.item_octopus.howmany = atoi(sql.sql_row[8]);
		item.item_shark.howmany = atoi(sql.sql_row[9]);
		item.item_trash.howmany = atoi(sql.sql_row[10]);
		item.item_tuna.howmany = atoi(sql.sql_row[11]);
		item.item_yeon.howmany = atoi(sql.sql_row[12]);
		item.item_bait.howmany = atoi(sql.sql_row[13]);
		item.item_ricecake.howmany = atoi(sql.sql_row[14]);
		item.item_shirimp.howmany = atoi(sql.sql_row[15]);
		item.item_fishingrod.howmany = atoi(sql.sql_row[16]);
		item.item_goodfishingrod.howmany = atoi(sql.sql_row[17]);
		quest.num_mission = atoi(sql.sql_row[18]);
		inventory.usingfishrodcode = atoi(sql.sql_row[19]);
		inventory.usingbaitcode = atoi(sql.sql_row[20]);


		// �̷������� ���ڿ��� ������ ��ȯ
		//int a = atoi(sql.sql_row[1]);
		// �������� ���ڿ��� ��ȯ �Լ� ����� #define _CRT_NONSTDC_NO_DEPRECATE ���ϸ� ���� �߻�
		//itoa(a, pw, 10);	// 10 ������ ������

		// ���ڵ� ����ŭ ����... 
		//count += 1;
	}
	// �������� ���ڿ��� ��ȯ �Լ� ����� #define _CRT_NONSTDC_NO_DEPRECATE ���ϸ� ���� �߻�
	//itoa(count, cnt, 10);	// 10 ������ ������

	// sql.sql_result �� ����
	mysql_free_result(sql.sql_result);
	///////////////////////////////////////////////////////////////////////////////////////////////
}

void Load::load2()
{
	if (!sql.mysql_Success)return;

	// ���� mysql_query() �Լ��� MYSQL ����ü�� ���� ������ ����
	sql.query_start = mysql_query(sql.connection, "select * from save where saveslot=2");
	if (sql.query_start != 0) // ���� ���н�
	{
		sprintf_s(sql.state, "Mysql query error : %s", mysql_error(&sql.conn));
	}
	else // ������
	{
		sql.mysql_Success = true;
	}


	// mysql_store_result �Լ��� �Ѿ�� ����Ÿ ���̽� �� ����
	sql.sql_result = mysql_store_result(sql.connection);

	// ID, ��й�ȣ �������� 
	// select * from login where ?? ��� ��������... �� ���ڵ� �� ��ŭ �Ѿ��(�� ��ŭ ������ ����)
	while ((sql.sql_row = mysql_fetch_row(sql.sql_result)) != NULL)
	{
		// ���� ����� ������ ���ڵ� ���� ����������... where id = ? ? ������ Ư�� ����� ���� ����������...
		// ��ü ����Ÿ�� �ʿ��� ���� �迭�� ������ ó������....
		// sql.sql_row[0] �ε����� �ش� Į��(��,�ʵ�)�� ������
		sprintf_s(sql.result, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",
			sql.sql_row[1], sql.sql_row[2], sql.sql_row[3], sql.sql_row[4], sql.sql_row[5],
			sql.sql_row[6], sql.sql_row[7], sql.sql_row[8], sql.sql_row[9], sql.sql_row[10],
			sql.sql_row[11], sql.sql_row[12], sql.sql_row[13], sql.sql_row[14], sql.sql_row[15],
			sql.sql_row[16], sql.sql_row[17], sql.sql_row[18], sql.sql_row[19], sql.sql_row[20]);

		inventory.money = atoi(sql.sql_row[1]);
		item.item_cruciancarp.howmany = atoi(sql.sql_row[2]);
		item.item_jang.howmany = atoi(sql.sql_row[3]);
		item.item_lobster.howmany = atoi(sql.sql_row[4]);
		item.item_bing.howmany = atoi(sql.sql_row[5]);
		item.item_frog.howmany = atoi(sql.sql_row[6]);
		item.item_ing.howmany = atoi(sql.sql_row[7]);
		item.item_octopus.howmany = atoi(sql.sql_row[8]);
		item.item_shark.howmany = atoi(sql.sql_row[9]);
		item.item_trash.howmany = atoi(sql.sql_row[10]);
		item.item_tuna.howmany = atoi(sql.sql_row[11]);
		item.item_yeon.howmany = atoi(sql.sql_row[12]);
		item.item_bait.howmany = atoi(sql.sql_row[13]);
		item.item_ricecake.howmany = atoi(sql.sql_row[14]);
		item.item_shirimp.howmany = atoi(sql.sql_row[15]);
		item.item_fishingrod.howmany = atoi(sql.sql_row[16]);
		item.item_goodfishingrod.howmany = atoi(sql.sql_row[17]);
		quest.num_mission = atoi(sql.sql_row[18]);
		inventory.usingfishrodcode = atoi(sql.sql_row[19]);
		inventory.usingbaitcode = atoi(sql.sql_row[20]);


		// �̷������� ���ڿ��� ������ ��ȯ
		//int a = atoi(sql.sql_row[1]);
		// �������� ���ڿ��� ��ȯ �Լ� ����� #define _CRT_NONSTDC_NO_DEPRECATE ���ϸ� ���� �߻�
		//itoa(a, pw, 10);	// 10 ������ ������

		// ���ڵ� ����ŭ ����... 
		//count += 1;
	}
	// �������� ���ڿ��� ��ȯ �Լ� ����� #define _CRT_NONSTDC_NO_DEPRECATE ���ϸ� ���� �߻�
	//itoa(count, cnt, 10);	// 10 ������ ������

	// sql.sql_result �� ����
	mysql_free_result(sql.sql_result);
	///////////////////////////////////////////////////////////////////////////////////////////////
}



void Load::load3()
{
	if (!sql.mysql_Success)return;

	// ���� mysql_query() �Լ��� MYSQL ����ü�� ���� ������ ����
	sql.query_start = mysql_query(sql.connection, "select * from save where saveslot=3");
	if (sql.query_start != 0) // ���� ���н�
	{
		sprintf_s(sql.state, "Mysql query error : %s", mysql_error(&sql.conn));
	}
	else // ������
	{
		sql.mysql_Success = true;
	}

	// mysql_store_result �Լ��� �Ѿ�� ����Ÿ ���̽� �� ����
	sql.sql_result = mysql_store_result(sql.connection);

	// ID, ��й�ȣ �������� 
	// select * from login where ?? ��� ��������... �� ���ڵ� �� ��ŭ �Ѿ��(�� ��ŭ ������ ����)
	while ((sql.sql_row = mysql_fetch_row(sql.sql_result)) != NULL)
	{
		// ���� ����� ������ ���ڵ� ���� ����������... where id = ? ? ������ Ư�� ����� ���� ����������...
		// ��ü ����Ÿ�� �ʿ��� ���� �迭�� ������ ó������....
		// sql.sql_row[0] �ε����� �ش� Į��(��,�ʵ�)�� ������
		sprintf_s(sql.result, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",
			sql.sql_row[1], sql.sql_row[2], sql.sql_row[3], sql.sql_row[4], sql.sql_row[5],
			sql.sql_row[6], sql.sql_row[7], sql.sql_row[8], sql.sql_row[9], sql.sql_row[10],
			sql.sql_row[11], sql.sql_row[12], sql.sql_row[13], sql.sql_row[14], sql.sql_row[15],
			sql.sql_row[16], sql.sql_row[17], sql.sql_row[18], sql.sql_row[19], sql.sql_row[20]);

		inventory.money = atoi(sql.sql_row[1]);
		item.item_cruciancarp.howmany = atoi(sql.sql_row[2]);
		item.item_jang.howmany = atoi(sql.sql_row[3]);
		item.item_lobster.howmany = atoi(sql.sql_row[4]);
		item.item_bing.howmany = atoi(sql.sql_row[5]);
		item.item_frog.howmany = atoi(sql.sql_row[6]);
		item.item_ing.howmany = atoi(sql.sql_row[7]);
		item.item_octopus.howmany = atoi(sql.sql_row[8]);
		item.item_shark.howmany = atoi(sql.sql_row[9]);
		item.item_trash.howmany = atoi(sql.sql_row[10]);
		item.item_tuna.howmany = atoi(sql.sql_row[11]);
		item.item_yeon.howmany = atoi(sql.sql_row[12]);
		item.item_bait.howmany = atoi(sql.sql_row[13]);
		item.item_ricecake.howmany = atoi(sql.sql_row[14]);
		item.item_shirimp.howmany = atoi(sql.sql_row[15]);
		item.item_fishingrod.howmany = atoi(sql.sql_row[16]);
		item.item_goodfishingrod.howmany = atoi(sql.sql_row[17]);
		quest.num_mission = atoi(sql.sql_row[18]);
		inventory.usingfishrodcode = atoi(sql.sql_row[19]);
		inventory.usingbaitcode = atoi(sql.sql_row[20]);


		// �̷������� ���ڿ��� ������ ��ȯ
		//int a = atoi(sql.sql_row[1]);
		// �������� ���ڿ��� ��ȯ �Լ� ����� #define _CRT_NONSTDC_NO_DEPRECATE ���ϸ� ���� �߻�
		//itoa(a, pw, 10);	// 10 ������ ������

		// ���ڵ� ����ŭ ����... 
		//count += 1;
	}
	// �������� ���ڿ��� ��ȯ �Լ� ����� #define _CRT_NONSTDC_NO_DEPRECATE ���ϸ� ���� �߻�
	//itoa(count, cnt, 10);	// 10 ������ ������

	// sql.sql_result �� ����
	mysql_free_result(sql.sql_result);
	///////////////////////////////////////////////////////////////////////////////////////////////
}

void Load::Update()
{
}


void Load::Draw()
{

	// ����Ÿ ���̽� ��� �� ó�� ���� ǥ��/////////////////////////////////////
	if (sql.mysql_Success)
	{
		//dv_font.DrawString("Success", 500, 0);
	}
	else
	{
		//dv_font.DrawString("��������ʾҴ�Error", 500, 0);
		//dv_font.DrawString(sql.state, 700, 0);
	}

	// ���
	//dv_font.DrawString(sql.result, 500, 30);

	// �� ���ڵ� ��
	//dv_font.DrawString(cnt, 500, 60);

	// ���
	//dv_font.DrawString(pw, 500, 100);
	////////////////////////////////////////////////////////////

}
