#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#define M 10000



void input(struct room wyr[M]);     //���뺯��
void output(struct room wyr[M]);     //�����û��Զ��庯��������
void lookfor(struct room wyr[M]);    //��ѯ����
void modify(struct room wyr[M]);     //�޸ĺ���
void delete_student(struct room wyr[M]);   //ɾ������
void fangjianhao(struct room wyr[M]);       //�Զ���ͨ��ѧ�ŷ�ʽɾ��ѧ����Ϣ����



struct room    //�ṹ�嶨�岢����
{
    char num[6];   //�����
    int siz;     //����
    char level[20];  //����
    float price;   //�۸�
    char use[10] ; //�Ƿ�����

};


int count=0;

int main()
{
    int choice,sum;
    struct room wyr[M];
    system("mode con:cols=150 lines=30000");        //���ڿ���̨�Ŀ�Ⱥ͸߶�
    system("color 3b");      //���ڿ���̨�ı�����������ɫ
point1:
    sum=0;
    printf("\t\t\t\t\t\t\t\t��ӭʹ�ñ�����Ϣ����ϵͳ\n");
     do
     {
        printf("\t\t\t\t\t\t\t\t-------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t     ������Ϣ����ϵͳ          \n");
        printf("\t\t\t\t\t\t\t\t-------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t ***************\n");
        printf("\t\t\t\t\t\t\t\t\t\t 1����ӱ�����Ϣ\n");
        printf("\t\t\t\t\t\t\t\t\t\t 2�����������Ϣ\n");
        printf("\t\t\t\t\t\t\t\t\t\t 3����ѯ������Ϣ\n");
        printf("\t\t\t\t\t\t\t\t\t\t 4���޸ı�����Ϣ\n");
        printf("\t\t\t\t\t\t\t\t\t\t 5��ɾ��������Ϣ\n");
        printf("\t\t\t\t\t\t\t\t\t\t 6���˳�ϵͳ\n");
        printf("\t\t\t\t\t\t\t\t\t\t ***************\n");
        printf("���������ѡ��\n");
        scanf("%d",&choice);
        fflush(stdin);       //������뻺����
        if (choice>6||choice<=0)
        {
            sum++;
            if (sum>=5)
            {
                printf("��������������,�������¿�ʼ\n");
                system("pause");        //������ͣ
                system("cls");   //�������
                goto point1;
            }
        }
        switch (choice)       //����ѡ�񣬵��ò�ͬ�ĺ�������ɲ�ͬ������
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
            printf("��лʹ��,��ص�����!!!\n");
            system("pause");
            break;
        default:
            printf("��Ч,����������\n");
            break;
        }
     }
 while (choice!=6);
    printf("the program is over!!!\n");
    return 0;
}

void input(struct room wyr[M])      //�Զ������뺯��
{

    int len;
    system("cls");

    printf("���Ҫ����ı�����Ϣ\n");
    do
    {
        printf("������6λ�������\n");   //do-whileѭ��Ӧ�ã���ʾ����λ��Ϊһȷ����
        scanf("%s",wyr[count].num);
        len=strlen(wyr[count].num);
    }
    while(len!=6);
    printf("���뷿������\n");
    scanf("%d",&wyr[count].siz);
    printf("���뷿�䵵��\n");
    scanf("%s",wyr[count].level);
    printf("���뷿��۸�\n");
    scanf("%f",&wyr[count].price);
    printf("�����Ƿ�����  ��  ��  \n");
    scanf("%s",wyr[count].use);
    count++;

}


void output(struct room wyr[M])     //�Զ����������
{
    int j;
    system("cls");
    if (count==0)
    {
        printf("��ǰ������ϢΪ0��\n");
        return;
    }

        printf("�����\t\t����\t\t����\t�۸�\t�Ƿ�����\n");
        for (j=0; j<count; j++)
        {
            printf("%s\t",wyr[j].num);
            printf("%d\t\t",wyr[j].siz);
            printf("%s\t",wyr[j].level);
            printf("%.2f\t\t",wyr[j].price);
            printf("%s\n",wyr[j].use);

        }

}


    void lookfor(struct room wyr[M])                   //�Զ����ѯ������Ϣ����
    {
        int j,flag=0;
        char xh[6];
        system("cls");
        if (count==0)
        {
            printf("��ǰ�Ѵ淿����ϢΪ0��\n");
            return;
        }
        else
        {
            printf("�����뷿���\n");
            scanf("%s",&xh);
            fflush(stdin);
            for (j=0; j<count; j++)
            {
                if (strcmp(wyr[j].num,xh)==0)
                {
                    printf("�����\t\t����\t\t����\t�۸�\t�Ƿ����\n");
                    printf("%s\t",wyr[j].num);
                    printf("%d\t\t",wyr[j].siz);
                    printf("%s\t",wyr[j].level);
                    printf("%.2f\t\t",wyr[j].price);
                    printf("%.2f\n",wyr[j].use);
                    flag=1;
                }
            }
            if (flag!=1)
                printf("�ܱ�Ǹ,û�д˷�����Ϣ\n");
        }
    }



    void modify(struct room wyr[M])    //�Զ����޸ĺ���
    {
        int j,flag=0,course;
        char xh[6];
        system("cls");
        if (count==0)
        {
            printf("��ǰ�Ѵ淿����ϢΪ0��,�޷��޸�!!!\n");
            return;
        }
        else
        {
            printf("��������Ҫ�޸ĵķ����(��_��)\n");
            scanf("%s",xh);
            fflush(stdin);
            for (j=0; j<count; j++)
                if (strcmp(wyr[j].num,xh)==0)
                {
                    printf("ѡ��:1  ����\t  2  ����\t  3  �۸�\t  4  �Ƿ�����\n");
                    scanf("%d",&course);
                    printf("����������Ҫ�޸ĺ�ķ�����Ϣ\n");
                    switch(course)
                    {
                    case 1:
                        scanf("%d",&wyr[j].siz) ;
                        break;
                    case 2:
                        scanf("%s",wyr[j].level);
                        break;        //switch�������
                    case 3:
                        scanf("%f",&wyr[j].price) ;
                        break;
                    case 4:
                        scanf("%s",wyr[j].use);
                        break;
                    default:
                        printf("��Ч��ѡ��!!!����������!!!\n");
                        break;
                    }
                }
        }
    }


    void delete_student(struct room wyr[M])        //�Զ���ɾ������
    {
        int choice;
        system("cls");
        if (count==0)
        {
            printf("��ǰ�Ѵ淿����ϢΪ0��,�޷�ɾ��!!!\n");
            return;
        }
        else
        {
            printf("�Ƿ�Ҫɾ��:1��ȷ��2��ȡ��\n");
            scanf("%d",&choice);
            switch(choice)            //switch�����û�Ҫɾ���ķ�ʽ����ѡ��
            {
            case 2:
                return;
                break;
            case 1:
                fangjianhao(wyr);
                break;
            default:
                printf("��Ч��ѡ��!!!����������!!!\n");
                break;
            }
        }
    }



    void fangjianhao(struct room wyr[M])           //�Զ���ɾ��������Ϣ����
    {
        int j,k=count;
        char xh[6];
        system("cls");
        printf("����������Ҫɾ���ķ����\n");
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
                    printf("���Ѿ�ɾ���ɹ�\n");
            }

        }
        if (j==count)
            printf("��Ǹ,�޷�����Ϣ!\n");
    }



