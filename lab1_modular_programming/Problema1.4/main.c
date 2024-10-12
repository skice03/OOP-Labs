#include<stdio.h>

#ifdef __APPLE__
	#define os 1
#endif

#ifdef _WIN32
	#define os 2
#endif

#ifdef __linux__
	#define os 3
#endif

void check_os()
{

	if(os==1) printf("Hello Mac user!");
	else if (os==2) printf ("Hello Windows user!");
	else if (os==3)	printf("Hello Linux user!");

}

int main()
{
	check_os();

	return 0;
}
