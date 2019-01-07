#include <iostream>
#include <stdio.h>
//#include "point.h"
#include <vector>
#include <iterator>
#include <windows.h>
#include <algorithm>
#include <bits/stl_algo.h>
#include <string>
#include <stdexcept>
#include <time.h>
#include <deque>
//#include <stl_algo.h>
#include <bits/stl_algo.h>
//#include <stl_algobase.h>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <functional>
#include <ctime>
#include <numeric>
#include <conio.h>

void test01();
void test02();
void test03();
void test04();
void test05();
void test06();
void test10();

void test09();
void test11();
void test12();
void test13();
void test14();

void file_test01();
int MyDevice(int a,int b);
void Myprint(int v);
/*类型转换的意义：
  1.数据类型的传递；
  2.高级语言，低级语言之间的转变
*/
//静态转化 基础类型: 具有继承关系的父子类指针或引用的转换


using namespace std;
class Base{};
class Child :public Base{};
class Otherr{};

class Person
{
public:
     Person(string name,int age)
     {
         this->M_Name = name;
         this->M_Age = age;
     }
     bool operator == (const Person&p)
     {
         if((this->M_Name == p.M_Name)&&(this->M_Age == p.M_Age))
         {
             return true;
         }
         else
         {
             return false;
         }

     }
    string M_Name;
    int  M_Age;
};






void test01()
{
    char a = 'a';
    double d = static_cast<double>(a);
    std::cout<<"d="<<d<<std::endl;
    std::cout<<"a="<<a<<std::endl;
}

//父子之间的转换
void test02()
{
    Base *base = NULL;
    Child *child = NULL;
    
    //把base 转换为Child*类型，向下  不安全
    Child *child2 = static_cast<Child*>(base);
   // 把child 转换为Base 类型，向上  安全
    Base *base2 = static_cast<Base*>(child);
    printf("test02\r\n");

}
//继承关系引用转换
void test04()
{
   Base base;
   Child child;
   Base & base3  = static_cast<Base&>(child);  //子类引用转换成父类引用 安全
   Child & child3 =static_cast <Child &>(base);
}

//不能进行无继承关系的指针或者引用转换


//动态转换
/*
动态转换，会对转换的数据进行类型检查，不支持基础数据类型见的转换，不支持无继承关系两个类型之间的指针
或者引用转换
*/
void test03()
{
    char c= 'a';
  //  double d = dynamic_cast<double>(c);
  //  std::cout<<"d1="<<d<<std::endl;
}

//常量转换
void test05()
{
    const int * p = NULL;
    //取出const
    int * newp  = const_cast< int *>(p);
    
    int *p2 = NULL;
    const int *newP2 = const_cast<const int *>(p2);
/*不能对非指针 或 非引用的变量进行转换*/
//引用
    int num =10;
    int &num1 = num;

    const int  &num2 = static_cast<const int &>(num1);
    
    std::cout<<num2<<std::endl;

}
/*重新解释转换 reinterpret_cast*/
void test06()
{
    //最不安全
    int a =10;
    int *p = reinterpret_cast<int *>(a);
}

/**/
int MyDevice(int a,int b)
{
   if(b==0)
   {
       throw 1;
   }
}





//如果dynamic_cast 发生了多态，可以让基类转换为派生类，向下转换



/*STL 的学习使用
容器：各种数据结构：序列式容器  关联式容器
算法：各种常用的算法：质变算法 非质变算法
迭代器 容器和算法间的粘合剂：输入迭代器 输出迭代器 前向迭代器  双向迭代器   随机访问迭代器
仿函数
适配器
空间适配器
六大组件的交互关系
高可重用性
高移植性能
*/

//遍历功能  普通指针也是一种迭代器
void Myprint(int v)
{
    cout<<v<<endl;
}



void test09()
{
    /*遍历容器中的数据*/
    std::vector<int> v;  //声明一个容器，用来存储数据类型是整型，对象是V;
    //向容器中加入数据
     v.push_back(10);
     v.push_back(20);
     v.push_back(30);
     v.push_back(40);


    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd  = v.end();
    while(itBegin !=itEnd)
    {
        cout<<*itBegin<<endl;
        itBegin++;
    }

    /*第二种遍历方式*/
    for(vector<int>::iterator it = v.begin();it !=v.end();it++)
    {
        cout<< *it<<endl;
    }
   
   Myprint(9);
   /*第三种遍历方式*/
 // for_each(v.begin,v.end,Myprint);

}


/*操作自定义数据类型*/
void test10()
{
    vector<Person> v;
    Person p1("xiao",20);
    Person p2("DA",25);
    Person p3("DUO",30);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    for(vector<Person>::iterator it = v.begin();it!=v.end();it++)
    {
      //  cout<<"name:"<<(*it).M_Name<<";"<<"age:"<<(*it).M_Age<<endl;
      cout<<"name:"<<(*it).M_Name<<";"<<"age:"<<it->M_Age<<endl;
    }
}
/*容器嵌套容器*/
void test11()
{
    vector<vector<int>> v;
    vector<vector<int>>::iterator it;
    vector<int>::iterator vit;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    for(int i =0;i<5;i++)
    {
        v1.push_back(i);
        v2.push_back(i+10);
        v3.push_back(i+100);
    }

    //小容器放入大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    //遍历所有数据
  
    for(it = v.begin();it != v.end();it++)
    {
        for(vit = (*it).begin();vit !=(*it).end();vit++)
        {
            cout<< *vit <<" ";
        }
            cout<<endl;
    }
}

/*三大组件
1.容器
2.算法
3.迭代器： 每个容器都有自己专属的迭代器
v.begin();指向第一个数据；
v.end();指向最后一个数据的下一个地址
常用容器：
string 
构造函数
赋值操作
string 容器操作API
字符操作
拼接操作
查找和替换
*/

void test12()
{
    string str ="hello"; //默认构造
    string str2(str); //拷贝构造
    string str3 = str;

    string str4 = "abcd";
    string str5(10,'a');


    str3.assign("abcdew",5);
    
    string str6;
    str6.assign(str,1,3);

    cout<<str6<<endl;

}

void test13()
{
    string s = "nihaoa";
    for(int i =0;i<s.size();i++)
    {
       // cout<<s[i]<<endl;
       cout<<s.at(i)<<endl;
    }
    //[] 和at 的区别，访问越界  aT 会抛出异常

    try 
    {
        cout<<s[100]<<endl;
    }
    catch(out_of_range &e)
    {
        cout<<e.what()<<endl;
    }
    catch(...)
    {
        cout<<"越界异常"<<endl;
    }
}

void test14()
{
    /*字符拼接*/
    string str1 = "I ";
    string str2 = "love you";

    str1 +=str2;
    str1.append(" ");
    str1.append("ru");
    cout<< str1<<endl;
    //查找和替换

    string str3 = "abcdfder";
   // int pos  =  str3.find("bc");
   // cout<<pos<<endl;

    //替换
    string str4 = "HELLO";
    //str4.replace(1,3,111);
    cout<<str4<<endl;

    //比较操作
    string s1 = "abc";
    string s2 = "abc";
    if(s1.compare(s2) == 0 )
    {
        cout<<"s1 == s2" <<endl;
    }
    else if(s1.compare(s2)==1)
    {
        cout<<"s1 != s2 "<<endl;
    }
    //string 子串
    string email = "xiaobang@qq.com";
    int pos = email.find("@");

    cout<<"pos = "<<pos<<endl;
    string usrName = email.substr(0,pos);
    cout<<usrName<<endl;

//插入和删除



}

void test15()
{
    string s1 = "hello";
    s1.insert(1,"111");
    cout<<s1<<endl;

    //删除
    s1.erase(1,3);
    cout<<s1<<endl;

    //string 和C-STYLE 转换
}

void func(string s)
{
    cout<<s<<endl;
}

void func2(const char *s)
{
    cout<<s<<endl;
}

void test16()
{
    string s= "abc";
    const char * p = s.c_str();
    func(s);
    //string s2(p);

}

void test17()
{
    string s = "abcdef";
    char &a = s[2];
    char &b = s[3];

    //cout<< &a<<endl;
    cout<<(int *)s.c_str()<<endl;
    

}


/*写一个函数将函数内部的string 字符串*/
void test18()
{
    string s= "abcdEfg";
    for(int i=0;i<s.size();i++)
    {
       // s[i] = toupper(s[i]);   //全变大写
       s[i] = tolower(s[i]);
    }
    cout<<s<<endl;

}


/*vector 容器的使用*
  vector 迭代器 提供的是随机访问迭代器
  动态增加大小，并不是原空间之后续接新
  vector 数据结构
**/

void test19()
{
    vector<int> v;
    for(int i= 0;i<10;i++)
    {
        v.push_back(i);
        cout<<v.capacity()<<endl;  //容器的容量

    }

}
void printVector(vector<int>&v)
{
        vector<int>::iterator it = v.begin();
        for(it;it!=v.end();it++)
        {
            cout<< *it<<" ";
            cout<<endl;
        }
}

void test20()
{
    vector<int> v;
    int arr[] = {2,3,4,5};
    vector<int> v1(arr,arr+sizeof(arr)/sizeof(int));

    vector<int> v2(v1.begin(),v1.end());
 //   printVector(v2);

    //拷贝n个 数赋予自身
    vector<int>v3(10,100);
  //  printVector(v3);
    //赋值使用
    vector<int> v4;
    v4.assign(v3.begin(),v3.end());
    //printVector(v4);
    v4.swap(v2);
  //  printVector(v4);
    //容器元素的个数 size   容器是否为空empty()  resize;
    v4.resize(10,44);
    printVector(v4);
    //巧用swap用来使用压缩空间
}

void test21()
{
    vector<int> v;
    v.reserve(1000000);

}

/*初始化匿名对象*/
void test22()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    cout<<"output is:"<<v.front()<<endl;
    cout<<"output is:"<<v.back()<<endl;
    v.insert(v.begin(),100);
    printVector(v);
    v.pop_back();
    /*插入删除*/
    printVector(v);
    v.erase(v.begin());
    printVector(v);
    
    printVector(v);
}

/*逆序遍历*/
void test23()
{
    vector<int> v;
   vector<int>::iterator it;
    for(int i =0;i<10;i++)
    {
        v.push_back(i);
    }
    for(it = v.begin();it !=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}


/*deque 容器*/
//vector 是一种单向开口的内存空间，  deque 是一种双向开口的线性空间
//中控器  缓冲区

void printDeque(deque<int>&a)
{
  deque<int>::iterator it;
  for(it= a.begin();it!=a.end();it++)
  {
      cout<<*it<<" ";
  }
    cout<<endl;
}





void test24()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);  

    //printDeque(d);
    deque<int> d2(d.begin(),d.end());
    d2.push_back(20000);
    //printDeque(d2);
    d.swap(d2);
    printDeque(d);
}

// iterator  普通迭代器   reverse_iterator 逆序迭代器  const_iterator 只读迭代器


/*
要求：5名选手，ABCDE 有10个评委对他们进行打分，去掉最高分，去掉最低分，求平均值，删选出来成绩最好的人
1.创建5名选手，放在VEctor 中
2.把10个人的评分存在deque 容器中；
3.把十个人的评分进行排序；
4.进行平均分计算，求出最大值的选手；


*/

//创建选手
void createPerson(vector<Person> &v)
{
    string nameseed = "ABCDE";
    for(int i =0;i<5;i++)
    {
        string name = "member";
        name+=nameseed[i];
        int score = 0;
        Person p(name,score);
        v.push_back(p);
    }

}

//打分
void SetScore(vector<Person>&v)
{
    //  vector<Person>::iterator it;
    //  for(it =v.begin();it!=v.end();it++)
    // {
    //  //为选手打分
    //  deque<int> d;
    //  for(int i= 0;i<10;i++)
    //  {
    //      int score = rand()%41+60;
    //      d.push_back(score);
    //  }
    //  //排序
    //  sort(v.begin(),v.end());

    // //去除最高最低分
    // d.pop_back();
    // d.pop_front();
    // int sum =0;
    // for(deque<it>::iterator dit = v.begin();dit!=v.end();dit++)
    // {
    //     sum+= *dit;
    // }
    // //平均分
    // int avg = sum/d.size();
    // it->M_Age = avg;




  //  }

}

void ShowScore(vector<Person>&v)
{
//   for(vector<Person>::it = v.begin();it!= v.end();it++)
//   {
//       cout<<"Name: "<< it->M_Name<<"最终得分"<<it->M_Age<<endl;
//   }

}

void test25()
{
    //创建容器  存放选手
     vector<Person> v;
    // 创建5名选手
    createPerson(v);

    //打分
    SetScore(v);
    //显示分数
  //  ShowScore(v);
    //测试
    // for(vector<Person>::iterator it = v.begin();it!=v.end();it++)
    // {
    //     cout<<"Name: "<<(*it).M_Name<<endl;
    // }
}

/*STACK 容器的基本概念*/

/*sTACK 构造函数*/
/*API调用*/
void test26()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(s.size()!=0)
    {
        cout<<"栈顶为："<<s.top()<<endl;
        s.pop(); //弹出站定元素
        cout<<"size = "<<s.size()<<endl;
    }
    
}
/*queue 容器*/
/*1.先进先出
  2.栈端元素才能够被使用
  3.没有迭代器，不能够遍历
  4.常用的API

*/

void test27()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    while(!q.empty())
    {
        cout<<"队头"<<q.front()<<endl;
        cout<<"队头"<<q.back()<<endl;
        //弹出队列元素
        q.pop();
         cout<<"size = "<<q.size()<<endl;
    }

}


/*链表元素*/
//vector 容器是连续线性空间
//lisT 容器是一个双向链表
//lisT 容器是一个循环的双向链表
//常用API


// void test28()
// {
//     list<int> mylist;
//     for(int i =0;i<10;i++)
//     {
//         mylist.pop_front(i);
//     }

//     list<int>:: _Nodeptr node = mylist._Myhead->Next;
//     for(int i= 0;i<mylist.size() *2;i++)
//     {
//         cout<<"Node:"<<node->_Myhead<<endl;
//         node = node->_Next;
//         if(node = mylist._Myhead)
//         {
//             node = node->Next;
//         }
//     }
// }

void printList(list<int> &L)
{
    for(list<int>::iterator it = L.begin();it!=L.end();it++)
    {
        cout<< *it<<endl;
    }

}





void test29()
{
     list<int>L(10,10);
     list<int>L2(L.begin(),L.end());
    // printList(L);
    // printList(L2);
}



/*插入数据*/
void test30()
{
    list<int> L3;
     list<int> L4;
    L3.push_back(10);
    L3.push_back(20);
    L3.push_back(30);
    L3.push_back(40);
    L3.push_back(50);
    L3.push_back(60);

   // printList(L3);
    L3.pop_front();
    L3.pop_back();
   // printList(L3);
    L3.insert(L3.begin(),1000);
    
    //L3.clear();
    // printList(L3);
    L3.remove(800);
 
    printList(L3);
    cout<<"size :"<<L3.size()<<endl;
    L3.resize(10);

    L4.assign(L3.begin(),L3.end());
    printList(L4);
}


bool My_Compare(int v1,int v2)
{
    return v1 > v2;
}
void test31()
{
    list<int> L;
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    L.push_back(40);
    L.reverse();
   // printList(L);
    L.sort();
    //printList(L);
    L.sort(My_Compare);
    printList(L);
     /*不支持随机访问的迭代器，其自身内部会提供相应的算法*/
}

class Person2
{
    public: Person2(string name,int age)
    {
        this->M_age = age;
        this->M_name =name;
    }

    string M_name;
    int M_age;
};

bool ComparePerson(Person2 &p1,Person2 &p2)
{
    if(p1.M_age<p2.M_age)
    {
        return true;
    }
    return false;
}

void test32()
{
    list<Person2> L;
    Person2 P1("WENXUE",1000);
    Person2 P2("movie",100);
    Person2 P3("sport",3000);
    Person2 P4("JAPAN",900);
    Person2 P5("gasme",800);
    L.push_back(P1);
    L.push_back(P2);
    L.push_back(P3);
    L.push_back(P4);
    L.push_back(P5);
    //定义数据类型的时候
  L.sort(ComparePerson);

  for(list<Person2>::iterator it =L.begin();it!=L.end();it++)
  {
      cout<<"姓名："<<it->M_name<<"AGE:"<<it->M_age<<endl;
  }
}
void printset(set<int> &s)
{
    for(set<int>::iterator it =s.begin();it!=s.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
/*set 容器使用*/
void test33()
{
    //关联式容器
    set<int> s1;
    s1.insert(5);
    s1.insert(1);
    s1.insert(7);
    s1.insert(9);
    s1.insert(3);
    // printset(s1);
    
    // s1.erase(s1.begin());
    // s1.erase(3);
    // printset(s1);
    //查找
    set<int> ::iterator pos = s1.find(2);
    if(pos !=s1.end())
    {
        cout<<"have found"<<*pos<<endl;
    }
    else
    {
        cout<< "cannot find"<<endl;
    }
    int num = s1.count(2);
    cout<<num<<endl;
   
}

// /*pair队组的创建方式 */
// void test34（）
// {
//     //第一种
//     pair<string,int> p(string("CAT"),10);

//     //取值
//     //cout<<"Name:"<<p.first<<endl;
//     //cout<<"AGE:"<<p.second<<endl;
//     //第二种
//    // pair<string,int> p2 = make_pair("JERRY",200);
//     //cout<<"Name:"<<p2.first()<<endl;
//     //cout<<"AGE:"<<p2.second()<<endl;
// }


void test35()
{
    set<int> s1;
    s1.insert(10);
   // s1.insert(10);

}
//set 容器排序

//map 容器
void test36()
{
    map<int,int> m;
    //第一种
    m.insert(pair<int,int>(1,10));
    //第二种 推荐
    m.insert(make_pair(2,20));
    //第三种
    m.insert(map<int,int>::value_type(3,30));
    //第四种
    m[4] = 40;
    m[5];
    m.erase(1);
    for(map<int,int>::iterator it = m.begin();it !=m.end();it++)
    {
        cout<<"KEY = "<<it->first<<" value "<<it->second<<endl;
    }
    if(m.empty())
    {
        cout<<"空"<<endl;
    }
    else
    {
        cout<<m.size()<<endl;
    }
    map<int,int>::iterator pos = m.find(1);
    if(pos!=m.end())
    {
       cout<<"找到KEY = "<<pos->first<<" value "<<pos->second<<endl;
    }
    else
    {
        cout<<"not find"<<endl;
    }
    int num = m.count(3);
    cout<<"num = "<<num <<endl;
}

//multimap 案例

enum {YABFA,DESIGN,RENLI,JINLI,};

class Worker 
{
    public:
        string M_Name;;
        int M_Age;
};

//创建员工
void CreateWorker(vector<Worker> &v)
{
    string nameseed = "ABCDE";
    
    for(int i =0;i<5;i++)
    {
        string name ="Member:";
        name += nameseed[i];
        int money = rand() %10000+10000;

        Worker w;
        w.M_Name = name;
        w.M_Age = money;
        v.push_back(w);
    }

}

//员工创建测试

void setGroup(vector<Worker> &v,multimap<int,Worker>&m)
{
    for(vector<Worker>::iterator it= v.begin();it!=v.end();it++)
    {
        //随机产生部门号码
        int departmentID = rand() %3;
        //将员工分到multimap 之中
        m.insert(make_pair(departmentID,*it));
    }
}


void showGroup(multimap<int,Worker> &m)
{
    cout<<"renlibumen"<<endl;

    multimap<int,Worker>:: iterator pos = m.find(RENLI);

    int index =0;
    int num = m.count(RENLI);
    for(;pos !=m.end(),index<num;pos++,index++)
    {
 //       count<<"NAME: "<<pos->second.M_Name<<"money: "<<pos->second.M_Age<<endl;
    cout<<"NAME: "<<pos->second.M_Name<<"money "<<pos->second.M_Age<<endl;
    }



}

class Myprint
{
    public:
        void operator() (int num)
        {
            cout<<"num = "<<num<<endl;
        }
};

void test37()
{
// Myprint() (100);
// myprint(111);

}

//函数对象超出普通函数的概念，内部可以保存状态
//函数对象作为参数；
//1.函数对象（仿函数） 1.1 重载（） 函数的对象，使用（） 像函数调用  1.2 是类，不是普通函数；1.3内部记录状态；1.4作为类型与模板配合使用
//谓词: 普通函数或者仿函数 的返回值是bool 类型；
//一元谓词


class GreaterThan20
{
    public:
    bool operator()(int val)
    {
        return val>20;
    }
};




void test38()
{
    vector<int > v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);

    //
    vector<int>::iterator   pos = find_if(v.begin(),v.end(),GreaterThan20());
    if(pos!=v.end())
    {
        cout<<"find the numb big than 20"<<*pos <<endl;
    }
    else
    {
        cout<<"not find"<<endl;
    }
}
class My_Compare1
{
    public:
        bool operator() (int v1,int v2)
        {
            return v1>v2;
        }
};
//二元谓词
void test39()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v.push_back(40);
    v.push_back(50);
    v.push_back(60);


    sort(v.begin(),v.end(),My_Compare1());

    for_each(v.begin(),v.end(),[](int val){cout<<val<<" ";});
}


//内建函数 STL 内建了一些函数   算术  关系运算   逻辑运算仿真类  也可以产生一些无名的临时对象

void test40()
{   
    //取反
    negate<int> n;
    cout<<n(10)<<endl;
    //加法
    plus<int> p;
    cout<< p(1,2)<<endl;
}
//适配器
class My_print2:public binary_function<int,int,void>
{
    public:
        void operator() (int v,int start) const 
        {
            cout<<""<<v<<"start"<<start<<"v+start"<<v+start<<endl;
        }
};

void test41()
{
    vector <int> v;
    for(int i=0;i< 10;i++)
    {
        v.push_back(i);
    }
    cout<<"请输入起始值"<<endl;
    int num;
    cin>>num;


    for_each(v.begin(),v.end(),bind2nd(My_print2(),num));
}


class GreaterThan5:public unary_function<int,bool>
{
public:
    bool operator() (int v)
    {
        return v>5;
    }
};




//取反适配器
void test42()
{
    //一元取反
    vector<int> v;
    for(int i =0;i<10;i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator pos= find_if(v.begin(),v.end(),GreaterThan5());
    if(pos!=v.end())
    {
        cout<<"find bigger than 5"<<*pos<<endl;
    }
}

//一元取反 适配器
//继承自：unary_function

//函数指针适配器
//ptr_fun
//成员函数适配 ：mem_fun   如果容器是对象指针；  mem_fun_ref 容器中存放的是对象实体 mem_fun_ref

void test43()
{
    vector<int> v;
    for(int i =0;i<10;i++)
    {
        v.push_back(i);
    }
}

//基本算法
class TransForm1
{
    public:
        int operator()(int val,int val1)
        {
            return val+val1;
        }
};
//常用遍历算法：1.for_each 可以有返回值    可以绑定参数进行输出    transform 可以将一个容器的数据搬到 另一个容器中  目标容器需要开辟




//transform 算法，把容器区间元素搬运到另一个容器中,不会给目标容器分配内存，需要提前分布好内存
// void test44()
// {
//     vector<int> v;         //原容器
//     for(int i =0;i<10;i++)
//     {
//         v.push_back(i);
//     }

//     vector<int> vTarget;   //目标容器
//     vTarget.resize(v.size());
//     transform(v.begin(),v.end(),vTarget.begin(),TransForm1());
//     for_each(vTarget.begin(),vTarget.end(),[](int val){cout<<val<<" ";});
// }

void test45()
{
    vector <int> v1;
    vector<int> v2;
    for(int i =0;i<10;i++)
    {
        v1.push_back(i);
        v2.push_back(i);

    }
    vector<int> vTarget;
    vTarget.resize(v1.size());
    transform(v1.begin(),v1.end(),v2.begin(),vTarget.begin(),TransForm1());
    for_each(vTarget.begin(),vTarget.end(),[](int val){cout<<val<<" ";});
}
//常用查找算法
void test46()
{
    vector<int> v;
    for(int i;i<10;i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator pos= find(v.begin(),v.end(),5);
    if(pos!=v.end())
    {
        cout<<"have find:"<<*pos<<endl;
    }
    else
    {
        cout<<"cannot find"<<endl;
    }
}

//利用find（） 查找自定义数据
void test47()
{
    vector<Person> v;
    Person p1 ("aaaa",10);
    Person p2 ("bbbb",20);
    Person p3 ("cccc",30);
    Person p4 ("dddd",40);
    Person p5 ("eeee",50);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    vector<Person>::iterator pos= find(v.begin(),v.end(),p2);
    
    if(pos!=v.end())
    {
        cout<<"have find:"<<(*pos).M_Name<<"age: "<<(*pos).M_Age<<endl;
    }
    else
    {
        cout<<"cannot find"<<endl;
    }
}
/*
adjacent_find 算法   查找相邻重复元素
beg容器开始i迭代器
end容器结束迭代器
_callback 回调函数或者谓词（返回bool 类型的函数对象）
返回相邻元素的第一个位置的迭代器
*/
void test48()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(5);
    v.push_back(3);
    
    vector<int>:: iterator pos= adjacent_find(v.begin(),v.end());

    if(pos!=v.end())
    {
        cout<<"neghbior"<<*pos<<endl;
    }
    else
    {
        cout<<"cannot find"<<endl;
    }
}

/*
binary_search 算法 二分查找法
在无序序列中不能够使用
beg 容器开始迭代器
end 容器结束迭代器
value 查找的元素

return bool 查找返回 true  否则 false 


*/
void test49()
{
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    bool ret = binary_search(v.begin(),v.end(),6);
    if(ret)
    {
         cout<<"find"<<endl;
    }
    else
    {
         cout<<"can not find"<<endl;
    }
}

class Greaterthan4
{
    public:
        bool operator()(int v)
        {
            return v>4;
        }
};
/*count 查找元素的个数*/
/*count_if*/
void test50()
{
    vector<int> v;
    int num = count_if(v.begin(),v.end(),Greaterthan4());
    cout<<num<<endl;
}
//operator操作符重载 ，重载（）是的该对象是一个函数对象，即该 、对象有函数的功能

void test51()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(40);
    v1.push_back(20);
    v1.push_back(50);
    v1.push_back(30);
    v1.push_back(60);

    sort(v1.begin(),v1.end());
    for_each(v1.begin(),v1.end(),[](int val){cout<<val<<" ";});
    cout<<endl;

    sort(v1.begin(),v1.end(),greater<int>());
    for_each(v1.begin(),v1.end(),[](int val){cout<<val<<" ";});
    cout<<endl;


}
/*random_shuffle 洗牌*/  
void test52()
{
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(),[](int val){cout<<val<<" ";});
    cout<<endl;
}

/*拷贝算法*/
//copy    replace 
//swap（）交换算法
//reverse fan
class MYcompare3
{
    public :
        bool operator()(int v)
        {
            return v>3;
        }

};
void test53()
{
    vector<int> v;
    for(int i =0;i<10;i++)
    {
        v.push_back(i);
    }
    vector<int> v1;
    // v1.resize(v.size());
    // copy(v.begin(),v.end(),v1.begin());
    // for_each(v1.begin(),v1.end(),[](int val){cout<<val<<" ";});
    replace(v.begin(),v.end(),3,300); 
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));

    replace_if(v.begin(),v.end(),MYcompare3(),30000);
    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
}

//算术生成算法
//accumulate  fill
void test54()
{
    vector<int> v;
    for(int i=0;i<101;i++)
    {
        v.push_back(i);
    }
    int num = accumulate(v.begin(),v.end(),0);
    cout<<num<<endl;
}

//常用集合算法   交集  并集 差集
//set_union 并集
//set_difference   差集
void test55()
{
    vector<int> v1;
    vector<int> v2;

    for(int i =0;i<10;i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }

    vector<int> vTarget;
    vTarget.resize(min(v1.size(),v2.size()));
    vector<int>::iterator itEnd = set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());//交集
    copy(vTarget.begin(),itEnd,ostream_iterator<int>(cout," "));

}

/*
比赛规则：24 个人参加比赛  参加三轮  前两轮为淘汰赛  第三轮为决赛
          第一轮分为4个小组 每组6人 第一轮比赛结束 每组淘汰三人 
          第二轮比赛，分为2个小组，每组6人，比赛结束，每组淘汰三人
          第三轮比赛，分为1个小组，一共6个人，决出前3名
          得分方式：有十名评委  去掉最高分，去掉最低分，剩下的取平均分
          每轮过后：打印出每个选手的分数
2.实现方案
        1.产生选手  姓名 、得分 、选手编号
        2.第一轮  选手抽签 选手比赛 查看得分结果
        3.第二轮  选手抽签 选手比赛 查看得分结果
        4.第三轮  选手抽签 选手比赛 查看得分结果

        思路：
        1.选手信息、得分信息 比赛抽签信息  晋级信息保存在容器中     容器选型

*/
class Speaker
{
    public:
        string M_name;   //选手姓名
        int Score[3];   //得分数组
};


//创建选手
void CreateSpeaker(vector<int>&v,map<int,Speaker>&m)
{
    string nameseed = "ABCDEFGHIJKLMNOPQRSTUVWX";
    for(int i = 0;i<nameseed.size();i++)
    {
        string name = "Member";
        name+= nameseed[i];

        Speaker sp;
        sp.M_name = name;
        
        for(int j =0;j<3;j++)
        {
            sp.Score[j] =0;
        }
        v.push_back(i+100);
        m.insert(make_pair(i+100,sp));
    }
}

//抽签
void  Speach_Draw(vector<int> v)
{
    random_shuffle(v.begin(),v.end());
}

//比赛
void Speach_Contenst(int index,vector<int>v1,map<int,Speaker>&m,vector<int>&v2)
{
    multimap<int,int,greater<int>> groupMAp;  //key  分数   value  编号
    int num =0;
    deque<int> d;
    for(vector<int>::iterator it= v1.begin();it !=v1.end();it++)
    {
        num++;
        for(int i =0;i<10;i++)
        {
            int score = rand() %41+60;
            d.push_back(score);
        }
        
    
    //排序
    sort(d.begin(),d.end());
    //去除最高低分数
    d.pop_back();
    d.pop_front();

    //求和
    int sum = accumulate(d.begin(),d.end(),0);
    //求平均
    int avg = sum/d.size();
    //将平均分 放入到容器中
    m[*it].Score[index-1] = avg;

    //每6个人 取前三名
    //临时容器
    //临时容器，存入数据

    groupMAp.insert(make_pair(avg,*it));
    if(num%6 == 0)
    {
        // cout<<"the mark in group list："<<endl;
        // for(multimap<int,int,greater<int>>::iterator mit =groupMAp.begin();mit!=groupMAp.end();mit++ )
        // {
        //     cout<<"num: "<<mit->second<<"name: "<<m[mit->second].M_name<<"Score :"<<m[mit->second].Score[index-1]<<endl;
        // }
        int count = 0;
        for(multimap<int,int,greater<int>>::iterator mit =groupMAp.begin();mit!=groupMAp.end();mit++ )
        {
         //晋级容器
         v2.push_back(mit->second);   
        }
        groupMAp.clear();    //清空临时容器
    }


    }
}

void showScore(int index,vector<int> &v,map<int,Speaker> &m)
{
    cout<<"the "<<index<<"  "<<endl;
    for(map<int,Speaker>::iterator it =m.begin();it !=m.end();it++)
    {
        cout<<"number: "<<it->first<<"name :"<<it->second.M_name<<"score: "<<it->second.Score[index-1]<<endl;
    }



    //cout<<"number: "<<m
}






//演讲比赛
void Speaker_match()
{
    vector<int> v1;              //存放选手编号
    map<int,Speaker> m;         //存放选手编号  和对应的具体选手

    //创建选手
    CreateSpeaker(v1,m);
    //测试
    // for(map<int,Speaker>::iterator it = m.begin();it!=m.end();it++)
    // {
    //     cout<<"numb:"<<it->first<<" name:"<<it->second.M_name<<"score"<<it->second.Score[0]<<endl;
    // }

    //抽签
    Speach_Draw(v1);

    vector<int> v2;
    //比赛
    Speach_Contenst(1,v1,m,v2);

    //显示比赛结果
    showScore(1,v2,m);

    //第二轮比赛
    Speach_Draw(v2);
    vector<int> v3;
    Speach_Contenst(2,v2,m,v3);
    showScore(2,v3,m);

    //第三轮比赛
    Speach_Draw(v3);
    vector<int> v4;
    Speach_Contenst(3,v3,m,v4);
    showScore(3,v4,m);
}

/*贪食蛇小游戏
1.墙  模块
二维数组维护  游戏内容
初始化二维数组 initwall
画出墙壁 drawwall
提供对外接口 setwall   get

蛇模块
初始化蛇
销毁所有节点
添加新的节点


食物模块
foodX foodT 位置
setFood 对外接口  可以设置食物
随机生成食物








*/
class Wall
{
 public:
    enum{
        ROW = 20,
        COL = 20
    };

//初始化墙壁
 void initWall();
 //画出墙壁
 void drawwall();
//根据索引设置 二维数组里的内容
 void setWall(int x,int y,char c);
//获取 索引里面的值
 char getwall(int x,int y);

 private:
    char gameArray[ROW][COL];
};
/*
    🐍 的 类
*/

class Food
{
    public:
        Food(Wall &tempWall);
        //设置食物
        void setFood();

        int foodX;
        int foodT;
        Wall &wall;
};
class Snake
{
    public:
        Snake(Wall &tempWall,Food & food);

        enum{UP = 'w',DOWN = 's',LEFT = 'a',RIGHT = 'd'};

        //节点
        struct Point
        {
            //数据域
            int x;
            int y;
            //指针阈
            Point *next;
        };
    //初始化
    void initSnake();
    //添加节点
    void addPoint(int x,int y);
    //销毁节点
    void destroyPoint();

    //删除节点
    void delPoint();
    //移动蛇操作
    //返回值代表 移动是否成功
    bool move(char key);

    Point *pHead;
    Wall &wall;
    Food &food;

};





Snake::Snake(Wall &tempWall,Food &tmpFood):wall(tempWall),food(tmpFood)
{
    pHead = NULL;
}



void Wall::initWall()
{
    for(int j =0;j<ROW;j++)
    {
        for(int i=0;i<COL;i++)
        {
            if(i==0||j==0||j == ROW-1||i== COL-1)
            {
                gameArray[i][j] = '*';
            }
            else
            {
                 gameArray[i][j] = ' ';
            }
        }
    }
}

void Wall::drawwall()
{
    
    for(int i=0;i<ROW;i++)
    {
       
        for(int j=0;j<COL;j++)
        {
            cout<<gameArray[i][j]<<" ";
        }
       
        if(i==5)
        {
            cout<<"create by zt";
        }
        if(i==6)
        {
            cout<<"a :left ";
        }
        if(i==7)
        {
            cout<<"d: right ";
        }
        if(i==8)
        {
            cout<<"w: up ";
        }
        if(i==9)
        {
            cout<<"s: down";
        }

         cout<<endl;
    }
   
    
}


void Wall::setWall(int x,int y,char c)
{
    gameArray[x][y] = c;
}

char Wall::getwall(int x,int y)
{
    return gameArray[x][y];
}



void Snake::initSnake()
{
    destroyPoint();
    addPoint(5,3);
    addPoint(5,5);
    addPoint(5,6);
}


//销毁所有节点
void Snake::destroyPoint()
{
    Point *PCur = pHead;
    while(pHead !=NULL)
    {
        PCur = pHead->next;
        delete pHead;
        pHead = PCur;
    }
}

void Snake::addPoint(int x,int y)
{
    //创建新节点
    Point *newPoint = new Point;
    newPoint->x=x;
    newPoint->y=y;
    newPoint->next = NULL;

    //如果原来头部位空 改为身子
    if(pHead != NULL)
    {
        wall.setWall(pHead->x,pHead->y,'=');
    }
    newPoint->next = pHead;

    pHead = newPoint; //更新头部
    wall.setWall(pHead->x,pHead->y,'@');

}

void Snake::delPoint()
{
    //两个节点以上  才做删除操作
    if(pHead == NULL || pHead->next ==NULL)
    {
        return;
    }

    Point *pCur = pHead->next;
    Point *pPre = pHead;
    while(pCur->next !=NULL)
    {
        pPre = pPre->next;
        pCur = pCur->next;

    }
    //删除尾节点
    wall.setWall(pCur->x,pCur->y,' ');
    delete pCur;
    pCur = NULL;
    pPre->next = NULL;


}

bool Snake::move(char key)
{
    int x = pHead->x;
    int y = pHead->y;

    switch(key)
    {
        case UP:
                x--;
        break;
        case DOWN:
                x++;
        break;

        case LEFT:
                y--;
        break;

        case RIGHT:
                y++;
        break;
        default:

        break;
    }

    //判断用户达到位置是否成功
    if(wall.getwall(x,y) == '*'||wall.getwall(x,y)=='=')
    {
        cout<<"GAME OVER"<<endl;
        return false;
    }


    //移动成功  吃到食物  未吃到食物
    if(wall.getwall(x,y)=='#')
    {
            addPoint(x,y);
            //重新设置食物
            food.setFood();
    }
    else
    {
             addPoint(x,y);
             delPoint();   
    }
    return true;

}







Food::Food(Wall & tempWall):wall (tempWall)
{

}

//设置食物
void Food::setFood()
{

    while(true)
    {
        foodX = rand() %(Wall::ROW-2)+1;
        foodT = rand() %(Wall::COL-2)+1;

        //如果随机的位置是舌头或者蛇身 ，就重新生成随机数
        if(wall.getwall(foodX,foodT)==' ')
        {
            wall.setWall(foodX,foodT,'#');
            break;
        }
      }

}

//贪食蛇测试
void Snake_test()
{


    //添加game over 标识

    bool isOver =  false;
   
    Wall wall;
    wall.initWall();
    Food food(wall);
    food.setFood();
    Snake snake(wall,food);
    snake.initSnake();

    
  
    wall.drawwall();






//接收用户输入

    while(!isOver)
    {
        char key = _getch();
        do 
        {
            if(snake.move(key) == true)
            {
                //移动成功  代码
                system("cls");
                wall.drawwall();
                Sleep(300);
            }
            else
            {
                isOver = true;
                break;
            }

        } while(!_kbhit);


    }
    
}



/*算法学习*/
//链表学习 8道经典题目

struct ListNode 
{
    int val;            //节点存储的值
    ListNode *next;     //next 节点指针
};




//链表逆序
//训练  填鸭式教育
//链表逆序
/*思路:
1.建立一个链表结构（节点值，节点指针）；
2.创建一个链表，给每一个节点赋值；
3.打印出每个节点的值；（此处遍历，判断节点头）

4.在构建一个链表的类用来解决链表的一写问题
5.创建一个函数用来倒序；
6.此函数为指针函数，有一个参数为 指针参数
7.函数的实现内容：由于有多个节点，每个节点的都需要处理，遍历，此处定义一个新的链表头，用来存储新的列表；
  7.1  定义一个  链表 *next指针用来使用更新 节点，把节点对应的指针 赋予 next  这个指针变量
  7.2  更新head,head->next 被new_head 赋值；
  7.3  移动 new_head；
  7.4  遍历
  7.5  返回new_head;


8.在类中定义另一个函数，用来倒序列表中的一部分；
    8.1 此函数类型 仍然是函数指针，参数变量有三个，一个为链表的指针，另一个为起始节点，另一节点为长度；
    8.2 重点：找到对应的起始地址，需要结束的地方；
              进行倒序；
              倒序过的部分进行拼接；
    8.3 输入一个链表，返回的值有哪些，返回一个链表，并且打印出来；
    
    倒序 那些节点；怎么倒序；

*/


//链表从第几个节点开始逆序  几个节点
//
class Solution 
{
    public:
          ListNode *reveselist(ListNode *head)
          {
            ListNode *new_head = NULL;
            while(head)
            {
                //备份
                ListNode *next = head->next;
                //更新
                head->next = new_head;
                //移动
                new_head = head;
                //遍历
                head = next;
            }
            return new_head;
          }
          
          /*链表从第几个节点开始逆序  几个节点*/
          ListNode *reverselist_m_n(ListNode *head,int m,int n)
          {
              int change_len = n-m+1;           //计算需要逆置的节点个数
              ListNode *pre_head = NULL;        //初始化开始逆置的节点前驱
              ListNode *result = head;          //最终转换的链表头节点，非特殊情况即为head;
              while(head && --m)                //将head 移动m-1 个位置；
              {
                  pre_head = head;              //记录head 前驱
                  head     = head->next;           
              }
             ListNode *modify_list_tail = head;  //将modify_list_tail 指向当前的head;
             ListNode *new_head = NULL;          //
             while(head &&change_len)
             {
                 ListNode *next = head->next;
                 head->next = new_head;
                 new_head= head;
                 head = next;
                 change_len--;                    
             }
             modify_list_tail->next =head;

             if(pre_head)
             {
                 pre_head->next = new_head;
             }
             else
             {
                 result = new_head;
             }
            return result;
          }

};


void test_ListNode()
{
    /*创建5个节点，链接成一个链表*/
    ListNode a,b,c,d,e;
  
    a.val = 10;
    b.val = 20;
    c.val = 30;
    d.val = 40;
    e.val = 50;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;
    /*打印链表*/
   // ListNode *head = &a;

    Solution solve;
    // cout<<"daoxuqian:"<<endl;
    // while(head)
    // {
    //     cout<<"the value"<<head->val<<endl;
    //     head = head->next;
    // }

    // cout<<"daoxuhou:"<<endl;
    // head = solve.reveselist(&a);

    // while(head)
    // {
    //     cout<<"the value"<<head->val<<endl;
    //     head = head->next;
    // }
    cout<<"between:"<<endl;

    ListNode *head = solve.reverselist_m_n(&a,3,4);
    while(head)
    {
        cout<<"the value"<<head->val<<endl;
        head = head->next;
    }

}

/*求两个链表的交点
1.就是两个链表共有部分的开始；
2.思路1： 遍历链表A 将A 中节点对应的指针，插入SET;
         遍历链表B 将B 中节点对应的指针，在SET 中查找，找到的第一个节点地址，就是两个链表的交点 
  思路2： 空间复杂度：求出A B 两个链表的长度，以及较长的链表多出的长度
                    将较长的指针移动和较短聊表指针对齐的位置；
                    将A B  同时移动，当两个指针指到同一个节点的时候没即为交点

*/
//获取 链表长度
int get_list_length(ListNode *head)
{
    int len = 0;
    while(head)
    {
        len++;
        head = head->next;
    }
        return len;
}

ListNode *forward_long_list(int long_len,int short_len,ListNode *head)
{
    int delta = long_len-short_len;
    while(head && delta)
    {
        head = head->next;          //将指针向前移动至多出节点个数后面的位置
        delta--;
    }
    return head;
}


class Solution_LIST_2
{
    public:
    ListNode *getIntersectionNode_2(ListNode *headA,ListNode *headB)
    {
        
        int list_A_len = get_list_length(headA);
        printf("%d",list_A_len);
        int list_B_len = get_list_length(headB);
        printf("OK3");
        if(list_A_len>list_B_len)
        {
            headA = forward_long_list(list_A_len,list_B_len,headA);
        }
        else
        {
            headB = forward_long_list(list_B_len,list_A_len,headB);
        }

        while(headA &&headB)
        {
            if(headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headA->next;
        }
        return NULL;
    }
};

//求链表交点
void list_test_intersection()
{
    
    ListNode a1,a2,b1,b2,b3,c1,c2,c3;
    a1.val = 1;
    a2.val =2;
    b1.val = 3;
    b2.val = 4;
    b3.val = 5;
    c1.val = 6;
    c2.val = 7;
    c3.val = 8;
    a1.next = &a2;
    a2.next = &c1;
    c1.next = &c2;
    c2.next = &c3;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;

    
    Solution_LIST_2 solve4;
    
    //ListNode *result = solve4.getIntersectionNode_2(&a1,&b1);
    cout<<"ko3"<<endl;
    cout<<"ko"<<endl;
    ListNode *result = solve4.getIntersectionNode_2(&a1,&b2);
    printf("%d\n",result->val);
    
 }



class Solution_LIST
{
    public:
        ListNode *getIntersectionNode(ListNode *headA,ListNode*headB)
        {
            set<ListNode*> node_set;
            while(headA)
            {
                node_set.insert(headA);            //将链表A中的节点插入node_set 中
                headA = headA->next;               //遍历链表A
            }

            while(headB)
            {
                if(node_set.find(headB) !=node_set.end())
                {
                    return headB;
                }
                    headB = headB->next;
            }

            return NULL;
        }
};




int main()
{
    int i =10;
    srand((unsigned int) time(NULL));
    std::cout<<"Hello world"<<std::endl;
    vector<Worker> v;
    CreateWorker(v);
    
    // test_ListNode();
   // list_test_intersection();
    bool acess  = false;
    if(acess)
    
    cout<< "test"<<endl;
    cout<<"ko"<<endl;
    
    

    //设置分组
    //分组的multimap 容器
    //multimap<int,Worker>m;
    //setGroup(v,m);
    //showGroup(m);
    //Speaker_match();
    //Snake_test();
    //for(vector<Worker>::iterator it =v.begin();it!=v.end();it++)
    //{
    //   cout<<"name:"<<it->M_Name<<"money:"<<it->M_Age<<endl;
    // }
     system("pause");
}


