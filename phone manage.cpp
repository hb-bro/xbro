#include <iostream>
#include <string>
using namespace std;

#define Max 1000 //最大人数

//联系人结构体
struct Person
{
    string m_Name;//姓名
    int m_Sex;//性别：1男 2女
    int m_Age;//年龄
    string m_phone;//电话
    string m_Addr;//住址
};

//通讯录结构体
struct Addressbooks
{
    struct Person PersonArray[Max];//通讯录中保存的联系人数组
    int m_Size;//通讯录中人员个数
};

//1、添加联系人
void addPerson(Addressbooks *abs)

{
    //判断通讯录是否已满，如果满了就不在添加
    if(abs->m_Size == Max)
    {
        cout << "通讯录已满" << endl;
        return;
    }
    else
    {
        //添加联系人

        //姓名
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->PersonArray[abs->m_Size].m_Name = name;

        //性别
        cout << "请输入性别" << endl;
        cout << "1---男" << endl;
        cout << "2---女" << endl;
        int sex = 0;
        while(1)
        {
            //如果输入1 or 2 可以推出循环
            cin >> sex;
            if(sex==1 || sex==2)
            {
                abs->PersonArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }
        

        //年龄
        cout << "请输入年龄： " << endl;
        int age = 0;
        cin >> age;
        abs->PersonArray[abs->m_Size].m_Age = age;

        //电话
        cout << "请输入联系电话： " << endl;
        string phone;
        cin >> phone;
        abs->PersonArray[abs->m_Size].m_phone = phone;

        //住址
        cout << "请输入家庭地址： " << endl;
        string addr;
        cin >> addr;
        abs->PersonArray[abs->m_Size].m_Addr = addr;
    }
    //更新通讯录人数
    abs->m_Size++;
    cout << "添加成功" << endl;

    system("pause");//请按任意键继续
    system("cls"); //清屏
}

//2、显示联系人
void showPerson(Addressbooks *abs)
{
    //判断通讯录中是否为零
    if(abs->m_Size == 0){
        cout << "通讯录记录为空" << endl; 
    }
    else
    {
        for(int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名： " << abs->PersonArray[i].m_Name << "\t";
            cout << "性别: " << (abs->PersonArray[i].m_Sex == 1 ? "男":"女")<< "\t";
            cout << "年龄: " << abs->PersonArray[i].m_Age << "\t";
            cout << "电话: " << abs->PersonArray[i].m_phone << "\t";
            cout << "家庭地址:" << abs->PersonArray[i].m_Addr << endl;
        }
        
    }
    system("pause");
    system("cls");
}

//检测联系人是否存在，如果存在，返回联系人所在数组的具体位置，不存在返回-1
//参数1：通讯录 参数2：对比姓名
int isExist(Addressbooks *abs, string name)
{
    for(int i = 0; i < abs->m_Size; i++)
    {
        if (name == abs->PersonArray[i].m_Name)
        {
            return i;//找到返回下标
        }
    }
    return -1;//如果遍历结束没有找到，返回-1
}

//3、删除联系人
void deletePerson(Addressbooks *abs)
{
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);//ret =1 找到了 ret=-1 没找到
    if(ret != -1)
    {
        //查到删除
        for(int i = ret; i < abs->m_Size; i++)
        {
            //数据迁移
            abs->PersonArray[i] = abs->PersonArray[i+i];
        }
        abs->m_Size--;//更新通讯录人数
        cout << "删除成功" << endl;
        
    }
    else
    {
        cout << "查无此人" <<endl;
    }
    system("pause");
    system("cls");
}

//4、查找联系人
void findPerson(Addressbooks *abs)
{
    cout << "请输入需要查找的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs,name);
    if(ret != -1)//找到了
    {
        cout << "姓名： " << abs->PersonArray[ret].m_Name << "\t";
            cout << "性别: " << (abs->PersonArray[ret].m_Sex == 1 ? "男":"女")<< "\t";
            cout << "年龄: " << abs->PersonArray[ret].m_Age << "\t";
            cout << "电话: " << abs->PersonArray[ret].m_phone << "\t";
            cout << "家庭地址:" << abs->PersonArray[ret].m_Addr << endl;
    }
    else//找不到
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

//5、修改联系人
void modifyPerson(Addressbooks *abs)
{
    cout<< "请输入需要修改的联系人：" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs,name);
    if(ret != -1)//找到联系人
    {
        //姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->PersonArray[ret].m_Name = name;
        
        //性别
        cout << "请输入性别：" << endl;
        cout << "1---男"<< endl;
        cout << "2---女" << endl;
        int sex = 0;

        while(1)
        {
            cin >> sex;
            if( sex==1 || sex==2)
            {
                abs->PersonArray[ret].m_Sex = sex;
                break;
            }
            else
            {
                cout << "输入错误，请重新输入：" << endl;
            }
        }
        
        //年龄
        cout << "请输入年龄： " << endl;
        int age;
        cin >> age;
        abs->PersonArray[ret].m_Age = age;
        
        //电话
        cout << "请输入联系电话：" << endl;
        string phone;
        cin >> phone;
        abs->PersonArray[ret].m_phone = phone;

        //地址
        cout << "请输入地址" << endl;
        string addr;
        cin >> addr;
        abs->PersonArray[ret].m_Addr = addr;

        cout << "修改成功" << endl;
    }
    else//找不到
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

//6、清空所有联系人
void cleanPerson(Addressbooks *abs)
{
    abs->m_Size = 0;
    cout << "通讯录已清零" << endl;
    system("pause");
    system("cls");
}
//显示菜单
void showMenu()
{
    cout << "***********************" << endl;
    cout << "*****1、添加联系人*****" << endl;
    cout << "*****2、显示联系人*****" << endl;
    cout << "*****3、删除联系人*****" << endl;
    cout << "*****4、查找联系人*****" << endl;
    cout << "*****5、修改联系人*****" << endl;
    cout << "*****6、清空联系人*****" << endl;
    cout << "*****0、退出通讯录*****" << endl;
    cout << "***********************" << endl;
}

int main()
{
    //创建通讯录结构体变量
    Addressbooks abs;
    //初始化通讯录当前人员
    abs.m_Size = 0;
    int select = 0;//
    
    while(1){
        showMenu();//菜单调用
        cin >> select;
        switch (select)
        {
            case 1: //1、添加联系人
                addPerson(&abs);//利用地址传递，可以修改实参
                break;
            case 2: //2、显示联系人
                showPerson(&abs);
                break;
            case 3: //3、删除联系人
                deletePerson(&abs);
                // {
                //     cout << "请输入删除联系人姓名：" << endl;
                //     string name;
                //     cin >> name;
                    
                //     if(isExist(&abs,name) == -1)
                //     {
                //         cout << "查无此人" << endl;
                //     }
                //     else
                //     {
                //         cout << "找到此人" << endl;
                //     }
                //     break;
                // }
                break;
            case 4: //4、查找联系人
                findPerson(&abs);
                break;
            case 5: //5、修改联系人
                modifyPerson(&abs);
                break;
            case 6: //6、清空联系人
                cleanPerson(&abs);
                break;
            case 0: //0、退出通讯录
                    cout  << "欢迎下次使用" << endl;
                    system("pause");
                    return 0;
                break;
            default:
                break;
        }
    }
    
    getchar();
    return 0;
}