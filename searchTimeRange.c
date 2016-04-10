/********************************************************************
@Overview
ある時刻(0時～23時)が、指定した時間の範囲内に含まれるかどうかを調べるプログラム．
以下のような条件を満たす．
- ある時刻と、時間の範囲(開始時刻と終了時刻)を受け取る。
- 時刻は、6時であれば6のような指定でよく、分単位は問わない。
- 範囲指定は、開始時刻を含み、終了時刻は含まないと判断する。
- ただし開始時刻と終了時刻が同じ場合は含むと判断する。
- 開始時刻が22時で終了時刻が5時、というような指定をされても動作する。

@Usage
リンカ起動時にコマンドライン引数を4つ以下のように記述する。
./searchTimeRange ある時刻 開始時刻 - 終了時刻

例：6時が10時から12時の間に含まれるかどうか調べる
./searchTimeRange 6 10 - 12

@author Ayano Masaki
********************************************************************/

#include <stdio.h>
#include <stdlib.h>

//コマンドライン引数の上限数
#define ARGMENTS_LIMIT 5

//調べる時刻のコマンドライン引数での番号指定
#define SEARCHED_TIME_ARG 1

//開始時刻のコマンドライン引数での番号指定
#define START_TIME_ARG 2

//終了時刻のコマンドライン引数での番号指定
#define END_TIME_ARG 4

/**
 * strings2Int
 * コマンドラインで受け取った文字列から時刻を表す文字だけを抜き出し、数値に変換する関数
 * @input
 * 	char *strings[] コマンドライン文字列
 * 	int *times 変換後の時刻の数値を格納するメモリのポインタ
*/
void args2Int(char *strings[],int *times){
	char *ep = NULL;//strodの変換不能文字列を格納するメモリのポインタ

	//times[0]に調べる時刻・times[1]に開始時刻・times[2]に終了時刻の数値を格納
	times[0] = strtod(strings[SEARCHED_TIME_ARG], &ep);
	times[1] = strtod(strings[START_TIME_ARG], &ep);
	times[2] = strtod(strings[END_TIME_ARG], &ep);

	//文字が含まれていた場合はエラー
	//エラー文字がNULLではない=何か格納されている
	if(ep != NULL){
		//エラー文字は数字ではない=文字である
		if( !('0' <= ep[0] && ep[0] <= '9')){
			printf("Error! Please input numeric numbers\n");
			//もしエラーがあればプログラムを終了する
			exit(1);
		}
	}
}

/**
 * checkInputError
 * 時間の範囲(0〜23)の数値であるかどうかのチェックを行う関数
 * @input
 * 	int *times 調べる時刻・開始時刻・終了時刻の数値が格納されたメモリのポインタ
*/
void checkInputError(int *times){
	int i;
	//時刻の数字が0〜23かのチェック
	for(i = 0; i < 3; i++){
		if(times[i] < 0 || times[i] > 23){
			printf("%d is Error! Input 0~23 numbers\n", times[i]);
			exit(1);
		}
	}
}

/**
 * searchTimeRange
 * 調べる時刻が開始時刻と終了時刻の範囲に含まれているか確認する関数
 * @input
 * 	int *times 調べる時刻・開始時刻・終了時刻の数値が格納されたメモリのポインタ
 * @output
 *  範囲に含まれる場合は1、含まれない場合は0
*/
int searchTimeRange(int *times){
	int searchedTime;//調べる時刻
	int fromTime;//開始時刻
	int endTime;//終了時刻

	searchedTime  = times[0];
	fromTime      = times[1];
	endTime       = times[2]; 
	
	//開始時刻が終了時刻より早い場合=日を跨いでいない場合
	if(fromTime < endTime){
		//開始時刻 <= 調べる時刻 < 終了時刻　のとき含むと判断する
		if(fromTime <= searchedTime && searchedTime < endTime){
			return 1;
		}
		else{
			return 0;
		}
	}
	//開始時刻が終了時刻と同じ場合
	else if(fromTime == endTime){
		//含むと判断する
		return 1;
	}
	//終了時刻が開始時刻より早い場合=日を跨いでいる場合
	else{
		//開始時刻 <= 調べる時刻 または 調べる時刻 < 終了時刻　のとき含むと判断する
		if(fromTime <= searchedTime || searchedTime < endTime){
			return 1;
		}
		else{
			return 0;
		}
	}
}

/**
 * main
 *　標準入出力を行う関数
 * @input
 * 	コマンドラインからの時刻文字列
 * @output
 * 	調べた結果の標準出力
*/
int main(int argc, char *argv[]){
	//時刻の数値を格納するメモリ領域の確保
	int times[3];
	
	//コマンドライン引数の個数チェック
	if(argc != ARGMENTS_LIMIT){
		printf("Error! Please input 3 arguments as the time, start time and end time.\n");
		exit(1);
	}

	//時刻の数値を取り出す
	args2Int(argv, &times[0]);

	//エラーチェック
	checkInputError(times);

	//調べた結果の標準出力

	//範囲内の場合
	if(searchTimeRange(times) == 1){
		//任意の処理を書く
		printf("%d時は%d時から%d時に含まれます\n", times[0], times[1], times[2]);
	}
	//範囲外の場合
	else{
		//任意の処理を書く
		printf("%d時は%d時から%d時に含まれません\n", times[0], times[1], times[2]);
	}
}



