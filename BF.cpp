#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 100
/*
一応形だけは動くようにしたから、データの突っぱねとか細かいとこを詰めて。
動かし方はコマンドライン引数だからね

*/

int comparison(char data[],char pattern[],int datanum,int patnum) {
	int copy;
	for (int i = 0; i < datanum-1; i++) {
		copy = i;
		for (int j = 0; j < patnum;j++) {
			if (data[copy] == pattern[j]) {
				copy++;
				if (j==patnum-1) {
					return i;
				}
			}
			else {
				break;
			}
		}
	}
	return -1;
	
}//実際にデータから力任せ法で検索する関数

void showresultpoint() {

}

int main(int argc, char* argv[])
{
	
	int datanum = strlen(argv[1]);//1をデータ
	int putnum = strlen(argv[2]);//２をパターン
	int resultnum;//比較関数の実行結果を格納するint

	if (argc != 3) {
		printf("入力されたデータの数に異常があります\n");
		return -1;
	}//コマンドライン引数が３つあったら突っぱねる
	if (datanum < putnum) {
		printf("データが不正です\n");
		return -1;
	}//データよりパターンが大きかったら不正
	if (datanum > MAX_STRING_SIZE) {
		printf("データの文字数が多すぎます(%d文字以内)\n",MAX_STRING_SIZE);
		return -1;
	}//データの文字数が多すぎたら突っぱねる

	resultnum = comparison(argv[1], argv[2], datanum, putnum);//検索実行
	printf("探索対象の文字列:%s\n", argv[1]);//入力されたデータを表示
	printf("検索したい文字列:%s\n", argv[2]);//入力されたパターンを表示
	if (resultnum >= 0) {
		printf("検索結果:%d番目に存在\n", resultnum);
	}
	else {
		printf("該当する文字列は発見されませんでした\n");
	}//検索結果を表示
	
}


