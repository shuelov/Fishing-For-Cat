#pragma once
#include "Include.h"

Mysql sql;


Mysql::Mysql()
{

}

Mysql::~Mysql()
{
}

void Mysql::Init()
{

}

void Mysql::Update()
{


}

void Mysql::Draw()
{
	// ����Ÿ ���̽� ó�� ���� ǥ��/////////////////////////////////////
	if (sql.mysql_Success)


	{
		//dv_font.DrawString("Success", 500, 0);
	}
	else
	{
		dv_font.DrawString("Error", 500, 0);
		dv_font.DrawString(sql.state, 700, 0);
	}
	////////////////////////////////////////////////////////////

}

void Mysql::save()
{
	if (!sql.mysql_Success)return;

	/////// ���� ����� ���////////////////////
	// insert Value
	// �̸�
	//fgets(name, 12, stdin);
	//CHOP(name);

	// ��й�ȣ
	//fgets(address, 80, stdin);
	//CHOP(address);
	////////////////////////////////////////////

	////// �츰 ������ �ڽ��� �ʿ�////////////////

	//// ���̺� ���� �� �Է�
	//sprintf_s(name, "%s", "A2");
	//sprintf_s(address, "%s", "2B");

	/////////////////////////////////////////////

	_itoa_s(inventory.money, money, 10); //1 ��
	_itoa_s(item.item_cruciancarp.howmany, cruciancarp, 10); //2 �ؾ�
	_itoa_s(item.item_jang.howmany, jang, 10); //3 ���
	_itoa_s(item.item_lobster.howmany, lobster, 10); //4 
	_itoa_s(item.item_bing.howmany, bing, 10); //5 
	_itoa_s(item.item_frog.howmany, frog, 10); //6 
	_itoa_s(item.item_ing.howmany, ing, 10); //7 
	_itoa_s(item.item_octopus.howmany, octopus, 10); //8 
	_itoa_s(item.item_shark.howmany, shark, 10); //9 
	_itoa_s(item.item_trash.howmany, trash, 10); //10 
	_itoa_s(item.item_tuna.howmany, tuna, 10); //11
	_itoa_s(item.item_yeon.howmany, yeon, 10); //12 
	_itoa_s(item.item_bait.howmany, bait, 10); //13
	_itoa_s(item.item_ricecake.howmany, ricecake, 10); //14 
	_itoa_s(item.item_shirimp.howmany, shirimp, 10); //15 
	_itoa_s(item.item_fishingrod.howmany, fishingrod, 10); //16 
	_itoa_s(item.item_goodfishingrod.howmany, goodfishingrod, 10); //17 
	_itoa_s(quest.num_mission, num_quest, 10); //18
	_itoa_s(inventory.usingfishrodcode, wear_fishingrod, 10); //19
	_itoa_s(inventory.usingbaitcode, use_item, 10); // 

	//������ #define���� ���ڷ� �����ؼ� for������ �����°� ����ϰ� �ڵ���
	// ���� �� ������ ����

	sprintf_s(query, "update save set money=%s where saveslot=1", money);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set cruciancarp_num=%s where saveslot=1", cruciancarp);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set jang_num=%s where saveslot=1", jang);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set lobster_num=%s where saveslot=1", lobster);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set bing_num=%s where saveslot=1", bing);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set frog_num=%s where saveslot=1", frog);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set ing_num=%s where saveslot=1", ing);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set octopus_num=%s where saveslot=1", octopus);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set shark_num=%s where saveslot=1", shark);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set trash_num=%s where saveslot=1", trash);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set tuna_num=%s where saveslot=1", tuna);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set yeon_num=%s where saveslot=1", yeon);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set bait_num=%s where saveslot=1", bait);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set ricecake_num=%s where saveslot=1", ricecake);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set shrimp_num=%s where saveslot=1", shirimp);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set fishingrod=%s where saveslot=1", fishingrod);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set goodfishingrod=%s where saveslot=1", goodfishingrod);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set quest=%s where saveslot=1", num_quest);//����
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set wearfishingrod=%s where saveslot=1", wear_fishingrod);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set usingitem=%s where saveslot=1", use_item);
	query_start = mysql_query(connection, query);


	//sprintf_s(query, "update save set money='%s' where saveslot is '1'", money); 

	//query_start = mysql_query(connection, "update save set money='money' where saveslot='1'");

	//query_start = mysql_query(connection, "insert into save (saveslot) values (2)");
	// ���� mysql_query() �Լ��� MYSQL ����ü�� ���� ������ ����
	query_start = mysql_query(connection, query);
	if (query_start != 0) // ���� ���н�
	{
		sprintf_s(state, "Mysql query error : %s", mysql_error(&conn));
		sql.mysql_Success = false;
	}
	else // ������
	{
		mysql_Success = true;
	}
}

void Mysql::save2()
{
	if (!sql.mysql_Success)return;
	/////////////////////////////////////////////

	_itoa_s(inventory.money, money, 10); //1 ��
	_itoa_s(item.item_cruciancarp.howmany, cruciancarp, 10); //2 �ؾ�
	_itoa_s(item.item_jang.howmany, jang, 10); //3 ���
	_itoa_s(item.item_lobster.howmany, lobster, 10); //4 
	_itoa_s(item.item_bing.howmany, bing, 10); //5 
	_itoa_s(item.item_frog.howmany, frog, 10); //6 
	_itoa_s(item.item_ing.howmany, ing, 10); //7 
	_itoa_s(item.item_octopus.howmany, octopus, 10); //8 
	_itoa_s(item.item_shark.howmany, shark, 10); //9 
	_itoa_s(item.item_trash.howmany, trash, 10); //10 
	_itoa_s(item.item_tuna.howmany, tuna, 10); //11
	_itoa_s(item.item_yeon.howmany, yeon, 10); //12 
	_itoa_s(item.item_bait.howmany, bait, 10); //13
	_itoa_s(item.item_ricecake.howmany, ricecake, 10); //14 
	_itoa_s(item.item_shirimp.howmany, shirimp, 10); //15 
	_itoa_s(item.item_fishingrod.howmany, fishingrod, 10); //16 
	_itoa_s(item.item_goodfishingrod.howmany, goodfishingrod, 10); //17 
	_itoa_s(quest.num_mission, num_quest, 10); //18
	_itoa_s(inventory.usingfishrodcode, wear_fishingrod, 10); //19
	_itoa_s(inventory.usingbaitcode, use_item, 10); // 

													 //������ #define���� ���ڷ� �����ؼ� for������ �����°� ����ϰ� �ڵ���
													 // ���� �� ������ ����

	sprintf_s(query, "update save set money=%s where saveslot=2", money);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set cruciancarp_num=%s where saveslot=2", cruciancarp);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set jang_num=%s where saveslot=2", jang);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set lobster_num=%s where saveslot=2", lobster);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set bing_num=%s where saveslot=2", bing);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set frog_num=%s where saveslot=2", frog);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set ing_num=%s where saveslot=2", ing);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set octopus_num=%s where saveslot=2", octopus);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set shark_num=%s where saveslot=2", shark);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set trash_num=%s where saveslot=2", trash);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set tuna_num=%s where saveslot=2", tuna);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set yeon_num=%s where saveslot=2", yeon);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set bait_num=%s where saveslot=2", bait);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set ricecake_num=%s where saveslot=2", ricecake);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set shrimp_num=%s where saveslot=2", shirimp);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set fishingrod=%s where saveslot=2", fishingrod);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set goodfishingrod=%s where saveslot=2", goodfishingrod);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set quest=%s where saveslot=2", num_quest);//����
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set wearfishingrod=%s where saveslot=2", wear_fishingrod);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set usingitem=%s where saveslot=2", use_item);
	query_start = mysql_query(connection, query);


	query_start = mysql_query(connection, query);
	if (query_start != 0) // ���� ���н�
	{
		sprintf_s(state, "Mysql query error : %s", mysql_error(&conn));
		sql.mysql_Success = false;
	}
	else // ������
	{
		mysql_Success = true;
	}
}
void Mysql::save3()
{
	if (!sql.mysql_Success)return;
	/////////////////////////////////////////////

	_itoa_s(inventory.money, money, 10); //1 ��
	_itoa_s(item.item_cruciancarp.howmany, cruciancarp, 10); //2 �ؾ�
	_itoa_s(item.item_jang.howmany, jang, 10); //3 ���
	_itoa_s(item.item_lobster.howmany, lobster, 10); //4 
	_itoa_s(item.item_bing.howmany, bing, 10); //5 
	_itoa_s(item.item_frog.howmany, frog, 10); //6 
	_itoa_s(item.item_ing.howmany, ing, 10); //7 
	_itoa_s(item.item_octopus.howmany, octopus, 10); //8 
	_itoa_s(item.item_shark.howmany, shark, 10); //9 
	_itoa_s(item.item_trash.howmany, trash, 10); //10 
	_itoa_s(item.item_tuna.howmany, tuna, 10); //11
	_itoa_s(item.item_yeon.howmany, yeon, 10); //12 
	_itoa_s(item.item_bait.howmany, bait, 10); //13
	_itoa_s(item.item_ricecake.howmany, ricecake, 10); //14 
	_itoa_s(item.item_shirimp.howmany, shirimp, 10); //15 
	_itoa_s(item.item_fishingrod.howmany, fishingrod, 10); //16 
	_itoa_s(item.item_goodfishingrod.howmany, goodfishingrod, 10); //17 
	_itoa_s(quest.num_mission, num_quest, 10); //18
	_itoa_s(inventory.usingfishrodcode, wear_fishingrod, 10); //19
	_itoa_s(inventory.usingbaitcode, use_item, 10); // 

													 //������ #define���� ���ڷ� �����ؼ� for������ �����°� ����ϰ� �ڵ���
													 // ���� �� ������ ����

	sprintf_s(query, "update save set money=%s where saveslot=3", money);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set cruciancarp_num=%s where saveslot=3", cruciancarp);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set jang_num=%s where saveslot=3", jang);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set lobster_num=%s where saveslot=3", lobster);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set bing_num=%s where saveslot=3", bing);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set frog_num=%s where saveslot=3", frog);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set ing_num=%s where saveslot=3", ing);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set octopus_num=%s where saveslot=3", octopus);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set shark_num=%s where saveslot=3", shark);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set trash_num=%s where saveslot=3", trash);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set tuna_num=%s where saveslot=3", tuna);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set yeon_num=%s where saveslot=3", yeon);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set bait_num=%s where saveslot=3", bait);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set ricecake_num=%s where saveslot=3", ricecake);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set shrimp_num=%s where saveslot=3", shirimp);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set fishingrod=%s where saveslot=3", fishingrod);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set goodfishingrod=%s where saveslot=3", goodfishingrod);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set quest=%s where saveslot=3", num_quest);//����
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set wearfishingrod=%s where saveslot=3", wear_fishingrod);
	query_start = mysql_query(connection, query);

	sprintf_s(query, "update save set usingitem=%s where saveslot=3", use_item);
	query_start = mysql_query(connection, query);


	query_start = mysql_query(connection, query);
	if (query_start != 0) // ���� ���н�
	{
		sprintf_s(state, "Mysql query error : %s", mysql_error(&conn));
		sql.mysql_Success = false;
	}
	else // ������
	{
		mysql_Success = true;
	}
}

/*
Mysql �����ϱ�
* 64 ��Ʈ�� ��� 64 ��Ʈ ���� �� ������.
* ���� ���͸��� C:\Program Files\MySQL\MySQL Server 5.7\include �� �߰�
* ���̺귯�� ���͸��� C:\Program Files\MySQL\MySQL Server 5.7\lib �߰�
* ��Ŀ ���� libmysql.lib
* C:\Program Files\MySQL\MySQL Server 5.7\lib �ȿ� libmysql.dll ���� �� ������ ������Ʈ ������ �����ֱ�

mysql ���� �Լ��� ����ϸ鼭 ������ �߻�?????.
�� mysql.h�� ������ ����, �� �Լ����� ���ǵǾ� �ִ� ����(���̺귯���� ���ǵǾ� �ֽ��ϴ�.)�� ã�� �� ���ٴ� �����̴�.
�츮 ���� ȯ���� ������7 64Bit �Դϴ�.
������ ������ ����� ���� 64 ��Ʈ�� �����Դϴ�.
ȯ���� 64��Ʈ�̴� �и� mysql ��ġ�� ���� 64��Ʈ�� �����Ͽ� ��ġ�߽��ϴ�.
�׷���? �츮�� ����ϰ� �ִ� ����� ��Ʃ���, �� ���� ȯ���� 32��Ʈ�Դϴ�.
���� ȯ���� 64��Ʈ�� �ٲ��ָ� ������ ������ϴ�.

*/