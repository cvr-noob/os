#include<stdio.h>
#include<stdbool.h>

int main() {
    int n;
    printf("Enter no of processes: ");
    scanf("%d", &n);

    int p[n], all[n][3], max[n][3], ava[3], req[n][3], safeSeq[n];
    bool com[n];
    
    for(int i = 0; i < n; i++) {
        printf("Enter process id: ");
        scanf("%d", &p[i]);
        printf("Enter allocated resources for p%d: ", p[i]);
        for (int j = 0; j < 3; j++) scanf("%d", &all[i][j]);
        
        printf("Enter max required resources for p%d: ", p[i]);
        for (int j = 0; j < 3; j++) scanf("%d", &max[i][j]);
        
        for (int j = 0; j < 3; j++) req[i][j] = max[i][j] - all[i][j];
        com[i] = false;
    }

    printf("Enter available resources: ");
    for (int i = 0; i < 3; i++) scanf("%d", &ava[i]);

    int c = 0, i = 0, x = 0, idx = 0;
    
    while(c < n) {
        if(!com[i] && req[i][0] <= ava[0] && req[i][1] <= ava[1] && req[i][2] <= ava[2]) {
            for (int j = 0; j < 3; j++) ava[j] += all[i][j];
            com[i] = true;
            c++; x++;
            safeSeq[idx++] = p[i];
            printf("p%d completed\n", p[i]);
        }
        i = (i + 1) % n;
        if(c == n) break;
        if(i == 0 && x == 0) {
            printf("Deadlock\n");
            return 0;
        }
        if(i == 0) x = 0;
    }
    
    printf("System is in safe state.\nSafe sequence: ");
    for (int k = 0; k < n; k++) printf("p%d ", safeSeq[k]);
    printf("\n");

    return 0;
}
