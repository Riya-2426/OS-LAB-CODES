#include <stdio.h> 
#include <stdbool.h> 
struct process { 
    int pid,at,bt;        
    int pr,ct,tat,wt,rt;        
    bool done;      
}; 
int main() { 
    int n; 
    printf("Enter number of processes: "); 
    scanf("%d", &n); 
    struct process p[n]; 
    for (int i = 0; i < n; i++) { 
        p[i].pid = i + 1; 
        printf("Enter AT, BT and Priority for P%d: ", i + 1); 
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].pr); 
        p[i].done = false; 
    } 
    int completed = 0, time = 0, idle = 0; 
    float avg_tat = 0, avg_wt = 0, avg_rt = 0; 
    int min_at = p[0].at, max_ct = 0; 
    for (int i = 0; i < n; i++) { 
        if (p[i].at < min_at) min_at = p[i].at;
         } 
    time = min_at; 
    while (completed < n) { 
        int idx = -1; 
        int best_priority = 1e9; 
        for (int i = 0; i < n; i++) { 
            if (!p[i].done && p[i].at <= time) { 
                if (p[i].pr < best_priority) { 
                    best_priority = p[i].pr; 
                    idx = i; 
                } else if (p[i].pr == best_priority) { 
                    if (p[i].at < p[idx].at) idx = i; 
                }}} 
        if (idx != -1) { 
            p[idx].ct = time + p[idx].bt; 
            p[idx].tat = p[idx].ct - p[idx].at; 
            p[idx].wt = p[idx].tat - p[idx].bt; 
            p[idx].rt = p[idx].wt;  
            avg_tat += p[idx].tat; 
            avg_wt += p[idx].wt; 
            avg_rt += p[idx].rt; 
            time = p[idx].ct; 
            p[idx].done = true; 
            completed++; 
            if (p[idx].ct > max_ct) max_ct = p[idx].ct; 
        } else { 
            time++;  
            idle++; 
        }
          } 
    printf("\nProcess\tAT\tBT\tPr\tCT\tTAT\tWT\tRT\n"); 
    for (int i = 0; i < n; i++) { 
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 
               p[i].pid, p[i].at, p[i].bt, p[i].pr, 
               p[i].ct, p[i].tat, p[i].wt, p[i].rt); 
    } 
    avg_tat /= n; 
    avg_wt /= n; 
    avg_rt /= n; 
    float cpu_util = ((max_ct - idle) / (float)max_ct) * 100.0; 
    float throughput = (float)n / (max_ct - min_at); 
    printf("\nAverage TAT = %.2f", avg_tat); 
    printf("\nAverage WT  = %.2f", avg_wt); 
    printf("\nAverage RT  = %.2f", avg_rt); 
    printf("\nCPU Utilization = %.2f%%", cpu_util); 
    printf("\nThroughput = %.2f process/unit time\n", throughput); 
    return 0; 
}