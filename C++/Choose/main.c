#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Course
{
	int no;//课程编号
	char name[20];//课程名
	char style[20];//课程性质
	int all_time;//总学时
	int teach_time;//授课学时
	int other_time;//实验或上机学时
	float score;//学分
}Course;//课程信息结构体

typedef struct _Stu
{
	int num;//选课数量
	int cou[20];//已选课程编号
	float sum;//已选课程总学分
}Stu;//学生选课记录

void Print_Cour_Info(Course arr[],int n)//输出课程信息
{
	int i;
	printf("%-10s%-15s%-10s%-10s","课程编号","课程名","性质","授课学时");
	printf("%-10s%-10s%-10s\n","实验/上机","总学时","学分");
	for(i=0;i<n;i++)//输出n个课程的信息
	{
		printf("%-10d%-15s%-10s%-10d",arr[i].no,arr[i].name,arr[i].style,arr[i].teach_time);
		printf("%-10d%-10d%-10.2f\n",arr[i].other_time,arr[i].all_time,arr[i].score);
	}
}

int Add_New_Cour_Info(Course arr[],int n)
{
	system("cls");
	printf("请输入新增课程编号:");
	scanf("%d",&arr[n].no);
	printf("请输入课程名:");
	scanf("%s",arr[n].name);
	printf("请输入课程性质:");
	scanf("%s",arr[n].style);
	printf("请输入授课学时:");
	scanf("%d",&arr[n].teach_time);
	printf("请输入实验或上机学时:");
	scanf("%d",&arr[n].other_time);
	arr[n].all_time=arr[n].other_time+arr[n].teach_time;
	printf("请输入该课程学分:");
	fflush(stdin);
	scanf("%f",&arr[n].score);
	printf("录入成功!\n");
	system("pause");
	return n+1;
}

void Add_New_Stu_Info(Course arr[],int n,Stu* stu)
{
	int temp,i,j;
	system("cls");
	Print_Cour_Info(arr,n);//先打印所有课程信息
	printf("请输入要选择的课程编号");
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
		printf("选课失败!\n");
		system("pause");
		return;
	}
	for(j=0;j<stu->num;j++)//遍历已选课程
	{
		if(temp==stu->cou[j])//判断是否已经选过
		{
			printf("该课程已选，不能重复选择!\n");
			system("pause");
			return;
		}
	}

	stu->cou[stu->num]=temp;
	stu->sum += arr[i].score;
	stu->num++;
	printf("选课成功!\n");
	system("pause");
}

void Search_Cour_Info(Course arr[],int n)
{
	int num,i;
	system("cls");
	printf("请输入要查询的课程编号:");
	scanf("%d",&num);
	for(i=0;i<n;i++)
	{
		if(num==arr[i].no)//如果课程编号一样
		{
			Print_Cour_Info(&arr[i],1);//输出该课程信息
			break;
		}
	}
	if(i==n)
	{
		printf("无该编号信息!\n");
	}
	system("pause");
}

void Search_Cour_Score(Course arr[],int n)
{
	int num,i,flag=0;
	system("cls");
	printf("请输入要查询的课程学分:");
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
		printf("无课程为该学分!\n");
	}
	system("pause");
}

int Menu()
{
	int choice;//记录选择
	system("cls");//清屏
	printf("1:录入课程信息\n");
	printf("2:录入选课信息\n");
	printf("3:输出课程信息\n");
	printf("4:查询课程信息\n");
	printf("5:按学分查询课程\n");
	printf("6:查看已选课程\n");
	printf("0:退出程序\n");
	printf("请输入选择:");
	scanf("%d",&choice);
	while(choice<0||choice>6)//避免数据输入不正确
	{
		printf("请重新选择:");//错误就重新输入
		scanf("%d",&choice);
	}
	return choice;
}

void Save_Course_Info(Course stu[],int n)//保存信息到文件
{
	int i;
	FILE* pFile;
	pFile= fopen("cou_info.txt","w");//打开文件
	if(pFile==NULL)//打开失败则退出
	{
		return;
	}
	for(i=0;i<n;i++)//循环写入到文件
	{
		fwrite(&stu[i],1,sizeof(Course),pFile);
	}
	fclose(pFile);
}

int Read_Course_Info(Course stu[])//读取文件
{
	int i=0;
	FILE* pFile;
	pFile= fopen("cou_info.txt","r");
	if(pFile==NULL)
	{
		return 0;
	}
	while(fread(&stu[i++],1,sizeof(Course),pFile));//当文件不为空 一直读取
	fclose(pFile);
	if(i>=1)//把读取的回车去掉
	{
		return i-1;
	}
	return 0;
}

void Print_Stu_Info(Course arr[],int n,Stu* stu)//输出课程信息
{
	int i,j;
	system("cls");
	printf("已选课程总数%d:\n",stu->num);
	for(i=0;i<stu->num;i++)//遍历已选课程
	{
		for(j=0;j<n;j++)//查询该课程信息并输出
		{
			if(stu->cou[i]==arr[j].no)
			{
				Print_Cour_Info(&arr[j],1);
				break;
			}
		}
	}

	printf("已选总学分%.2f\n",stu->sum);
	system("pause");

}

int main()
{
	Course cour[100];
	int NUM=0;//记录课程数目
	Stu stu;
	stu.num=0;
	stu.sum=0;
	NUM=Read_Course_Info(cour);//读取文件信息

	int choice;
	do
	{
		choice=Menu();
		switch(choice)
		{
		case 1:
			NUM=Add_New_Cour_Info(cour,NUM);//录入课程信息
			break;
		case 2:
			Add_New_Stu_Info(cour,NUM,&stu);//录入选课信息
			break;
		case 3:
			system("cls");
			Print_Cour_Info(cour,NUM);//输出课程信息
			system("pause");
			break;
		case 4:
			Search_Cour_Info(cour,NUM);//查询课程信息
			break;
		case 5:
			Search_Cour_Score(cour,NUM);//按学分查询课程
			break;
		case 6:
			Print_Stu_Info(cour,NUM,&stu);//查看已选课程
			break;
		}
	}while(choice!=0);

	Save_Course_Info(cour,NUM);//保存文件信息

	return 0;
}
