#include <iostream>
#include<windows.h>
#include<time.h>
#include<ctime>
#include<math.h>
using namespace std;

int main()
{
//    ----------//0、低精度算大规模计算速度（tick计算）//--------------
//    int (*a)[10000]=new int [10000][10000];//终于对了，注意复习c++
//    for(int i=0;i<10000;i++){
//       for(int j = 0; j < 10000; j++)
//       a[i][j] = i+j;
//    }
////
//    int sum[10000]={0},b[10000]={0};
//    for(int i=0;i<10000;i++){
//        b[i]=i*i;
//    }
////
//    DWORD startime1 = GetTickCount();
//    for(int i=0;i<10000;i++){
//       sum[i] = 0.0;
//       for(int j = 0; j < 10000; j++)
//       sum[i] += a[j][i]*b[j];//按列计算向量
//    }
//    DWORD endtime1=GetTickCount();
//    cout<<"first time is"<<endtime1-startime1<<"ms"<<endl;
//    cout<<"sum[10]="<<sum[10]<<endl;
////
//    DWORD startime2 = GetTickCount();
//    int sum2[10000]={0};
//    for(int j = 0; j < 10000; j++)
//      for(int i = 0; i < 10000; i++)
//        sum2[i] += a[j][i] *b[j];
//    DWORD endtime2=GetTickCount();
//    cout<<"second time is"<<endtime2-startime2<<"ms"<<endl;
//    cout<<"sum2[10]="<<sum2[10]<<endl;
////
            //clock也可，更准确//
//


//      ----------//1、低精度算大规模计算速度//--------------

//    int (*a)[10000]=new int [10000][10000];//终于对了，注意复习c++
//    for(int i=0;i<10000;i++){
//       for(int j = 0; j < 10000; j++)
//       a[i][j] = i+j;
//    }
////
//    int sum1[10000]={0},b[10000]={0};
//    for(int i=0;i<10000;i++){
//        b[i]=i*i;
//    }
////
//    clock_t startime1=clock();
//    for(int i=0;i<10000;i++){
//       sum1[i] = 0.0;
//       for(int j = 0; j < 10000; j++)
//       sum1[i] += a[j][i]*b[j];//按列计算向量
//    }
//    clock_t endtime1=clock();
//    cout<<"first time is"<<endtime1-startime1<<"ms"<<endl;
//    cout<<"sum1[10]="<<sum1[10]<<endl;
////
//    int sum2[10000]={0};
//    clock_t startime2 = clock();
//    for(int j = 0; j < 10000; j++)
//      for(int i = 0; i < 10000; i++)
//        sum2[i] += a[j][i] *b[j];
//    clock_t endtime2=clock();
//    cout<<"second time is"<<endtime2-startime2<<"ms"<<endl;
//    cout<<"sum2[10]="<<sum2[10]<<endl;
////
////     ------------//2、高精度计算//---------------
////
//    double time = 0,time2 = 0;
//    //int (*a2)[100]=new int [100][100];//终于对了，注意复习c++
//    int a2[100][100]={0};
//    for(int i=0;i<100;i++){
//       for(int j = 0; j < 100; j++)
//       a2[i][j] = i+j;
//    }
////
//    long long int sum3[100]={0},b2[100]={0};
//    for(int i=0;i<100;i++){
//        b2[i]=i*i;
//    }
////
////
////  clock_t startime3=clock();
//
//    LARGE_INTEGER nFreq;
//	LARGE_INTEGER nBeginTime;
//	LARGE_INTEGER nEndTime;
//	QueryPerformanceFrequency(&nFreq);
//	QueryPerformanceCounter(&nBeginTime);//开始计时
//    for(int i=0;i<100;i++){
//       for(int j = 0; j < 100; j++)
//       sum3[i] += a2[j][i]*b2[j];//按列计算向量
//    }
//
////  clock_t endtime3=clock();
//
//    QueryPerformanceCounter(&nEndTime);//停止计时
//    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s
//	cout << "程序执行时间：" << time * 1000000 << "us" << endl;
//
////
//    long int sum4[100]={0};
//    QueryPerformanceCounter(&nBeginTime);
//    for(int j = 0; j < 100; j++)
//      for(int i = 0; i < 100; i++)
//        sum4[i] += a2[j][i] *b2[j];
//    QueryPerformanceCounter(&nEndTime);
//    time2 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s
//	cout << "程序执行时间：" << time2 * 1000000 << "us" << endl;
//
//
//	////     ------------//3、循环展开计算//---------------
////
//    long long int sum5[100]={0},sum51[100]={0},sum52[100]={0};
//    double time3=0;
//    QueryPerformanceCounter(&nBeginTime);
//    for(int j = 0; j < 100; j++){
//      for(int i = 0; i < 100; i+=2)
//      {
//        sum51[i] += a2[j][i] *b2[j];
//        sum52[i+1] += a2[j][i+1]*b2[j];
//      }
//    }
//    for(int i=0;i<100;i+=2)
//    {
//        sum5[i]=sum51[i];
//        sum5[i+1]=sum52[i+1];
//    }
//    QueryPerformanceCounter(&nEndTime);
//    time3 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s
//	cout << "程序执行时间：" << time3 * 1000000 << "us" << endl;



//            ------------超标量优化------------

    long long int a[100]={0};double time,time2,time3;
    for(int i=0;i<100;i++)
        a[i]=pow(2,i);
    long long int sum1=0,sum2=0;
    int k=10000;
    LARGE_INTEGER nFreq,freq2;
 	LARGE_INTEGER nBeginTime,begin2,begin3;
	LARGE_INTEGER nEndTime,end2,end3;
	QueryPerformanceFrequency(&nFreq);

//          ---------0.平凡算法--------
    QueryPerformanceCounter(&nBeginTime);//开始计时
    while(k)
    {
      for (int i = 0; i < 100; i++)
        sum1 += a[i];
      k--;
    }
    QueryPerformanceCounter(&nEndTime);//停止计时
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    cout << "0程序执行时间：" << time * 1000000 << "us" << endl;

//          ---------1.链式算法(循环展开)---------

    int sum21 = 0,sum22 = 0;
    k=10000;
    QueryPerformanceCounter(&begin2);//开始计时
    while(k){
        for (int i = 0;i < 100; i += 2) {
         sum21 += a[i];
         sum22 += a[i + 1];
      }
       sum2 = sum21 + sum22;
       k--;
    }
    QueryPerformanceCounter(&end2);//停止计时
    time2 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    cout << "1程序执行时间：" << time2 * 1000000 << "us" << endl;

//          ----------2.递归算法----------
    k=10000;
    QueryPerformanceCounter(&begin3);
    while(k){
      for (int m = 100; m > 1; m /= 2)
        for (int i = 0; i < m / 2; i+=3)
        {
          a[i] = a[i * 2] + a[i * 2 + 1];
          a[i+1]=a[(i+1)*2]+a[(i+1)*2+1];
          a[i+2]=a[(i+2)*2]+a[(i+2)*2+1];
        }
      k--;
    }
    QueryPerformanceCounter(&end3);//停止计时
    time3 = (double)(end3.QuadPart - begin3.QuadPart) / (double)nFreq.QuadPart;
    cout << "2程序执行时间：" << time3 * 1000000<< "us" << endl;

    return 0;
}
