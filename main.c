// Powered by Pinus -<<-<<-<<< // 03-R-3 division (c) 2008
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "multiple.h"
//#include <math.h>

int main(int argc, char *argv[ ]){
	FILE *fileptr,*fwriter; // ��������� �� ������ (����)
	char c; // ���������-�������
	char filename[40]; // ������ ��	����� �����
	char foutname[6]={'o','u','t','.','m','\0'}; // ������������ �������� ����
	char inputchr[5]={'\012'}; // ������ ���������������������� ������� ���������� LF-�����: ���������� ����� ������ ��� atoi
	int i,k,input,j;          // ��������������� ����������
	double summare[15]={0.0}; // �������� ������� �� ������ ������� (�������)
	float freq; // ���������������  ����������	��� ������� � ������������� ��������� �������� ������� �� ������
	struct Out filtered; // ���������� �� ������� ��������� � ��������� �������� �� ������ �������� (Real Time Filtering)
	struct Out exited[4096]; // �������� ������ ���	������������ �������
	    k=0;   // �����	�� ��������������� ���������� ��������� ������
	if(argc){
		printf("The digital filtering version 3.5 stable\n"); // ��������� ����� , ���� �� ���� ��������
		puts("Choose the input signal file from here:");              // ����� �����
		for(i=1; i<61; i++){                                          // �������
			freq = (float)i*0.5;									  // ������
			if(i<10)printf("file00%d.sig => %2.1f Hz  ",i,freq);      // ��������������� ��������(��)
			else	printf("file0%d.sig => %2.1f Hz  ",i,freq);       // ������� �������� (�����)
			if(i%3 == 0)printf("\n");                                 // � ��������� �������� 12 ������� ���
		}
	}
	printf("\n");
	printf("Type input signal file name here: "); // ������ ����� �����
	gets(filename);                            // �������� ��� �������� �����
	i=0;   										// ��������� �������� �������
	if((fileptr = fopen(filename,"r")) == NULL){ // ������� ����� fileptr �� ������
		perror(filename);                        // ���� ��� ������������ - ���������� ������
		main(0,0);                              // ������� � main!
		return 1;
	}

	if((fwriter = fopen(foutname,"w")) == NULL){ // ������� ����� fwriter �� ������
		perror(foutname);                        // ���� �������� �� ����� - ���������� ������
		main(0,0);                              // ������� � main!
		return 1;
	}

	while((c=getc(fileptr)) != EOF){             // ���� �� ��������� ����� �����...

		if(c != '\012'){                             // ���� �� ���������� ����������� (LF eq 0x0A)
			i++;
			inputchr[i] = c;    // ������� � ������ ���	�������������� ������ � �����
		}
		if ((c == '\012')||(i > 4)) {
			input = atoi(inputchr); // ��������� �������� �� ������ � �����

		//!!!!!!!!!!!!!! ���������! !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

			filtered=Filtering(input); // ��������� input-� ������ ���������!
			exited[k++]=filtered; // ������� � ������ ��������, ����� ��-�������� ��������� �������� � ������, � ����� ���������� � �����������!
			if(k==1)fprintf(fwriter,"script\n Yout=[\n");                    //������� m-���� c� ��������,
			for(j=0;j<14;j++)fprintf(fwriter,"%e,\t",filtered.output[j]);    //���������� ��������� ������
			fprintf(fwriter,"%e;\n",filtered.output[14]);		             //�������� �������� �������
			if(k==4096)fprintf(fwriter,"];\n");		                         //��������!

		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

			for(i=0;i<5;i++)inputchr[i]='\012'; // ���� ���������� ����������� �������� ������
			    i=0;        // ���������� ������
		}


	}
	////////////////////////////////////////////////////////////////////////////////////////
	fclose(fileptr);                            // ������� ����
	fclose(fwriter);                            // ������� ����
	/////////////////////////////////////////////////////
	for(i=0; i<15; i++){
		for(k=0;k<4096;k++)summare[i]+= exited[k].output[i]*exited[k].output[i]; // ������� ������� �� ������ �������
		printf("From %d filter energy is:  %e   band is: %d to %d Hz \n",i+1,summare[i],i*2,i*2+2); // ������� �������
	}
	puts("Generated output file is:");
	puts(foutname);               // ��� ��������� m-�����
	/////////////////////////////////////////////////////
	getchar();                              // ����� ����� �������

	return 0;
}




