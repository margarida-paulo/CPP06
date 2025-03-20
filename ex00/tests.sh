#!/bin/bash

# Função para imprimir testes com cores
run_test() {
    echo -e "\n\n\n\033[35m$1\033[0m"
    ./converter "$2"
}

test_group() {
    echo -e "\n**************************************************"
    echo -e "\033[36m$1\033[0m"
    echo -e "**************************************************"
}

# ------------------- OVERFLOW AND UNDERFLOW TESTS -------------------
test_group "Overflow and Underflow Tests"

run_test "Test 1: Input Overflow - Int (2147483648)" "2147483648"
run_test "Test 2: Input Overflow - Int (-2147483649)" "-2147483649"

run_test "Test 3: Input Overflow - Float (3.5e38f)" "3.5e38f"
run_test "Test 4: Input Overflow - Float (-3.5e38f)" "-3.5e38f"

run_test "Test 5: Input Overflow - Double (1.8e308)" "1.8e308"
run_test "Test 6: Input Overflow - Double (-1.8e308)" "-1.8e308"

run_test "Test 9: Input Underflow - Float (1.0e-46f)" "1.0e-46f"
run_test "Test 10: Input Underflow - Float (-1.0e-46f)" "-1.0e-46f"

run_test "Test 11: Input Underflow - Double (5.0e-325)" "5.0e-325"
run_test "Test 12: Input Underflow - Double (-5.0e-325)" "-5.0e-325"

# ------------------------ NORMAL CASES ------------------------
test_group "Normal Cases Tests"

run_test "Test 15: Normal Integer (42)" "42"
run_test "Test 16: Normal Float (3.14f)" "3.14f"
run_test "Test 17: Normal Double (2.71828)" "2.71828"

# ------------------------ LIMITE E SPECIAL CASES ------------------------
test_group "Limit and Special Cases Tests"

run_test "Test 18: INT_MAX (2147483647)" "2147483647"
run_test "Test 19: INT_MIN (-2147483648)" "-2147483648"

run_test "Test 20: FLOAT_MAX (3.40282e+38f)" "3.40282e+38f"
run_test "Test 21: FLOAT_MIN (1.17549e-38f)" "1.17549e-38f"

run_test "Test 22: DOUBLE_MAX (1.79769e+308)" "1.79769e+308"
run_test "Test 23: DOUBLE_MIN (2.22507e-308)" "2.22507e-308"

run_test "Test 24: FLOAT_EPSILON (1.19209e-07f)" "1.19209e-07f"
run_test "Test 25: DOUBLE_EPSILON (2.22045e-16)" "2.22045e-16"

# ------------------------ SPECIAL NUMBERS ------------------------
test_group "Special Numbers Tests"

run_test "Test 26: Infinity (inf)" "inf"
run_test "Test 27: Negative Infinity (-inf)" "-inf"
run_test "Test 28: Not-a-Number (NaN)" "NaN"

# ------------------------ EDGE CASES ------------------------
test_group "Edge Cases Tests"

run_test "Test 29: Zero (0)" "0"
run_test "Test 30: Negative Zero (-0)" "-0"

run_test "Test 31: Large Integer that fits in double but not int (9223372036854775807)" "9223372036854775807"
run_test "Test 32: Large Negative Integer that fits in double but not int (-9223372036854775808)" "-9223372036854775808"

run_test "Test 35: Largest normal float before INF (3.40282e+38f)" "3.40282e+38f"
run_test "Test 36: Largest normal double before INF (1.79769e+308)" "1.79769e+308"

run_test "Test 37: Almost Overflow Float (3.4e38f)" "3.4e38f"
run_test "Test 38: Almost Overflow Double (1.79e308)" "1.79e308"

run_test "Test 39: Almost Underflow Float (1.2e-38f)" "1.2e-38f"
run_test "Test 40: Almost Underflow Double (2.3e-308)" "2.3e-308"

run_test "Test 43: Maximum normal float (1.17549e-38f)" "1.17549e-38f"
run_test "Test 44: Maximum normal double (2.22507e-308)" "2.22507e-308"

run_test "Test 45: One more than INT_MAX (2147483648)" "2147483648"
run_test "Test 46: One less than INT_MIN (-2147483649)" "-2147483649"

run_test "Test 49: Smallest normal float (1.17549e-38f)" "1.17549e-38f"
run_test "Test 50: Smallest normal double (2.22507e-308)" "2.22507e-308"

echo -e "\n\n\033[32mTodos os testes foram executados!\033[0m 🚀"