// 卷积编码(r=1/2,k=3)
// g1= 1 1 1
// g2= 1 0 1
//　输入l bit，输出(2*l+4)bit，在信息序列较长的时候接近于1/2
// 当前程序给每bit分配了1个int的空间，可改进

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cv_code(int *buff_in,int k,int *buff_out);
int move(int *buff);

int main()
{
	int m[3]={1,0,1};
	//
	int out[10];//
	cv_code(m,3,out);

	// for(int i=0;i<10;i++)
	// {
	// 	printf("%d ",out[i]);
	// }
	// printf("\n");

	return 0;
}

int cv_code(int *buff_in,int k,int *buff_out)
{
	int len=sizeof(buff_in)/sizeof(int)+1;
	int count=0;
	int *temp;
	temp=(int*)calloc(k,sizeof(int));
	memset(temp,0,k);
    for(int i=0;i<len;i++)
    {
    	move(temp);
    	temp[0]=buff_in[i];
    	buff_out[count++]=(temp[0]+temp[1]+temp[2])%2;//
    	buff_out[count++]=(temp[0]+temp[2])%2;//
    }
    for(int i=0;i<len-1;i++)
    {
    	move(temp);
    	temp[0]=0;
    	buff_out[count++]=(temp[0]+temp[1]+temp[2])%2;//
    	buff_out[count++]=(temp[0]+temp[2])%2;//
    }

	free(temp);
	return 0;
}

int move(int *buff)
{
	int len=sizeof(buff)/sizeof(int)+1;
	for(int i=0;i<len-1;i++)
	{
		buff[len-i-1]=buff[len-i-2];
	}
}