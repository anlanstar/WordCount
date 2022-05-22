#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 1024
/**
 * 统计文件的单词数
 * @param  filename  文件名
 * @return  成功返回单词数，否则返回NULL
**/
int *getWordNum(char *filename){
    FILE *fp;
    char buffer[MAX_NUM]; 
    int isLastBlank = 0;  // 上个字符是否是空格
    int wordNum = 0;
    int i;
    char c;
    if( (fp=fopen(filename, "rb")) == NULL ){
    	printf("文件错误！");
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
 * 统计文件的单词数
 * @param  filename  文件名
 * @return  成功返回文件字符数数，否则返回NULL
**/
int *getCharNum(char* filename){
	char buffer[MAX_NUM];//字符缓冲区
	FILE* fp;
	int tmp, charNum = 0;//每行字符个数和总字数
	if ((fp = fopen(filename, "r")) == NULL) {
		printf("文件错误！");
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
                printf("字符数：%d",getCharNum(argv[argc-1])); 
                break;  
            case 'w':  
                printf("单词数：%d",getWordNum(argv[argc-1])); 
            	break;  
        }  
    }
    return 0;
}


