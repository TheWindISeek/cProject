#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Course
{
	int no;//�γ̱��
	char name[20];//�γ���
	char style[20];//�γ�����
	int all_time;//��ѧʱ
	int teach_time;//�ڿ�ѧʱ
	int other_time;//ʵ����ϻ�ѧʱ
	float score;//ѧ��
}Course;//�γ���Ϣ�ṹ��

typedef struct _Stu
{
	int num;//ѡ������
	int cou[20];//��ѡ�γ̱��
	float sum;//��ѡ�γ���ѧ��
}Stu;//ѧ��ѡ�μ�¼

void Print_Cour_Info(Course arr[],int n)//����γ���Ϣ
{
	int i;
	printf("%-10s%-15s%-10s%-10s","�γ̱��","�γ���","����","�ڿ�ѧʱ");
	printf("%-10s%-10s%-10s\n","ʵ��/�ϻ�","��ѧʱ","ѧ��");
	for(i=0;i<n;i++)//���n���γ̵���Ϣ
	{
		printf("%-10d%-15s%-10s%-10d",arr[i].no,arr[i].name,arr[i].style,arr[i].teach_time);
		printf("%-10d%-10d%-10.2f\n",arr[i].other_time,arr[i].all_time,arr[i].score);
	}
}

int Add_New_Cour_Info(Course arr[],int n)
{
	system("cls");
	printf("�����������γ̱��:");
	scanf("%d",&arr[n].no);
	printf("������γ���:");
	scanf("%s",arr[n].name);
	printf("������γ�����:");
	scanf("%s",arr[n].style);
	printf("�������ڿ�ѧʱ:");
	scanf("%d",&arr[n].teach_time);
	printf("������ʵ����ϻ�ѧʱ:");
	scanf("%d",&arr[n].other_time);
	arr[n].all_time=arr[n].other_time+arr[n].teach_time;
	printf("������ÿγ�ѧ��:");
	fflush(stdin);
	scanf("%f",&arr[n].score);
	printf("¼��ɹ�!\n");
	system("pause");
	return n+1;
}

void Add_New_Stu_Info(Course arr[],int n,Stu* stu)
{
	int temp,i,j;
	system("cls");
	Print_Cour_Info(arr,n);//�ȴ�ӡ���пγ���Ϣ
	printf("������Ҫѡ��Ŀγ̱��");
	scanf("%d",&temp);
	for(i=0;i<n;i++)
	{
		if(temp==arr[i].no)
		{
			break;
		}
	}
	if(i==n)
	{
		printf("ѡ��ʧ��!\n");
		system("pause");
		return;
	}
	for(j=0;j<stu->num;j++)//������ѡ�γ�
	{
		if(temp==stu->cou[j])//�ж��Ƿ��Ѿ�ѡ��
		{
			printf("�ÿγ���ѡ�������ظ�ѡ��!\n");
			system("pause");
			return;
		}
	}

	stu->cou[stu->num]=temp;
	stu->sum += arr[i].score;
	stu->num++;
	printf("ѡ�γɹ�!\n");
	system("pause");
}

void Search_Cour_Info(Course arr[],int n)
{
	int num,i;
	system("cls");
	printf("������Ҫ��ѯ�Ŀγ̱��:");
	scanf("%d",&num);
	for(i=0;i<n;i++)
	{
		if(num==arr[i].no)//����γ̱��һ��
		{
			Print_Cour_Info(&arr[i],1);//����ÿγ���Ϣ
			break;
		}
	}
	if(i==n)
	{
		printf("�޸ñ����Ϣ!\n");
	}
	system("pause");
}

void Search_Cour_Score(Course arr[],int n)
{
	int num,i,flag=0;
	system("cls");
	printf("������Ҫ��ѯ�Ŀγ�ѧ��:");
	scanf("%d",&num);
	for(i=0;i<n;i++)
	{
		if(num==arr[i].score)
		{
			Print_Cour_Info(&arr[i],1);
			flag=1;
		}
	}
	if(0==flag)
	{
		printf("�޿γ�Ϊ��ѧ��!\n");
	}
	system("pause");
}

int Menu()
{
	int choice;//��¼ѡ��
	system("cls");//����
	printf("1:¼��γ���Ϣ\n");
	printf("2:¼��ѡ����Ϣ\n");
	printf("3:����γ���Ϣ\n");
	printf("4:��ѯ�γ���Ϣ\n");
	printf("5:��ѧ�ֲ�ѯ�γ�\n");
	printf("6:�鿴��ѡ�γ�\n");
	printf("0:�˳�����\n");
	printf("������ѡ��:");
	scanf("%d",&choice);
	while(choice<0||choice>6)//�����������벻��ȷ
	{
		printf("������ѡ��:");//�������������
		scanf("%d",&choice);
	}
	return choice;
}

void Save_Course_Info(Course stu[],int n)//������Ϣ���ļ�
{
	int i;
	FILE* pFile;
	pFile= fopen("cou_info.txt","w");//���ļ�
	if(pFile==NULL)//��ʧ�����˳�
	{
		return;
	}
	for(i=0;i<n;i++)//ѭ��д�뵽�ļ�
	{
		fwrite(&stu[i],1,sizeof(Course),pFile);
	}
	fclose(pFile);
}

int Read_Course_Info(Course stu[])//��ȡ�ļ�
{
	int i=0;
	FILE* pFile;
	pFile= fopen("cou_info.txt","r");
	if(pFile==NULL)
	{
		return 0;
	}
	while(fread(&stu[i++],1,sizeof(Course),pFile));//���ļ���Ϊ�� һֱ��ȡ
	fclose(pFile);
	if(i>=1)//�Ѷ�ȡ�Ļس�ȥ��
	{
		return i-1;
	}
	return 0;
}

void Print_Stu_Info(Course arr[],int n,Stu* stu)//����γ���Ϣ
{
	int i,j;
	system("cls");
	printf("��ѡ�γ�����%d:\n",stu->num);
	for(i=0;i<stu->num;i++)//������ѡ�γ�
	{
		for(j=0;j<n;j++)//��ѯ�ÿγ���Ϣ�����
		{
			if(stu->cou[i]==arr[j].no)
			{
				Print_Cour_Info(&arr[j],1);
				break;
			}
		}
	}

	printf("��ѡ��ѧ��%.2f\n",stu->sum);
	system("pause");

}

int main()
{
	Course cour[100];
	int NUM=0;//��¼�γ���Ŀ
	Stu stu;
	stu.num=0;
	stu.sum=0;
	NUM=Read_Course_Info(cour);//��ȡ�ļ���Ϣ

	int choice;
	do
	{
		choice=Menu();
		switch(choice)
		{
		case 1:
			NUM=Add_New_Cour_Info(cour,NUM);//¼��γ���Ϣ
			break;
		case 2:
			Add_New_Stu_Info(cour,NUM,&stu);//¼��ѡ����Ϣ
			break;
		case 3:
			system("cls");
			Print_Cour_Info(cour,NUM);//����γ���Ϣ
			system("pause");
			break;
		case 4:
			Search_Cour_Info(cour,NUM);//��ѯ�γ���Ϣ
			break;
		case 5:
			Search_Cour_Score(cour,NUM);//��ѧ�ֲ�ѯ�γ�
			break;
		case 6:
			Print_Stu_Info(cour,NUM,&stu);//�鿴��ѡ�γ�
			break;
		}
	}while(choice!=0);

	Save_Course_Info(cour,NUM);//�����ļ���Ϣ

	return 0;
}
