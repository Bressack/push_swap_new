# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test5.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 15:46:40 by tharchen          #+#    #+#              #
#    Updated: 2021/06/12 18:19:23 by tharchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_G_BLACK="\033[30;01m"
C_G_RED="\033[31;01m"
C_G_GREEN="\033[32;01m"
C_G_YELLOW="\033[33;01m"
C_G_BLUE="\033[34;01m"
C_G_MAGENTA="\033[35;01m"
C_G_CYAN="\033[36;01m"
C_G_WHITE="\033[37;01m"
C_G_GREY="\033[90;01m"
C_RES='\033[0m'

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
	_CHECKER_STAFF=checker_linux
elif [[ "$OSTYPE" == "darwin"* ]]; then
	_CHECKER_STAFF=checker_mac
fi

tester_dir=`pwd`/`dirname $0`

checker_staff=${tester_dir}/$_CHECKER_STAFF

bins_dir=$1

bin_push_swap=$bins_dir/push_swap

STACKS=(
	"1 2 3 4 5" "2 1 3 4 5" "5 1 2 3 4" "2 3 4 5 1" "1 5 2 3 4" "3 2 4 5 1"
	"5 2 1 3 4" "4 5 1 2 3" "1 3 4 5 2" "3 4 5 1 2" "2 5 1 3 4" "5 4 1 2 3"
	"3 1 4 5 2" "4 3 5 1 2" "4 1 5 2 3" "1 3 2 4 5" "4 5 2 1 3" "5 2 3 4 1"
	"2 4 5 1 3" "3 4 5 2 1" "1 4 5 2 3" "3 1 2 4 5" "5 4 2 1 3" "2 5 3 4 1"
	"4 2 5 1 3" "4 3 5 2 1" "3 5 4 1 2" "2 3 1 4 5" "2 4 3 5 1" "3 4 1 5 2"
	"5 1 3 2 4" "5 1 3 4 2" "4 1 2 3 5" "3 5 1 2 4" "2 3 4 1 5" "4 5 1 3 2"
	"1 2 5 3 4" "1 4 3 5 2" "1 5 3 2 4" "1 2 4 5 3" "5 3 4 1 2" "3 2 1 4 5"
	"4 2 3 5 1" "4 3 1 5 2" "1 5 3 4 2" "1 4 2 3 5" "5 3 1 2 4" "3 2 4 1 5"
	"5 4 1 3 2" "2 1 5 3 4" "4 1 3 5 2" "2 1 4 5 3" "3 5 4 2 1" "3 4 2 5 1"
	"2 3 5 4 1" "5 2 3 1 4" "1 2 4 3 5" "4 1 2 5 3" "2 1 4 3 5" "4 1 5 3 2"
	"4 5 2 3 1" "4 2 1 3 5" "3 5 2 1 4" "1 3 4 2 5" "1 2 3 5 4" "5 1 2 4 3"
	"5 3 2 4 1" "2 4 5 3 1" "1 3 5 2 4" "1 5 4 2 3" "5 1 4 2 3" "1 4 2 5 3"
	"2 5 4 1 3" "2 5 3 1 4" "1 4 5 3 2" "2 3 5 1 4" "5 3 4 2 1" "4 3 2 5 1"
	"3 2 5 4 1" "5 4 2 3 1" "2 4 1 3 5" "5 3 2 1 4" "3 1 4 2 5" "2 1 3 5 4"
	"1 5 2 4 3" "3 5 2 4 1" "4 2 5 3 1" "3 1 5 2 4" "5 2 4 1 3" "3 2 5 1 4"
	"2 4 3 1 5" "4 5 3 1 2" "4 2 1 5 3" "1 3 5 4 2" "3 4 1 2 5" "5 2 1 4 3"
	"2 4 1 5 3" "3 1 5 4 2" "3 5 1 4 2" "4 1 3 2 5" "5 3 1 4 2" "4 5 3 2 1"
	"1 5 4 3 2" "5 4 3 1 2" "2 5 1 4 3" "1 2 5 4 3" "2 1 5 4 3" "4 2 3 1 5"
	"4 3 1 2 5" "1 4 3 2 5" "5 4 3 2 1" "5 1 4 3 2" "1 3 2 5 4" "5 2 4 3 1"
	"3 4 2 1 5" "2 3 1 5 4" "2 5 4 3 1" "3 1 2 5 4" "3 2 1 5 4" "4 3 2 1 5"
)

# STACKS=(
# "1 2 3 4"
# "2 1 3 4"
# "4 1 2 3"
# "2 3 4 1"
# "1 4 2 3"
# "3 2 4 1"
# "4 2 1 3"
# "3 4 1 2"
# "1 3 4 2"
# "2 4 1 3"
# "4 3 1 2"
# "3 1 4 2"
# "1 3 2 4"
# "3 4 2 1"
# "4 2 3 1"
# "3 1 2 4"
# "4 3 2 1"
# "2 4 3 1"
# "2 3 1 4"
# "4 1 3 2"
# "1 2 4 3"
# "1 4 3 2"
# "3 2 1 4"
# "2 1 4 3"
# "3 1 2 4"
# "3 1 4 2"
# "3 2 1 4"
# "3 2 4 1"
# "3 4 1 2"
# "3 4 2 1"
# )

test()
{
	$bin_push_swap $1 > test5.$1.output
	RESULT=`cat test5.$1.output | $checker_staff $1`
	if [[ $RESULT == "OK" ]]; then
		COLOR_RESULT=$C_G_GREEN
	else
		COLOR_RESULT=$C_G_RED
	fi
	COUNT=`cat test5.$1.output | wc -l`
	if (( $COUNT < 13 )); then
		COLOR_COUNT=$C_G_GREEN
	else
		COLOR_COUNT=$C_G_RED
	fi
	# if (( $COUNT > 12 )); then
		echo "$COLOR_COUNT $COUNT $C_RES operation(s) | stack $C_G_YELLOW $1 $C_RES: $COLOR_RESULT $RESULT $C_RES"
	# fi
	rm test5.$1.output
}

for stack in $STACKS; do
	test $stack
done
