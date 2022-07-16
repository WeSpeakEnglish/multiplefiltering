#include <stdio.h>
#include "filter1.h"
#include "filter2.h"
#include "filter3.h"
#include "filter4.h"
#include "filter5.h"
#include "filter6.h"
#include "filter7.h"
#include "filter8.h"
#include "filter9.h"
#include "filter10.h"
#include "filter11.h"
#include "filter12.h"
#include "filter13.h"
#include "filter14.h"
#include "filter15.h"
#include "multiple.h"

int history [15][161]={0}; // ������������������ ������� (��������� ��������)
int k,i;
struct Out out; // �������� ��������� � �����������

struct Out Filtering(int input){

input -= 2048;  // ����� ���������
Coefs_ptr[0] = &Coeffs1[160];   //���������� � ������������� ���������
Coefs_ptr[1] = &Coeffs2[160];
Coefs_ptr[2] = &Coeffs3[160];
Coefs_ptr[3] = &Coeffs4[160];
Coefs_ptr[4] = &Coeffs5[160];
Coefs_ptr[5] = &Coeffs6[160];
Coefs_ptr[6] = &Coeffs7[160];
Coefs_ptr[7] = &Coeffs8[160];
Coefs_ptr[8] = &Coeffs9[160];
Coefs_ptr[9] = &Coeffs10[160];
Coefs_ptr[10] = &Coeffs11[160];
Coefs_ptr[11] = &Coeffs12[160];
Coefs_ptr[12] = &Coeffs13[160];
Coefs_ptr[13] = &Coeffs14[160];
Coefs_ptr[14] = &Coeffs15[160];

for(i=0; i<15; i++)	{ // ��� ���������� ��������
hist_ptr[i] = &history[i][160]; // ��������� ��������� � ���������� ��������
out.output[i] =0.0;             // �������� �����
for(k=1; k<161; k++){           // ��� 160 ������������
	*hist_ptr[i] = *(hist_ptr[i]-1); // ������� � ����� (160-� �����������) ����������� (������� ���� ������ �� ��������� ������� ���� ("shifting"))...
	out.output[i] += (double)(*hist_ptr[i]--)*(*Coefs_ptr[i]--); //���������� � ���������� � ������� (��������� � �����������), ������� ���������
  }
 *hist_ptr[i] = input; // ������� ������� � �������
 out.output[i]+=input*(*Coefs_ptr[i]); // ����������� �� 0-� ����������� � ���������� � ������
}
return out;
}



