#include <iostream>
using namespace std;
#include <string>
#define MAXNUMB 1000


struct Person  //��ϵ�˽ṹ��person
{
	string name;
	int gender;
	int		phonenumb;
	string	location;
};


struct Callbook  //ͨѶ¼�ṹ��
{
	struct Person person[MAXNUMB];
	int coum;
};


void printfmenu();    //��ӡ�˵�
int menu(struct Callbook *); //����ѡ��
void addperson(struct Callbook *); //�����ϵ��
void showperson(Callbook *);//չʾ��ϵ��
int find(Callbook*);  //��������
void deleteperson(Callbook *);//ɾ����ϵ��
void findperson(Callbook *);//������ϵ��
void update(Callbook*);//�޸���ϵ��
void empty(Callbook *);//�����ϵ��



void printfmenu()
{
	cout<<"1.������ϵ��"<<endl;
	cout<<"2.չʾ��ϵ��"<<endl;
	cout<<"3.ɾ����ϵ��"<<endl;
	cout << "4.������ϵ��" << endl;
	cout << "5.�޸���ϵ��" << endl;
	cout << "6.�����ϵ��" << endl;
	cout << "7.�˳�ͨѶ¼" << endl;
}

int menu(struct Callbook * txlp)
{
	int menunumb;
	while (1)
	{
		printfmenu();
		cout <<endl<< "��ѡ��Ҫʹ�õĹ���" << endl;
		cin >> menunumb;
		cout << "ѡ��Ĺ�����" << menunumb << endl;
	
		switch (menunumb)
		{
		case 1:
			addperson(txlp);
			break;
		case 2:
			showperson(txlp);
			break;
		case 3:
			deleteperson(txlp);
			break;
		case 4:
			findperson(txlp);
			break;
		case 5:
			update(txlp);
			break;
		case 6:
			empty(txlp);
			break;
		case 7:
			cout << "�ټ�!" << endl;
			return 0;
			break;

			default:cout << "�����������������" << endl;
				system("pause");
				system("cls");
		}
		
	}

}

void addperson(struct Callbook *txlp)
{
	cout << "������Ҫ�洢����ϵ������" << endl;
	cin >> txlp->person[txlp->coum].name;
	cout << "���������Ϊ" << txlp->person[txlp->coum].name<<endl;
	cout << "�������Ա�1--��  2--Ů" << endl;
	cin >> txlp->person[txlp->coum].gender;
	cout << "��������Ա�Ϊ" << (txlp->person[txlp->coum].gender==1 ? "��" : "Ů" )<< endl;
	cout << "������绰" << endl;
	cin >> txlp->person[txlp->coum].phonenumb;
	cout <<"������ĵ绰Ϊ��"<< txlp->person[txlp->coum].phonenumb << endl;
	cout << "��������ϵ�˵ĵ�ַ" << txlp->person[txlp->coum].location << endl;
	cin >> txlp->person[txlp->coum].location;
	cout << "������ĵ�ַΪ��" << txlp->person[txlp->coum].location << endl;
	cout << "�����ϵ�˳ɹ�" << endl;
	++txlp->coum;
	system("pause");
	system("cls");
}



void showperson(Callbook * txlp)
{
	if (txlp->coum != 0)
	{
		for (int i = 0;i<(txlp->coum);i++)
		{
			cout << "��ϵ������Ϊ" << txlp->person[i].name << "\t";
			cout << "��ϵ���Ա�Ϊ" << (txlp->person[txlp->coum].gender == 1 ? "��" : "Ů") << "\t";
			cout << "��ϵ�˵绰Ϊ" << txlp->person[i].phonenumb << '\t';
			cout << "��ϵ�˵�ַΪ" << txlp->person[i].location <<endl;
		}
	}
	else
		cout << "�տ���Ҳ" << endl;
	system("pause");
	system("cls");
}
	
int find(Callbook *txlp)
{
		string name;
		cout << "��������Ҫ��������ϵ������" << endl;
		cin >> name;
		for (int i = 0; i < txlp->coum; i++)
		{
			if (txlp->person[i].name==name)
			{
				cout << "i����" << i << endl;
				return i;
			}
		}
		return -1;
}


void deleteperson(Callbook * txlp)
{
	if (txlp->coum == 0)
	{
		cout << "���ͨѶ¼û����Ŷ" << endl;
	}
	else
	{
		int del_i = find(txlp);
		if (del_i == -1)
		{
			cout << "û�ҵ�����ˣ��ϵ����ǲ��������" << endl;
		}
		else
		{
			for (int i = del_i; i < txlp->coum; i++)
			{
				txlp->person[i].name = txlp->person[i + 1].name;
				txlp->person[i].gender = txlp->person[i + 1].gender;
				txlp->person[i].phonenumb = txlp->person[i + 1].phonenumb;
				txlp->person[i].location = txlp->person[i + 1].location;
				cout << "ɾ���ɹ�" << endl;
				txlp->coum--;
			}
		}
	}
	system("pause");
	system("cls");
	
}


void findperson(Callbook* txlp)
{
	if (txlp->coum == 0)
	{
		cout << "���ͨѶ¼û����Ŷ" << endl;
	}
	else
	{
		int find_i = find(txlp);
		if (find_i == -1)
		{
			cout << "û�ҵ�������˰��ֵ�" << endl;
		}
		else
		{
			cout << "��ϵ������Ϊ" << txlp->person[find_i].name << "\t";
			cout << "��ϵ���Ա�Ϊ" << (txlp->person[txlp->coum].gender == 1 ? "��" : "Ů") << "\t";
			cout << "��ϵ�˵绰Ϊ" << txlp->person[find_i].phonenumb << '\t';
			cout << "��ϵ�˵�ַΪ" << txlp->person[find_i].location << "\t";
		}

	}
	system("pause");
	system("cls");
	
}

void update(Callbook * txlp)
{
	if (txlp->coum == 0)
	{
		cout << "���ͨѶ¼û����Ŷ" << endl;
	}
	else 
	{
		int upd_i = find(txlp);
		if (upd_i == -1)
		{
			cout << "û�ҵ�����ˣ�����˰�" << endl;
		}
		else
		{
			cout << "������Ҫ�洢����ϵ������" << endl;
			cin >> txlp->person[upd_i].name;
			cout << "���������Ϊ" << txlp->person[upd_i].name << endl;
			cout << "�������Ա�1--��  2--Ů" << endl;
			cin >> txlp->person[upd_i].gender;
			cout << "��������Ա�Ϊ" << (txlp->person[txlp->coum].gender == 1 ? "��" : "Ů") << endl;
			cout << "������绰" << endl;
			cin >> txlp->person[upd_i].phonenumb;
			cout << "������ĵ绰Ϊ��" << txlp->person[upd_i].phonenumb << endl;
			cout << "��������ϵ�˵ĵ�ַ" << txlp->person[upd_i].location << endl;
			cin >> txlp->person[upd_i].location;
			cout << "������ĵ�ַΪ��" << txlp->person[upd_i].location << endl;
			cout << "�����ϵ�˳ɹ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

void empty(Callbook *txlp)   //�߼����
{
	txlp->coum = 0;
	cout << "��ճɹ�" << endl;
}

int main()
{
	struct Callbook txl;
	txl.coum = 0;
	struct Callbook *txlp = &txl;
	menu(txlp);
	system("pause");
}