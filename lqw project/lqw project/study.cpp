#include <iostream>
using namespace std;
#include <string>
#define MAXNUMB 1000


struct Person  //联系人结构体person
{
	string name;
	int gender;
	int		phonenumb;
	string	location;
};


struct Callbook  //通讯录结构体
{
	struct Person person[MAXNUMB];
	int coum;
};


void printfmenu();    //打印菜单
int menu(struct Callbook *); //功能选择
void addperson(struct Callbook *); //添加联系人
void showperson(Callbook *);//展示联系人
int find(Callbook*);  //遍历搜索
void deleteperson(Callbook *);//删除联系人
void findperson(Callbook *);//查找联系人
void update(Callbook*);//修改联系人
void empty(Callbook *);//清空联系人



void printfmenu()
{
	cout<<"1.增加联系人"<<endl;
	cout<<"2.展示联系人"<<endl;
	cout<<"3.删除联系人"<<endl;
	cout << "4.查找联系人" << endl;
	cout << "5.修改联系人" << endl;
	cout << "6.清空联系人" << endl;
	cout << "7.退出通讯录" << endl;
}

int menu(struct Callbook * txlp)
{
	int menunumb;
	while (1)
	{
		cout <<endl<< "请选择要使用的功能" << endl;
		cin >> menunumb;
		cout << "选择的功能是" << menunumb << endl;
	
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
			cout << "再见!" << endl;
			return 0;
			break;
			/*default:cout << "error" << endl;*/
		}
		
	}

}

void addperson(struct Callbook *txlp)
{
	cout << "请输入要存储的联系人姓名" << endl;
	cin >> txlp->person[txlp->coum].name;
	cout << "输入的姓名为" << txlp->person[txlp->coum].name<<endl;
	cout << "请输入性别：1--男  2--女" << endl;
	cin >> txlp->person[txlp->coum].gender;
	cout << "你输入的性别为" << (txlp->person[txlp->coum].gender==1 ? "男" : "女" )<< endl;
	cout << "请输入电话" << endl;
	cin >> txlp->person[txlp->coum].phonenumb;
	cout <<"你输入的电话为："<< txlp->person[txlp->coum].phonenumb << endl;
	cout << "请输入联系人的地址" << txlp->person[txlp->coum].location << endl;
	cin >> txlp->person[txlp->coum].location;
	cout << "你输入的地址为：" << txlp->person[txlp->coum].location << endl;
	cout << "添加联系人成功" << endl;
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
			cout << "联系人姓名为" << txlp->person[i].name << "\t";
			cout << "联系人性别为" << (txlp->person[txlp->coum].gender == 1 ? "男" : "女") << "\t";
			cout << "联系人电话为" << txlp->person[i].phonenumb << '\t';
			cout << "联系人地址为" << txlp->person[i].location <<endl;
		}
	}
	else
		cout << "空空如也" << endl;
}
	
int find(Callbook *txlp)
{
		string name;
		cout << "请输入你要操作的联系人姓名" << endl;
		cin >> name;
		for (int i = 0; i < txlp->coum; i++)
		{
			if (txlp->person[i].name==name)
			{
				cout << "i等于" << i << endl;
				return i;
			}
		}
		return 0;
}


void deleteperson(Callbook * txlp)
{
	if (txlp->coum == 0)
	{
		cout << "你的通讯录没有人哦" << endl;
	}
	else
	{
		int del_i = find(txlp);
		if (del_i == -1)
		{
			cout << "没找到这个人，老弟你是不是输错了" << endl;
		}
		else
		{
			for (int i = del_i; i < txlp->coum; i++)
			{
				txlp->person[i].name = txlp->person[i + 1].name;
				txlp->person[i].gender = txlp->person[i + 1].gender;
				txlp->person[i].phonenumb = txlp->person[i + 1].phonenumb;
				txlp->person[i].location = txlp->person[i + 1].location;
				cout << "删除成功" << endl;
				txlp->coum--;
			}
		}
	}
	
}


void findperson(Callbook* txlp)
{
	if (txlp->coum == 0)
	{
		cout << "你的通讯录没有人哦" << endl;
	}
	else
	{
		int find_i = find(txlp);
		if (find_i == -1)
		{
			cout << "没找到，输错了吧兄弟" << endl;
		}
		else
		{
			cout << "联系人姓名为" << txlp->person[find_i].name << "\t";
			cout << "联系人性别为" << (txlp->person[txlp->coum].gender == 1 ? "男" : "女") << "\t";
			cout << "联系人电话为" << txlp->person[find_i].phonenumb << '\t';
			cout << "联系人地址为" << txlp->person[find_i].location << "\t";
		}

	}
	
}

void update(Callbook * txlp)
{
	if (txlp->coum == 0)
	{
		cout << "你的通讯录没有人哦" << endl;
	}
	else 
	{
		int upd_i = find(txlp);
		if (upd_i == -1)
		{
			cout << "没找到这个人，输错了吧" << endl;
		}
		else
		{
			cout << "请输入要存储的联系人姓名" << endl;
			cin >> txlp->person[upd_i].name;
			cout << "输入的姓名为" << txlp->person[upd_i].name << endl;
			cout << "请输入性别：1--男  2--女" << endl;
			cin >> txlp->person[upd_i].gender;
			cout << "你输入的性别为" << (txlp->person[txlp->coum].gender == 1 ? "男" : "女") << endl;
			cout << "请输入电话" << endl;
			cin >> txlp->person[upd_i].phonenumb;
			cout << "你输入的电话为：" << txlp->person[upd_i].phonenumb << endl;
			cout << "请输入联系人的地址" << txlp->person[upd_i].location << endl;
			cin >> txlp->person[upd_i].location;
			cout << "你输入的地址为：" << txlp->person[upd_i].location << endl;
			cout << "添加联系人成功" << endl;
		}
	}

}

void empty(Callbook *txlp)   //逻辑清空
{
	txlp->coum = 0;
	cout << "清空成功" << endl;
}

int main()
{
	struct Callbook txl;
	txl.coum = 0;
	struct Callbook *txlp = &txl;
	printfmenu();
	menu(txlp);
	system("pause");
}