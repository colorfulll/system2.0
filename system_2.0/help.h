#ifndef HELP_H_INCLUDED
#define HELP_H_INCLUDED
#include <string>
using namespace std;
//HelpItem储存普通物品信息
class HelpItem
{
    private:
        string itemName;
        string ownerName;

    public:
        int leftNum;
        HelpItem(){};
        HelpItem(string item, string owner, int num);
        bool compareTwo(string item, string owner);//既比较物品又比较主人；
        bool compareOne(string item);//只比较物品；
        void show();
        void itemStore();//将一条信息写入file；
        void itemRead();//将file中的信息读入；
        HelpItem &operator=(const HelpItem &item);//"="运算符重载；
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
        bool compareThree(string item, string owner,string );//既比较物品又比较主人；
        bool compareOne(string item);//只比较物品；
        void show();
        void foodStore();//将一条信息写入file；
        void foodRead();//将file中的信息读入；
        HelpFood &operator=(const HelpFood &item);//"="运算符重载；
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
        bool compareThree(string item, string owner, string publish);//既比较物品又比较主人；
        bool compareOne(string item);//只比较物品；
        void show();
        void BookStore();//将一条信息写入file；
        void BookRead();//将file中的信息读入；
        HelpBook &operator=(const HelpBook &item);//"="运算符重载；
        ~HelpBook(){};
};

//将所有普通物品信息存为一个表
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
        void listRead();//将原文件中的信息读入；
        void listStore();//将一个表的信息全部写入file；
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
        void listRead();//将原文件中的信息读入；
        void listStore();//将一个表的信息全部写入file；
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
        void listRead();//将原文件中的信息读入；
        void listStore();//将一个表的信息全部写入file；
        ~BookList();
};

class User//用户类
{
    private://private中主要是用户信息
        string address;
        string phoneNumber;
        string userName;
        string password;

    public:
        User(){};
        User(string location, string phone, string user, string theCode);
        bool login(string user, string code);//用户登录
        bool compareUser(string username);
        bool findUser(string theName, string theCode);
        void userRead();
        void userStore();
        ~User(){};
};

class UserList//用户列表
{
    private:
        User *userList;
        int numofUser;

    public:
        UserList();
        bool userLogin(string username, string userpassword);//用户登录函数
        bool userRegister(string address, string phonenum, string username, string password);//用户注册函数
        void listRead();//将文件中信息读入表中
        void listStore();//储存表中信息
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
        void permitRegister();//同意新用户注册
        void managerRead();//读取管理员信息
        void managerStore();//管理员信息存储
        ~manager(){};
};

class ManagerList//管理员列表类
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
