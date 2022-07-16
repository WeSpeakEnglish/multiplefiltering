// Powered by Pinus -<<-<<-<<< // 03-R-3 division (c) 2008
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "multiple.h"
//#include <math.h>

int main(int argc, char *argv[ ]){
	FILE *fileptr,*fwriter; // указатели на потоки (файл)
	char c; // константа-приёмник
	char filename[40]; // массив дл	имени файла
	char foutname[6]={'o','u','t','.','m','\0'}; // генерируемый выходной файл
	char inputchr[5]={'\012'}; // массив длпреобразованивходных величин закатываем LF-амими: признаками конца строки для atoi
	int i,k,input,j;          // вспомогательные переменные
	double summare[15]={0.0}; // итоговый уровень на выходе фильтра (энергия)
	float freq; // вспомогательная  переменная	для диалога с пользователем начальные значения энергии на выходе
	struct Out filtered; // получаемая от фильтра структура с выходными уровнями на каждый входящий (Real Time Filtering)
	struct Out exited[4096]; // Заплняем массив для	последующего анализа
	    k=0;   // занул	ем вспомогательную переменную вложенных циклов
	if(argc){
		printf("The digital filtering version 3.5 stable\n"); // Заголовок проги , если не было возврата
		puts("Choose the input signal file from here:");              // Выбор файла
		for(i=1; i<61; i++){                                          // выводим
			freq = (float)i*0.5;									  // список
			if(i<10)printf("file00%d.sig => %2.1f Hz  ",i,freq);      // сгенерированных МатЛабом(тм)
			else	printf("file0%d.sig => %2.1f Hz  ",i,freq);       // входных сигналов (файлы)
			if(i%3 == 0)printf("\n");                                 // с имитацией отсчётов 12 битного АЦП
		}
	}
	printf("\n");
	printf("Type input signal file name here: "); // запрос имени файла
	gets(filename);                            // получаем имя входного файла
	i=0;   										// начальное значение индекса
	if((fileptr = fopen(filename,"r")) == NULL){ // открыть поток fileptr на чтение
		perror(filename);                        // если имя неправильное - выкидываем ошибку
		main(0,0);                              // возврат в main!
		return 1;
	}

	if((fwriter = fopen(foutname,"w")) == NULL){ // открыть поток fwriter на запись
		perror(foutname);                        // если записать не можем - выкидываем ошибку
		main(0,0);                              // возврат в main!
		return 1;
	}

	while((c=getc(fileptr)) != EOF){             // пока не достигнут конец файла...

		if(c != '\012'){                             // пока не встретится разделитель (LF eq 0x0A)
			i++;
			inputchr[i] = c;    // заносим в массив для	преобразования строки в число
		}
		if ((c == '\012')||(i > 4)) {
			input = atoi(inputchr); // считываем значения из строки в число

		//!!!!!!!!!!!!!! ОБРАБОТКА! !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

			filtered=Filtering(input); // фильтруем input-ы нашими фильтрами!
			exited[k++]=filtered; // заносим в массив структур, чтобы по-быстрому завершить операции с файлом, а потом приступить к вычислениям!
			if(k==1)fprintf(fwriter,"script\n Yout=[\n");                    //генерим m-файл cо скриптом,
			for(j=0;j<14;j++)fprintf(fwriter,"%e,\t",filtered.output[j]);    //содержащим двумерный массив
			fprintf(fwriter,"%e;\n",filtered.output[14]);		             //выходных значений длявсех
			if(k==4096)fprintf(fwriter,"];\n");		                         //фильтров!

		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

			for(i=0;i<5;i++)inputchr[i]='\012'; // если встретился разделитель обнуляем массив
			    i=0;        // сбрасываем индекс
		}


	}
	////////////////////////////////////////////////////////////////////////////////////////
	fclose(fileptr);                            // закрыть файл
	fclose(fwriter);                            // закрыть файл
	/////////////////////////////////////////////////////
	for(i=0; i<15; i++){
		for(k=0;k<4096;k++)summare[i]+= exited[k].output[i]*exited[k].output[i]; // подсчёт энергии на выходе фильтра
		printf("From %d filter energy is:  %e   band is: %d to %d Hz \n",i+1,summare[i],i*2,i*2+2); // выводим энергию
	}
	puts("Generated output file is:");
	puts(foutname);               // имя выходного m-файла
	/////////////////////////////////////////////////////
	getchar();                              // ждать ввода символа

	return 0;
}




