//2012��9�£�Сѧ�ڴ���ҵ��ѧ���ɼ�����ϵͳ

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CH  20  // ����ַ�
#define N  100  // ѧ����������

typedef struct student //ѧ���Ľṹ��
{
   char  name[CH];               // ����
   char  no[CH];                 //ѧ��
   char  col[CH];				//ѧԺ 
   float chinese;                //����     
   float math;                   //��ѧ      
   float english;         		 //Ӣ��     
   float physic;          	     //����     
   float chemstry; 				 //��ѧ 
   float biology;			  	 //���� 
   float fAvage;                 //ƽ������
   float S_all;                  //�ܷ���
}student;

student  s[N];                   //ѧ������

int i,num;
int average;                      

void welcome()//��ӭ���� 
{
	printf("\n\n\n\n\n");
	printf("\t\t �q�T�T�T�T�T�T��ѧ���ɼ�����ϵͳ���T�T�T�T�T�T�r\n"); 
    printf("\t\t�U                                        \t�U\n");
    printf("\t\t�U                                        \t�U\n"); 
    printf("\t\t�U          	    ��ӭʹ��              \t�U\n"); 
    printf("\t\t�U                                        \t�U\n"); 
    printf("\t\t�U                ���ߣ�ʮ����            \t�U\n");
    printf("\t\t�U                                        \t�U\n");
    printf("\t\t�U                ���س�����������        \t�U\n");
    printf("\t\t�U                                        \t�U\n");
    printf("\t\t�U                                        \t�U\n");
    printf("\t\t�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n"); 
    getchar();
}

void meun()//�˵� 
{
	system("cls");                                                     //��Ļ���
	printf("\n\n\n\n\n");
	printf("\t\t �q�T�T�T�T�T�T�T�ȳɼ�����ϵͳ���T�T�T�T�T�T�T�r\n"); /*�˵�ѡ��*/
    printf("\t\t�U                    ��������ʮ��������  \t�U\n");
	printf("\t\t�U           ѧ �� �� �� �� �� ϵ ͳ      \t�U\n");
	printf("\t\t�U                  ���˵�                \t�U\n"); 
	printf("\t\t�U              1. ¼��ѧ������           \t�U\n"); 
	printf("\t\t�U              2. ɾ��ѧ������           \t�U\n"); 
	printf("\t\t�U              3. �޸�ѧ������           \t�U\n");
	printf("\t\t�U              4. ����ѧ������           \t�U\n");
	printf("\t\t�U              5. �������               \t�U\n");
	printf("\t\t�U              6. ͳ����Ϣ���           \t�U\n");
	printf("\t\t�U              7. �˳��ɼ�����ϵͳ       \t�U\n");
	printf("\t\t�U                                        \t�U\n");
	printf("\t\t�U                                        \t�U\n");
	printf("\t\t�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n"); 
	printf("\t\t           \1ѡ��˵�ѡ��(1-8):"); 
}

void  read_from_file()
//���ļ��ж�ȡѧ������Ϣ
{
   FILE *fp;
   int i=0;
   fp=fopen("data.dat","rb");
   if(!fp)
   {
	   printf("���ļ�data.datʧ��!\n");
       return ;
   }

   fread(&num,1,sizeof(num),fp); //�ȶ�ȡѧ���ĸ���
   for(i=0;i<num;i++)
	    fread(&s[i],1,sizeof(student),fp); //��ȡÿ��ѧ������Ϣ��ŵ��ṹ��
       
   fclose(fp);//�ر��ļ�

}

void  write_to_file()
//���ļ��ж�ȡѧ������Ϣ
{
   FILE *fp;
   int i=0;
   fp=fopen("data.dat","wb+");
   if(!fp)
   {
	   printf("���ļ�data.datʧ��!\n");
       return ;
   }

   fwrite(&num,1,sizeof(num),fp); //��д��ѧ���ĸ���
   for(i=0;i<num;i++)
	    fwrite(&s[i],1,sizeof(student),fp); //д��ÿ��ѧ������Ϣ
       
   fclose(fp);//�ر��ļ�

}
void search_num()
{
	int i=0;
	char  no[CH];   //ѧ��
	printf("������������ҵ�ѧ��\n");
	scanf("%s",no);
		for(i=0;i<num;i++)//���ҵ���ѧ�Ŷ�Ӧ�����
			if(strcmp(s[i].no,no)==0)
			{
			printf("����   ѧ��   ѧԺ   ����   ��ѧ   Ӣ��   ����   ��ѧ   ����  �ܷ�  ƽ����\n");

			printf("%s%8s%8s%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].chinese,s[i].math,s[i].english,s[i].physic,s[i].chemstry,s[i].biology, s[i].S_all,s[i].fAvage);
    		return;
			}
			printf("���������ѧ��.\n");
	
}

void search_name()
{
	char  name[CH];
	printf("������������ҵ�ѧ��������\n");
	scanf("%s",name);
	for(i=0;i<num;i++)//numΪȫ�ֱ���
	{
		for(i=0;i<num;i++)
			if(strcmp(s[i].name,name)==0)
			{
					printf("����   ѧ��   ѧԺ   ����   ��ѧ   Ӣ��   ����   ��ѧ   ����  �ܷ�  ƽ����\n");

			printf("%s%8s%8s%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].chinese,s[i].math,s[i].english,s[i].physic,s[i].chemstry,s[i].biology, s[i].S_all,s[i].fAvage);
    		return;
			}
		
				printf("�������������.");
    }
}
void search_col()
{
	char col[CH];
	printf("������������ҵ�ѧԺ���ƣ�\n");
	scanf("%s",col);
	for(i=0;i<num;i++)//numΪȫ�ֱ���
	{
		for(i=0;i<num;i++)
			if(strcmp(s[i].col,col)==0)
			{
				printf("����   ѧ��   ѧԺ   ����   ��ѧ   Ӣ��   ����   ��ѧ   ����  �ܷ�  ƽ����\n");

			printf("%s%8s%8s%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].chinese,s[i].math,s[i].english,s[i].physic,s[i].chemstry,s[i].biology, s[i].S_all,s[i].fAvage);
    		return;
			}
			//else
				printf("�����ڴ�ѧԺ���������.");
    }
}

void search_sub()
{
	int sub;
	printf("������������ҵĿ�Ŀ����1�������ģ�2������ѧ��3����Ӣ�4��������5����ѧ��6�������");
	scanf("%d",&sub);
	switch(sub)
	{
		case 1:
		{
			printf("����   ѧ��   ѧԺ   ����\n");
			for(i=0;i<num;i++)
			{
				printf("%s%7.2s%7.2s%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].chinese);			
			}
		}
		break;
		case 2:
		{
			printf("����   ѧ��   ѧԺ   ��ѧ\n");
			for(i=0;i<num;i++)
			{
				printf("%s%7.2s%7.2s%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].math);			
			}
		}
	    break;
		case 3:
		{
			printf("����   ѧ��   ѧԺ  Ӣ��\n");
			for(i=0;i<num;i++)
			{
				printf("%s%7.2s%7.2s%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].english);			
			}
		}
		break;
        case 4:
		{
			printf("����   ѧ��   ѧԺ  ����\n");
			for(i=0;i<num;i++)
			{
				printf("%s%7.2s%7.2s%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].physic);			
			}
		}
		break;
		case 5:
		{
			printf("����   ѧ��   ѧԺ  ��ѧ\n");
			for(i=0;i<num;i++)
			{
				printf("%s%7.2s%7.2s%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].chemstry);			
			}
		}
		break;
		case 6:
		{
			printf("����   ѧ��   ѧԺ  ����\n");
			for(i=0;i<num;i++)
			{
				printf("%s%7.2s%7.2s%7.2f\n",s[i].name,s[i].no,s[i].col,s[i].biology);			
			}
		}
		break;
	}
	return;
}

void sum_result()//����ͳ�Ƹ��������ƽ���ֵ�����
{
	//int average��ƽ����
	int h_ave=0,l_ave=0,ave=0;//h_aveΪ����ƽ���ֵ�����,l_aveΪ����ƽ���ֵ�����,aveΪ����ƽ���ֵ�����
	for(i=0;i<num;i++)
	{
		if(s[i].fAvage>average)
			h_ave++;
		else if(s[i].fAvage==average)
				ave++;
		     else
				 l_ave++;
	}
	printf("����ƽ���ֵ�����Ϊ%d������ƽ���ֵ�����Ϊ%d������ƽ���ֵ�����Ϊ%d",h_ave,l_ave,ave);
	return;
}

void percentage()//����ͳ�����㣬���ã������벻����İٷֱ�
{
	float A=0,B=0,C=0,D=0,E=0;//A��ʾ���㣬B��ʾ���ã�C��ʾ�еȣ�D��ʾ����E��ʾ������
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
	printf("���������Ϊ%d,��ռ����Ϊ%f",A,QA);
    printf("���õ�����Ϊ%d,��ռ����Ϊ%f",B,QB);
	printf("�еȵ�����Ϊ%d,��ռ����Ϊ%f",C,QC);
	printf("���������Ϊ%d,��ռ����Ϊ%f",D,QD);
	printf("�����������Ϊ%d,��ռ����Ϊ%f",E,QE);
	return;
}

/*void sort_result()
{
	int i=0,j=0;
	student  t;//�������򽻻�����ʱ����
	student  s1[N]; //ѧ������,�����������ʱ����
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
	printf("����   ѧ��   ѧԺ  ����    ��ѧ   Ӣ��   ����   ��ѧ  ����  �ܷ���  ƽ����\n");
	for(i=0;i<num;i++)
		printf("%10s%12s%10s%9.2f%9.2f%9.2f%9.2f%9.2f%9.2f%9.2f%9.2f\n",s[i].name,s[i].no,s[i].col,s[i].chinese,s[i].math,s[i].english,s[i].physic,s[i].chemstry,s[i].biology, s[i].S_all,s[i].fAvage);
	return;
}*/
void search()
{
	int operate=0;
	printf("����������Ѱ�ҵ���Ϣ��\n");
	printf("*****************\n");
	printf("1����ѧ��\n");
	printf("2��������\n");
	printf("3����ѧԺ\n");
	printf("4������Ŀ\n");
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

void add()//����ѧ���ɼ���Ϣ
{
	int i=num;
	printf("����������\n");
	scanf("%s",s[i].name);
	printf("������ѧ��");
	scanf("%s",s[i].no);
	printf("������ѧԺ");
	scanf("%s",s[i].col);
	printf("���������ĳɼ�");
	scanf("%f",&s[i].chinese);
	printf("��������ѧ�ɼ�");
	scanf("%f",&s[i].math);
	printf("������Ӣ��ɼ�");
	scanf("%f",&s[i].english);
	printf("����������ɼ�");
	scanf("%f",&s[i].physic);
	printf("�����뻯ѧ�ɼ�");
	scanf("%f",&s[i].chemstry);
	printf("����������ɼ�");
	scanf("%f",&s[i].biology);
	s[i].S_all=s[i].chinese+s[i].math+s[i].english+s[i].physic+s[i].chemstry+s[i].biology;
	s[i].fAvage=s[i].S_all/6;
	num++;
}
void delet()
{
    int j;
	char delnum[CH];//������Ҫɾ����ѧ��
	printf("������Ҫɾ����ѧ��");
	scanf("%s",delnum);
	for(i=0;i<num;i++)
	    if(strcmp(s[i].no,delnum)==0)//�Ա��ҵ�ѧ��
		{
			for(j=i;j<num-1;j++)//��ÿ���ṹ������ǰ��
				 s[j]=s[j+1];

			num--; //�������� 1

			return;
		}

   printf("�Ҳ�����ѧ��!");//���Ҳ������ѧ��

}

void Delete_infor()//�޸�ѧ����Ϣ
{

	
	char  no[CH];   //ѧ��
  	printf("��������Ҫ�޸ĵ�ѧ��ѧ��:");
	scanf("%s",no);
	for(i=0;i<num;i++)//���ҵ���ѧ�Ŷ�Ӧ�����
	    if(strcmp(s[i].no,no)==0)
		{
				printf("����������: ");
				scanf("%s",s[i].name);
				printf("������ѧ��:");
				scanf("%s",s[i].no);
				printf("������ѧԺ: ");
				scanf("%s",s[i].col);
				printf("����������: ");
				scanf("%f",&s[i].chinese);
				printf("��������ѧ: ");
				scanf("%f",&s[i].math);
				printf("������Ӣ��: ");
				scanf("%f",&s[i].english);
				printf("����������: ");
				scanf("%f",&s[i].physic);
				printf("�����뻯ѧ: ");
				scanf("%f",&s[i].chemstry);
				 printf("����������: ");
				 scanf("%f",&s[i].biology);
				s[i].S_all=s[i].chinese+s[i].math+s[i].english+s[i].physic+s[i].chemstry+s[i].biology;
				//�ܷ�

				s[i].fAvage=s[i].S_all/6;
				//ƽ����

		

			return;
		}

		printf("û�����ѧ��!");
}


void output ()
{
	int i,j,v[30],high=0,equal=0,low=0,num1=0,num2=0,num3=0,num4=0,num5=0;
	float av,all=0,allav=0,class1=0,class2=0,class3=0,class4=0,class5=0,class6=0,class1av,class2av,class3av,class4av,class5av,class6av,max=0,per1,per2,per3,per4,per5;
	for(i=0;s[i].no[0]!='\0';i++)
	{	
		all=s[i].chinese+s[i].math+s[i].english+s[i].physic+s[i].chemstry+s[i].biology;
		allav=all/6;                                             //����ÿ���˵��ֺܷ�ƽ���� 
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
	class6av=class6/i;                                           //�������ÿ�ſε�ƽ���ɼ� 
	printf("ȫ������ƽ���֣�%.2f\n��ѧƽ���֣�%.2f\nӢ��ƽ���֣�%.2f\n����ƽ���֣�%.2f\n��ѧƽ���֣�%.2f\n����ƽ���֣�%.2f\n\n", class1av,class2av,class3av,class4av,class5av,class6av); 
	for(i=0;s[i].no[0]!='\0';i++)
	{
		if(s[i].S_all>max)
		{	
				max=s[i].S_all;
				v[0]=i;//v�Ǽ�¼���з�����߷ֵ�iֵ 
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
			                                      //�Ƚϵó���߳ɼ� 
	}
	printf("��߳ɼ���%.2f\n",max);
	for(j=0;v[j]!=0;j++)
	{
		printf("ѧ�ţ�%s\n������%s\n�ɼ���%.2f\n",s[i].no,s[i].name,s[i].S_all);
	}
	av=(class1av+class2av+class3av+class4av+class5av+class6av)/6;
	for(i=0;s[i].no[0]!='\0';i++)
	{
		if(s[i].fAvage>av)
			high++;
		else if(s[i].fAvage==av)
				equal++;                                           //����ƽ�������µ����� 
			else	
				low++;
	}
	printf("ȫ��ƽ���ɼ���%.2f\n����ƽ���ɼ�������%d\n����ƽ���ɼ�������%d\n����ƽ���ɼ�������%d\n",av,high,equal,low);
	for(i=0;s[i].no[0]!='\0';i++)
	{	
		if(s[i].fAvage>90)
			num1++;
		else if(s[i].fAvage>80)
				num2++;
			 else if(s[i].fAvage>70)
			 		num3++;
	 		      else if(s[i].fAvage>60)
	 		      		num4++;                                                   //������ֶε������Ͱٷֱ� 
	 		      		else
	 		      		     num5++;
	}
	per1=(float)num1/num;
	per2=(float)num2/num;
	per3=(float)num3/num;
	per4=(float)num4/num;
	per5=(float)num5/num;
	printf("����������90-100����%d  �ٷֱȣ�%.2f%%\n����������80-89����%d   �ٷֱȣ�%.2f%%\n�е�������70-79����%d   �ٷֱȣ�%.2f%%\n",num1,per1*100,num2,per2*100,num3,per3*100);
	printf("����������50-59����%d   �ٷֱȣ�%.2f%%\n������������0-59����%d  �ٷֱȣ�%.2f%%\n ",num4,per4*100,num5,per5*100);	
}

void sort_result()
{
        int i,j;
        int choice;
        struct student temp;
        printf("\t\t��ѡ��������:\n");
        printf("\t1.��ѧ������\n");
        printf("\t2.����������\n");
        printf("\t3.����ѧ����\n");
        printf("\t4.��Ӣ������\n");
        printf("\t5.����������\n");
        printf("\t6.����ѧ����\n");
        printf("\t7.����������\n");
        printf("\t8.��ƽ���ɼ�����\n");
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
        printf("   ����   ѧ��   ѧԺ    ����   ��ѧ   Ӣ��   ����   ��ѧ   ����   �ܷ���  ƽ����\n");
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
    fprintf(fp," ����  ѧ��  ѧԺ  ����  ��ѧ  Ӣ��  ����  ��ѧ  ����\n");
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
	printf("�Ƿ�����ʼ���룺�������롰1�����������롰2��\n");
	scanf("%d",&key);
	if(1==key)
	{
		printf("Ҫ����ѧ����Ϣ������\n");
		scanf("%d",&num);
		printf("����������(�Ե�һ�ո�ָ�):\n����  ѧ��  ѧԺ  ����  ��ѧ  Ӣ��  ����  ��ѧ  ����\n"); 
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
				//�ܷ�

			s[j].fAvage=s[j].S_all/6;
				//ƽ����
				 
		} 
		
	}
	else read_from_file();
	return;	
} 

int main()
{
   int choose=0;
   num=0;//��ʼ��ѧ������Ϊ0
   //read_from_file(); //��ȡ�ļ�
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


   write_txt();//д���ļ�
   write_to_file();

   printf("ллʹ��ѧ���ɼ�����ϵͳ!�ټ�!\n");
   
   getchar();
}