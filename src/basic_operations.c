#include <stdlib.h>
#include <assert.h>
#include "basic_operations.h"
static int compare (const void * a, const void * b)
{
    double _a = *(double*)a;
    double _b = *(double*)b;
    if(_a < _b) return -1;
    else if(_a == _b) return 0;
    else return 1;
}

double mean(double* array,int el_count)
{
  assert(el_count>0);
  double sum=0;
  for(int i=0;i<el_count;i++){
    sum+=array[i];
  }
  return sum/el_count;
}

double median(double* array,int el_count)
{
  assert(el_count>0);
  qsort(array,el_count,sizeof(double),compare);
  if(el_count%2==0)
    return (array[(el_count)/2]+array[(el_count)/2-1])/2;
  return array[(el_count-1)/2];
}
int mode(double* array, int el_count,double* output)
{
  assert(el_count>0);
  double max_value=0;
  int max_count=0,i,j,mode_count=0;
  for(i=0;i<el_count;i++){
    int count=0;
    for(j=i+1;j<el_count;j++){
      if(array[j]==array[i])
        ++count;
    }
    if(count>max_count){
      mode_count=1;
      max_count=count;
      max_value=array[i];
    }
    else if(count==max_count)
      mode_count++;
  }
  if(mode_count==1)
    *output=max_value;
  return mode_count==1?1:-1;
}
int range(double* array,int el_count,double *output)
{
  assert(el_count>0);
  double max=array[0],min=array[0];
  for(int i=0;i<el_count;i++){
    if(array[i]>max)
      max=array[i];
    if(array[i]<min)
      min=array[i];
  }
  *output=max-min;
  return 1;
}
