#include "help.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include "main.h"
using namespace std;

int itemCounter = 0;//��¼����itemFile��λ��
int ownerCounter = 0;//��¼����ownerFile��λ��
int numCounter = 0;//��¼����numFile��λ��
int addressCounter = 0;//��¼����addressFile��λ��
int phoneCounter = 0;//��¼����phoneFile��λ��
int userNameCounter = 0;//��¼����userFile��λ��
int passwordCounter = 0;//��¼����passwordFile��λ��
int managerNameCounter = 0;
int managerCodeCounter = 0;
int foodNameCounter = 0;
int foodOwnerCounter = 0;
int foodExpCounter = 0;
int foodNumCounter = 0;
int bookNameCounter = 0;
int bookOwnerCounter = 0;
int bookNumCounter = 0;
int bookAuthorCounter = 0;
int bookPublisherCounter = 0;

ofstream outItem;
ofstream outOwner;
ofstream outNum;
ofstream outSummary;
ofstream outAddress;
ofstream outPhone;
ofstream outUserName;
ofstream outPassword;
ofstream outUserNum;
ofstream outmanagerName;
ofstream outmanagerCode;
ofstream outspareUser;
ofstream outspareNum;
ofstream outsparePassword;
ofstream outsparePhone;
ofstream outspareAddress;
ofstream outExp;
ofstream outAuthor;
ofstream outPublisher;


ifstream inItem;
ifstream inOwner;
ifstream inNum;
ifstream inSummary;
ifstream inAddress;
ifstream inPhone;
ifstream inUserName;
ifstream inPassword;
ifstream inUserNum;
ifstream inspareUser;
ifstream inspareNum;
ifstream insparePassword;
ifstream insparePhone;
ifstream inspareAddress;

fstream spareUser;
fstream sparePassword;
fstream sparePhone;
fstream spareAddress;

extern string mycopy;
//���ļ��ж��ַ���
string readFileIntoString(const char * filename, int &counter)
{
ifstream ifile(filename);
//���ļ����뵽ostringstream����buf��
ostringstream buf;
char ch;
ifile.seekg(counter);
while(buf&&ifile.get(ch)&&(ch!=' '))
{
    buf.put(ch);
    counter++;
}
counter++;
//������������buf�������ַ���
return buf.str();
}

//��һ����Ʒ���г�ʼ��
HelpItem::HelpItem(string item, string owner, int num)
{
    itemName = item;
    ownerName = owner;
    leftNum = num;
}

//�Ƚ�����Ʒ�Ƿ���ͬ����Ʒ���Ƿ�����ͬһ���ˣ�
bool HelpItem::compareTwo(string item, string owner)
{
    if ((item.compare(this->itemName) || owner.compare(this->ownerName)) == 0) return true;
    else return false;
}

//�Ƚ�����Ʒ�Ƿ���ͬһ����Ʒ
bool HelpItem::compareOne(string item)
{
    if (item.compare(this->itemName) == 0) return true;
    else return false;
}

//��ʾһ����Ʒ����Ϣ
void HelpItem::show()
{
   cout << "itemname:" << this -> itemName << "     �����ˣ�"
    << this -> ownerName << "      ������" << this ->leftNum << endl ;
}

//"="���������
HelpItem &HelpItem::operator=(const HelpItem &item)
{
    itemName = item.itemName;
    ownerName = item.ownerName;
    leftNum = item.leftNum;
    return *this;
}

//��һ����Ʒ����Ϣ������ļ���
void HelpItem::itemStore()
{
    outItem<< this->itemName << " " ;
    outOwner<< this->ownerName << " " ;
    outNum<< this->leftNum << " " ;
}

void HelpItem::itemRead()
{
    char ch;
    this->itemName = readFileIntoString("itemFile", itemCounter);
    this->ownerName = readFileIntoString("ownerFile", ownerCounter);
    inNum.open("numFile");
    inNum.seekg(numCounter);
    inNum.get(ch);
    this->leftNum = ch-'0';
    numCounter+=2;
    inNum.close();
}



//��ʼ����Ʒ�б�
HelpList::HelpList()
{
    HelpItem *tmp = new HelpItem [100];
    infoList = tmp;
    listRead();
}

//�����Ʒ, ����б���������false
bool HelpList::addItem(string item, string owner, int addNum)
{
    if (numofItem == 100) return false;
    else
    {
        HelpItem *tmp = new HelpItem(item, owner, addNum);
        infoList[numofItem]= *tmp;
        numofItem++;
        return true;
    }
}

//ɾ����Ʒ
bool HelpList::deleteItem(string item, string owner, int deleteNum)
{
    int track = -1;
    if (numofItem == 0) return false;
    else
    {
        //�ҵ�Ҫɾ����Ԫ�ص��±�
        for (int i=0; i<numofItem; ++i)
        {
            if (infoList[i].compareTwo(item, owner)) track=i;
        }
          if (track == -1) return false;

        //ɾ�������������ȫ��ɾ���Ͳ���ɾ����
        if (deleteNum == infoList[track].leftNum)
        {
            --numofItem;
            for (int i=track; i<numofItem; ++i) infoList[i] = infoList[i+1];
        }
        else
        {
            infoList[track].leftNum -= deleteNum;
        }
    return true;
    }
}

//������Ʒ
void HelpList::findItem(string item)
{
    int counter = 0;
    for (int i=0; i<numofItem; ++i)
    {
        if (infoList[i].compareOne(item))
        {
            infoList[i].show();
            counter++;
        }
    }
    if (counter == 0) cout << "û�и���Ʒ" << endl ;
}

//��ʾ��Ʒ�б�
void HelpList::presentList()
{
    for (int i=0; i<numofItem; ++i) infoList[i].show();
}

HelpList::~HelpList()
{
    delete [] infoList;
}

//����ʼʱ�����ļ���ʼ���б�
void HelpList::listRead()
{
    char ch;
    inSummary.open("summary");
    ch = inSummary.get();
    this->numofItem = ch-'0';
    for (int i=0; i<this->numofItem; ++i)
    {
        this->infoList[i].itemRead();
    }
    inSummary.close();

}

//��һ�������Ϣ������ļ���
void HelpList::listStore()
{
    outItem.open("itemFile");
    outOwner.open("ownerFile");
    outNum.open("numFile");
    for (int i=0; i<this->numofItem; ++i)
    {
        this->infoList[i].itemStore();
    }
    outSummary.open("summary");
    outSummary << numofItem;
    outItem.close();
    outOwner.close();
    outNum.close();
    outSummary.close();
}

User::User(string location, string phone, string user, string theCode)
{
    address = location;
    phoneNumber = phone;
    userName = user;
    password = theCode;
}

bool User::login(string user, string code)
{
    if ((user.compare(this->userName)||code.compare(this->password))==0)
    return true;
    else return false;
}

bool User::findUser(string theName, string theCode)
{
    if ((theName.compare(this->userName)||theCode.compare(this->password))==0)
    return true;
    else return false;
}

bool User::compareUser(string username)
{
    if (!this->userName.compare(username)) return true;
    else return false;
}

void User::userRead()
{
    this->address = readFileIntoString("addressFile", addressCounter);
    this->phoneNumber = readFileIntoString("phoneFile", phoneCounter);
    this->userName = readFileIntoString("userNameFile", userNameCounter);
    this->password = readFileIntoString("passwordFile", passwordCounter);
}

void User::userStore()
{
    outAddress<< this->address << " " ;
    outPhone<< this->phoneNumber << " " ;
    outUserName<< this->userName << " " ;
    outPassword<< this->password << " " ;
}

UserList::UserList()
{
    User *tmp = new User [100];
    userList = tmp;
    listRead();
}

bool UserList::userLogin(string username, string userpassword)
{
    for (int i=0; i<numofUser; ++i)
    {
        if (userList[i].login(username, userpassword)) return true;
    }
    return false;
}

bool UserList::userRegister(string address, string phonenum, string username, string password)
{
    int x;
    if (numofUser == 100) return false;
    for (int i=0; i<numofUser; ++i)
    {
         if (userList[i].compareUser(username)) return false;
    }
    spareUser.open("spareUserFile");
    sparePassword.open("sparePassFile");
    spareAddress.open("spareAddressFile");
    sparePhone.open("sparePhoneFile");
    char ch;
    inspareNum.open("spareNumFile");
    ch = inspareNum.get();
    x =ch-'0'+1;
    inspareNum.close();
    outspareNum.open("spareNumFile");
    outspareNum << x;
    outspareNum.close();
    spareUser << username << " ";
    sparePassword << password << " ";
    sparePhone << phonenum << " ";
    spareAddress << address << " ";
    spareUser.close();
    sparePhone.close();
    spareAddress.close();
    sparePassword.close();
    return true;
}

void UserList::listRead()
{
    char ch;
    inUserNum.open("UserNum");
    ch = inUserNum.get();
    this->numofUser = ch-'0';
    for (int i=0; i<this->numofUser; ++i)
    {
        this->userList[i].userRead();
    }
    inUserNum.close();
}

void UserList::listStore()
{
    outAddress.open("addressFile");
    outPhone.open("phoneFile");
    outUserName.open("userNameFile");
    outPassword.open("passwordFile");
    for (int i=0; i<this->numofUser; ++i)
    {
        this->userList[i].userStore();
    }
    outUserNum.open("UserNum");
    outUserNum << numofUser;
    outAddress.close();
    outPhone.close();
    outUserName.close();
    outPassword.close();
    outUserNum.close();
}

UserList::~UserList()
{
    delete [] userList;
}

manager::manager(string managerName, string myCode)
{
    userName = managerName;
    password = myCode;
}

bool  manager::managerLogin(string user, string code)
{
    if ((user.compare(this->userName)||code.compare(this->password))==0)
    return true;
    else return false;
}

bool manager::compareManager(string username)
{
    if (!this->userName.compare(username)) return true;
    else return false;
}
void manager::managerRead()
{
    this->userName = readFileIntoString("managerNameFile", managerNameCounter);
    this->password = readFileIntoString("managerCodeFile", managerCodeCounter);
}

void manager::managerStore()
{
    outmanagerName<< this->userName << " " ;
    outmanagerCode<< this->password << " " ;
}

void manager::permitRegister()
{
    int counter_in_Register, counter_user = 0, counter_password = 0, counter_address = 0, counter_phone = 0, agreement, open;
    char ch1,ch2;
    string transUser, transPassword, transAddress, transPhone;
    inspareNum.open("spareNumFile");
    ch1 = inspareNum.get();
    counter_in_Register = ch1-'0';
    cout << "���û�ע�����룺" << endl;
    for (int i=0; i<counter_in_Register; ++i)
    {
        transUser = readFileIntoString("spareUserFile", counter_user);
        transPassword = readFileIntoString("sparePassFile", counter_password);
        transAddress = readFileIntoString("spareAddressFile", counter_address);
        transPhone = readFileIntoString("sparePhoneFile", counter_phone);
        cout << "��" << (i+1) << "�����û���Ϣ��" << endl;
        cout << "�û�����" << transUser << " " << "���룺" << transPassword << " " << "�ֻ��ţ�" << transPhone << " " << "��ַ��" << transAddress;
        cout << endl << "��ͬ������������1�����ܾ�����������0" <<endl;
        cin >> agreement ;
        if (agreement)
        {
            spareUser.open("userNameFile", ios::app);
            sparePassword.open("passwordFile", ios::app);
            sparePhone.open("phoneFile", ios::app);
            spareAddress.open("addressFile", ios::app);
            inUserNum.open("UserNum");
            ch2 = inUserNum.get();
            open = ch2-'0'+1;
            inUserNum.close();
            outUserNum.open("UserNum");
            outUserNum << open;
            outUserNum.close();
            spareUser << transUser << " ";
            sparePassword << transPassword << " ";
            spareAddress << transAddress << " ";
            sparePhone << transPhone << " ";
            spareUser.close();
            sparePassword.close();
            sparePhone.close();
            spareAddress.close();
        }
    }
    outUserName.open("spareUserFile");
    outPassword.open("sparePassFile");
    outAddress.open("spareAddressFile");
    outPhone.open("sparePhoneFile");
    outNum.open("spareNumFile");
    outNum << '0' ;
    outUserName.close();
    outPassword.close();
    outAddress.close();
    outPhone.close();
    outNum.close();
}

ManagerList::ManagerList()
{
    manager *tmp = new manager [100];
    managerList = tmp;
    listRead();
}

bool ManagerList::managerLogin(string username, string userpassword)
{
     for (int i=0; i<numofManager; ++i)
    {
        if (managerList[i].managerLogin(username, userpassword))
        {
            cout << "��½�ɹ�" <<endl;
            managerList[i].permitRegister();
            return true;
        }
    }
    return false;
}

void ManagerList::listRead()
{
    char ch;
    inUserNum.open("managerNumFile");
    ch = inUserNum.get();
    this->numofManager = ch-'0';
    for (int i=0; i<(this->numofManager); ++i)
    {
        this->managerList[i].managerRead();
    }
    inUserNum.close();
}

void ManagerList::listStore()
{
    outUserName.open("managerNameFile");
    outPassword.open("managerCodeFile");
    for (int i=0; i<this->numofManager; ++i)
    {
        this->managerList[i].managerStore();
    }
    outUserNum.open("managerNumFile");
    outUserNum << numofManager;
    outAddress.close();
    outPhone.close();
    outUserName.close();
    outPassword.close();
    outUserNum.close();
}

ManagerList::~ManagerList()
{
    delete [] managerList;
}

HelpFood::HelpFood(string item, string owner, int num, string exp1)
{
    foodName = item;
    ownerName = owner;
    leftNum = num;
    exp = exp1;
}

bool HelpFood::compareThree(string item, string owner, string exp1)
{
    if ((item.compare(this->foodName) || owner.compare(this->ownerName)||exp1.compare(this->exp)) == 0) return true;
    else return false;
}

bool HelpFood::compareOne(string item)
{
    if (item.compare(this->foodName) == 0) return true;
    else return false;
}

void HelpFood::show()
{
    cout << "foodname:" << this -> foodName << "     �����ˣ�"
    << this -> ownerName << "      ������" << this ->leftNum << "      �����ڣ�" << this->exp << endl ;
}
//��һ����Ʒ����Ϣ������ļ���
void HelpFood::foodStore()
{
    outItem<< this->foodName << " " ;
    outOwner<< this->ownerName << " " ;
    outNum<< this->leftNum << " " ;
    outExp<< this->exp << " ";
}

void HelpFood::foodRead()
{
    char ch;
    this->foodName = readFileIntoString("foodNameFile", foodNameCounter);
    this->ownerName = readFileIntoString("foodOwnerFile", foodOwnerCounter);
    this->exp = readFileIntoString("foodExpFile", foodExpCounter);
    inNum.open("foodNumFile");
    inNum.seekg(foodNumCounter);
    inNum.get(ch);
    this->leftNum = ch-'0';
    foodNumCounter+=2;
    inNum.close();
}

HelpFood &HelpFood::operator=(const HelpFood &item)
{
    foodName = item.foodName;
    ownerName = item.ownerName;
    leftNum = item.leftNum;
    exp = item.exp;
    return *this;
}

FoodList::FoodList()
{
    HelpFood *tmp = new HelpFood [100];
    infoList = tmp;
    listRead();
}

bool FoodList::addItem(string item, string owner, int addNum, string exp1)
{
    if (numofFood == 100) return false;
    else
    {
        HelpFood *tmp = new HelpFood(item, owner, addNum, exp1);
        infoList[numofFood]= *tmp;
        numofFood++;
        return true;
    }
}

bool FoodList::deleteItem(string item, string owner, int deleteNum, string exp1)
{
        int track = -1;
    if (numofFood == 0) return false;
    else
    {
        //�ҵ�Ҫɾ����Ԫ�ص��±�
        for (int i=0; i<numofFood; ++i)
        {
            if (infoList[i].compareThree(item, owner, exp1)) track=i;
        }
          if (track == -1) return false;

        //ɾ�������������ȫ��ɾ���Ͳ���ɾ����
        if (deleteNum == infoList[track].leftNum)
        {
            --numofFood;
            for (int i=track; i<numofFood; ++i) infoList[i] = infoList[i+1];
        }
        else
        {
            infoList[track].leftNum -= deleteNum;
        }
    return true;
    }
}

void FoodList::presentList()
{
    for (int i=0; i<numofFood; ++i) infoList[i].show();
}

void FoodList::findItem(string item)
{
    int counter = 0;
    for (int i=0; i<numofFood; ++i)
    {
        if (infoList[i].compareOne(item))
        {
            infoList[i].show();
            counter++;
        }
    }
    if (counter == 0) cout << "û�и���Ʒ" << endl ;
}

void FoodList::listRead()
{
    char ch;
    inSummary.open("foodSummary");
    ch = inSummary.get();
    this->numofFood = ch-'0';
    for (int i=0; i<this->numofFood; ++i)
    {
        this->infoList[i].foodRead();
    }
    inSummary.close();
}

void FoodList::listStore()
{
    outItem.open("foodNameFile");
    outOwner.open("foodOwnerFile");
    outNum.open("foodNumFile");
    outExp.open("foodExpFile");
    for (int i=0; i<this->numofFood; ++i)
    {
        this->infoList[i].foodStore();
    }
    outSummary.open("foodSummary");
    outSummary << numofFood;
    outItem.close();
    outOwner.close();
    outNum.close();
    outExp.close();
    outSummary.close();
}

FoodList::~FoodList()
{
    delete [] infoList;
}

HelpBook::HelpBook(string item, string owner, int num, string theAuthor, string publish)
{
    bookName = item;
    ownerName = owner;
    leftNum = num;
    author = theAuthor;
    publisher = publish;
}

bool HelpBook::compareThree(string item, string owner, string publish)
{
    if ((item.compare(this->bookName) || owner.compare(this->ownerName)||publish.compare(this->publisher)) == 0) return true;
    else return false;
}

bool HelpBook::compareOne(string item)
{
    if (item.compare(this->bookName) == 0) return true;
    else return false;
}

void HelpBook::show()
{
    cout << "bookname:" << this -> bookName << "     �����ˣ�"
    << this -> ownerName << "      ������" << this ->leftNum << "      ���ߣ�"
    << this->author << "    �����磺"<< this->publisher << endl ;
}
//��һ����Ʒ����Ϣ������ļ���
void HelpBook::BookStore()
{
    outItem<< this->bookName << " " ;
    outOwner<< this->ownerName << " " ;
    outNum<< this->leftNum << " " ;
    outAuthor<< this->author << " ";
    outPublisher<< this->publisher << " ";
}

void HelpBook::BookRead()
{
    char ch;
    this->bookName = readFileIntoString("bookNameFile", bookNameCounter);
    this->ownerName = readFileIntoString("foodOwnerFile", bookOwnerCounter);
    this->author = readFileIntoString("bookAuthorFile", bookAuthorCounter);
    this->publisher = readFileIntoString("bookPublisherFile", bookPublisherCounter);
    inNum.open("bookNumFile");
    inNum.seekg(bookNumCounter);
    inNum.get(ch);
    this->leftNum = ch-'0';
    bookNumCounter+=2;
    inNum.close();
}

HelpBook &HelpBook::operator=(const HelpBook &item)
{
    bookName = item.bookName;
    ownerName = item.ownerName;
    leftNum = item.leftNum;
    author = item.author;
    publisher = item.publisher;
    return *this;
}

BookList::BookList()
{
    HelpBook *tmp = new HelpBook [100];
    infoList = tmp;
    listRead();
}

bool BookList::addItem(string item, string owner, int addNum, string theAuthor, string publish)
{
    if (numofBook == 100) return false;
    else
    {
        HelpBook *tmp = new HelpBook(item, owner, addNum, theAuthor, publish);
        infoList[numofBook]= *tmp;
        numofBook++;
        return true;
    }
}

bool BookList::deleteItem(string item, string owner, int deleteNum, string publish)
{
        int track = -1;
    if (numofBook == 0) return false;
    else
    {
        //�ҵ�Ҫɾ����Ԫ�ص��±�
        for (int i=0; i<numofBook; ++i)
        {
            if (infoList[i].compareThree(item, owner, publish)) track=i;
        }
          if (track == -1) return false;

        //ɾ�������������ȫ��ɾ���Ͳ���ɾ����
        if (deleteNum == infoList[track].leftNum)
        {
            --numofBook;
            for (int i=track; i<numofBook; ++i) infoList[i] = infoList[i+1];
        }
        else
        {
            infoList[track].leftNum -= deleteNum;
        }
    return true;
    }
}

void BookList::presentList()
{
    for (int i=0; i<numofBook; ++i) infoList[i].show();
}

void BookList::findItem(string item)
{
    int counter = 0;
    for (int i=0; i<numofBook; ++i)
    {
        if (infoList[i].compareOne(item))
        {
            infoList[i].show();
            counter++;
        }
    }
    if (counter == 0) cout << "û�и���Ʒ" << endl ;
}

void BookList::listRead()
{
    char ch;
    inSummary.open("bookSummary");
    ch = inSummary.get();
    this->numofBook = ch-'0';
    for (int i=0; i<this->numofBook; ++i)
    {
        this->infoList[i].BookRead();
    }
    inSummary.close();
}

void BookList::listStore()
{
    outItem.open("bookNameFile");
    outOwner.open("bookOwnerFile");
    outNum.open("bookNumFile");
    outAuthor.open("bookAuthorFile");
    outPublisher.open("bookPublisherFile");
    for (int i=0; i<this->numofBook; ++i)
    {
        this->infoList[i].BookStore();
    }
    outSummary.open("bookSummary");
    outSummary << numofBook;
    outItem.close();
    outOwner.close();
    outNum.close();
    outAuthor.close();
    outPublisher.close();
    outSummary.close();
}

BookList::~BookList()
{
    delete [] infoList;
}

void blockshow1()
{
    SimpleWindow win(300,200,"write name!");
    Fl::run();
    return;
}

void blockshow2()
{
    SimpleWindow win(300,200,"write password!");
    Fl::run();
    return;
}

void blockshow3()
{
    SimpleWindow win(300,200,"write address!");
    Fl::run();
    return;
}

void blockshow4()
{
    SimpleWindow win(300,200,"write phonenum!");
    Fl::run();
    return;
}

void blockshow5()
{
    SimpleWindow win(300,200,"write the item!");
    Fl::run();
    return;
}

void blockshow6()
{
    SimpleWindow win(300,200,"write exp!");
    Fl::run();
    return;
}

void blockshow7()
{
    SimpleWindow win(300,200,"write author!");
    Fl::run();
    return;
}

void blockshow8()
{
    SimpleWindow win(300,200,"write publisher!");
    Fl::run();
    return;
}

SimpleWindow::SimpleWindow(int w, int h, const char* title):Fl_Window(w,h,title)
{
    begin();
    copy = new Fl_Button( 50, 150, 70, 30, "end");
    copy->callback( cb_copy, this );
    inp = new Fl_Input(50, 50, 140, 30, "Input:");
    end();
    resizable(this);
    show();
}

void SimpleWindow::cb_copy(Fl_Widget* o, void* v)
{
    ( (SimpleWindow*)v )->cb_copy_i();
}


void SimpleWindow::cb_copy_i()
{
   mycopy = inp->value();
   hide();
}



