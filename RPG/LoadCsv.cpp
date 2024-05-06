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

	vector<int>			 int_tmpvec;
	vector<bool>		 bool_tmpvec;
	vector<vector<int>>  layer1;
	vector<vector<int>>  layer2;
	vector<vector<int>>  layer3;
	vector<vector<bool>> passflag;
	vector<eEvent>		 eventdata;

	vector<MapCell> tmpmapcells;
	
	//layer1
	while (true)
	{
		c = FileRead_getc(fp);

		if (isCharactor(c) == true)//�����������s�͓ǂݔ�΂�(0�`9,\n,\r�͂̂���)
		{
			while (c != '\n')
				c = FileRead_getc(fp);

			if (isTitle==true) {//�ǂݍ��݂������C���[�Ȃ�while������
				isTitle = false;
				continue;
			}
			else {
				break;//���̃��C���[�֐i��
				isTitle = true;
			}
		}
		else if (c == ',')//�J���}�Ȃ琔�l������
		{
			int_tmpvec.push_back(atoi(str.c_str()));
			str.erase(str.begin(), str.end());
		}
		else if (c == '\n' || c == '\r')
		{
			if (str == "")
				continue;
			int_tmpvec.push_back(atoi(str.c_str()));
			str.erase(str.begin(), str.end());
			layer1.push_back(int_tmpvec);
			int_tmpvec.clear();
		}
		else if (c == EOF) {
			break;
		}
		else {
			str.push_back(c);
		}
	}
	//layer2
	while (true)
	{
		c = FileRead_getc(fp);

		if (isCharactor(c) == true)//�����������s�͓ǂݔ�΂�(0�`9,\n,\r�͂̂���)
		{
			while (c != '\n')
				c = FileRead_getc(fp);

			if (isTitle == true) {//�ǂݍ��݂������C���[�Ȃ�while������
				isTitle = false;
				continue;
			}
			else {
				break;//���̃��C���[�֐i��
				isTitle = true;
			}
		}
		else if (c == ',')//�J���}�Ȃ琔�l������
		{
			int_tmpvec.push_back(atoi(str.c_str()));
			str.erase(str.begin(), str.end());
		}
		else if (c == '\n' || c == '\r')
		{
			if (str == "")
				continue;
			int_tmpvec.push_back(atoi(str.c_str()));
			str.erase(str.begin(), str.end());
			layer2.push_back(int_tmpvec);
			int_tmpvec.clear();
		}
		else if (c == EOF) {
			break;
		}
		else {
			str.push_back(c);
		}
	}
	//layer3
	while (true)
	{
		c = FileRead_getc(fp);

		if (isCharactor(c) == true)//�����������s�͓ǂݔ�΂�(0�`9,\n,\r�͂̂���)
		{
			while (c != '\n')
				c = FileRead_getc(fp);

			if (isTitle == true) {//�ǂݍ��݂������C���[�Ȃ�while������
				isTitle = false;
				continue;
			}
			else {
				break;//���̃��C���[�֐i��
				isTitle = true;
			}
		}
		else if (c == ',')//�J���}�Ȃ琔�l������
		{
			int_tmpvec.push_back(atoi(str.c_str()));
			str.erase(str.begin(), str.end());
		}
		else if (c == '\n' || c == '\r')
		{
			if (str == "")
				continue;
			int_tmpvec.push_back(atoi(str.c_str()));
			str.erase(str.begin(), str.end());
			layer3.push_back(int_tmpvec);
			int_tmpvec.clear();
		}
		else if (c == EOF) {
			break;
		}
		else {
			str.push_back(c);
		}
	}
	//canpass flag
	while (true)
	{
		c = FileRead_getc(fp);

		if (isCharactor(c) == true)//�����������s�͓ǂݔ�΂�(0�`9,\n,\r�͂̂���)
		{
			while (c != '\n')
				c = FileRead_getc(fp);

			if (isTitle == true) {//�ǂݍ��݂������C���[�Ȃ�while������
				isTitle = false;
				continue;
			}
			else {
				break;//���̃��C���[�֐i��
				isTitle = true;
			}
		}
		else if (c == ',')//�J���}�Ȃ琔�l������
		{
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
		else if (c == EOF) {
			break;
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
				eEvent::testevent//����͉�
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
		ERR("���݂��Ȃ��}�b�v�ł�");
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