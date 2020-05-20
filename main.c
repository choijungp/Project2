#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
    stat("text1", &stat1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
    stat("text2", &stat2);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
	time1 = localtime(&stat1.st_mtime);    
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
	time2 = localtime(&stat2.st_mtime);
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
	int size1 = stat1.st_size;
	int size2 = stat2.st_size;

	printf("size compare\n");

	if (size1 > size2)
		printf("text1 is bigger\n");
	else if (size2 > size1)
		printf("text2 is bigger\n");
	else
		printf("sizes are equal\n");
	printf("\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
	int block1 = stat1.st_blocks;
	int block2 = stat2.st_blocks;

	printf("block compare\n");

	if (block1 > block2)
		printf("text1 is bigger\n");
	else if (block2 > block1)
		printf("text2 is bigger\n");
	else
		printf("sizes are equal\n");
	printf("\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
   int t1_year, t1_mon, t1_day;
   int t2_year, t2_mon, t2_day;

   time1 = localtime(&stat1.st_mtime);
   t1_mon = time1->tm_mon;
   t1_day = time1->tm_mday;
   t1_year = time1->tm_year;

   time2 = localtime(&stat2.st_mtime);
   t2_mon = time2->tm_mon;
   t2_day = time2->tm_mday;
   t2_year = time2->tm_year;

   printf("date compare\n");
   if (t1_year < t2_year)
      printf("text1 is early\n");
   else if (t1_mon < t2_mon)
      printf("text2 is early\n");
   else
   {
      if (t1_day < t2_day)
         printf("text1 is early\n");
      else if (t1_day > t2_day)
         printf("text2 is early\n");
      else
         printf("same date\n");
   }
   printf("\n");

}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
   int t1_hour, t1_min, t1_sec;
   int t2_hour, t2_min, t2_sec;

   time1 = localtime(&stat1.st_mtime);
   t1_hour = time1->tm_hour;
   t1_min = time1->tm_min;
   t1_sec = time1->tm_sec;

   time2 = localtime(&stat2.st_mtime);
   t2_hour = time2->tm_hour;
   t2_min = time2->tm_min;
   t2_sec = time2->tm_sec;

   printf("time compare\n");

   if (t2_hour > t1_hour)
      printf("text1 is early\n");
   else if (t2_hour < t1_hour)
      printf("text2 is early\n");
   else
   {
      if (t2_min > t1_min)
         printf("text1 is early\n");
      else if (t2_min < t1_min)
         printf("text2 is early\n");
      else
         printf("same time\n");
   }
   printf("\n");    
}
