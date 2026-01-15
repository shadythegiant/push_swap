#!/usr/bin/env bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 00:20:56 by bfathi            #+#    #+#              #
#    Updated: 2026/01/12 00:20:57 by bfathi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
WHITE='\033[1;37m'
DIM='\033[2m'
NC='\033[0m'
BOLD='\033[1m'

# Check arguments
if [ $# -ne 2 ]; then
    echo -e "${RED}Usage: $0 <number_of_elements> <number_of_tests>${NC}"
    echo -e "Example: $0 100 50"
    exit 1
fi

NUM_ELEMENTS=$1
NUM_TESTS=$2

# Check if executables exist
if [ ! -f "./push_swap" ]; then
    echo -e "${RED}Error: push_swap executable not found. Run 'make' first.${NC}"
    exit 1
fi

if [ ! -f "./checker_linux" ]; then
    echo -e "${RED}Error: checker_linux not found.${NC}"
    exit 1
fi

CHECKER_BONUS=""
if [ -f "./checker" ]; then
    CHECKER_BONUS="./checker"
fi

# Variables for statistics
WORST=0
BEST=999999999
TOTAL=0
OK_COUNT=0
KO_COUNT=0
CHECKER_MATCH=0
CHECKER_MISMATCH=0
CURRENT_TEST=0
PARSING_PASS=0
PARSING_TOTAL=18

# Leaks test results
LEAKS_TOTAL=14
LEAKS_PASS=0

# Error test results
ERR_TESTS_TOTAL=10
ERR_TESTS_PASS=0

# Generate random unique numbers
generate_numbers() {
    shuf -i 1-100000 -n $NUM_ELEMENTS | tr '\n' ' '
}

# Hide cursor
tput civis

# Cleanup on exit
cleanup() {
    tput cnorm  # Show cursor
    tput sgr0   # Reset colors
    echo ""
}
trap cleanup EXIT

# Clear screen and draw UI
draw_ui() {
    printf "\033[H"  # Move cursor to top-left
    
    # Calculate progress bar
    if [ $NUM_TESTS -gt 0 ]; then
        PROGRESS=$((CURRENT_TEST * 100 / NUM_TESTS))
        PROGRESS_BAR=""
        FILLED=$((PROGRESS / 5))
        for ((j=0; j<20; j++)); do
            if [ $j -lt $FILLED ]; then
                PROGRESS_BAR="${PROGRESS_BAR}█"
            else
                PROGRESS_BAR="${PROGRESS_BAR}░"
            fi
        done
    else
        PROGRESS=0
        PROGRESS_BAR="░░░░░░░░░░░░░░░░░░░░"
    fi
    
    # Calculate average
    if [ $CURRENT_TEST -gt 0 ]; then
        AVERAGE=$((TOTAL / CURRENT_TEST))
    else
        AVERAGE=0
    fi
    
    # Grade calculation
    GRADE_MSG="      "
    if [ $NUM_ELEMENTS -eq 100 ]; then
        if [ $WORST -lt 700 ] && [ $WORST -gt 0 ]; then
            GRADE_MSG="${GREEN}5/5 pts${NC}"
        elif [ $WORST -lt 900 ] && [ $WORST -gt 0 ]; then
            GRADE_MSG="${YELLOW}4/5 pts${NC}"
        elif [ $WORST -lt 1100 ] && [ $WORST -gt 0 ]; then
            GRADE_MSG="${YELLOW}3/5 pts${NC}"
        elif [ $WORST -lt 1300 ] && [ $WORST -gt 0 ]; then
            GRADE_MSG="${RED}2/5 pts${NC}"
        elif [ $WORST -lt 1500 ] && [ $WORST -gt 0 ]; then
            GRADE_MSG="${RED}1/5 pts${NC}"
        elif [ $WORST -gt 0 ]; then
            GRADE_MSG="${RED}0/5 pts${NC}"
        fi
    elif [ $NUM_ELEMENTS -eq 500 ]; then
        if [ $WORST -lt 5500 ] && [ $WORST -gt 0 ]; then
            GRADE_MSG="${GREEN}5/5 pts${NC}"
        elif [ $WORST -lt 7000 ] && [ $WORST -gt 0 ]; then
            GRADE_MSG="${YELLOW}4/5 pts${NC}"
        elif [ $WORST -lt 8500 ] && [ $WORST -gt 0 ]; then
            GRADE_MSG="${YELLOW}3/5 pts${NC}"
        elif [ $WORST -lt 10000 ] && [ $WORST -gt 0 ]; then
            GRADE_MSG="${RED}2/5 pts${NC}"
        elif [ $WORST -lt 11500 ] && [ $WORST -gt 0 ]; then
            GRADE_MSG="${RED}1/5 pts${NC}"
        elif [ $WORST -gt 0 ]; then
            GRADE_MSG="${RED}0/5 pts${NC}"
        fi
    fi
    
    # Display best
    if [ $BEST -eq 999999999 ]; then
        BEST_DISPLAY="-     "
    else
        BEST_DISPLAY=$(printf "%-6s" "$BEST")
    fi
    
    # Display worst
    if [ $WORST -eq 0 ]; then
        WORST_DISPLAY="-     "
    else
        WORST_DISPLAY=$(printf "%-6s" "$WORST")
    fi
    
    # Format average
    AVG_DISPLAY=$(printf "%-6s" "$AVERAGE")
    
    # Format counts
    OK_DISPLAY=$(printf "%-4s" "$OK_COUNT")
    KO_DISPLAY=$(printf "%-4s" "$KO_COUNT")
    MATCH_DISPLAY=$(printf "%-4s" "$CHECKER_MATCH")
    MISMATCH_DISPLAY=$(printf "%-4s" "$CHECKER_MISMATCH")
    ERR_DISPLAY=$(printf "%-2s" "$ERR_TESTS_PASS")
    PARSING_DISPLAY=$(printf "%-2s" "$PARSING_PASS")
    TOTAL_PARSING_DISPLAY=$(printf "%-2s" "$PARSING_TOTAL")
    LEAKS_DISPLAY=$(printf "%-2s" "$LEAKS_PASS")

    echo -e "${CYAN}╔══════════════════════════════════════════════════════════════════╗${NC}"
    echo -e "${CYAN}║${NC}              ${BOLD}${WHITE}PUSH_SWAP TESTER${NC}                                    ${CYAN}║${NC}"
    echo -e "${CYAN}╠══════════════════════════════════════════════════════════════════╣${NC}"
    echo -e "${CYAN}║${NC}  ${DIM}Elements:${NC} ${WHITE}$(printf "%-8s" "$NUM_ELEMENTS")${NC}    ${DIM}Tests:${NC} ${WHITE}$(printf "%-8s" "$NUM_TESTS")${NC}                           ${CYAN}║${NC}"
    echo -e "${CYAN}╠══════════════════════════════════════════════════════════════════╣${NC}"
    echo -e "${CYAN}║${NC}                                                                  ${CYAN}║${NC}"
    echo -e "${CYAN}║${NC}  ${BOLD}${YELLOW}MANDATORY PART${NC}                                                  ${CYAN}║${NC}"
    echo -e "${CYAN}║${NC}  ──────────────                                                  ${CYAN}║${NC}"
    echo -e "${CYAN}║${NC}                                                                  ${CYAN}║${NC}"
    echo -e "${CYAN}║${NC}  ${DIM}Progress:${NC} [${GREEN}$PROGRESS_BAR${NC}] ${WHITE}$(printf "%3s" "$CURRENT_TEST")${NC}/${WHITE}$(printf "%-3s" "$NUM_TESTS")${NC} ${DIM}($(printf "%3s" "$PROGRESS")%)${NC}                 ${CYAN}║${NC}"
    echo -e "${CYAN}║${NC}                                                                  ${CYAN}║${NC}"
    echo -e "${CYAN}║${NC}  ${GREEN}Best:${NC}     ${WHITE}$BEST_DISPLAY${NC}     ${RED}Worst:${NC}  ${WHITE}$WORST_DISPLAY${NC}     ${YELLOW}Avg:${NC} ${WHITE}$AVG_DISPLAY${NC}             ${CYAN}║${NC}"
    echo -e "${CYAN}║${NC}                                                                  ${CYAN}║${NC}"
    echo -e "${CYAN}║${NC}  ${DIM}Sorting:${NC}  ${GREEN}OK: $OK_DISPLAY${NC}  ${RED}KO: $KO_DISPLAY${NC}        ${DIM}Grade:${NC} $GRADE_MSG              ${CYAN}║${NC}"
    echo -e "${CYAN}║${NC}                                                                  ${CYAN}║${NC}"
    echo -e "${CYAN}║${NC}  ${DIM}Parsing:${NC}  ${GREEN}$PARSING_DISPLAY${NC}/${WHITE}$TOTAL_PARSING_DISPLAY${NC}                                                ${CYAN}║${NC}"
    echo -e "${CYAN}║${NC}                                                                  ${CYAN}║${NC}"
    echo -e "${CYAN}║${NC}  ${DIM}Leaks:${NC}    ${GREEN}$LEAKS_DISPLAY${NC}/${WHITE}$LEAKS_TOTAL${NC}                                                ${CYAN}║${NC}"
    echo -e "${CYAN}║${NC}                                                                  ${CYAN}║${NC}"
    echo -e "${CYAN}╠══════════════════════════════════════════════════════════════════╣${NC}"
    echo -e "${CYAN}║${NC}                                                                  ${CYAN}║${NC}"
    echo -e "${CYAN}║${NC}  ${BOLD}${YELLOW}BONUS PART${NC}                                                      ${CYAN}║${NC}"
    echo -e "${CYAN}║${NC}  ──────────                                                      ${CYAN}║${NC}"
    echo -e "${CYAN}║${NC}                                                                  ${CYAN}║${NC}"
    if [ -n "$CHECKER_BONUS" ]; then
        echo -e "${CYAN}║${NC}  ${DIM}Checker:${NC}  ${GREEN}Found${NC}        ${DIM}Match:${NC} ${GREEN}$MATCH_DISPLAY${NC}  ${DIM}Mismatch:${NC} ${RED}$MISMATCH_DISPLAY${NC}              ${CYAN}║${NC}"
        echo -e "${CYAN}║${NC}                                                                  ${CYAN}║${NC}"
        echo -e "${CYAN}║${NC}  ${DIM}Error Tests:${NC} ${GREEN}$ERR_DISPLAY${NC}/${WHITE}$ERR_TESTS_TOTAL${NC}                                              ${CYAN}║${NC}"
    else
        echo -e "${CYAN}║${NC}  ${DIM}Checker:${NC}  ${RED}Not Found${NC}                                             ${CYAN}║${NC}"
        echo -e "${CYAN}║${NC}  ${DIM}Run 'make bonus' to build checker${NC}                               ${CYAN}║${NC}"
        echo -e "${CYAN}║${NC}                                                                  ${CYAN}║${NC}"
    fi
    echo -e "${CYAN}║${NC}                                                                  ${CYAN}║${NC}"
    echo -e "${CYAN}╠══════════════════════════════════════════════════════════════════╣${NC}"
    
    # Calculate visible length of status message for correct padding
    CLEAN_STATUS=$(echo -e "$STATUS_MSG" | sed 's/\x1b\[[0-9;]*m//g')
    STATUS_LEN=${#CLEAN_STATUS}
    
    # Total space for message is 56 chars (66 inner width - 10 chars for "  Status: ")
    PAD_LEN=$((56 - STATUS_LEN))
    if [ $PAD_LEN -lt 0 ]; then PAD_LEN=0; fi
    PADDING=$(printf "%${PAD_LEN}s")
    
    echo -e "${CYAN}║${NC}  ${DIM}Status:${NC} ${STATUS_MSG}${PADDING}${CYAN}║${NC}"
    echo -e "${CYAN}╚══════════════════════════════════════════════════════════════════╝${NC}"
}

# Clear screen first
clear

# Initial draw
STATUS_MSG="${YELLOW}Starting tests...${NC}"
draw_ui

# Output file for failed sequences
FAIL_LOG="failed_sequences.txt"
> "$FAIL_LOG"  # Clear the file at start

# Run mandatory tests
for ((i=1; i<=NUM_TESTS; i++)); do
    CURRENT_TEST=$i
    STATUS_MSG="${BLUE}Running test $i/$NUM_TESTS...${NC}"
    draw_ui
    
    # Generate random numbers
    ARG=$(generate_numbers)
    
    # Run push_swap and count moves
    RESULT=$(./push_swap $ARG)
    MOVE_COUNT=$(echo "$RESULT" | grep -c .)
    
    if [ -z "$RESULT" ]; then
        MOVE_COUNT=0
    fi
    
    # Update statistics
    TOTAL=$((TOTAL + MOVE_COUNT))
    
    if [ $MOVE_COUNT -gt $WORST ]; then
        WORST=$MOVE_COUNT
    fi
    
    if [ $MOVE_COUNT -lt $BEST ]; then
        BEST=$MOVE_COUNT
    fi
    
    # Test with checker_linux
    if [ -z "$RESULT" ]; then
        CHECKER_RESULT=$(printf "" | ./checker_linux $ARG)
    else
        CHECKER_RESULT=$(echo "$RESULT" | ./checker_linux $ARG)
    fi
    
    if [ "$CHECKER_RESULT" == "OK" ]; then
        OK_COUNT=$((OK_COUNT + 1))
    else
        KO_COUNT=$((KO_COUNT + 1))
        # Log the failed sequence
        echo "Test #$i FAILED" >> "$FAIL_LOG"
        echo "Args: $ARG" >> "$FAIL_LOG"
        echo "Moves: $MOVE_COUNT" >> "$FAIL_LOG"
        echo "Checker result: $CHECKER_RESULT" >> "$FAIL_LOG"
        echo "---" >> "$FAIL_LOG"
    fi
    
    # Test bonus checker
    if [ -n "$CHECKER_BONUS" ]; then
        if [ -z "$RESULT" ]; then
            BONUS_RESULT=$(printf "" | $CHECKER_BONUS $ARG)
        else
            BONUS_RESULT=$(echo "$RESULT" | $CHECKER_BONUS $ARG)
        fi
        if [ "$CHECKER_RESULT" == "$BONUS_RESULT" ]; then
            CHECKER_MATCH=$((CHECKER_MATCH + 1))
        else
            CHECKER_MISMATCH=$((CHECKER_MISMATCH + 1))
        fi
    fi
    
    draw_ui
done

# Run Parsing Tests
STATUS_MSG="${BLUE}Running parsing tests...${NC}"
draw_ui

# helper for parsing check valid
check_valid() {
    ERR=$(./push_swap "$@" 2>&1 >/dev/null)
    if [ -z "$ERR" ]; then
        PARSING_PASS=$((PARSING_PASS + 1))
    else
        echo "Parsing Fail (Valid expected): $@" >> "$FAIL_LOG"
        echo "Output: $ERR" >> "$FAIL_LOG"
    fi
    draw_ui
}

# helper for parsing check error
check_error() {
    ERR=$(./push_swap "$@" 2>&1 >/dev/null)
    if [[ "$ERR" == *"Error"* ]]; then
        PARSING_PASS=$((PARSING_PASS + 1))
    else
        echo "Parsing Fail (Error expected): $@" >> "$FAIL_LOG"
        echo "Output: $ERR" >> "$FAIL_LOG"
    fi
    draw_ui
}

# Valid cases
check_valid 1 3 5 +9 20 -4 50 60 04 08
check_valid "3 4 6 8 9 74 -56 +495"
check_valid "95 99 -9 10 9"
check_valid 2147483647 2 4 7
check_valid 99 -2147483648 23 545
check_valid "2147483647 843 56544 24394"
check_valid "1 2 4 3" 76 90 "348 05"

# Error cases
check_error 1 3 dog 35 80 -3
check_error a
check_error 1 2 3 5 67b778 947
check_error " 12 4 6 8 54fhd 4354"
check_error 1 -- 45 32
check_error 1 3 58 9 3
check_error 3 03
check_error " 49 128     50 38   49"
check_error 54867543867438 3
check_error -2147483647765 4 5
check_error "214748364748385 28 47 29"

# Run error handling tests for bonus
if [ -n "$CHECKER_BONUS" ]; then
    STATUS_MSG="${BLUE}Testing checker error handling...${NC}"
    ERR_TESTS_PASS=0
    draw_ui
    
    # Test: Non-numeric argument
    LINUX_ERR=$(./checker_linux "a" "b" "c" 2>&1)
    BONUS_ERR=$($CHECKER_BONUS "a" "b" "c" 2>&1)
    [ "$LINUX_ERR" == "$BONUS_ERR" ] && ERR_TESTS_PASS=$((ERR_TESTS_PASS + 1))
    draw_ui
    
    # Test: Duplicate numbers
    LINUX_ERR=$(./checker_linux 1 2 3 1 2>&1)
    BONUS_ERR=$($CHECKER_BONUS 1 2 3 1 2>&1)
    [ "$LINUX_ERR" == "$BONUS_ERR" ] && ERR_TESTS_PASS=$((ERR_TESTS_PASS + 1))
    draw_ui
    
    # Test: Integer overflow
    LINUX_ERR=$(./checker_linux 2147483648 2>&1)
    BONUS_ERR=$($CHECKER_BONUS 2147483648 2>&1)
    [ "$LINUX_ERR" == "$BONUS_ERR" ] && ERR_TESTS_PASS=$((ERR_TESTS_PASS + 1))
    draw_ui
    
    # Test: Integer underflow
    LINUX_ERR=$(./checker_linux -2147483649 2>&1)
    BONUS_ERR=$($CHECKER_BONUS -2147483649 2>&1)
    [ "$LINUX_ERR" == "$BONUS_ERR" ] && ERR_TESTS_PASS=$((ERR_TESTS_PASS + 1))
    draw_ui
    
    # Test: Empty string
    LINUX_ERR=$(./checker_linux "" 2>&1)
    BONUS_ERR=$($CHECKER_BONUS "" 2>&1)
    [ "$LINUX_ERR" == "$BONUS_ERR" ] && ERR_TESTS_PASS=$((ERR_TESTS_PASS + 1))
    draw_ui
    
    # Test: Invalid instruction
    LINUX_ERR=$(echo "invalid" | ./checker_linux 1 2 3 2>&1)
    BONUS_ERR=$(echo "invalid" | $CHECKER_BONUS 1 2 3 2>&1)
    [ "$LINUX_ERR" == "$BONUS_ERR" ] && ERR_TESTS_PASS=$((ERR_TESTS_PASS + 1))
    draw_ui
    
    # Test: Already sorted
    LINUX_OK=$(./checker_linux 1 2 3 < /dev/null 2>&1)
    BONUS_OK=$($CHECKER_BONUS 1 2 3 < /dev/null 2>&1)
    [ "$LINUX_OK" == "$BONUS_OK" ] && ERR_TESTS_PASS=$((ERR_TESTS_PASS + 1))
    draw_ui
    
    # Test: Single number
    LINUX_OK=$(./checker_linux 42 < /dev/null 2>&1)
    BONUS_OK=$($CHECKER_BONUS 42 < /dev/null 2>&1)
    [ "$LINUX_OK" == "$BONUS_OK" ] && ERR_TESTS_PASS=$((ERR_TESTS_PASS + 1))
    draw_ui
    
    # Test: Valid operations (sorted)
    LINUX_OK=$(printf "sa\n" | ./checker_linux 2 1 3 2>&1)
    BONUS_OK=$(printf "sa\n" | $CHECKER_BONUS 2 1 3 2>&1)
    [ "$LINUX_OK" == "$BONUS_OK" ] && ERR_TESTS_PASS=$((ERR_TESTS_PASS + 1))
    # Test: Valid operations (unsorted)
    LINUX_OK=$(printf "sa\n" | ./checker_linux 1 2 3 2>&1)
    BONUS_OK=$(printf "sa\n" | $CHECKER_BONUS 1 2 3 2>&1)
    [ "$LINUX_OK" == "$BONUS_OK" ] && ERR_TESTS_PASS=$((ERR_TESTS_PASS + 1))
    draw_ui
fi

# Run Leaks Tests
if command -v valgrind &> /dev/null; then
    STATUS_MSG="${BLUE}Running memory leak tests...${NC}"
    draw_ui
    
    run_leak_test() {
        valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=42 ./push_swap $1 > /dev/null 2>&1
        if [ $? -ne 42 ]; then
            LEAKS_PASS=$((LEAKS_PASS + 1))
        else
            echo "Leak detected with args: '$1'" >> "$FAIL_LOG"
        fi
        draw_ui
    }

    # 1. Empty string
    run_leak_test ""
    
    # 2. Spaces
    run_leak_test "   "
    
    # 3. Non-numeric
    run_leak_test "a b c"
    
    # 4. Duplicate
    run_leak_test "1 2 3 1"
    
    # 5. Overflow
    run_leak_test "2147483648"
    
    # 6. Underflow
    run_leak_test "-2147483649"
    
    # 7. Already sorted
    run_leak_test "1 2 3"
    
    # 8. Single number
    run_leak_test "42"
    
    # 9. Simple Swap
    run_leak_test "2 1"
    
    # 10-14. Random Valid Tests
    for ((i=1; i<=5; i++)); do
        ARG=$(generate_numbers)
        run_leak_test "$ARG"
    done
else
    STATUS_MSG="${YELLOW}Valgrind not found, skipping leaks${NC}"
    draw_ui
    sleep 1
fi

# Final status
if [ $KO_COUNT -eq 0 ] && [ $CHECKER_MISMATCH -eq 0 ] && [ $ERR_TESTS_PASS -eq $ERR_TESTS_TOTAL ] && [ $PARSING_PASS -eq $PARSING_TOTAL ] && [ $LEAKS_PASS -eq $LEAKS_TOTAL ]; then
    STATUS_MSG="${GREEN}All tests passed! ✓${NC}"
elif [ $KO_COUNT -gt 0 ]; then
    STATUS_MSG="${RED}Some sorting tests failed!${NC}"
elif [ $PARSING_PASS -lt $PARSING_TOTAL ]; then
    STATUS_MSG="${RED}Parsing tests failed!${NC}"
elif [ $LEAKS_PASS -lt $LEAKS_TOTAL ]; then
    STATUS_MSG="${RED}Memory leaks detected!${NC}"
elif [ $CHECKER_MISMATCH -gt 0 ]; then
    STATUS_MSG="${RED}Checker mismatch detected!${NC}"
else
    STATUS_MSG="${YELLOW}Tests complete with issues${NC}"
fi

draw_ui

# Move cursor below the UI and exit
tput cup 29 0
echo ""
