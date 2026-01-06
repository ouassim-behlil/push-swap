#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}=== Push Swap Performance Testing ===${NC}\n"

# Function to generate random numbers
generate_random_numbers() {
	local count=$1
	local min=-2147483648
	local max=2147483647

	python3 - <<EOF
import random
numbers = random.sample(range($min, $max), $count)
print(' '.join(map(str, numbers)))
EOF
}

# Function to test a specific size
test_size() {
	local size=$1
	local max_ops=$2
	local iterations=$3

	echo -e "${YELLOW}Testing with $size numbers (Target: < $max_ops operations)${NC}"

	local total_ops=0
	local min_ops=999999
	local max_found=0
	local passed=0
	local failed_ops=0
	local failed_check=0

	for i in $(seq 1 $iterations); do
		numbers=$(generate_random_numbers $size)
		solution=$(./push_swap $numbers)
		
		# Count operations and verify with checker
		if [ -z "$solution" ]; then
			ops=0
			check_res=$(echo -n "" | ./checker_linux $numbers 2>/dev/null)
		else
			ops=$(echo "$solution" | wc -l)
			check_res=$(echo "$solution" | ./checker_linux $numbers 2>/dev/null)
		fi
		
		if [ "$check_res" != "OK" ]; then
			failed_check=$((failed_check + 1))
		fi

		total_ops=$((total_ops + ops))

		if [ $ops -lt $min_ops ]; then
			min_ops=$ops
		fi

		if [ $ops -gt $max_found ]; then
			max_found=$ops
		fi

		if [ $ops -lt $max_ops ]; then
			passed=$((passed + 1))
		else
			failed_ops=$((failed_ops + 1))
		fi

		# Progress indicator
		if [ $((i % 10)) -eq 0 ]; then
			echo -ne "  Progress: $i/$iterations\r"
		fi
	done

	local avg_ops=$((total_ops / iterations))

	echo -e "  Progress: $iterations/$iterations"
	echo -e "  ${GREEN}Average operations: $avg_ops${NC}"
	echo -e "  ${GREEN}Minimum operations: $min_ops${NC}"
	echo -e "  ${RED}Maximum operations: $max_found${NC}"
	echo -e "  ${GREEN}Passed (within limit): $passed${NC}"
	
	if [ $failed_ops -gt 0 ]; then
		echo -e "  ${RED}Exceeded limit: $failed_ops${NC}"
	fi
	
	if [ $failed_check -gt 0 ]; then
		echo -e "  ${RED}Wrong sorting: $failed_check${NC}"
	fi

	if [ $max_found -lt $max_ops ] && [ $failed_check -eq 0 ]; then
		echo -e "  ${GREEN}✓ All tests passed (correctness and performance)!${NC}\n"
		return 0
	else
		if [ $failed_check -gt 0 ]; then
			echo -e "  ${RED}✗ Failed: $failed_check tests had incorrect sorting${NC}\n"
		else
			echo -e "  ${RED}✗ Failed: Some tests exceeded limit by $((max_found - max_ops)) operations${NC}\n"
		fi
		return 1
	fi
}

# Compile the project
echo -e "${BLUE}Compiling push_swap...${NC}"
make re >/dev/null 2>&1

if [ ! -f "./push_swap" ]; then
	echo -e "${RED}Error: push_swap executable not found${NC}"
	exit 1
fi

if [ ! -f "./checker_linux" ]; then
	echo -e "${RED}Error: checker_linux not found. Please download it from the project resources.${NC}"
	exit 1
fi

chmod +x ./checker_linux

echo -e "${GREEN}Compilation successful!${NC}\n"

# Test with 100 numbers (target: < 700 operations)
test_size 100 700 1000

# Test with 500 numbers (target: < 5500 operations)
test_size 500 5500 100

echo -e "${BLUE}=== Testing Complete ===${NC}"
