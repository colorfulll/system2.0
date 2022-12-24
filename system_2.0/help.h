#ifndef HELP_H_INCLUDED
#define HELP_H_INCLUDED
#include <string>
using namespace std;
//HelpItem������ͨ��Ʒ��Ϣ
class HelpItem
{
    private:
        string itemName;
        string ownerName;

    public:
        int leftNum;
        HelpItem(){};
        HelpItem(string item, string owner, int num);
        bool compareTwo(string item, string owner);//�ȱȽ���Ʒ�ֱȽ����ˣ�
        bool compareOne(string item);//ֻ�Ƚ���Ʒ��
        void show();
        void itemStore();//��һ����Ϣд��file��
        void itemRead();//��file�е���Ϣ���룻
        HelpItem &operator=(const HelpItem &item);//"="��������أ�
        ~HelpItem(){};
};

class HelpFood
{
    private:
        string foodName;
        string ownerName;
        string exp;

    public:
        int leftNum;
        HelpFood(){};
        HelpFood(string item, string owner, int num, string exp1);
        bool compareThree(string item, string owner,string );//�ȱȽ���Ʒ�ֱȽ����ˣ�
        bool compareOne(string item);//ֻ�Ƚ���Ʒ��
        void show();
        void foodStore();//��һ����Ϣд��file��
        void foodRead();//��file�е���Ϣ���룻
        HelpFood &operator=(const HelpFood &item);//"="��������أ�
        ~HelpFood(){};
};

class HelpBook
{
    private:
        string bookName;
        string ownerName;
        string author;
        string publisher;

    public:
        int leftNum;
        HelpBook(){};
        HelpBook(string item, string owner, int num, string theAuthor, string publish);
        bool compareThree(string item, string owner, string publish);//�ȱȽ���Ʒ�ֱȽ����ˣ�
        bool compareOne(string item);//ֻ�Ƚ���Ʒ��
        void show();
        void BookStore();//��һ����Ϣд��file��
        void BookRead();//��file�е���Ϣ���룻
        HelpBook &operator=(const HelpBook &item);//"="��������أ�
        ~HelpBook(){};
};

//��������ͨ��Ʒ��Ϣ��Ϊһ����
class HelpList
{
    private:
        HelpItem *infoList;
        int numofItem;

    public:
        HelpList();
        bool addItem(string item, string owner, int addNum);
        bool deleteItem(string item, string owner, int deleteNum);
        void presentList();
        void findItem(string item);
        void listRead();//��ԭ�ļ��е���Ϣ���룻
        void listStore();//��һ�������Ϣȫ��д��file��
        ~HelpList();
};

class FoodList
{
    private:
        HelpFood *infoList;
        int numofFood;

    public:
        FoodList();
        bool addItem(string item, string owner, int addNum, string exp1);
        bool deleteItem(string item, string owner, int deleteNum, string exp1);
        void presentList();
        void findItem(string item);
        void listRead();//��ԭ�ļ��е���Ϣ���룻
        void listStore();//��һ�������Ϣȫ��д��file��
        ~FoodList();
};

class BookList
{
    private:
        HelpBook *infoList;
        int numofBook;

    public:
        BookList();
        bool addItem(string item, string owner, int addNum, string theAuthor, string publish);
        bool deleteItem(string item, string owner, int deleteNum, string publish);
        void presentList();
        void findItem(string item);
        void listRead();//��ԭ�ļ��е���Ϣ���룻
        void listStore();//��һ�������Ϣȫ��д��file��
        ~BookList();
};

class User//�û���
{
    private://private����Ҫ���û���Ϣ
        string address;
        string phoneNumber;
        string userName;
        string password;

    public:
        User(){};
        User(string location, string phone, string user, string theCode);
        bool login(string user, string code);//�û���¼
        bool compareUser(string username);
        bool findUser(string theName, string theCode);
        void userRead();
        void userStore();
        ~User(){};
};

class UserList//�û��б�
{
    private:
        User *userList;
        int numofUser;

    public:
        UserList();
        bool userLogin(string username, string userpassword);//�û���¼����
        bool userRegister(string address, string phonenum, string username, string password);//�û�ע�ắ��
        void listRead();//���ļ�����Ϣ�������
        void listStore();//���������Ϣ
        ~UserList();
};

class manager
{
    private:
        string userName;
        string password;

    public:
        manager(){};
        manager(string managerName, string myCode);
        bool managerLogin(string user, string code);
        bool compareManager(string username);
        void permitRegister();//ͬ�����û�ע��
        void managerRead();//��ȡ����Ա��Ϣ
        void managerStore();//����Ա��Ϣ�洢
        ~manager(){};
};

class ManagerList//����Ա�б���
{
    private:
        manager *managerList;
        int numofManager;

    public:
        ManagerList();
        bool managerLogin(string username, string userpassword);
        void listRead();
        void listStore();
        ~ManagerList();
};

#endif // HELP_H_INCLUDED
