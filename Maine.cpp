#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;
//#define WRITE_TO_FILE
//#define READ_FROM_FILE
//#define DZ_FILE_1
#define DZ_FILE_2
void main()
{
	setlocale(LC_ALL, "RUS");
#ifdef WRITE_TO_FILE
	char fillename[_MAX_FNAME] = {};
	cout << "������� ��� �����: ";
	cin.getline(fillename, _MAX_FNAME);
	if (strcmp(fillename + strlen(fillename) - 4, ".txt"))strcat_s(fillename, _MAX_FNAME, ".txt");

	ofstream  fout;					//1)������� �����
	fout.open(fillename,std::ios_base::app);//2) ��������� �����

	fout << "Hello files" << endl;	//3)����� � �����
	fout.close();					//4)��������� �����
	char sz_command[_MAX_FNAME] = "notepad ";
	strcat_s(sz_command, _MAX_FNAME, fillename);
	system(sz_command);

#endif // WRITE_TO_FILE
#ifdef READ_FROM_FILE


	ifstream fin;
	fin.open("File.txt");
	if (fin.is_open())
	{
		const int size = 30720;
		char sz_bufer[size]{};
		while (!fin.eof())
		{
			//fin >> sz_bufer;
			fin.getline(sz_bufer, size);
			cout << sz_bufer << endl;
		}

		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
		//cout -console out
		//cerr - console error
	}
#endif // READ_FROM_FILE 
#ifdef DZ_FILE_1
	ifstream fin;
	fin.open("201 RAW.txt");
	if (fin.is_open())
	{
		const int size = _MAX_FNAME;
		char sz_bufer[size]{};//����� ����� 
		char st_bufer[size]{};//����� ����������� �����	
		int size_st{};
		while (!fin.eof())
		{
			fin.getline(sz_bufer, size);
			cout << sz_bufer << endl;
			
			size_st = strlen(sz_bufer);//���������� ������ ������ ��� ������� �� ���
			for (int i = 0, coll = 0; i < size_st; i++)
			{
				if (sz_bufer[i] == ' ' && coll == 0)
				{
					strcpy_s(st_bufer, size, sz_bufer + i + 8);
					coll++;
				}
				if (sz_bufer[i] == ' ')
				{
					strcat_s(st_bufer, size, " ");
				}
				if (sz_bufer[i] == ' ' && sz_bufer[i + 1] != ' ')
				{
					strncat(st_bufer, sz_bufer, i);
				}
			}
			char fillename[_MAX_FNAME] = { "201 ready.txt" };
			ofstream  fout;					//1)������� �����
			fout.open(fillename, std::ios_base::app);//2) ��������� �����
			fout << st_bufer << endl;	//3)����� � �����
			system("notepad 201 ready.txt");
			fout.close();				//4)��������� ����� ������		
		}			
		fin.close();//��������� ����� ������
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
		//cout -console out
		//cerr - console error
	}
#endif // DZ_FILE_1
#ifdef DZ_FILE_2
	ifstream fin;
	fin.open("201 RAW.txt");
	if (fin.is_open())
	{
		const int size = _MAX_FNAME;
		char sz_bufer[size]{};//����� ����� 
		char st_bufer_IP[size]{};//����� IP
		char st_bufer_har[size]{};//����� har
		int size_st{};
		int index=0;
		while (!fin.eof())
		{
			fin.getline(sz_bufer, size);
			//cout << sz_bufer << endl;

			size_st = strlen(sz_bufer);//���������� ������ ������ ��� ������� �� ���
			for (int i = 0; i < size_st; i++)
			{
				if (sz_bufer[i] != ' '&&sz_bufer[i+1]==' ')
				{

					strcpy(st_bufer_IP,sz_bufer);//�������
					
				}
						for (int j = 0; j < size_st; j++)
						{
							if (st_bufer_IP[i] == ' ')
							{
							st_bufer_IP[i] = '\0';
							break;
							}
						}

			}
			for (int i = 0; i < size_st; i++)
			{
				if (sz_bufer[i] == ' ' && sz_bufer[i + 1] != ' ')
				{
					strcpy(st_bufer_har, &sz_bufer[i]);
				}
			}



			char fillename[_MAX_FNAME] = { "201.dhcpd.txt" };
			ofstream  fout;					//1)������� �����
			fout.open(fillename, std::ios_base::app);//2) ��������� �����
			index++;
				fout << "host 201-" <<index << endl;
				fout << "{" << endl;
				fout << "\thardware ethernet\t" << st_bufer_har << ";" << endl;
				fout << "\tfixed-address\t\t" << st_bufer_IP << ";" << endl;
				fout << "}" << endl;
				
			fout.close();				//4)��������� ����� ������	

			
		}
		fin.close();//��������� ����� ������
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
		//cout -console out
		//cerr - console error
	}







#endif // DZ_FILE_2




}