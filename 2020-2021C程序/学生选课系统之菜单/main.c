#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <ctype.h>
void check()//������
{
    int ff=62;//��������������д
    unsigned a[]=
    {
        659,659,698,784,
        784,698,659,587,
        523,523,587,659,
        659,587,587,
        659,659,698,784,
        784,698,659,587,
        523,523,587,659,
        587,523,523,
        587,659,523,587,659,698,659,523,
        587,659,698,659,587,
        523,587,392,659,
        659,659,698,784,
        784,698,659,587,
        523,523,587,659,
        587,523,523,

        //����
    };
    unsigned b[]=
    {
        400,400,400,400,
        400,400,400,400,
        400,400,400,400,
        600,200,800,
        400,400,400,400,
        400,400,400,400,
        400,400,400,400,
        600,200,800,
        600,400,400,
        400,200,200,400,400,
        400,200,200,400,400,
        400,400,400,400,
        400,400,400,400,
        400,400,400,400,
        400,400,400,400,
        600,400,800,
        //����
    };
    for(int i=0; i<ff/2; i++)
    {
        // printf("��%d������\n",i+1);//��ʾ�������Ҵ�
        Beep(a[i],b[i]);
    }
}
void PengYou()//����
{
    int ff=131;
    unsigned a[]=
    {
        0,587,659,523,587,659,587,659,784,
        880,784,659,659,587,659,523,587,659,392,587,659,
        587,440,523,
        587,659,523,587,659,523,587,659,
        784,784,880,523,440,523,
        587,587,523,440,440,523,
        587,659,587,523,587,587,659,587,523,
        523,587,587,659,523,587,659,
        784,784,784,880,523,440,523,
        587,587,523,440,440,392,440,
        523,0,
        659,659,784,
        784,784,784,880,784,880,988,
        1046,880,880,784,659,659,587,523,
        523,880,784,659,587,523,
        523,440,587,659,659,784,
        784,784,784,880,784,880,988,
        1046,880,880,784,659,659,587,523,
        523,880,784,659,587,523,
        440,440,523,523,

    };
    unsigned b[]=
    {
        900,450,450,900,450,450,900,450,450,
        900,450,450,900,450,450,900,450,450,900,450,450,
        900,450,4950,
        450,450,900,450,450,900,450,450,900,450,450,900,450,450,
        900,450,450,900,450,450,
        450,450,450,225,225,900,450,225,225,
        900,450,225,225,900,450,450,
        900,450,225,225,900,450,450,
        900,450,225,225,900,450,450,
        1800,900,
        450,225,225,
        450,450,450,225,1125,450,450,
        450,450,450,225,1125,450,225,1125,
        450,225,1125,450,225,1125,
        225,225,1350,450,225,225,
        450,450,450,225,1125,450,450,
        450,450,450,225,1125,450,225,1125,
        450,225,1125,450,225,1125,
        450,225,675,1350,
    };
    for(int i=0; i<ff/2; i++)
    {
        //printf("��%d������\n",i);
        Beep(a[i],b[i]);
    }
}
int work (int x,int i)
{
    int y;
    y = x/(int)(pow(10,i-1)+0.5)%10;
    return y;
}
typedef struct xy
{
    int x[3];
    int y[3];
} XY;
//�γ���Ϣ�ṹ��
typedef  struct course
{
    int num;               //�γ̱��
    int score;               //�γ�ѧ��
    int  totalPeriod;            //ÿ����ѧʱ
    int  classPeriod;    //ÿ����ѧʱ��ʵ������һ��Σ�����ô��Ĵ�����
    int  week;             //������
    int people;           //������ѡ�������
} COURSE;
//ѧ��ѡ����Ϣ�ṹ��
typedef  struct student
{
    int stuNo;              //ѧ��ż��Ϊ�У�����ΪŮ��
    int num[6];         //��ѡ�γ̱��0��ʾû��ѡ����0��ʾѡ��
    int score;        //����Ҫѡ��ѧ��
} STUDENT;
//�γ����ƣ���Ϊ�������������ݣ��������ط�Ҫ�ã����н�������Ϊȫ�ֱ���
char name[6][26]= { "operations research","database","java","visual computing","computing system","algorithm design analysis"};
char name2[6][26]= { "�˳�ѧ","���ݿ�","Java","���ӻ�","����ϵͳ","�㷨���"};
void readfile (COURSE cour[],STUDENT stu[])//��ȡ�ļ���Ϣ�����ڽṹ��������
{
    FILE *fp;
    int n,m;
    int i,j;
    if((fp=fopen("data.txt","r"))==NULL)
    {
        printf("��ʧ��");
        exit(0);
    }
    fscanf(fp,"%d",&n);
    fscanf(fp," %d",&m);
    for(i=0; i<6; i++)
    {
        fscanf(fp," %d",&cour[i].num);
        fscanf(fp," %d",&cour[i].score);
        fscanf(fp," %d",&cour[i].classPeriod);
        fscanf(fp," %d",&cour[i].totalPeriod);
        fscanf(fp," %d",&cour[i].week);
        fscanf(fp," %d",&cour[i].people);
    }
    for(i=0; i<4; i++)
    {
        fscanf(fp," %d",&stu[i].stuNo);
        for(j=0; j<6; j++)
        {
            fscanf(fp," %d",&stu[i].num[j]);
        }
        fscanf(fp," %d",&stu[i].score);
    }
    fclose(fp);
}
void writefile (COURSE cour[],STUDENT stu[])//���ṹ����Ϣд���ļ�
{
    int i,j;
    int n=4,m=6;
    FILE *fp;
    if((fp=fopen("data.txt","w"))==NULL)
    {
        printf("��ʧ��");
        exit(0);
    }
    fprintf(fp,"%d %d",n,m);
    for(i=0; i<6; i++)
    {
        fprintf(fp," %d %d %d %d %d %d",cour[i].num,cour[i].score,cour[i].classPeriod,cour[i].totalPeriod,cour[i].week,cour[i].people);
    }
    for(i=0; i<4; i++)
    {
        fprintf(fp," %d",stu[i].stuNo);
        for(j=0; j<6; j++)
        {
            fprintf(fp," %d",stu[i].num[j]);
        }
        fprintf(fp," %d",stu[i].score);
    }
    fclose(fp);
}
void writepassword (char password[][26],int n)//������д���ļ�
{
    int i;
    FILE *fp;
    if((fp=fopen("password.txt","w"))==NULL)
    {
        printf("��ʧ��");
        exit(0);
    }
    for(i=0; i<n; i++)
        fprintf(fp,"%s ",password[i]);
    fclose(fp);
}
void readpassword (char password[][26],int n)//���ļ��ж�ȡ����
{
    int i;
    FILE *fp;
    if((fp=fopen("password.txt","r"))==NULL)
    {
        printf("��ʧ��");
        exit(0);
    }
    for(i=0; i<n; i++)
    {
        fscanf(fp,"%s",password[i]);
    }
    fclose(fp);
}
void writejn(void)//����һ��������־���ı��ļ�
{
    FILE *fp;
    if((fp=fopen("1.txt","w"))==NULL)
    {

        printf("��ʧ��");
        exit(0);
    }
    fprintf(fp,"������ʱ�� �γ� ѧ�� ����\n");
    fclose(fp);
}
void addjournal(char *t,int i,int num,int n)//����־�м�������Ϣ,�����ֱ���ʱ�䣬�γ̱��,ѧ����ţ�ѧ���Ĳ���
{
    FILE *fp;
    if((fp=fopen("1.txt","a"))==NULL)
    {
        printf("��ʧ��");
        exit(0);
    }
    fprintf(fp,"%s",t);
    fprintf(fp,"  %s ",name[i]);
    fprintf(fp,"%d",num);
    if(n) fprintf(fp," ѡ��\n");
    else fprintf(fp," �˿�\n");
    fclose(fp);
}
int correct(void)//����ʵ������ж�
{
    int i=1,flag=0;
    char num;
    while(i++<6) //��������
    {
        num=getch();//���η������û������ģ���û��������ݣ�ֻ�е���
        if(num==8)//����������������ʾ���û�,8��Ϊ�����û���ɾ��
        {
            putchar(8);//��ʾ���û�
            putchar(32);
            putchar(8);
        }
        else if (num=='1')
        {
            flag=1;
            putchar(num);
        }
        else if (num=='0')
        {
            flag=0;
            putchar(num);
        }
        else
        {
            if(num==13)//�س���Ϊ������׼
            {
                goto END;
            }
            else//�Ե��Ƿ�����
            {
                putchar(32);//�ո�
                putchar(8);//�˸�
                putchar(32);//�ո�
                putchar(8);//�ٴ��˸�
            }
        }
    }
END:
    return flag;
}
char* hide (int lazy)//����ʵ����Ϣ����
{
    char num[26];
    int i=0;
    char *pstr=num;
    int n;
START:

    for(i=0; i<25; i++) //��������
    {
        num[i]=getch();//���η������û������ģ���û��������ݣ�ֻ�е���
        if((num[i]>='0'&&num[i]<='9')||num[i]==8||(num[i]>='a'&&num[i]<='z')||(num[i]>='A'&&num[i]<='Z'))//����������������ʾ���û�,8��Ϊ�����û���ɾ��
        {
            if(num[i]==8)
            {
                i-=2;
                putchar(8);
                putchar(32);
                putchar(8);
            }
            else
            {
                putchar('*');//��ʾ���û�
            }
        }
        else
        {
            if(num[i]==13)//�س���Ϊ������׼
            {
                goto END;
            }
            else//�Ե��Ƿ�����
            {
                putchar(32);//�ո�
                putchar(8);//�˸�
                putchar(32);//�ո�
                putchar(8);//�ٴ��˸�
                i--;
            }
        }
    }
END:
    num[i]='\0';
    if(!lazy)
    {
        printf("\n�������޴���,������밴1��û�а�0\n");
        Sleep(1000);
        if(correct())
            goto START;
    }

    return pstr;
}
int correctint(int lazy)//�������û�������ͨ������

{
    char num[9];
    int i=0;
    char *pstr=num;
    int n,flag;
START:

    for(i=0; i<8; i++) //��������
    {
        num[i]=getch();//���η������û������ģ���û��������ݣ�ֻ�е���
        if(num[i]>='0'&&num[i]<='9'||num[i]==8||num[i]==' ')//����������������ʾ���û�,8��Ϊ�����û���ɾ��
        {
            putchar(num[i]);//��ʾ���û�
            if(num[i]==8)
            {
                i-=2;
                putchar(32);
                putchar(8);
            }
        }
        else
        {
            if(num[i]==13)//�س���Ϊ������׼
            {
                goto END;
            }
            else//�Ե��Ƿ�����
            {
                putchar(32);//�ո�
                putchar(8);//�˸�
                putchar(32);//�ո�
                putchar(8);//�ٴ��˸�
                i--;
            }
        }
    }
    num[8]='\0';
END:
    n=atoi(pstr);

    if(!lazy)
    {
        printf("\n�������޴���,������밴1��û�а�0\n");
        Sleep(1000);
        flag=correct();
        if(flag)
            goto START;
    }
    return n;
}
char* correctchar (int lazy)//�������û��������ù����ֺ��ַ�
{
    char num[26];
    int i=0;
    char *pstr=num;
    int n;
START:

    for(i=0; i<25; i++) //��������
    {
        num[i]=getch();//���η������û������ģ���û��������ݣ�ֻ�е���
        if((num[i]>='0'&&num[i]<='9')||num[i]==8||(num[i]>='a'&&num[i]<='z')||(num[i]>='A'&&num[i]<='Z')||num[i]==' ')//����������������ʾ���û�,8��Ϊ�����û���ɾ��
        {
            putchar(num[i]);//��ʾ���û�
            if(num[i]==8)
            {
                i-=2;
                putchar(32);
                putchar(8);
            }
        }
        else
        {
            if(num[i]==13)//�س���Ϊ������׼
            {
                goto END;
            }
            else//�Ե��Ƿ�����
            {
                putchar(32);//�ո�
                putchar(8);//�˸�
                putchar(32);//�ո�
                putchar(8);//�ٴ��˸�
                i--;
            }
        }
    }
END:
    num[i]='\0';
    if(!lazy)
    {
        printf("\n�������޴���,������밴1��û�а�0\n");
        Sleep(1000);
        if(correct())
            goto START;
    }

    return pstr;
}
int format (const COURSE cour[],const STUDENT stu[],XY pos[])//�������˺����пγ̵���Ϣ��ӡ����Ļ��
{
    system("title ѧ���Ϳγ���Ϣ");
    int flag,k;
    printf("\n\t��0�ص���һ��\n");
    printf("\n\t����������1\n");
    flag=correct();
    if(!flag)
        return 1;
    system("cls");
    int i,j;

    printf("                 �γ�����\t");//15���ո�
    printf("�γ̱���\t");
    printf("�γ̵�ѧ��\t");
    printf("   ʱ��\t");//3���ո�
    printf("        ÿ��ѧʱ\t");//8���ո�
    printf("     ������\t");//4���ո�
    printf(" ʣ������\t");//1���ո�
    printf("\n");
    for(i=0; i<6; i++)
    {
        printf("%-25s\t",name[i]);
        printf("%-8d\t",cour[i].num);
        printf("%-8d\t",cour[i].score);
        printf("%-8d\t",cour[i].classPeriod);
        printf("%-8d\t",cour[i].totalPeriod);
        printf("%-10d\t", cour[i].week);
        printf("%-8d\t",cour[i].people);
        printf("\n");
    }
    printf("\n\n");
    for(i=0; i<4; i++)
    {
        printf("ѧ��ѧ��\t");
        printf("%-8d\t", stu[i].stuNo);
        printf("��ѡ�γ�\t");
        for(j=0; j<6; j++)
            if(stu[i].num[j])
                printf("%-25s",name[j]);
        printf("����Ҫѡ��ѧ��\t");
        printf("%-3d\t",stu[i].score);
        printf("\n");
    }
    printf("\n\tʱ������һ�飬��һ��Ϊ���ڣ��ڶ���Ϊ���ٽڿ�\n");
    system("pause");
    printf("\n\t������޷�����밴1����������0\n");
    flag=correct();
    printf("\n\n");
    if(flag)
    {
        for(k=0; k<6; k++)
        {
            printf("\t%-25s ",name[k]);
            for(j=0; j<cour[k].totalPeriod; j++)
            {
                printf("\t����%-5d", pos[k].y[j]);
                printf("��%-2d�� \t",pos[k].x[j]);
            }
            printf("\n");
        }
    }
    printf("\n\t��0�ص���һ��\n");
    printf("\n\t�˳�ϵͳ��1\n");
    flag=correct();
    if(flag)
        return 0;
    else
        return 1;
}
int journal (int lazy,COURSE cour[],STUDENT stu[],int i,int n,int d)//�����ֱ����Ƿ�ʡ�ԣ��γ̣�ѧ�����飬�γ�λ��,ѧ����������
{
    system("title ��������");
    system("cls");
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo=localtime(&rawtime);
    char *s=asctime(timeinfo);
    addjournal(s,i,stu[n].stuNo,d);
    return 0;
}
int change(char password[][26],int n,int lazy)//��������
{
    system("title �޸�����");
    char str[26];
    char newstr[26];
    char last[26];
    int i,k,flag;
    printf("------------------------------------��������(���벻�ɴ��ո�)\n");
    printf("\n\t������һ����0\n");
    printf("\n\t����������1\n");
    flag=correct();
    if(!flag)
        return 0;
START:
    system("cls");
    printf("\n\t���������������벻�ɼ��밴1����0\n");
    k=correct();
    if(!k)
    {
        printf("\n\t������ԭ����\n");
        strcpy(last,correctchar(lazy));
        printf("\n\t���������������\n");
        strcpy(str,correctchar(lazy));
        printf("\n\t���ٴ��������������\n");
        strcpy(newstr,correctchar(lazy));
    }
    else
    {
        printf("\n\t������ԭ����\n");
        strcpy(last,hide(lazy));
        printf("\n\t���������������\n");
        strcpy(str,hide(lazy));
        printf("\n\t���ٴ��������������\n");
        strcpy(newstr,hide(lazy));
    }
    if(strcmp(last,password[n])==0)
    {
        if(strcmp(str,newstr)==0)
        {
            strcpy(password[n],newstr);
            system("pause");
        }
        else
        {
            printf("\n\t�������벻��ͬ,��������ٴ����룬�밴1���˳��밴0\n");
            flag=correct();
            if(flag)
                goto START;
        }
    }
    else
    {
        printf("\n\tԭ�������������������ٴ����룬�밴1���˳��밴0\n");
        flag=correct();
        if(flag)
            goto START;
    }
    system("cls");
    printf("\n\t�ı�ɹ���\n");
    return 1;
}
int passwords (char password[][26],int m,int lazy)//����������
{
    int number;
    int count=0;
    int n[5]= {2020,2020201,2020202,2020203,2020104};
    char ps[26];
    int i,k;
    printf("\t�����·����������˺�������\n");
NUMBER:
    printf("\n�˺�:\n");
    number=correctint(lazy);
    printf("\n���������������벻�ɼ��밴1����0(Ĭ�ϲ��ɼ�)\n");
    k=correct();
    printf("\n����:\n");
    if(k)
    {
        strcpy(ps,hide(lazy));
    }
    else
    {
        strcpy(ps,correctchar(lazy));
    }
    for(i=0; i<5; i++)
    {
        if(number==n[i])
        {
            if(strcmp(password[i],ps)==0)
                return i;
        }
    }
    printf("\n�˺Ż������������,��0�˳�ϵͳ����1��������\n");
    int a;
    a=correct();
    if(a)
    {
        if(count++<5)
            goto NUMBER;
        else
        {
            printf("\n���������������࣬��1�����Ժ�����\n");
            Sleep(60*1000);
        }
    }
    else
        return -1;
}
int   choose (int lazy,COURSE cour[],STUDENT stu[],int n)//ѡ�λ����˿�
{
    system("title ѡ�λ��˿�");
    int flag;
    int number;//�γ̱��
    char *s;//�γ�����
    int i,k,j;
    printf("\t��0�ص���һ��\n");
    printf("\t����������1\n");
    flag=correct();
    if(!flag)
        return 1;
START:
    system("cls");
    printf("\n\t��������Ҫѡ/�˵Ŀε�\n");
    printf("\n\t���ƣ���0��\n");
    printf("\n\t��ţ���1��\n");
    flag=correct();
    printf("\n\t��������������ƻ��Ű�1�鿴��û�����ǰ�0��������\t\n");
    if(correct())
    {
         printf("                 �γ�����\t");//15���ո�
    printf("�γ̱���\t");
    printf("�γ̵�ѧ��\t");
    printf("   ʱ��\t");//3���ո�
    printf("        ÿ��ѧʱ\t");//8���ո�
    printf("     ������\t");//4���ո�
    printf(" ʣ������\t");//1���ո�
    printf("\n");
    for(i=0; i<6; i++)
    {
        printf("%-25s\t",name[i]);
        printf("%-8d\t",cour[i].num);
        printf("%-8d\t",cour[i].score);
        printf("%-8d\t",cour[i].classPeriod);
        printf("%-8d\t",cour[i].totalPeriod);
        printf("%-10d\t", cour[i].week);
        printf("%-8d\t",cour[i].people);
        printf("\n");
    }
    printf("\n\n");
    }
    if(flag)
    {
        printf("\n\t������γ̱��\n");
        number=correctint(lazy);
        printf("\n\n");
        for(i=0; i<6; i++)
        {
            if(number==cour[i].num)
            {
FIRST:
                system("pause");//������ͣ����ֹ̫�쿴����
                system("cls");//��ֹ��Ϣ����
                printf("\n\n");//��ӡ���ſε���Ϣ
                printf("                 �γ�����\t");//15���ո�
                printf("�γ̱���\t");
                printf("�γ̵�ѧ��\t");
                printf("   ʱ��\t");//3���ո�
                printf("        ÿ��ѧʱ\t");//8���ո�
                printf("     ������\t");//4���ո�
                printf(" ʣ������\n");//1���ո�
                printf("%25s\t",name[i]);
                printf("%8d\t",cour[i].num);
                printf("%8d\t",cour[i].score);
                printf("%8d\t",cour[i].classPeriod);
                printf("%8d\t",cour[i].totalPeriod);
                printf("%8d\t", cour[i].week);
                printf("%3d\t",cour[i].people);
                printf("\n");
                //����Ϊѡ�����˿β���
                printf("\t��1ѡ��\n");
                printf("\t��2�˿�\n");
                printf("\t��0�˳�\n");
                flag=correctint(lazy);
                if(flag==1)
                {
                    if(stu[n].score<-5)//��ֹһ����ѡ̫���
                    {
                        printf("\n\t�Բ�����ѡ��̫����\t\n");
                        goto END;
                    }
                    if(!stu[n].num[i]&&cour[i].people>0)//ѧ��ûѡ��ڿΣ���ڿλ���ѡ
                    {

                        srand((int)time(NULL));
                        if(rand()%2+0)//ѡ�γɹ���ת����־���汣��
                        {
                            cour[i].people--;//�γ�������1
                            stu[n].score=stu[n].score-cour[i].score;//ѧ����ѧ�ּ�ȥ�γ̵�ѧ��
                            stu[n].num[i]++;//��ʾѧ��ѡ��ʲô��
                            journal(lazy,cour,stu,i,n,1);//���浽�γ���־
                            printf("\n\t����һ�����˶���ѡ������ڿΣ�\n\t");
                            check();
                            system("pause");
                            goto END;
                        }
                        else//����
                        {
                            printf("\n\t����һЩ����֪��ԭ����û��ѡ�ϿΣ�����������3����\n");
                            PengYou();
                            static const unsigned int  table[] =
                            {

                                0x00000000, 0x00000000, 0x000FF000, 0x00300C00,
                                0x00C00300, 0x01000080, 0x02000040, 0x04000020,
                                0x08700E10, 0x098C3190, 0x127E4FC8, 0x118C3188,
                                0x20000004, 0x20000004, 0x20000004, 0x20000004,
                                0x24000024, 0x24000024, 0x24000024, 0x22000044,
                                0x12000048, 0x11000088, 0x09000090, 0x08800110,
                                0x04600620, 0x02181840, 0x0107E080, 0x00C00300,
                                0x00300C00, 0x000FF000, 0x00000000, 0x00000000,

                            };
                            for(int y = 0; y < 32; ++y)
                            {

                                for(int x = 0; x < 64; ++x)
                                {

                                    putchar((table[y] & (1 << (x >> 1))) ? 'X' : ' ');

                                }
                                putchar('\n');
                                system("pause");
                                system("cls");
                                goto START;
                            }
                        }

                    }
                    else//��������ж�
                    {
                        printf("\n\t�����ظ�ѡͬһ�ڿΣ�������ڿ��Ѿ�����ѡ��\n");
                        printf("\n\t����3���ص�ѡ�ν���\n");
                        Sleep(3*1000);
                        system("cls");
                        goto START;
                    }
                }
                else if (flag==2)//�˿�
                {
                    printf("%d\n",stu[n].num[i]);
                    if(stu[n].num[i]<=0)//��ֹûѡ���˿�
                    {
                        printf("\n�㻹ûѡ��!\n");
                        printf("\n����3���ص�ѡ�ν���\n");
                        Sleep(3*1000);
                        system("cls");
                        goto START;
                    }
                    else//ѡ�˿�����
                    {

                        srand((int)time(NULL));
                        if(rand()%2+0)//�˿γɹ�
                        {
                            cour[i].people++;
                            stu[n].score=stu[n].score+cour[i].score;
                            stu[n].num[i]--;
                            journal(lazy,cour,stu,i,n,0);
                            printf("\n�˿γɹ�\n");
                            check();
                            goto END;
                        }
                        else//ģ����������
                        {
                            printf("\n\t����һЩ����֪��ԭ�����˲��˿��ˣ�����������3����\n");
                            PengYou();
                            static const unsigned int  table[] =
                            {

                                0x00000000, 0x00000000, 0x000FF000, 0x00300C00,
                                0x00C00300, 0x01000080, 0x02000040, 0x04000020,
                                0x08700E10, 0x098C3190, 0x127E4FC8, 0x118C3188,
                                0x20000004, 0x20000004, 0x20000004, 0x20000004,
                                0x24000024, 0x24000024, 0x24000024, 0x22000044,
                                0x12000048, 0x11000088, 0x09000090, 0x08800110,
                                0x04600620, 0x02181840, 0x0107E080, 0x00C00300,
                                0x00300C00, 0x000FF000, 0x00000000, 0x00000000,

                            };
                            for(int y = 0; y < 32; ++y)
                            {

                                for(int x = 0; x < 64; ++x)
                                {

                                    putchar((table[y] & (1 << (x >> 1))) ? 'X' : ' ');

                                }
                                putchar('\n');
                                Sleep(1000*3);
                                system("cls");
                                goto START;
                            }
                        }
                    }
                }
                else if(flag==0)
                {
                    goto END;
                }
                else
                {
                    printf("\n\t�������3������������\n");
                    Sleep(3*1000);
                    system("cls");
                    goto START;
                }
            }
        }
        printf("\n\tδ�ҵ���\n");
        printf("\n\t����3�������ѡ�ν���\n");
        Sleep(3*1000);
        system("cls");
        goto START;
    }
    else
    {
        printf("\n\t������γ�����(ȫ��Сд�����ʷָ���һ���ո�)\n");
        char *pt=correctchar(lazy);
        for(i=0; i<6; i++)
        {
            if(strcmp(pt,name[i])==0)
            {
                goto FIRST;
            }
        }
        printf("\n\tδ�ҵ���\n");
        printf("\n\t����3�������ѡ�ν���\n");
        Sleep(3*1000);
        system("cls");
        goto START;
    }
END:
    system("pause");
    printf("\n\t��1�ص���һ��\n");
    printf("\n\t����������0\n");
    flag=correct();
    if(flag)
        return 1;
    else
        return 0;
    return 0;
}
int  search (int lazy,COURSE cour[])//�ҿΣ�ͨ�����ƣ���ţ�ѧ��
{
    system("title ���ҿγ�");
    int flag;
    printf("\n\t��0�ص���һ��\n");
    printf("\n\t����������1\n");
    flag=correct();
    if(!flag)
        return 1;
    system("cls");
    int a;
    char s[26];
    int i,k,label=1;
    system("cls");
    START:
    system("cls");
    printf("\n\t��ѡ�������ѯ�ķ�ʽ��\n1.�γ����Ʋ�ѯ\n2.�γ̱�Ų�ѯ\n3.ѧ�ֲ�ѯ\n4.��ѧʱ��ѯ\n5.�˳�ϵͳ\n6.������һ��\n��ѡ�����:\t\n");
    a=correctint(lazy);
    switch(a)
    {
    case 1:
        printf("\n����γ�����:(���ʼ���һ���ո���Ϊ�ָ�,������Сд)\n");
        strcpy(s,correctchar(lazy));
        for(i=0; i<6; i++)
        {
            if(strcmp(s,name[i])==0)
            {
                printf("\n\t----------------------------------------------------------------\n");
                printf("�γ̱�ţ�%d|---�γ�ѧ�֣�%d|---ÿ����ѧʱ��%-6d|---�����ܣ�%d|\n",cour[k].num,cour[k].score,cour[k].classPeriod,cour[k].week);
                label=0;
            }
        }
        if(label)
        {
            printf("\nδ�ҵ�������2�����ת��ѡ��ҳ��\n");
            goto START;
        }
       printf("\n\t---------------------------------------------------------------------------------\n");
        printf("\n�Ƿ������ѯ1����0�˳�\n");
            flag=correct();
            if(flag) goto START;
            else goto END;
        break;
    case 2:
        system("cls");
        printf("\n\t����γ̱��:\n");
        a=correctint(lazy);
        printf("\n\t---------------------------------------------------------------------------------\n");
        for(i=0; i<6; i++)
        {
            if(a==cour[i].num)
            {
                printf("�γ����ƣ�");
                printf("%-25s|",name[i]);
                printf("---�γ�ѧ�֣�%-8d|---ÿ����ѧʱ��%-6d|---�����ܣ�%-2d|\n",cour[i].score,cour[i].classPeriod,cour[i].week);
                label=0;
            }
            if(label)
            {
                printf("\nδ�ҵ�������2�����ת��ѡ��ҳ��\n");
                Sleep(1000*2);
                goto START;
            }
            system("pause");
            printf("\n\t---------------------------------------------------------------------------------\n");
            printf("\n�Ƿ������ѯ1����0�˳�\n");
            flag=correct();
            if(flag) goto START;
            else goto END;
        }
        break;
    case 3:
        system("cls");
        printf("\n\t����������ѧ��:\n");
        a=correctint(lazy);
        printf("\n\t----------------------------------------------------------------------------------------\n");
        for(i=0; i<6; i++)
        {
            if(a==cour[i].score)
            {
                printf("�γ����ƣ�");
                printf("%-25s|",name[i]);
                printf("---�γ̱�ţ�%-8d|---ÿ����ѧʱ��%-6d|---�����ܣ�%-2d|\n",cour[i].num,cour[i].totalPeriod,cour[i].week);
                label=0;
            }
        }
        if(label)
        {
            printf("\nδ�ҵ�������2�����ת��ѡ��ҳ��\n");
            Sleep(1000*2);
            goto START;
        }
        system("pause");
        printf("\n\t---------------------------------------------------------------------------------\n");
        printf("\n�Ƿ������ѯ1����0�˳�\n");
        flag=correct();
        if(flag) goto START;
        else goto END;
        break;
    case 4:
        system("cls");
        printf("\n\t�γ̰���ÿ��2ѧʱ�γ̺�ÿ��3ѧʱ�γ�\n");
        a=correctint(lazy);
        if(a!=2||a!=3)
        {
            printf("\n�������������\n");
            goto START;
        }
        printf("\n\t--------------------------------------------------------------------------------------\n");
        for(i=0; i<6; i++)
        {
            if(a==cour[i].classPeriod)
            {
                printf("�γ����ƣ�");
                printf("%-25s|",name[i]);
                printf("---�γ̱�ţ�%-8d|---�γ�ѧ�֣�%-6d|---�����ܣ�%-2d|\n",cour[i].num,cour[i].score,cour[i].week);
                label=0;
            }
        }
        if(label)
        {
            printf("\n\tδ�ҵ�������2�����ת��ѡ��ҳ��\n");
            goto START;
        }
        system("pause");
        printf("\n\t---------------------------------------------------------------------------------\n");
        printf("\n\t�Ƿ������ѯ1����0�˳�\n");
        flag=correct();
        if(flag) goto START;
        else goto END;
        break;
    case 5:
        exit(0);
        break;
    case 6:
        goto END;
        break;
    default:
        printf("\n\t�������,����3�������ѡ��ҳ��\n");
        Sleep(1000*3);
        goto START;
    }
END:
    printf("\n\t��0�ص���һ��\n");
    printf("\n\t�˳�ϵͳ��1\n");
    flag=correct();
    if(!flag)
        return 1;
    system("cls");
    return 0;
}
int scan(int lazy,int n,STUDENT stu[])//ѧ������Լ�����Ϣ
{
    system("title �����Ϣ");
    int flag,j;
    printf("\n\t��0�ص���һ��\n");
    printf("\n\t����������1\n");
    flag=correct();
    if(!flag)
        return 1;
    system("cls");
    printf("\t�����Ϣ���£�\n");
    printf("ѧ��ѧ��\t");
    printf("%d\t",stu[n].stuNo);
    printf("\n��ѡ�γ�\t");
    for(j=0; j<6; j++)
        if(stu[n].num[j])
            printf("\n\t%-25s\t\n",name[j]);
    printf("\n����Ҫѡ��ѧ��\t");
    printf("%d\t",stu[n].score);
    printf("\n");
    system("pause");
    printf("\n\t��1�ص���һ��\n");
    printf("\n\t�˳�ϵͳ��0\n");
    flag=correct();
    if(flag)
        return 1;
    else
        return 0;
}
void trans (COURSE cour[],XY pos[])
{
    int k,i;
    for(k=0; k<6; k++)
    {
        for(i=0; i<cour[k].totalPeriod*2; i++)
        {

            if((i+1)%2)
            {
                pos[k].y[cour[k].totalPeriod-(i+1)/2-1]=work(cour[k].classPeriod,i+1);
            }
            else
            {
                pos[k].x[cour[k].totalPeriod-(i+2)/2]=work(cour[k].classPeriod,i+1);
            }
        }
    }
}
int  timetable(int lazy,int n,COURSE cour[],STUDENT stu[])//�α��ӡ
{
    system("title �α�");
    int flag;
    printf("\n\t��0�ص���һ��\n");
    printf("\n\t����������1\n");
    flag=correct();
    if(!flag)
        return 1;
    system("cls");
    XY pos[6];
    trans(cour,pos);
    char cl[100][26];
    int i,j,k;
    char pr[8][9][26];
    char s0[26]="       ";
    for(i=0; i<9; i++)
    {
        for(j=0; j<8; j++)
        {
            strcpy(pr[i][j],s0);
        }
    }
    for(i=0; i<6; i++)
    {
        if(stu[n].num[i])
        {
            for(k=0; k<cour[i].totalPeriod; k++)
            {
                strcpy(pr[pos[i].x[k]][pos[i].y[k]],name2[i]);
            }
        }
    }

    strcpy(pr[0][0],"    ");
    strcpy(pr[1][0],"     ����һ");
    strcpy(pr[2][0],"      ���ڶ�");
    strcpy(pr[3][0],"     ������");
    strcpy(pr[4][0],"     ������");
    strcpy(pr[5][0],"     ������");
    strcpy(pr[6][0],"    ������");
    strcpy(pr[7][0],"     ������");
    strcpy(pr[0][1],"��һ��");
    strcpy(pr[0][2],"�ڶ���");
    strcpy(pr[0][3],"������");
    strcpy(pr[0][4],"���Ľ�");
    strcpy(pr[0][5],"�����");
    strcpy(pr[0][6],"������");
    strcpy(pr[0][7],"���߽�");
    strcpy(pr[0][8],"�ڰ˽�");

    for(i=0; i<8; i++)
        printf("%s",pr[i][0]);
    printf("\n");
    printf("\n");
    for(j=1; j<8; j++)
    {
        for(i=0; i<8; i++)
        {
            printf("%s    ",pr[i][j]);

        }
        printf("\n");
        printf("\n");

    }
    system("pause");
    printf("\n\t��0�ص���һ��\n");
    printf("\n\t�˳�ϵͳ��1\n");
    flag=correct();
    if(!flag)
        return 1;
    system("cls");

    return 0;
}
int  lookjournal (int lazy,int n)//�鿴��־
{

    system("title ��־");
    int flag;
    printf("\n\t��0�ص���һ��\n");
    printf("\n\t����������1\n");
    flag=correct();
    if(!flag)
        return 1;
    system("cls");
    system("type D:\\CBproject\\ѧ��ѡ��ϵͳ֮�˵�\\1.txt");
    system("pause");
    printf("\n\t��0�ص���һ��\n");
    printf("\n\t�˳�ϵͳ��1\n");
    flag=correct();
    if(!flag)
        return 1;
    system("cls");
    return 0;
}
int changestudent(int lazy,int n,STUDENT stu[],COURSE cour[])//�ı�ѧ�������Ϣ
{
    system("title ѧ����Ϣ�޸�");
    int flag;
    printf("\n\t��0�ص���һ��\n");
    printf("\n\t����������1\n");
    flag=correct();
    if(!flag)
        return 1;
START:
    system("cls");
    printf("\n\t��ѡ��Ҫ�޸�˭����Ϣ(��������)�˳��밴0\n");
    flag=correctint(lazy);
    if(flag==0)
        goto EXIT;
    int i,k,m=0;
    for(i=0; i<4; i++)
    {
        if(flag==stu[i].stuNo)
        {
CHANGE:
            system("cls");
            printf("------------------------------------------------------�����޸�ʲô��Ϣ��\n");
            printf("------------------------------------------------------��0�˳�ҳ��\n");
            printf("------------------------------------------------------ѧ��ѡ�ΰ�1\n");
            printf("------------------------------------------------------ѧ���˿ΰ�2\n");
            printf("------------------------------------------------------ѧ��ѧ���޸İ�3\n");
            flag=correctint(lazy);
            switch(flag)
            {
            case 1:
                m++;
            case 2:
                printf("\n��ѡ���ǿγ̵����ƣ�0�����ţ�1��\n");
                flag=correct();
                if(flag)
                {
                    printf("\n��������\n");
                    flag=correctint(lazy);
                    for(k=0; k<6; k++)
                    {
                        if(flag==cour[k].num)
                        {
                            printf("\n��ȷ��1ȷ��0�˳�\n");
                            flag=correct();
                            if(flag)
                            {
                                if(!m)
                                {
                                    cour[i].people++;
                                    stu[n].score=stu[n].score+cour[i].score;
                                    stu[n].num[i]--;
                                    printf("\n\t�޸ĳɹ�\n");
                                    Sleep(1000*2);
                                    system("cls");
                                    goto CHANGE;
                                }
                                else
                                {
                                    cour[i].people--;//�γ�������1
                                    stu[n].score=stu[n].score-cour[i].score;//ѧ����ѧ�ּ�ȥ�γ̵�ѧ��
                                    stu[n].num[i]++;//��ʾѧ��ѡ��ʲô��
                                    printf("\n\t�޸ĳɹ�\n");
                                    Sleep(1000*2);
                                    system("cls");
                                    goto CHANGE;
                                }

                            }
                            else
                            {
                                goto CHANGE;
                            }
                        }
                    }
                    printf("\nδ�ҵ�������ת��ԭ�����棡\n");
                    goto CHANGE;
                }
                else
                {
                    printf("\n����������\n");
                    char *s;
                    strcpy(s,correctchar(lazy));
                    for(k=0; k<6; k++)
                    {
                        if(strcmp(s,name[k]))
                        {
                            printf("\n��ȷ����1����������0���޸�\n");
                            flag=correct();
                            if(flag)
                            {
                                cour[i].people++;
                                stu[n].score=stu[n].score+cour[i].score;
                                stu[n].num[i]--;
                                printf("�޸ĳɹ���");
                                system("pause");
                                goto EXIT;
                            }
                            else
                            {
                                goto CHANGE;
                            }
                        }
                    }
                    printf("\nδ�ҵ�������ת��ԭ�����棡\n");
                    system("cls");
                    goto CHANGE;

                }
                break;
            case 3:
CHANGE3:
                system("cls");
                printf("\n����������Ҫ��ֵ\n");
                stu[i].score=correctint(lazy);
                printf("\n�����������޸ĸ�ѧ������Ϣ��0\n");
                printf("\n������޸ı��ѧ������Ϣ��1\n");
                printf("\n������˳�ϵͳ��2\n");
                flag=correctint(lazy);
                switch(flag)
                {
                case 1:
                    goto START;
                    break;
                case 2:
                    goto  EXIT;
                    break;
                case 0:
                    goto CHANGE;
                    break;
                default:
                {
                    printf("\n�������������!\n");
                    goto CHANGE3;
                }
                }
                break;
            case 0:
                goto EXIT;
                break;
            default:

            {
                printf("\n������������䣡\n");
                goto CHANGE;
            }

            }
        }
    }
    printf("\nû���ҵ�������3������ز���ҳ��\n");
    Sleep(1000*3);
    goto START;
EXIT:
    printf("��0�ص���һ��");
    printf("\n\t�˳�ϵͳ��1\n");
    flag=correct();
    if(!flag)
        return 1;
    system("cls");
    return 0;
}
int main(void)//�������飬�ļ���飬�޸İ�飬��ӡ������
{
    system("title ����ϵͳ");
    //�����������飬ѧ�����飬�γ�����
    char password[5][26];
    COURSE cour[6];
    STUDENT stu [4];
    XY pos1[6];
    //��ȡ�ļ���Ϣ����ֵ����������
    //writefile(cour,stu);
    readfile(cour,stu);
    readpassword(password,5);
    trans(cour,pos1);
    //format(cour,stu,pos);
    // writejn();
    int c;
    //����Ϊ���˵�
    printf("\t                                        ��ӭ��������ƽ̨\t\n");
    Sleep(1000);
PASS:
    system("title ����ϵͳ��¼");
    system("cls");
    printf("\t��ע����;�˳����ᱣ��\n\n\t�ڵ�һ������ǰ������ѡ�������Լ�������ȷ��,\n\n\t����ÿ�����붼���һ�顣\n\n\t����������밴1������0\n\n\t�Իس���Ϊ������׼(Ĭ��0��������0��1���������һ��Ϊ׼,��������5��)\n");
    int lazy=correct();
    printf("\n");
    int flag=passwords(password,5,lazy);//����ֵΪ�����������е�λ�ã��ҽ�����Ա���ڵ�0��
    if(flag>0)//ѧ�����
    { flag--;//�����Ϊ��ѧ������ƥ��
START:
        system("cls");
        system("title ����ϵͳѧ����");
        printf("-------------------��1�����γ������Ϣ\n");
        printf("-------------------��2�鿴�Լ���Ϣ\n");
        printf("-------------------��3�鿴��ǰ�α�\n");
        printf("-------------------��4�޸�����\n");
        printf("-------------------��5ѡ�λ��˿�\n");
        printf("-------------------��6�˳�ϵͳ\n");
        printf("-------------------��7�л��˺�\n");
        c=correctint(lazy);
        switch(c)
        {
        case 1:
            system("cls");
            if(search(lazy,cour))
                goto START;
            else
                goto END;
            break;
        case 2:
            system("cls");
            if(scan(lazy,flag,stu))
                goto START;
            else
                goto END;
            break;
        case 3:
            system("cls");
            if(timetable(lazy,flag,cour,stu))
                goto START;
            else
                goto END;
            break;
        case 4:
            system("cls");
            if(change(password,flag+1,lazy))
                goto START;
            else
                goto END;
            break;
        case 5:
            system("cls");
            if(choose(lazy,cour,stu,flag))
                goto START;
            else
                goto END;
            break;
        case 6:
            system("cls");
            goto END;
            break;
        case 7:
            system("cls");
            goto PASS;
            break;
        default:
        {
            printf("\n\t������󣬽���5�����ת��ϵͳ��ҳ\n");
            Sleep(5*1000);
            system("cls");
            goto START;
        }
        }
    }
    else if(flag==0)//����Ա���
    {

START1:
        system("cls");
        system("title ����ϵͳ����Ա");
        printf("-------------------��1�鿴�γ̺�ѧ������Ϣ\n");
        printf("-------------------��2��ѧ������Ϣ�����޸�\n");
        printf("-------------------��3�鿴�γ���־\n");
        printf("-------------------��4�޸�����\n");
        printf("-------------------��5�˳�ϵͳ\n");
        c=correctint(lazy);
        switch(c)
        {
        case 1:
            system("cls");
            if(format(cour,stu,pos1))
                goto START1;
            else
                goto END;
            break;
        case 2:
            system("cls");
            if(changestudent(lazy,flag,stu,cour))
                goto START1;
            else
                goto END;
            break;
        case 3:
            system("cls");
            if(lookjournal(lazy,flag))
                goto START1;
            else
                goto END;
            break;
        case 4:
            system("cls");
            if(change(password,0,lazy))
                goto START1;
            else
                goto END;
            break;
        case 5:
            system("cls");
            goto END;
            break;
        default:
        {
            printf("\n\t������󣬽���5�����ת��ϵͳ��ҳ\n");
            Sleep(5*1000);
            system("cls");
            goto START1;
        }
        }
    }
    else//��ӭ�ٴι���
    {
END:
        system("cls");
        system("title ��ӭ�ٴι���");
        printf("\n\t��ӭ�ٴι���\n");
    }
    //�����ĺ����Ϣд���ļ�
    writepassword (password,5);
     writefile(cour,stu);
    return 0;
}
