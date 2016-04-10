#!/bin/sh

#searchTimeRange.c のテストスクリプト
gcc searchTimeRange.c -o searchTimeRange

#ある時刻と、時間の範囲(開始時刻と終了時刻)を受け取る。
#時刻は、6時であれば6のような指定でよく、分単位は問わない。
echo "・0〜23以外の数字や文字はエラー"
./searchTimeRange 50 12 - 15
./searchTimeRange 3 -1 - 15
./searchTimeRange 3 12 - yahooo
./searchTimeRange 3 12 - @

echo "\n"

echo "・引数が5つ以外だとエラー"
./searchTimeRange 0 12
./searchTimeRange 0 12 - 5 5

echo "\n"

#範囲指定は、開始時刻を含み、終了時刻は含まないと判断すること。
echo "・12時から18時の間で"
./searchTimeRange 12 12 - 18
./searchTimeRange 18 12 - 18

echo "\n"

#開始時刻と終了時刻が同じ場合は含むと判断すること。
echo "・12時から12時の間で"
./searchTimeRange 12 12 - 12
./searchTimeRange 0 12 - 12

echo "\n"

#開始時刻が22時で終了時刻が5時、というような指定をされても動作すること。
echo "・22時から5時の間で"
./searchTimeRange 0 22 - 5
./searchTimeRange 23 22 - 5
./searchTimeRange 22 22 - 5
./searchTimeRange 13 22 - 5
./searchTimeRange 5 22 - 5


###############実行結果#################
# ・0〜23以外の数字や文字はエラー
# 50 is Error! Input 0~23 numbers
# -1 is Error! Input 0~23 numbers
# Error! Please input numeric numbers
# Error! Please input numeric numbers
#
#
# ・引数が5つ以外だとエラー
# Error! Please input 3 arguments as the time, start time and end time.
# Error! Please input 3 arguments as the time, start time and end time.


# ・12時から18時の間で
# 12時は12時から18時に含まれます
# 18時は12時から18時に含まれません


# ・12時から12時の間で
# 12時は12時から12時に含まれます
# 0時は12時から12時に含まれます


# ・22時から5時の間で
# 0時は22時から5時に含まれます
# 23時は22時から5時に含まれます
# 22時は22時から5時に含まれます
# 13時は22時から5時に含まれません
# 5時は22時から5時に含まれません
#######################################