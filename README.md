# C-hotel_balabala
here! https://github.com/2678344415/C-hotel_balabala
## 一. 需求分析
 宾馆信息管理系统：
 用于查询宾馆信息，从而使客人更方便查询宾馆信息及使用情况。本系统功能有：浏览房间号、容量、档次、价格、是否已用；商家增加、删除、修改房间信息的功能。
 
 
## 二. 系统设计
### （一）. 系统中的数据定义
struct room    //结构体定义并声明  
{  
    char num[6];   //房间号  
    int siz;     //容量  
    char level[20];  //档次  
    float price;   //价格  
    char use[10] ; //是否已用  
};  
### （二）. 系统的概要设计
 宾馆信息管理系统  
   1.添加宾馆信息  
   2.浏览宾馆信息  
   3.查询宾馆信息  
   4.修改宾馆信息  
   5.删除宾馆信息  
   6.退出系统  
### （三）. 系统的详细设计
a.添加宾馆信息  
根据宾馆信息分别将6位数房间号、房间容量、房间档次、房间价格、房间是否已用输入程序中。  
b.浏览宾馆信息  
       可浏览已添加的宾馆信息，使客人更加方便了解宾馆的实际情况。  
c.查询宾馆信息  
              可查询宾馆各个房间的详细情况，是否已使用等等。  
d.修改宾馆信息  
商家可通过此项修改房间的信息。  
e.删除宾馆信息  
       商家可通过此项将房间信息删除。  
f.退出  
退出当前模块。  
### （四）. 系统的核心算法  
void input(struct room wyr[M]);     //输入函数  
void output(struct room wyr[M]);     //各类用户自定义函数的声明  
void lookfor(struct room wyr[M]);    //查询函数  
void modify(struct room wyr[M]);     //修改函数  
void delete_student(struct room wyr[M]);   //删除函数  
void fangjianhao(struct room wyr[M]);       //自定义通过学号方式删除学生信息函数  


## 三. 系统编码及运行  
### （一） . 系统开发设计的软件
Code：：Blocks  
### （二） . 系统运行界面及结果
1. 初始界面  
![image](https://github.com/2678344415/C-hotel_balabala/raw/master/1.png)    
2. 添加宾馆信息  
![image](https://github.com/2678344415/C-hotel_balabala/raw/master/2.png)    
3. 浏览宾馆信息  
![image](https://github.com/2678344415/C-hotel_balabala/raw/master/3.png)   
4. 查询宾馆信息  
![image](https://github.com/2678344415/C-hotel_balabala/raw/master/4.png) 
5. 修改宾馆信息  
![image](https://github.com/2678344415/C-hotel_balabala/raw/master/5.png) 
6. 删除宾馆信息  
![image](https://github.com/2678344415/C-hotel_balabala/raw/master/6.png) 
7. 退出系统  
![image](https://github.com/2678344415/C-hotel_balabala/raw/master/7.png) 


## 四. 系统测试
如上述截图，调试一切正常。

## 五. 总结
- 项目实践是锻炼编程能力的一个很好的机会，从零到一个程序的实现，需要设计，思考，查找资料，编写，以及调试与总结，前前后后不仅是对单个编程能力的实现，也是对所有所学知识的一个综合运用和实现。  
- 本次项目实践收获颇丰，大幅度锻炼了我的代码实现能力，也使我更加进一步的理解了程序结构化编程的原理。  
- 通过本程序，我更进一步熟悉了老师上课所讲的知识，在数据管理，文件操作方面也有了自己的创新与实践。
