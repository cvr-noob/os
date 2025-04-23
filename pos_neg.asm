DATA SEGMENT
    num      DB -5
    msg_pos  DB 'Number is positive$'
    msg_neg  DB 'Number is negative$'
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

START:
    MOV AX, DATA
    MOV DS, AX

    MOV AL, num
    CMP AL, 0
    JL NEGATIVE

POSITIVE:
    LEA DX, msg_pos
    JMP PRINT

NEGATIVE:
    LEA DX, msg_neg

PRINT:
    MOV AH, 09H
    INT 21H

    MOV AH, 4CH
    INT 21H

CODE ENDS
END START
