#ifndef	multiple_h
#define	multiple_h

int * hist_ptr[15];
double const  * Coefs_ptr[15];
struct Out{
double output[15];
};


struct Out Filtering(int);

#endif



