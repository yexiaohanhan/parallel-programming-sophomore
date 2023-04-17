#include <sys/time.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>
using namespace std;
const int N=200;
float m[N][N];
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
		__m256 vt= _mm256_set1_ps(m[k][k]);
		for(int j=k+1;j<N;j+=8)
		{
			if(j+8>N)
				for(;j<N;j++)
					m[k][j]=m[k][j]/m[k][k];
			else
			{
				__m256 va= _mm256_loadu_ps(m[k]+j);
				va= _mm256_div_ps(va,vt);
				_mm256_storeu_ps(m[k]+j,va);
			}
			m[k][k]=1.0;
		}
		m[k][k]=1.0;
		for(int i=k+1;i<N;i++)
		{
			for(int j=k;j<N;j+=8)
			{
				if(j+8>N)
					for(;j<N;j++)
						m[i][j]=m[i][j]-m[i][k]*m[k][j];//rest value
				else//pal
				{
					__m256 temp1= _mm256_loadu_ps(m[i]+j);
					__m256 temp2= _mm256_loadu_ps(m[k]+j);
					__m256 temp3= _mm256_set1_ps(m[i][k]);
					temp2= _mm256_mul_ps(temp3,temp2);
					temp1= _mm256_sub_ps(temp1,temp2);
					_mm256_storeu_ps(m[i]+j,temp1);
				}
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
