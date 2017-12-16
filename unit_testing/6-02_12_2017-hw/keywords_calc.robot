*** Settings ***
Documentation     Homework test case - keyword-driven testing.
Library           CalculatorLibrary.py

*** Test Cases ***
Push button 1
    Push button    1
    Result should be    1

Push button 9
    Push button    9
    Result should be    9

Clear
    Push button    1
    Push button    C
    Result should be    ${EMPTY}    # ${EMPTY} is a built-in variable

Add
    Push buttons    2 + 3 =
    Result should be    5

Subtract
    Push buttons    5 - 4 =
    Result should be    1

Multiply
    Push buttons    6 * 7 =
    Result should be    42

Division
    Push buttons    8 / 2 =
    Result should be    4

Multiple add and sub
    Push buttons    9 + 1 - 5 =
    Result should be    5

Multiple multiply and div
    Push buttons    6 * 2 / 3 =
    Result should be    4
