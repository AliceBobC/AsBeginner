//2012年9月，小学期大作业：学生成绩管理系统

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CH  20  // 最大字符
#define N  100  // 学生的最大个数

typedef struct student //学生的结构体
{
   char  name[CH];               // 姓名
   char  no[CH];                 //学号
   char  col[CH];				//学院 
   float chinese;                //语文     
   float math;                   //数学      
   float english;         		 //英语     
   float physic;          	     //物理     
   float chemstry; 				 //化学 
   float biology;			  	 //生物 
   float fAvage;                 //平均分数
   float S_all;                  //总分数
}student;

student  s[N];                   //学生数组

int i,num;
int average;                      

void welcome()//欢迎界面 
{
	printf("\n\n\n\n\n");
	printf("\t\t ╭══════┤学生成绩管理系统├══════╮\n"); 
    printf("\t\t║                                        \t║\n");
    printf("\t\t║                                        \t║\n"); 
    printf("\t\t║          	    欢迎使用              \t║\n"); 
    printf("\t\t║                                        \t║\n"); 
    printf("\t\t║                作者：十六班            \t║\n");
    printf("\t\t║                                        \t║\n");
    printf("\t\t║                按回车键继续……        \t║\n");
    printf("\t\t║                                        \t║\n");
    printf("\t\t║                                        \t║\n");
    printf("\t\t╰═══════════════════════╯\n"); 
    getchar();
}

void meun()//菜单 
{
	system("cls");                                                     //屏幕清空
	printf("\n\n\n\n\n");
	printf("\t\t ╭═══════┤成绩管理系统├═══════╮\n"); /*菜单选择*/
    printf("\t\t║                    …………十六班制作  \t║\n");
	printf("\t\t║           学 生 成 绩 管 理 系 统      \t║\n");
	printf("\t\t║                  主菜单                \t║\n"); 
	printf("\t\t║              1. 录入学生数据           \t║\n"); 
	printf("\t\t║              2. 删除学生数据           \t║\n"); 
	printf("\t\t║              3. 修改学生数据           \t║\n");
	printf("\t\t║              4. 查找学生数据           \t║\n");
	printf("\t\t║              5. 排序输出               \t║\n");
	printf("\t\t║              6. 统计信息输出           \t║\n");
	printf("\t\t║              7. 退出成绩管理系统       \t║\n");
	printf("\t\t║                                        \t║\n");
	printf("\t\t║                                        \t║\n");
	printf("\t\t╰═══════════════════════╯\n"); 
	printf("\t\t           \1选择菜单选项(1-8):"); 
}

void  read_from_file()
//从文件中读取学生的信息
{
   FILE *fp;
   int i=0;
   fp=fopen("data.dat","rb");
   if(!fp)
   {
	   printf("打开文件data.dat失败!\n");
       return ;
   }

   fread(&num,1,sizeof(num),fp); //先读取学生的个数
   for(i=0;i<num;i++)
	    fread(&s[i],1,sizeof(student),fp); //读取每个学生的信息存放到结构体
       
   fclose(fp);//关闭文件

}

void  write_to_file()
//从文件中读取学生的信息
{
   FILE *fp;
   int i=0;
   fp=fopen("data.dat","wb+");
   if(!fp)
   {
	   printf("打开文件data.dat失败!\n");
       return ;
   }

   fwrite(&num,1,sizeof(num),fp); //先写入学生的个数
   for(i=0;i<num;i++)
	    fwrite(&s[i],1,sizeof(student),fp); //写入每个学生的信息
       
   fclose(fp);//关闭文件

}
void search_num()
{
	int i=0;
	char  no[CH];   //学号
	printf("请输入你想查找的学号\n");
	scanf("%s",no);
		for(i=0;i<num;i++)//先找到该学号对应的序号
			if(strcmp(s[i].no,no)==0)
			{
			printf("姓名   学号   学院   语文   数学   英语   物理   化学   生物  总分  平均分\n");

			printf("%s%8s%8s%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].chinese,s[i].math,s[i].english,s[i].physic,s[i].chemstry,s[i].biology, s[i].S_all,s[i].fAvage);
    		return;
			}
			printf("不存在这个学号.\n");
	
}

void search_name()
{
	char  name[CH];
	printf("请输入你想查找的学生姓名：\n");
	scanf("%s",name);
	for(i=0;i<num;i++)//num为全局变量
	{
		for(i=0;i<num;i++)
			if(strcmp(s[i].name,name)==0)
			{
					printf("姓名   学号   学院   语文   数学   英语   物理   化学   生物  总分  平均分\n");

			printf("%s%8s%8s%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].chinese,s[i].math,s[i].english,s[i].physic,s[i].chemstry,s[i].biology, s[i].S_all,s[i].fAvage);
    		return;
			}
		
				printf("不存在这个姓名.");
    }
}
void search_col()
{
	char col[CH];
	printf("请输入你想查找的学院名称：\n");
	scanf("%s",col);
	for(i=0;i<num;i++)//num为全局变量
	{
		for(i=0;i<num;i++)
			if(strcmp(s[i].col,col)==0)
			{
				printf("姓名   学号   学院   语文   数学   英语   物理   化学   生物  总分  平均分\n");

			printf("%s%8s%8s%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].chinese,s[i].math,s[i].english,s[i].physic,s[i].chemstry,s[i].biology, s[i].S_all,s[i].fAvage);
    		return;
			}
			//else
				printf("不存在此学院或输入错误.");
    }
}

void search_sub()
{
	int sub;
	printf("请输入你想查找的科目：（1代表语文，2代表数学，3代表英语，4代表物理，5代表化学，6代表生物）");
	scanf("%d",&sub);
	switch(sub)
	{
		case 1:
		{
			printf("姓名   学号   学院   语文\n");
			for(i=0;i<num;i++)
			{
				printf("%s%7.2s%7.2s%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].chinese);			
			}
		}
		break;
		case 2:
		{
			printf("姓名   学号   学院   数学\n");
			for(i=0;i<num;i++)
			{
				printf("%s%7.2s%7.2s%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].math);			
			}
		}
	    break;
		case 3:
		{
			printf("姓名   学号   学院  英语\n");
			for(i=0;i<num;i++)
			{
				printf("%s%7.2s%7.2s%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].english);			
			}
		}
		break;
        case 4:
		{
			printf("姓名   学号   学院  物理\n");
			for(i=0;i<num;i++)
			{
				printf("%s%7.2s%7.2s%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].physic);			
			}
		}
		break;
		case 5:
		{
			printf("姓名   学号   学院  化学\n");
			for(i=0;i<num;i++)
			{
				printf("%s%7.2s%7.2s%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].chemstry);			
			}
		}
		break;
		case 6:
		{
			printf("姓名   学号   学院  生物\n");
			for(i=0;i<num;i++)
			{
				printf("%s%7.2s%7.2s%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].biology);			
			}
		}
		break;
	}
	return;
}

void sum_result()//用于统计高于与低于平均分的人数
{
	//int average总平均分
	int h_ave=0,l_ave=0,ave=0;//h_ave为高于平均分的人数,l_ave为低于平均分的人数,ave为等于平均分的人数
	for(i=0;i<num;i++)
	{
		if(s[i].fAvage>average)
			h_ave++;
		else if(s[i].fAvage==average)
				ave++;
		     else
				 l_ave++;
	}
	printf("高于平均分的人数为%d，低于平均分的人数为%d，等于平均分的人数为%d",h_ave,l_ave,ave);
	return;
}

void percentage()//用于统计优秀，良好，及格与不及格的百分比
{
	float A=0,B=0,C=0,D=0,E=0;//A表示优秀，B表示良好，C表示中等，D表示及格，E表示不及格
	float QA=0,QB=0,QC=0,QD=0,QE=0;
	for(i=0;i<num;i++)
	{
		if(s[i].fAvage>=90)
			A++;
		if(s[i].fAvage<=89&&s[i].fAvage>=80)
			B++;
		if(s[i].fAvage<=79&&s[i].fAvage>=70)
			C++;
		if(s[i].fAvage<=69&&s[i].fAvage>=60)
			D++;
		if(s[i].fAvage<=59)
			E++;
	}
	QA=A/num;
    QB=B/num;
	QC=C/num;
    QD=D/num;
	QE=E/num;
	printf("优秀的人数为%d,所占比例为%f",A,QA);
    printf("良好的人数为%d,所占比例为%f",B,QB);
	printf("中等的人数为%d,所占比例为%f",C,QC);
	printf("及格的人数为%d,所占比例为%f",D,QD);
	printf("不及格的人数为%d,所占比例为%f",E,QE);
	return;
}

/*void sort_result()
{
	int i=0,j=0;
	student  t;//用于排序交换的临时变量
	student  s1[N]; //学生数组,用来排序的临时数组
    for(i=0;i<num;i++)
          s1[i]=s[i];
    for(i=0;i<num;i++)
		 for(j=i+1;j<num;j++)
			 if(s1[i].fAvage<s1[j].fAvage)
			 {
			    t=s1[i];
				s1[i]=s1[j];
				s1[j]=t;
			 }
	printf("姓名   学号   学院  语文    数学   英语   物理   化学  生物  总分数  平均分\n");
	for(i=0;i<num;i++)
		printf("%10s%12s%10s%9.2f%9.2f%9.2f%9.2f%9.2f%9.2f%9.2f%9.2f\n",s[i].name,s[i].no,s[i].col,s[i].chinese,s[i].math,s[i].english,s[i].physic,s[i].chemstry,s[i].biology, s[i].S_all,s[i].fAvage);
	return;
}*/
void search()
{
	int operate=0;
	printf("请输入你想寻找的信息：\n");
	printf("*****************\n");
	printf("1代表按学号\n");
	printf("2代表按姓名\n");
	printf("3代表按学院\n");
	printf("4代表按科目\n");
	printf("*****************\n");
	
	scanf("%d",&operate);
	switch(operate)
	{
		case 1:search_num();break;
		case 2:search_name();break;
		case 3:search_col();break;
		case 4:search_sub();break;
  
	}
}

void add()//增加学生成绩信息
{
	int i=num;
	printf("请输入姓名\n");
	scanf("%s",s[i].name);
	printf("请输入学号");
	scanf("%s",s[i].no);
	printf("请输入学院");
	scanf("%s",s[i].col);
	printf("请输入语文成绩");
	scanf("%f",&s[i].chinese);
	printf("请输入数学成绩");
	scanf("%f",&s[i].math);
	printf("请输入英语成绩");
	scanf("%f",&s[i].english);
	printf("请输入物理成绩");
	scanf("%f",&s[i].physic);
	printf("请输入化学成绩");
	scanf("%f",&s[i].chemstry);
	printf("请输入生物成绩");
	scanf("%f",&s[i].biology);
	s[i].S_all=s[i].chinese+s[i].math+s[i].english+s[i].physic+s[i].chemstry+s[i].biology;
	s[i].fAvage=s[i].S_all/6;
	num++;
}
void delet()
{
    int j;
	char delnum[CH];//定义需要删除的学号
	printf("请输入要删除的学号");
	scanf("%s",delnum);
	for(i=0;i<num;i++)
	    if(strcmp(s[i].no,delnum)==0)//对比找到学号
		{
			for(j=i;j<num-1;j++)//将每个结构体数据前移
				 s[j]=s[j+1];

			num--; //数量减少 1

			return;
		}

   printf("找不到该学号!");//查找不到这个学生

}

void Delete_infor()//修改学生信息
{

	
	char  no[CH];   //学号
  	printf("请输入你要修改的学生学号:");
	scanf("%s",no);
	for(i=0;i<num;i++)//先找到该学号对应的序号
	    if(strcmp(s[i].no,no)==0)
		{
				printf("请输入姓名: ");
				scanf("%s",s[i].name);
				printf("请输入学号:");
				scanf("%s",s[i].no);
				printf("请输入学院: ");
				scanf("%s",s[i].col);
				printf("请输入语文: ");
				scanf("%f",&s[i].chinese);
				printf("请输入数学: ");
				scanf("%f",&s[i].math);
				printf("请输入英语: ");
				scanf("%f",&s[i].english);
				printf("请输入物理: ");
				scanf("%f",&s[i].physic);
				printf("请输入化学: ");
				scanf("%f",&s[i].chemstry);
				 printf("请输入生物: ");
				 scanf("%f",&s[i].biology);
				s[i].S_all=s[i].chinese+s[i].math+s[i].english+s[i].physic+s[i].chemstry+s[i].biology;
				//总分

				s[i].fAvage=s[i].S_all/6;
				//平均分

		

			return;
		}

		printf("没有这个学号!");
}


void output ()
{
	int i,j,v[30],high=0,equal=0,low=0,num1=0,num2=0,num3=0,num4=0,num5=0;
	float av,all=0,allav=0,class1=0,class2=0,class3=0,class4=0,class5=0,class6=0,class1av,class2av,class3av,class4av,class5av,class6av,max=0,per1,per2,per3,per4,per5;
	for(i=0;s[i].no[0]!='\0';i++)
	{	
		all=s[i].chinese+s[i].math+s[i].english+s[i].physic+s[i].chemstry+s[i].biology;
		allav=all/6;                                             //计算每个人的总分和平均数 
		s[i].fAvage=allav;
		s[i].S_all=all;
		class1=class1+s[i].chinese;       
		class2=class2+s[i].math;
		class3=class3+s[i].english;
		class4=class4+s[i].physic;
		class5=class5+s[i].chemstry;
		class6=class6+s[i].biology;
	}
	class1av=class1/i;
	class2av=class2/i;
	class3av=class3/i;
	class4av=class4/i;
	class5av=class5/i;
	class6av=class6/i;                                           //计算班里每门课的平均成绩 
	printf("全班语文平均分：%.2f\n数学平均分：%.2f\n英语平均分：%.2f\n物理平均分：%.2f\n化学平均分：%.2f\n生物平均分：%.2f\n\n", class1av,class2av,class3av,class4av,class5av,class6av); 
	for(i=0;s[i].no[0]!='\0';i++)
	{
		if(s[i].S_all>max)
		{	
				max=s[i].S_all;
				v[0]=i;//v是记录所有符合最高分的i值 
				j=1;
				while(v[j]!=0)
				{
					v[j]=0;j++;
				}
				j=1;
		}
		else if (s[i].S_all==max)
				{
					v[j]=i;                                            
					j++;
				}	
			                                      //比较得出最高成绩 
	}
	printf("最高成绩：%.2f\n",max);
	for(j=0;v[j]!=0;j++)
	{
		printf("学号：%s\n姓名：%s\n成绩：%.2f\n",s[i].no,s[i].name,s[i].S_all);
	}
	av=(class1av+class2av+class3av+class4av+class5av+class6av)/6;
	for(i=0;s[i].no[0]!='\0';i++)
	{
		if(s[i].fAvage>av)
			high++;
		else if(s[i].fAvage==av)
				equal++;                                           //计算平均分上下的人数 
			else	
				low++;
	}
	printf("全班平均成绩：%.2f\n高于平均成绩人数：%d\n等于平均成绩人数：%d\n低于平均成绩人数：%d\n",av,high,equal,low);
	for(i=0;s[i].no[0]!='\0';i++)
	{	
		if(s[i].fAvage>90)
			num1++;
		else if(s[i].fAvage>80)
				num2++;
			 else if(s[i].fAvage>70)
			 		num3++;
	 		      else if(s[i].fAvage>60)
	 		      		num4++;                                                   //计算各分段的人数和百分比 
	 		      		else
	 		      		     num5++;
	}
	per1=(float)num1/num;
	per2=(float)num2/num;
	per3=(float)num3/num;
	per4=(float)num4/num;
	per5=(float)num5/num;
	printf("优秀人数（90-100）：%d  百分比：%.2f%%\n良好人数（80-89）：%d   百分比：%.2f%%\n中等人数（70-79）：%d   百分比：%.2f%%\n",num1,per1*100,num2,per2*100,num3,per3*100);
	printf("及格人数（50-59）：%d   百分比：%.2f%%\n不及格人数（0-59）：%d  百分比：%.2f%%\n ",num4,per4*100,num5,per5*100);	
}

void sort_result()
{
        int i,j;
        int choice;
        struct student temp;
        printf("\t\t请选择排序功能:\n");
        printf("\t1.按学号排序\n");
        printf("\t2.按语文排序\n");
        printf("\t3.按数学排序\n");
        printf("\t4.按英语排序\n");
        printf("\t5.按物理排序\n");
        printf("\t6.按化学排序\n");
        printf("\t7.按生物排序\n");
        printf("\t8.按平均成绩排序\n");
        do
        {
                scanf("%d",&choice);
        }while((choice!=1)&&(choice!=2)&&(choice!=3)&&(choice!=4)&&(choice!=5)&&(choice!=6)&&(choice!=7)&&(choice!=8));
        switch(choice)
        {
        case 1:
                {
                        for(i=0;i<num-1;i++)
                        {
                                for(j=0;j<num-i-1;j++)
                                {
                                        if(strcmp(s[j].no,s[j+1].no)>0)
                                        {
                                                temp=s[j];
                                                s[j]=s[j+1];
                                                s[j+1]=temp;
                                        }
                                }
                        }
                        
                        break;
                }
                case 2:
                {
                        for(i=0;i<num-1;i++)
                        {
                                for(j=0;j<num-i-1;j++)
                                {
                                        if(s[j].chinese<s[j+1].chinese)
                                        {
                                                temp=s[j];
                                                s[j]=s[j+1];
                                                s[j+1]=temp;
                                        }
                                }
                        }
                        
                        break;
                }
                case 3:
                {
                        for(i=0;i<num-1;i++)
                        {
                                for(j=0;j<num-i-1;j++)
                                {
                                        if(s[j].math<s[j+1].math)
                                        {
                                                temp=s[j];
                                                s[j]=s[j+1];
                                                s[j+1]=temp;
                                        }
                                }
                        }
                        
                        break;
                }
                case 4:
                {
                        for(i=0;i<num-1;i++)
                        {
                                for(j=0;j<num-i-1;j++)
                                {
                                        if(s[j].english<s[j+1].english)
                                        {
                                                temp=s[j];
                                                s[j]=s[j+1];
                                                s[j+1]=temp;
                                        }
                                }
                        }
                        
                        break;
                }
                case 5:
                {
                        for(i=0;i<num-1;i++)
                        {
                                for(j=0;j<num-i-1;j++)
                                {
                                        if(s[j].physic<s[j+1].physic)
                                        {
                                                temp=s[j];
                                                s[j]=s[j+1];
                                                s[j+1]=temp;
                                        }
                                }
                        }
                        
                        break;
                }
                case 6:
                {
                        for(i=0;i<num-1;i++)
                        {
                                for(j=0;j<num-i-1;j++)
                                {
                                        if(s[j].chemstry<s[j+1].chemstry)
                                        {
                                                temp=s[j];
                                                s[j]=s[j+1];
                                                s[j+1]=temp;
                                        }
                                }
                        }
                        
                        break;
                }
                case 7:
                {
                        for(i=0;i<num-1;i++)
                        {
                                for(j=0;j<num-i-1;j++)
                                {
                                        if(s[j].biology<s[j+1].biology)
                                        {
                                                temp=s[j];
                                                s[j]=s[j+1];
                                                s[j+1]=temp;
                                        }
                                }
                        }
                        
                        break;
                }
                case 8:
                {
                        for(i=0;i<num-1;i++)
                        {
                                for(j=0;j<num-i-1;j++)
                                {
                                        if(s[j].fAvage<s[j+1].fAvage)
                                        {
                                                temp=s[j];
                                                s[j]=s[j+1];
                                                s[j+1]=temp;
                                        }
                                }
                        }
                        
                        break;
                }
        }
        printf("   姓名   学号   学院    语文   数学   英语   物理   化学   生物   总分数  平均分\n");
				for(i=0;i<num;i++)
					printf("%5s%8s%8s%8.2f%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].chinese,s[i].math,s[i].english,s[i].physic,s[i].chemstry,s[i].biology, s[i].S_all,s[i].fAvage);
			    return;
        
        
}
void write_txt()
{
	FILE *fp;
	int i,j;
	char ch[30]={'\0'};
	if((fp=fopen("file1.txt","w"))==NULL)
	{
		printf("Can't open the file!\n");
		exit(0);
	}
    fprintf(fp," 姓名  学号  学院  语文  数学  英语  物理  化学  生物\n");
	for(i=0;i<num;i++)
	{
	
		fprintf(fp,"%s",s[i].name);
		fprintf(fp,"   %s",s[i].no);
		fprintf(fp,"    %s",s[i].col);
		fprintf(fp,"   %.2f",s[i].chinese);
		fprintf(fp,"  %.2f",s[i].math);
		fprintf(fp,"  %.2f",s[i].english);
		fprintf(fp,"  %.2f",s[i].physic);
		fprintf(fp,"  %.2f",s[i].chemstry);
		fprintf(fp,"  %.2f\n",s[i].biology);
		//fputc('\n',fp);
	}
	fclose(fp);
	return;
}

void input()
{
	int j,key;
	printf("是否进入初始输入：是请输入“1”。否请输入“2”\n");
	scanf("%d",&key);
	if(1==key)
	{
		printf("要输入学生信息的数量\n");
		scanf("%d",&num);
		printf("请依次输入(以单一空格分隔):\n姓名  学号  学院  语文  数学  英语  物理  化学  生物\n"); 
		for(j=0;j<=num-1;j++)
		{
		    
			scanf("%s ",s[j].name);
   			scanf("%s ",s[j].no);
			scanf("%s ",s[j].col);
			scanf("%f ",&s[j].chinese);
			scanf("%f ",&s[j].math);	
			scanf("%f ",&s[j].english);		
			scanf("%f ",&s[j].physic);		
			scanf("%f ",&s[j].chemstry);
			scanf("%f",&s[j].biology); 
			s[j].S_all=s[j].chinese+s[j].math+s[j].english+s[j].physic+s[j].chemstry+s[j].biology;
				//总分

			s[j].fAvage=s[j].S_all/6;
				//平均分
				 
		} 
		
	}
	else read_from_file();
	return;	
} 

int main()
{
   int choose=0;
   num=0;//初始化学生个数为0
   //read_from_file(); //读取文件
   welcome();
   input(); 
   meun();
   scanf("%d",&choose);
   printf("\n");
   while(choose>0&&choose<7)
   {
   
       switch(choose)
	   {
	     case 1:add();system("pause");break;
		 case 2:delet();system("pause");break;
		 case 3:Delete_infor();system("pause");break;
		 case 4:search();system("pause");break;
		 case 5:sort_result();system("pause");break;
		 case 6:output();system("pause");break;
		 
	   }
       printf("\n");
	   meun();
       scanf("%d",&choose);
	   printf("\n");
   }


   write_txt();//写入文件
   write_to_file();

   printf("谢谢使用学生成绩评定系统!再见!\n");
   
   getchar();
}