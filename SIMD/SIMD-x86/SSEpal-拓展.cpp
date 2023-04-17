#include <sys/time.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>
using namespace std;
const int N=1000;
float m[N+3][N+3];
void m_reset()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<i;j++)
			m[i][j]=0;
		m[i][i]=1.0;
		for(int j=i+1;j<N;j++)
			m[i][j]=rand();
	}
	for(int k=0;k<N;k++)
		for(int i=k+1;i<N;i++)
			for(int j=0;j<N;j++)
				m[i][j]+=m[k][j];
}
int main(){
	struct timeval start;
	struct timeval end;//clock
	float timecount;
	m_reset();
	gettimeofday(&start,NULL);
	for(int cy=0;cy<20;cy++){
		for(int k=0;k<N;k++)
		{
			__m128 vt= _mm_set1_ps(m[k][k]);
			for(int j=k+1;j<N;j+=4)
			{

					__m128 va= _mm_loadu_ps(m[k]+j);
					va= _mm_div_ps(va,vt);
					_mm_storeu_ps(m[k]+j,va);
				m[k][k]=1.0;
			}
			m[k][k]=1.0;
			for(int i=k+1;i<N;i++)
			{
				for(int j=k;j<N;j+=4)
				{
						__m128 temp1= _mm_loadu_ps(m[i]+j);
						__m128 temp2= _mm_loadu_ps(m[k]+j);
						__m128 temp3= _mm_set1_ps(m[i][k]);
						temp2= _mm_mul_ps(temp3,temp2);
						temp1= _mm_sub_ps(temp1,temp2);
						_mm_storeu_ps(m[i]+j,temp1);
					m[i][k]=0;
				}
			}
		}
	}
	gettimeofday(&end,NULL);
	timecount+=(end.tv_sec-start.tv_sec)*1000000+end.tv_usec-start.tv_usec;
	cout<<timecount/20<<endl;
	return 0;
}