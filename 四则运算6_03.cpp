// ��Ҫ�����������������  ����ǿ 2015/3/10 
#include<fstream> 
#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<time.h>
#include<cmath>  
#include<string>  
#include<stdio.h> 
using namespace std;
#define random() (rand()%100000) 

//��������
char create_symbol(int n)
{
    int n1,j;    
    char symbol[1];
    if(n==0)
    {
        n1=2;
    }
    else if(n=1)
    {
        n1=4;
    }
    j=random()%n1;
    if(j==0) symbol[0]='+';
    else if(j==1) symbol[0]='-';
    else if(j==2) symbol[0]='*';
    else symbol[0]='/';
    return symbol[0];      
 } 
 //������ת�����ַ�����
 string int_string(int number)
 {
    char str[200];
    itoa(number,str,10);
    string str_=str;
    return str_; 
  } 
  //������ϳ�һ���ַ���
 string combination1(string str1,string str2,char k) 
 {
     string equation;
     equation=str1+k+str2;
     return equation;
 } 
 //������һ����
string create_num(int proper_fs,int range)
{ 
    int num,num1,num2,fs;
    string str_num,str_num1,str_num2;
  	num=random()%range+1;
    str_num=int_string(num);
    if(proper_fs==1)
    {
        fs=random()%2;
	    if(fs==0)//�ж��Ƿ����������  
		{	
		    for(;;)
			{
            	num1=random()%range+1;
             	num2=random()%range+1;
	        	if(num1<num2) break;
			}
			str_num1=int_string(num1);
			str_num2=int_string(num2);
			str_num=combination1(str_num1,str_num2,'/');
		}
	}
	return str_num; 
  } 
 //����ʽת����һ���ַ���
 string combination(string str1,string str2,char k) 
 {
     string equation;
     equation=str1+' '+k+' '+str2;
     return equation;
 }
 //������ 
int main()
{
    srand((int)time(NULL));  //����ʱ������ ��ʹ�ó���ÿ�����еĽ������ͬ 
    int num1,num2,num3,num4,count,n,change,amount,shuchu,range,j,repeat=0,bracket,proper_fs;
    string str_num1,str_num2,temp;
    cout<<"���޳˳�����1�У�0û�У�"<<endl;
    cin>>n;
    cout<<"�Ƿ������ţ�1�У�0û�У�"<<endl;
    cin>>bracket; 
    cout<<"�Ƿ����������1�У�0û�У�"<<endl;
	cin>>proper_fs; 
    cout<<"��Ŀ�Ƿ����ļ��������1�ǣ�0���ǣ�"<<endl;
    cin>>shuchu;
    cout<<"���������ַ�Χ��"<<endl;
    cin>>range; 
    cout<<"���������������"<<endl;
    cin>>amount; 
    string Equation[amount];
    char symbol;
    ofstream fout;
    if(shuchu==1)
    {
        fout.open("fl.txt");
        fout<<amount<<"���������������£�"<<endl; 
    }
    else 
    {
        cout<<amount<<"���������������£�"<<endl; 
    }
    for(int i=0;i<amount;i++)
    {    
        count=random()%9+2;
        str_num1=create_num(proper_fs,range);
        str_num2=create_num(proper_fs,range);
        symbol=create_symbol(n);
        Equation[i]=combination(str_num1,str_num2,symbol);
        if(count>2)
        {
            for(count;count>2;count--)
            {
                symbol=create_symbol(n);
                str_num1=Equation[i];
                if(bracket==1)
                {
                    change=random()%2;
                    if(change==0)
                    {
                       str_num1='('+str_num1+')';
                     }
                } 
                symbol=create_symbol(n);
			    str_num2=create_num(proper_fs,range);	
                change=random()%2;
                if(change==0)
                {
                    temp=str_num1;
                    str_num1=str_num2;
                    str_num2=temp;
                }                
                Equation[i]=combination(str_num1,str_num2,symbol);
            }
        }
        //�ж��Ƿ��ظ�
         for(j=0;j<i;j++)
         {
             if(Equation[j]==Equation[i])
             {
                i=i-1;
                repeat=1;
                break;
             }
         }
         if(repeat!=1)//�����ظ�������� 
         {
             if(shuchu==1)
            {
                fout<<Equation[i]<<"="<<endl;
            }
            else
            {
                cout<<Equation[i]<<"="<<endl;
            }
         }
       
    }
    if(shuchu==1)
    {
        fout.close();
    }
}
