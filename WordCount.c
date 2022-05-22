#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 1024
/**
 * ͳ���ļ��ĵ�����
 * @param  filename  �ļ���
 * @return  �ɹ����ص����������򷵻�NULL
**/
int *getWordNum(char *filename){
    FILE *fp;
    char buffer[MAX_NUM]; 
    int isLastBlank = 0;  // �ϸ��ַ��Ƿ��ǿո�
    int wordNum = 0;
    int i;
    char c;
    if( (fp=fopen(filename, "rb")) == NULL ){
    	printf("�ļ�����");
        perror(filename);
        exit(1);
        return NULL;
    }
    while(fgets(buffer, MAX_NUM, fp) != NULL){
        for(i=0; i<strlen(buffer); i++){
            c = buffer[i];
            if( c==' ' || c=='\t'){
                !isLastBlank && wordNum++;
                isLastBlank = 1;
            }else if( c==',' || c=='.'){
                !isLastBlank && wordNum++;
                isLastBlank = 1;
            }else if(c!='\n'&&c!='\r'){
                isLastBlank = 0;
            }
        }
        !isLastBlank && wordNum++;
        isLastBlank = 1;
    }
    return wordNum;
}
/**
 * ͳ���ļ��ĵ�����
 * @param  filename  �ļ���
 * @return  �ɹ������ļ��ַ����������򷵻�NULL
**/
int *getCharNum(char* filename){
	char buffer[MAX_NUM];//�ַ�������
	FILE* fp;
	int tmp, charNum = 0;//ÿ���ַ�������������
	if ((fp = fopen(filename, "r")) == NULL) {
		printf("�ļ�����");
		perror(filename);
		exit(1);
	}
	while (!feof(fp) && !ferror(fp)) {
		fgets(buffer, MAX_NUM, fp);
		tmp = strlen(buffer);
		if (tmp == 0) 
			continue;
		charNum += tmp;
	}
	fclose(fp);
	return charNum;
}


int main(int argc,char *argv[]) {
	int ch;
    while ((ch = getopt(argc,argv,"w:c"))!=-1)  
    {  
        switch(ch)  
        {  
            case 'c':  
                printf("�ַ�����%d",getCharNum(argv[argc-1])); 
                break;  
            case 'w':  
                printf("��������%d",getWordNum(argv[argc-1])); 
            	break;  
        }  
    }
    return 0;
}


