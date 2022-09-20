#include <iostream>
#include <string>
using namespace std;

#define Max 1000 //�������

//��ϵ�˽ṹ��
struct Person
{
    string m_Name;//����
    int m_Sex;//�Ա�1�� 2Ů
    int m_Age;//����
    string m_phone;//�绰
    string m_Addr;//סַ
};

//ͨѶ¼�ṹ��
struct Addressbooks
{
    struct Person PersonArray[Max];//ͨѶ¼�б������ϵ������
    int m_Size;//ͨѶ¼����Ա����
};

//1�������ϵ��
void addPerson(Addressbooks *abs)

{
    //�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
    if(abs->m_Size == Max)
    {
        cout << "ͨѶ¼����" << endl;
        return;
    }
    else
    {
        //�����ϵ��

        //����
        string name;
        cout << "����������" << endl;
        cin >> name;
        abs->PersonArray[abs->m_Size].m_Name = name;

        //�Ա�
        cout << "�������Ա�" << endl;
        cout << "1---��" << endl;
        cout << "2---Ů" << endl;
        int sex = 0;
        while(1)
        {
            //�������1 or 2 �����Ƴ�ѭ��
            cin >> sex;
            if(sex==1 || sex==2)
            {
                abs->PersonArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "������������������" << endl;
        }
        

        //����
        cout << "���������䣺 " << endl;
        int age = 0;
        cin >> age;
        abs->PersonArray[abs->m_Size].m_Age = age;

        //�绰
        cout << "��������ϵ�绰�� " << endl;
        string phone;
        cin >> phone;
        abs->PersonArray[abs->m_Size].m_phone = phone;

        //סַ
        cout << "�������ͥ��ַ�� " << endl;
        string addr;
        cin >> addr;
        abs->PersonArray[abs->m_Size].m_Addr = addr;
    }
    //����ͨѶ¼����
    abs->m_Size++;
    cout << "��ӳɹ�" << endl;

    system("pause");//�밴���������
    system("cls"); //����
}

//2����ʾ��ϵ��
void showPerson(Addressbooks *abs)
{
    //�ж�ͨѶ¼���Ƿ�Ϊ��
    if(abs->m_Size == 0){
        cout << "ͨѶ¼��¼Ϊ��" << endl; 
    }
    else
    {
        for(int i = 0; i < abs->m_Size; i++)
        {
            cout << "������ " << abs->PersonArray[i].m_Name << "\t";
            cout << "�Ա�: " << (abs->PersonArray[i].m_Sex == 1 ? "��":"Ů")<< "\t";
            cout << "����: " << abs->PersonArray[i].m_Age << "\t";
            cout << "�绰: " << abs->PersonArray[i].m_phone << "\t";
            cout << "��ͥ��ַ:" << abs->PersonArray[i].m_Addr << endl;
        }
        
    }
    system("pause");
    system("cls");
}

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ����������ľ���λ�ã������ڷ���-1
//����1��ͨѶ¼ ����2���Ա�����
int isExist(Addressbooks *abs, string name)
{
    for(int i = 0; i < abs->m_Size; i++)
    {
        if (name == abs->PersonArray[i].m_Name)
        {
            return i;//�ҵ������±�
        }
    }
    return -1;//�����������û���ҵ�������-1
}

//3��ɾ����ϵ��
void deletePerson(Addressbooks *abs)
{
    cout << "��������Ҫɾ������ϵ��" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);//ret =1 �ҵ��� ret=-1 û�ҵ�
    if(ret != -1)
    {
        //�鵽ɾ��
        for(int i = ret; i < abs->m_Size; i++)
        {
            //����Ǩ��
            abs->PersonArray[i] = abs->PersonArray[i+i];
        }
        abs->m_Size--;//����ͨѶ¼����
        cout << "ɾ���ɹ�" << endl;
        
    }
    else
    {
        cout << "���޴���" <<endl;
    }
    system("pause");
    system("cls");
}

//4��������ϵ��
void findPerson(Addressbooks *abs)
{
    cout << "��������Ҫ���ҵ���ϵ��" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs,name);
    if(ret != -1)//�ҵ���
    {
        cout << "������ " << abs->PersonArray[ret].m_Name << "\t";
            cout << "�Ա�: " << (abs->PersonArray[ret].m_Sex == 1 ? "��":"Ů")<< "\t";
            cout << "����: " << abs->PersonArray[ret].m_Age << "\t";
            cout << "�绰: " << abs->PersonArray[ret].m_phone << "\t";
            cout << "��ͥ��ַ:" << abs->PersonArray[ret].m_Addr << endl;
    }
    else//�Ҳ���
    {
        cout << "���޴���" << endl;
    }
    system("pause");
    system("cls");
}

//5���޸���ϵ��
void modifyPerson(Addressbooks *abs)
{
    cout<< "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs,name);
    if(ret != -1)//�ҵ���ϵ��
    {
        //����
        string name;
        cout << "������������" << endl;
        cin >> name;
        abs->PersonArray[ret].m_Name = name;
        
        //�Ա�
        cout << "�������Ա�" << endl;
        cout << "1---��"<< endl;
        cout << "2---Ů" << endl;
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
                cout << "����������������룺" << endl;
            }
        }
        
        //����
        cout << "���������䣺 " << endl;
        int age;
        cin >> age;
        abs->PersonArray[ret].m_Age = age;
        
        //�绰
        cout << "��������ϵ�绰��" << endl;
        string phone;
        cin >> phone;
        abs->PersonArray[ret].m_phone = phone;

        //��ַ
        cout << "�������ַ" << endl;
        string addr;
        cin >> addr;
        abs->PersonArray[ret].m_Addr = addr;

        cout << "�޸ĳɹ�" << endl;
    }
    else//�Ҳ���
    {
        cout << "���޴���" << endl;
    }
    system("pause");
    system("cls");
}

//6�����������ϵ��
void cleanPerson(Addressbooks *abs)
{
    abs->m_Size = 0;
    cout << "ͨѶ¼������" << endl;
    system("pause");
    system("cls");
}
//��ʾ�˵�
void showMenu()
{
    cout << "***********************" << endl;
    cout << "*****1�������ϵ��*****" << endl;
    cout << "*****2����ʾ��ϵ��*****" << endl;
    cout << "*****3��ɾ����ϵ��*****" << endl;
    cout << "*****4��������ϵ��*****" << endl;
    cout << "*****5���޸���ϵ��*****" << endl;
    cout << "*****6�������ϵ��*****" << endl;
    cout << "*****0���˳�ͨѶ¼*****" << endl;
    cout << "***********************" << endl;
}

int main()
{
    //����ͨѶ¼�ṹ�����
    Addressbooks abs;
    //��ʼ��ͨѶ¼��ǰ��Ա
    abs.m_Size = 0;
    int select = 0;//
    
    while(1){
        showMenu();//�˵�����
        cin >> select;
        switch (select)
        {
            case 1: //1�������ϵ��
                addPerson(&abs);//���õ�ַ���ݣ������޸�ʵ��
                break;
            case 2: //2����ʾ��ϵ��
                showPerson(&abs);
                break;
            case 3: //3��ɾ����ϵ��
                deletePerson(&abs);
                // {
                //     cout << "������ɾ����ϵ��������" << endl;
                //     string name;
                //     cin >> name;
                    
                //     if(isExist(&abs,name) == -1)
                //     {
                //         cout << "���޴���" << endl;
                //     }
                //     else
                //     {
                //         cout << "�ҵ�����" << endl;
                //     }
                //     break;
                // }
                break;
            case 4: //4��������ϵ��
                findPerson(&abs);
                break;
            case 5: //5���޸���ϵ��
                modifyPerson(&abs);
                break;
            case 6: //6�������ϵ��
                cleanPerson(&abs);
                break;
            case 0: //0���˳�ͨѶ¼
                    cout  << "��ӭ�´�ʹ��" << endl;
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