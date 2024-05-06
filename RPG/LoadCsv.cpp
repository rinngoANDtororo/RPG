#include"LoadCsv.h"

void LoadCsv::getMapCsv(eMapNames mname,vector<vector<MapCell>>& mapdata)
{
	int fp = FileRead_open(getMapCsvFilepass(mname).c_str());

	if (fp == NULL){
		ERR("Cannnot open 'map csv' file!");
		return;
	}

	string str = "";
	int c = 0;

	bool isTitle = true;
	short layernumber = 0;

	vector<int>			 int_tmpvec;
	vector<bool>		 bool_tmpvec;
	vector<vector<int>>  layer1;
	vector<vector<int>>  layer2;
	vector<vector<int>>  layer3;
	vector<vector<bool>> passflag;
	vector<eEvent>		 eventdata;

	vector<MapCell> tmpmapcells;
	
	//layer1,2,3
	while (true)
	{
		c = FileRead_getc(fp);

		if (isCharactor(c) == true)//文字だった行は読み飛ばす(0～9,\n,\rはのぞく)
		{
			while (c != '\n')
				c = FileRead_getc(fp);
			layernumber++;

			if (layernumber <= 3)
				continue;
			else
				break;
		}
		else if (c == ',')//カンマなら数値化する
		{
			if (str == "")
				continue;
			int_tmpvec.push_back(atoi(str.c_str()));
			str.erase(str.begin(), str.end());
		}
		else if (c == '\n' || c == '\r')
		{
			if (str == "")
				continue;
			int_tmpvec.push_back(atoi(str.c_str()));
			str.erase(str.begin(), str.end());
			switch (layernumber)
			{
			case 1:
				layer1.push_back(int_tmpvec);
				break;
			case 2:
				layer2.push_back(int_tmpvec);
				break;
			case 3:
				layer3.push_back(int_tmpvec);
				break;
			default:
				ERR("レイヤー範囲外です");
				break;
			}
			int_tmpvec.clear();
		}
		else {
			str.push_back(c);
		}
	}
	//canpass flag
	while (true)
	{
		c = FileRead_getc(fp);

		if (isCharactor(c) == true)//文字だった行は読み飛ばす(0～9,\n,\rはのぞく)
		{
			while (c != '\n')
				c = FileRead_getc(fp);
			layernumber++;


			if (layernumber <= 4)
				continue;//読み込みたいレイヤーならwhile続ける
			else
				break;//次のレイヤーへ進む
		}
		else if (c == ',')//カンマなら数値化する
		{
			if (str == "")
				continue;
			bool_tmpvec.push_back(ConvertPassageFlag(atoi(str.c_str())));
			str.erase(str.begin(), str.end());
		}
		else if (c == '\n' || c == '\r')
		{
			if (str == "")
				continue;
			bool_tmpvec.push_back(ConvertPassageFlag(atoi(str.c_str())));
			str.erase(str.begin(), str.end());
			passflag.push_back(bool_tmpvec);
			bool_tmpvec.clear();
		}
		else {
			str.push_back(c);
		}
	}
	//event
	while (true)
	{
		c = FileRead_getc(fp);
		if (c == EOF)
			break;
	}

	FileRead_close(fp);

	for (int i = 0; i < layer1.size(); i++)
	{
		for (int j = 0; j < layer1[0].size(); j++)
		{
			MapCell tmpcell = {
				j,
				i,
				layer1[i][j],
				layer2[i][j],
				layer3[i][j],
				passflag[i][j],
				eEvent::testevent//これは仮
			};
			tmpmapcells.push_back(tmpcell);
		}
		mapdata.push_back(tmpmapcells);
		tmpmapcells.clear();
	}

}

string LoadCsv::getMapCsvFilepass(eMapNames mname)
{
	string Filepass = "src/Map/";
	string filename;

	switch (mname)
	{
	case eMapNames::testMap:
		filename = "testMap";
		break;
	case eMapNames::testMap2:
		filename = "testMap2";
		break;
	default:
		ERR("存在しないマップです");
		break;
	}
	return (Filepass + filename + "/" + filename + ".csv");
}

bool LoadCsv::isCharactor(int ch)
{
	if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '0' || ch == ',' || ch == '\n' || ch == '\r')
		return false;
	else
		return true;
}