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
#include <math.h>

void checkInputError(int argNum, char *argChara[4]){
	int i;
	int argInt;

	if(argNum != 4){
		printf("Error! Please input 3 arguments as the time, start time and end time.\n");
		exit(1);
	}

	for(i=1; i < argNum; i++){
		argInt = atof(argChara[i]);
		if(argInt < 0 || argInt > 23){
			printf("%d is Error! Input 0~23 numbers\n", argInt);
			exit(1);
		}
	}
}


int main(int argc, char *argv[4]){
	checkInputError(argc, argv);

	/*
	if(serchTimeRange(argc[0], argc[1], argc[2]) == 1){
		printf("%d時は%d時から%d時に含まれます", argc[0], argc[1], argc[2]);
	}
	else{
		printf("%d時は%d時から%d時に含まれません", argc[0], argc[1], argc[2]);
	}*/
}



