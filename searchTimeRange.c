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

#define ARGMENTS_LIMIT_NUMBER 4

int *strings2Int(int size, char *strings[]){
	int i = 1;
	int argInt[size-1];
	
	for(i = 1; i < size; i++){
		argInt[i-1] = atof(strings[i]);
	}
	return &argInt;
}

void checkInputError(int argNum, int *argIntNums){
	int i;

	if(argNum != ARGMENTS_LIMIT_NUMBER){
		printf("Error! Please input 3 arguments as the time, start time and end time.\n");
		exit(1);
	}

	for(i = 0; i < argNum-1; i++){
		if(argIntNums[i] < 0 || argIntNums[i] > 23){
			printf("%d is Error! Input 0~23 numbers\n", argIntNums[i]);
			exit(1);
		}
	}
}

int searchTimeRange(int *times){
	int searchedTime;
	int fromTime;
	int endTime;

	searchedTime  = times[0];
	fromTime      = times[1];
	endTime       = times[2]; 
	
	if(fromTime < endTime){
		if(fromTime <= searchedTime && searchedTime < endTime){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if(fromTime == endTime){
		if(fromTime <= searchedTime && searchedTime <= endTime){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		if(fromTime <= searchedTime || searchedTime < endTime){
			return 1;
		}
		else{
			return 0;
		}
	}
}

int main(int argc, char *argv[]){
	int *argIntNums;

	argIntNums = strings2Int(argc, argv);
	checkInputError(argc, argIntNums);

	if(searchTimeRange(argIntNums) == 1){
		//任意の処理を書く
		printf("%d時は%d時から%d時に含まれます\n", argIntNums[0], argIntNums[1], argIntNums[2]);
	}
	else{
		//任意の処理を書く
		printf("%d時は%d時から%d時に含まれません\n", argIntNums[0], argIntNums[1], argIntNums[2]);
	}
}



