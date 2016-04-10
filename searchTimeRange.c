/********************************************************************
@Overview
ある時刻(0時～23時)が、指定した時間の範囲内に含まれるかどうかを調べるプログラム．
以下のような条件を満たす．
- ある時刻と、時間の範囲(開始時刻と終了時刻)を受け取る。
- 時刻は、6時であれば6のような指定でよく、分単位は問わない。
- 範囲指定は、開始時刻を含み、終了時刻は含まないと判断すること。
- ただし開始時刻と終了時刻が同じ場合は含むと判断すること。
- 開始時刻が22時で終了時刻が5時、というような指定をされても動作すること。

@author Ayano Masaki
********************************************************************/

#include <stdio.h>
#include <stdlib.h>


void checkInputError(char *argv[3]){
	int i;

	if(argc != 3){
		printf("Error! Please input 3 arguments as the time, start time and end time.")
		exit(1);
	}

	for(i=0; i < argc; i++){
		if(argc[i] < '0' || argc[i] > '23'){
			printf("Error! Input 0~23 numbers");
		}
	}
}


int main(int argc, char *argv[3]){

	if(serchTimeRange(argc[0], argc[1], argc[2]) == 1){
		printf("%d時は%d時から%d時に含まれます", argc[0], argc[1], argc[2]);
	}
	else{
		printf("%d時は%d時から%d時に含まれません", argc[0], argc[1], argc[2]);
	}
}



