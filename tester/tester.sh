# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tharchen <tharchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 17:10:52 by tharchen          #+#    #+#              #
#    Updated: 2021/06/15 12:42:22 by tharchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Created by lmalki-h with <3
# Usage: bash visualise.sh [directory to push_swap and ${checker_staff} progs ] [stacksize 0R stacksize_min-stacksize_max ] [nb_of_test per stacksize]
# Example 1: bash visualise.sh ../push_swap/ 5 100
# Will test your program 100 times with a stack of 5 random ints
# Example 2: bash visualise.sh ../push_swap/ 3-5 50
# Will test your program 50 times with a stack of 3 random ints, then 50 times with 4 ints , then 50 times with 5 ints.

NOCOLOR='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
LIGHTGRAY='\033[0;37m'
DARKGRAY='\033[1;30m'
LIGHTRED='\033[1;31m'
LIGHTGREEN='\033[1;32m'
YELLOW='\033[1;33m'
LIGHTBLUE='\033[1;34m'
LIGHTPURPLE='\033[1;35m'
LIGHTCYAN='\033[1;36m'
WHITE='\033[1;37m'

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
	_CHECKER_STAFF=checker_linux
elif [[ "$OSTYPE" == "darwin"* ]]; then
	_CHECKER_STAFF=checker_mac
fi

tester_dir=`pwd`/`dirname $0`

checker_staff=${tester_dir}/$_CHECKER_STAFF

if [[ $2 == "error" ]] ; then
	error_test
	exit 0
fi

if [[ $# -ne 3 && $# -ne 4 && $# -ne 5 ]]; then
    printf "Usage: visualise.sh [directory-to-push_swap] [stacksize 0R range] [nb_of_test]\n" >&2
    exit -1
fi

rm -f push_swap_result.txt

digit='^[0-9]+$' 		#digit number
range='^[0-9]+-[0-9]+$' #range type

if [[ $2 =~ $range ]]; then
	startRange=$(( ${2%-*} + 0))
	endRange=$(( ${2##*-} + 0))
elif [[ $2 =~ $digit ]]; then
	startRange=$(( ${2%-*} + 0))
	endRange=$(( ${2##*-} + 0))
else
	printf "${RED} error: %s must be a positive number or range\n${NOCOLOR}" "$2">&2
	exit -1
fi

if ! [[ $3 =~ $digit ]]; then
	printf "${RED}error: %s must be a positive number\n${NOCOLOR}" "$3" >&2
	exit -1;
fi

TotalNbTest=$(($3 + 0))

if [[ $TotalNbTest -lt 1 ]]; then
	printf "${RED}error: %s must be a positive number\n${NOCOLOR}" "$3" >&2
	exit -1;
fi

if (( $endRange < $startRange )); then
	printf "${RED}error: invalid range\n${NOCOLOR}" >&2
	exit -1
fi

if ! [[ -f "$1/push_swap" ]]; then
	printf "${RED}error: could not find push_swap in $1 \n${NOCOLOR}" >&2
	exit -1;
elif ! [[ -f "${checker_staff}" ]]; then
	printf "${RED}error: could not find ${checker_staff} in $1 \n${NOCOLOR}" >&2
	exit -1;
elif ! [[ -x "$1/push_swap" ]]; then
	printf "${RED}error: cannot execute push_swap in $1 \n${NOCOLOR}" >&2
	exit -1;
elif ! [[ -x "${checker_staff}" ]]; then
	printf "${RED}error: cannot execute ${checker_staff} in $1 \n${NOCOLOR}" >&2
	exit -1;
else
	if [[ $5 != "testerall" ]]; then
		printf "${GREEN}Testing push_swap with $TotalNbTest tests from $startRange to $endRange \n\n${NOCOLOR}" >&2
	fi
fi

if [[ $4 == "stats" ]]; then
	if [[ $5 != "testerall" ]]; then
		printf "stack size,min,max,avg\n"
	fi
	for ((stack_size = $startRange; stack_size <= $endRange; stack_size++)); do
		(
			export TOTAL=0
			export MIN=999999999
			export MAX=0
			for ((testNB = 0; testNB < $TotalNbTest; testNB++)); do
				ARG=`${tester_dir}/genstack.pl $stack_size -2147483648 2147483647` ;
				"./$1/push_swap" $ARG > push_swap_result_$stack_size.txt ;
				RESULT_CHECKER=`"${checker_staff}" $ARG < push_swap_result_$stack_size.txt`
				MOVES=` cat push_swap_result_$stack_size.txt | wc -l`
				if (( $MOVES < $MIN )); then
					MIN=$MOVES
				fi
				if (( $MOVES > $MAX )); then
					MAX=$MOVES
				fi
				TOTAL=$(( $TOTAL + $MOVES ))
				# printf "testNB: %5d | MOVES: %5d | MIN: %5d | MAX: %5d | TOTAL: %5d                                 \r" $testNB $MOVES $MIN $MAX $TOTAL
			done
			rm -rf push_swap_result_$stack_size.txt
			AVG=$(( $TOTAL / $TotalNbTest ))
			printf "%d,%d,%d,%d                                                                                                  \n" $stack_size $MIN $MAX $AVG
		) &
	done
	wait
else
	for ((stack_size = $startRange; stack_size <= $endRange; stack_size++)); do
		TOTAL=0
		printf "${PURPLE} Generating random numbers for stack_size $stack_size...\n\n${NOCOLOR}"
	  for ((testNB = 0; testNB < $TotalNbTest; testNB++)); do
	  	printf "${DARKGRAY} TEST $testNB: ${NOCOLOR}"
		ARG=`${tester_dir}/genstack.pl $stack_size -2147483648 2147483647` ;
		"./$1/push_swap" $ARG > push_swap_result.txt ;
		RESULT_CHECKER=`"${checker_staff}" $ARG < push_swap_result.txt`
		if [[ "$RESULT_CHECKER" = "KO" ]]; then
			printf "${RED}$RESULT_CHECKER ${NOCOLOR}"
		else
			printf "${GREEN}$RESULT_CHECKER ${NOCOLOR}"
		fi
		MOVES=` cat push_swap_result.txt | wc -l`
		if (( $stack_size <= 3 )) ; then
			if (( $MOVES < 3 )); then
				COLOR=${WHITE}
			else
				COLOR=${RED}
			fi
		elif (( $stack_size <= 5 )) ; then
			if (( $MOVES < 8 )); then
				COLOR=${WHITE}
			elif (( $MOVES == 8 )); then
				COLOR=${BLUE}
			elif (( $MOVES < 13 )); then
				COLOR=${GREEN}
			else
				COLOR=${RED}
			fi
		elif (( $stack_size <= 100 )) ; then
			if (( $MOVES < 700 )); then
				COLOR=${WHITE}
			elif (( $MOVES < 900 )); then
				COLOR=${BLUE}
			elif (( $MOVES < 1100 )); then
				COLOR=${GREEN}
			elif (( $MOVES < 1500 )); then
				COLOR=${ORANGE}
			else
				COLOR=${RED}
			fi
		elif (( $stack_size <= 500 )) ; then
			if (( $MOVES < 5500 )); then
				COLOR=${WHITE}
			elif (( $MOVES < 7000 )); then
				COLOR=${BLUE}
			elif (( $MOVES < 8500 )); then
				COLOR=${GREEN}
			elif (( $MOVES < 11500 )); then
				COLOR=${ORANGE}
			else
				COLOR=${RED}
			fi
		fi
		if [[ "$RESULT_CHECKER" = "KO" ]]; then
			printf "${COLOR} $MOVES ${NOCOLOR} instructions ($ARG)\n"
		else
			printf "${COLOR} $MOVES ${NOCOLOR} instructions\n"
		fi
		TOTAL=$(( $TOTAL + $MOVES ))
	  done
	  AVG=$(( $TOTAL / $TotalNbTest ))
	  printf "\nMean: $AVG for stack of size $stack_size \n\n"
	done
fi


rm -rf push_swap_result.txt
