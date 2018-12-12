#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#define M 10000



void input(struct room wyr[M]);     //输入函数
void output(struct room wyr[M]);     //各类用户自定义函数的声明
void lookfor(struct room wyr[M]);    //查询函数
void modify(struct room wyr[M]);     //修改函数
void delete_student(struct room wyr[M]);   //删除函数
void fangjianhao(struct room wyr[M]);       //自定义通过学号方式删除学生信息函数



struct room    //结构体定义并声明
{
    char num[6];   //房间号
    int siz;     //容量
    char level[20];  //档次
    float price;   //价格
    char use[10] ; //是否已用

};


int count=0;

int main()
{
    int choice,sum;
    struct room wyr[M];
    system("mode con:cols=150 lines=30000");        //调节控制台的宽度和高度
    system("color 3b");      //调节控制台的背景和字体颜色
point1:
    sum=0;
    printf("\t\t\t\t\t\t\t\t欢迎使用宾馆信息管理系统\n");
     do
     {
        printf("\t\t\t\t\t\t\t\t-------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t     宾馆信息管理系统          \n");
        printf("\t\t\t\t\t\t\t\t-------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t ***************\n");
        printf("\t\t\t\t\t\t\t\t\t\t 1、添加宾馆信息\n");
        printf("\t\t\t\t\t\t\t\t\t\t 2、浏览宾馆信息\n");
        printf("\t\t\t\t\t\t\t\t\t\t 3、查询宾馆信息\n");
        printf("\t\t\t\t\t\t\t\t\t\t 4、修改宾馆信息\n");
        printf("\t\t\t\t\t\t\t\t\t\t 5、删除宾馆信息\n");
        printf("\t\t\t\t\t\t\t\t\t\t 6、退出系统\n");
        printf("\t\t\t\t\t\t\t\t\t\t ***************\n");
        printf("请输入你的选择\n");
        scanf("%d",&choice);
        fflush(stdin);       //清除输入缓冲区
        if (choice>6||choice<=0)
        {
            sum++;
            if (sum>=5)
            {
                printf("输入错误次数过多,程序将重新开始\n");
                system("pause");        //程序暂停
                system("cls");   //清屏语句
                goto point1;
            }
        }
        switch (choice)       //根据选择，调用不同的函数来完成不同的任务
        {
        case 1:
            input(wyr);
            break;
        case 2:
            output(wyr);
            break;
        case 3:
            lookfor(wyr);
            break;
        case 4:
            modify(wyr);
            break;
        case 5:
            delete_student(wyr);
            break;
        case 6:
            printf("感谢使用,请关掉程序!!!\n");
            system("pause");
            break;
        default:
            printf("无效,请重新输入\n");
            break;
        }
     }
 while (choice!=6);
    printf("the program is over!!!\n");
    return 0;
}

void input(struct room wyr[M])      //自定义输入函数
{

    int len;
    system("cls");

    printf("添加要输入的宾馆信息\n");
    do
    {
        printf("请输入6位数房间号\n");   //do-while循环应用，提示输入位数为一确定数
        scanf("%s",wyr[count].num);
        len=strlen(wyr[count].num);
    }
    while(len!=6);
    printf("输入房间容量\n");
    scanf("%d",&wyr[count].siz);
    printf("输入房间档次\n");
    scanf("%s",wyr[count].level);
    printf("输入房间价格\n");
    scanf("%f",&wyr[count].price);
    printf("输入是否已用  是  否  \n");
    scanf("%s",wyr[count].use);
    count++;

}


void output(struct room wyr[M])     //自定义输出函数
{
    int j;
    system("cls");
    if (count==0)
    {
        printf("当前房间信息为0个\n");
        return;
    }

        printf("房间号\t\t容量\t\t档次\t价格\t是否已用\n");
        for (j=0; j<count; j++)
        {
            printf("%s\t",wyr[j].num);
            printf("%d\t\t",wyr[j].siz);
            printf("%s\t",wyr[j].level);
            printf("%.2f\t\t",wyr[j].price);
            printf("%s\n",wyr[j].use);

        }

}


    void lookfor(struct room wyr[M])                   //自定义查询房间信息函数
    {
        int j,flag=0;
        char xh[6];
        system("cls");
        if (count==0)
        {
            printf("当前已存房间信息为0个\n");
            return;
        }
        else
        {
            printf("请输入房间号\n");
            scanf("%s",&xh);
            fflush(stdin);
            for (j=0; j<count; j++)
            {
                if (strcmp(wyr[j].num,xh)==0)
                {
                    printf("房间号\t\t容量\t\t档次\t价格\t是否可用\n");
                    printf("%s\t",wyr[j].num);
                    printf("%d\t\t",wyr[j].siz);
                    printf("%s\t",wyr[j].level);
                    printf("%.2f\t\t",wyr[j].price);
                    printf("%.2f\n",wyr[j].use);
                    flag=1;
                }
            }
            if (flag!=1)
                printf("很抱歉,没有此房间信息\n");
        }
    }



    void modify(struct room wyr[M])    //自定义修改函数
    {
        int j,flag=0,course;
        char xh[6];
        system("cls");
        if (count==0)
        {
            printf("当前已存房间信息为0个,无法修改!!!\n");
            return;
        }
        else
        {
            printf("输入你想要修改的房间号(→_→)\n");
            scanf("%s",xh);
            fflush(stdin);
            for (j=0; j<count; j++)
                if (strcmp(wyr[j].num,xh)==0)
                {
                    printf("选择:1  容量\t  2  档次\t  3  价格\t  4  是否已用\n");
                    scanf("%d",&course);
                    printf("请输入你想要修改后的房间信息\n");
                    switch(course)
                    {
                    case 1:
                        scanf("%d",&wyr[j].siz) ;
                        break;
                    case 2:
                        scanf("%s",wyr[j].level);
                        break;        //switch控制语句
                    case 3:
                        scanf("%f",&wyr[j].price) ;
                        break;
                    case 4:
                        scanf("%s",wyr[j].use);
                        break;
                    default:
                        printf("无效的选择!!!请重新输入!!!\n");
                        break;
                    }
                }
        }
    }


    void delete_student(struct room wyr[M])        //自定义删除函数
    {
        int choice;
        system("cls");
        if (count==0)
        {
            printf("当前已存房间信息为0个,无法删除!!!\n");
            return;
        }
        else
        {
            printf("是否要删除:1、确认2、取消\n");
            scanf("%d",&choice);
            switch(choice)            //switch语句对用户要删除的方式进行选择
            {
            case 2:
                return;
                break;
            case 1:
                fangjianhao(wyr);
                break;
            default:
                printf("无效的选择!!!请重新输入!!!\n");
                break;
            }
        }
    }



    void fangjianhao(struct room wyr[M])           //自定义删除房间信息函数
    {
        int j,k=count;
        char xh[6];
        system("cls");
        printf("请输入你想要删除的房间号\n");
        scanf("%s",xh);
        fflush(stdin);
        for (j=0; j<count; j++)
        {
            if (strcmp(wyr[j].num,xh)==0)
            {
                for (j=0; j<count; j++)
                    wyr[j]=wyr[j+1];
                count--;
                if (count<k)
                    printf("你已经删除成功\n");
            }

        }
        if (j==count)
            printf("抱歉,无房间信息!\n");
    }



