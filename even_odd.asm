DATA SEGMENT
    arr       DB 5, 2, 9, 6, 7, 4
    arr_size  DB 6
    even_count DB 0
    odd_count  DB 0
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

START:
    MOV AX, DATA
    MOV DS, AX

    MOV SI, 0
    MOV CL, arr_size

NEXT_ELEMENT:
    MOV AL, arr[SI]
    TEST AL, 01H
    JZ IS_EVEN

IS_ODD:
    INC odd_count
    JMP CONTINUE

IS_EVEN:
    INC even_count

CONTINUE:
    INC SI
    LOOP NEXT_ELEMENT
    HLT

CODE ENDS
END START
